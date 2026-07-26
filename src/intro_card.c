#include "global.h"
#include "scanline_effect.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "malloc.h"
#include "link.h"
#include "bg.h"
#include "sound.h"
#include "frontier_pass.h"
#include "overworld.h"
#include "menu.h"
#include "text.h"
#include "event_data.h"
#include "easy_chat.h"
#include "money.h"
#include "strings.h"
#include "string_util.h"
//#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "pokemon_icon.h"
#include "trainer_pokemon_sprites.h"
#include "contest_util.h"
#include "decompress.h"
#include "naming_screen.h"
#include "load_save.h"
#include "intro_card.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "constants/union_room.h"

enum {
    WIN_MSG,
    WIN_CARD_TEXT,
    WIN_TRAINER_PIC,
    WIN_FOOTER,
};

struct CardData
{
    u8 mainState;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    MainCallback callback2;
    u16 backTilemap[600];
    u16 frontTilemap[600];
    u16 bgTilemap[600];
    u8 cardTiles[0x2300];
    u16 cardTilemapBuffer[0x1000];
    u16 bgTilemapBuffer[0x1000];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u16 trainerSprite;
    bool8 allowDMACopy;
    u16 cardTop;
    u8 flipDrawState;
    bool8 onBack;
    s8 flipBlendY;
};

static const struct BgTemplate sIntroCardBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 192
    },
};

static const struct WindowTemplate sIntroCardWindowTemplates[] =
{
    [WIN_MSG] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x253,
    },
    [WIN_CARD_TEXT] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    [WIN_TRAINER_PIC] = {
        .bg = 3,
        .tilemapLeft = 19,
        .tilemapTop = 5,
        .width = 9,
        .height = 10,
        .paletteNum = 8,
        .baseBlock = 0x150,
    },
    [WIN_FOOTER] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 18,
        .width = 28, //224 px
        .height = 2, //16 px
        .paletteNum = 15,
        .baseBlock = 504,
    },
    DUMMY_WIN_TEMPLATE
};

EWRAM_DATA static struct CardData *sData = NULL;

static void VblankCb_IntroCard(void);
static void HblankCb_IntroCard(void);
static void CB2_IntroCard(void);
static void CloseIntroCard(u8 taskId);
static bool8 PrintAllOnCardFront(void);
static bool8 PrintAllOnCardBack(void);
static void PrintControls(void);
static void PrintObjectivesOnCard(void);
static void DrawIntroCardWindow(u8);
static u8 SetCardBgsAndPals(void);
static void CreateIntroCardTrainerPic(void);
static void DrawCard(u16 *ptr);
static void DrawCardScreenBackground(u16 *);
static bool8 LoadCardGfx(void);
//static void CB2_InitIntroCard(void);
static void InitGpuRegs(void);
static void ResetGpuRegs(void);
static void InitBgsAndWindows(void);
static void SetIntroCardCb2(void);
static void SetUpIntroCardTask(void);
//static void InitIntroCardData(void);

static void PrintNameOnCard(void);
static void PrintIdOnCard(void);
static void PrintOthersOnCard(void);

//static void Task_IntroCard_Init(u8 taskId);
static void Task_IntroCard(u8 taskId);
static void Task_StartNamingScreen(u8 taskId);
static void FlipTrainerCard(void);
static bool8 IsCardFlipTaskActive(void);
static void Task_DoCardFlipTask(u8);
static bool8 Task_BeginCardFlip(struct Task *task);
static bool8 Task_AnimateCardFlipDown(struct Task *task);
static bool8 Task_DrawFlippedCardSide(struct Task *task);
static bool8 Task_SetCardFlipped(struct Task *task);
static bool8 Task_AnimateCardFlipUp(struct Task *task);
static bool8 Task_EndCardFlip(struct Task *task);
static void UpdateCardFlipRegs(u16);
void CB2_InitIntroCard_BackFromNaming(void);
void CB2_InitIntroCard(void);

static const u8 sIntroCardTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sIntroCardControlColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sIntroCardBlankColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_TRANSPARENT};

static bool8 (*const sTrainerCardFlipTasks[])(struct Task *) =
{
    Task_BeginCardFlip,
    Task_AnimateCardFlipDown,
    Task_DrawFlippedCardSide,
    Task_SetCardFlipped,
    Task_AnimateCardFlipUp,
    Task_EndCardFlip,
};

static void VblankCb_IntroCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    DmaCopy16(3, &gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 0x140);
}

static void HblankCb_IntroCard(void)
{
    u16 backup;
    u16 bgVOffset;

    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_IntroCard(void)
{
    //DebugPrintf("CB2_IntroCard");
    RunTasks();
    //DebugPrintf("CB2_IntroCard after RunTasks");
    AnimateSprites();
    //DebugPrintf("CB2_IntroCard after AnimateSprites");
    BuildOamBuffer();
    //DebugPrintf("CB2_IntroCard after BuildOamBuffer");
    UpdatePaletteFade();
    //DebugPrintf("CB2_IntroCard after UpdatePaletteFade");
}

static void CloseIntroCard(u8 taskId)
{
    SetMainCallback2(sData->callback2);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    DestroyTask(taskId);
}

static void SetIntroCardCb2(void)
{
    //DebugPrintf("SetIntroCardCb2");
    SetMainCallback2(CB2_IntroCard);
}

static void SetUpIntroCardTask(void)
{
    //DebugPrintf("SetUpIntroCardTask");
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(Task_IntroCard, 0);
}

static bool8 PrintAllOnCardFront(void)
{
    //DebugPrintf("sData->printState: %d", sData->printState);
    switch (sData->printState)
    {
    case 0:
        //DebugPrintf("Print Name");
        PrintNameOnCard();
        //DebugPrintf("Finished Print Name");
        break;
    case 1:
        //DebugPrintf("Print Id");
        PrintIdOnCard();
        //DebugPrintf("Finished Print Id");
        break;
    case 2:
        //DebugPrintf("Print Others");
        PrintOthersOnCard();
        //DebugPrintf("Finished Print Others");
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static bool8 PrintAllOnCardBack(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintObjectivesOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void PrintNameOnCard(void)
{
    u8 buffer[32];
    u8 *txtPtr;
    txtPtr = StringCopy(buffer, gText_TrainerCardName);
    if (sData->playerName[0] != EOS)
        StringCopy(txtPtr, sData->playerName);
    else
    {
        s32 xOffset = GetStringWidth(FONT_NORMAL, buffer, 0);

        const u8 aColor[] = _("{A_COLOR}");
        const u8 aButton[] = _("{A_BUTTON}");
        const u8 text[] = _(" ENTER NAME");
        
        u8 txt2[32];
        StringCopy(txt2, aButton);
        StringAppend(txt2, text);
        s32 centerOffset = GetStringCenterAlignXOffset(FONT_SMALL, txt2, 66);

        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16 + xOffset + centerOffset, 33, sIntroCardBlankColors, TEXT_SKIP_DRAW, aColor);
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_SMALL, 16 + xOffset + centerOffset + 8, 33, sIntroCardBlankColors, TEXT_SKIP_DRAW, text);
    }
    //DebugPrintf("StringCopy succeeded");
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 33, sIntroCardTextColors, TEXT_SKIP_DRAW, buffer);
}

static void PrintIdOnCard(void)
{
    u8 fullStr[32];
    StringCopy(fullStr, gText_TrainerCardIDNo);
    StringAppend(fullStr, gText_TrainerCardIDDashes);
    s32 centerOffset = GetStringCenterAlignXOffset(FONT_NORMAL, fullStr, 96) + 120;
    u32 top = 9;

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, centerOffset, top, sIntroCardTextColors, TEXT_SKIP_DRAW, fullStr);
}

static void PrintOthersOnCard(void)
{
    s32 xOffset;

    // Money (M-E)
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 57, sIntroCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardMoney);
    ConvertIntToDecimalStringN(gStringVar1, 3000, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 128);
    
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xOffset, 57, sIntroCardTextColors, TEXT_SKIP_DRAW, gStringVar4);

    // Pokedex
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 73, sIntroCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardPokedex);
    StringCopy(ConvertIntToDecimalStringN(gStringVar4, 0, STR_CONV_MODE_LEFT_ALIGN, 4), gText_EmptyString6);
    
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 128);

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xOffset, 73, sIntroCardTextColors, TEXT_SKIP_DRAW, gStringVar4);

    // Time
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 89, sIntroCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardTime);
    s32 width = GetStringWidth(FONT_NORMAL, gText_TrainerCardTimeBlank, 0);
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 128 - width, 89, sIntroCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardTimeBlank);
}

static void PrintControls(void)
{
    if (sData->playerName[0] == EOS)
        return;
    
    s32 width;
    u8 buffer[64];

    // Rename after naming has happened once, and before the flip
    if (IsCardFlipTaskActive())
    {
        u8 enterName[] = _("{B_BUTTON}RENAME ");
        StringCopy(buffer, enterName);
    }

    // Flip or finish depending on flipped
    u8 flip[] = _("{A_BUTTON}FLIP");
    u8 finish[] = _("{A_BUTTON}FINISH");
    if (IsCardFlipTaskActive())
        StringAppend(buffer, flip);
    else
        StringCopy(buffer, finish);
    
    // Print controls
    width = GetStringWidth(FONT_SMALL, buffer, 0);
    FillWindowPixelRect(WIN_FOOTER, PIXEL_FILL(0), 224 - width, 1, width, 15);
    AddTextPrinterParameterized3(WIN_FOOTER, FONT_SMALL, 224 - width, 1, sIntroCardControlColors, TEXT_SKIP_DRAW, buffer);
}

static void PrintObjectiveOnCard(u8 top, const u8 *text)
{
    static const u8 textOffset = 16;
    //static const u8 checkOffset = 0;

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, textOffset, top * 16 + 33, sIntroCardTextColors, TEXT_SKIP_DRAW, text);
}

static void PrintObjectivesOnCard(void)
{
    const u8 str1[] = _("Catch first partner");
    const u8 str2[] = _("Study alien devices");
    const u8 str3[] = _("Find cause of EXO-POKéMON agitation");

    PrintObjectiveOnCard(0, str1);
    PrintObjectiveOnCard(1, str2);
    PrintObjectiveOnCard(2, str3);
}

static void DoNaming(u8 taskId)
{
    PlaySE(SE_SELECT);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_StartNamingScreen;
}

#define STATE_HANDLE_INPUT_FRONT  9
#define STATE_HANDLE_INPUT_BACK   10
#define STATE_WAIT_FLIP           11
#define STATE_CLOSE_CARD          12

static void Task_IntroCard(u8 taskId)
{
    //DebugPrintfLevel(MGBA_LOG_DEBUG,"Task_IntroCard: sData->mainState: %d", sData->mainState);
    switch(sData->mainState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(WIN_FOOTER, PIXEL_FILL(0));
            FillWindowPixelBuffer(WIN_CARD_TEXT, PIXEL_FILL(0));
            sData->mainState++;
        }
        break;
    case 1:
        if (PrintAllOnCardFront())
            sData->mainState++;
        break;
    case 2:
        DrawIntroCardWindow(WIN_CARD_TEXT);
        sData->mainState++;
        break;
    case 3:
        PrintControls();
        DrawIntroCardWindow(WIN_FOOTER);
        sData->mainState++;
        break;
    case 4:
        FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
        CreateIntroCardTrainerPic();
        //DebugPrintfLevel(MGBA_LOG_DEBUG, "Outside Trainer Pic");
        DrawIntroCardWindow(WIN_TRAINER_PIC);
        sData->mainState++;
        break;
    case 5:
        DrawCardScreenBackground(sData->bgTilemap);
        sData->mainState++;
        break;
    case 6:
        DrawCard(sData->frontTilemap);
        sData->mainState++;
        break;
    case 7:
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VblankCb_IntroCard);
        sData->mainState++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            if (sData->playerName[0] == EOS)
                PlaySE(SE_RG_CARD_OPEN);
            sData->mainState++;
        }
        break;
    case STATE_HANDLE_INPUT_FRONT:
        if (sData->playerName[0] == EOS)
        {
            if (JOY_NEW(A_BUTTON))
                DoNaming(taskId);
        }
        else
        {
            if (JOY_NEW(A_BUTTON))
            {
                FlipTrainerCard();
                PlaySE(SE_RG_CARD_FLIP);
                sData->mainState = STATE_WAIT_FLIP;
            }
            else if (JOY_NEW(B_BUTTON))
                DoNaming(taskId);
        }
        break;
    case STATE_WAIT_FLIP:
        if (IsCardFlipTaskActive())
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_BACK;
        }
        break;
    case STATE_HANDLE_INPUT_BACK:
        if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            //PlaySE(SE_RG_CARD_FLIP);
            PlaySE(SE_M_MORNING_SUN);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!UpdatePaletteFade())
            CloseIntroCard(taskId);
        break;
    }
}

static void Task_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyTrainerPicSprite(sData->trainerSprite);
        FREE_AND_SET_NULL(sData);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, MALE, 0, 0, CB2_InitIntroCard_BackFromNaming);
    }
}

#define tFlipState data[0]
#define tCardTop   data[1]

static void FlipTrainerCard(void)
{
    u8 taskId = CreateTask(Task_DoCardFlipTask, 0);
    Task_DoCardFlipTask(taskId);
    SetHBlankCallback(HblankCb_IntroCard);
}

static bool8 IsCardFlipTaskActive(void)
{
    if (FindTaskIdByFunc(Task_DoCardFlipTask) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_DoCardFlipTask(u8 taskId)
{
    while (sTrainerCardFlipTasks[gTasks[taskId].tFlipState](&gTasks[taskId]))
        ;
}

static bool8 Task_BeginCardFlip(struct Task *task)
{
    u32 i;

    HideBg(1);
    HideBg(3);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = 0;
    task->tFlipState++;
    return FALSE;
}

// Note: Cannot be DISPLAY_HEIGHT / 2, or cardHeight will be 0
#define CARD_FLIP_Y ((DISPLAY_HEIGHT / 2) - 3) // 77

static bool8 Task_AnimateCardFlipDown(struct Task *task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tCardTop = CARD_FLIP_Y;
    else
        task->tCardTop += 7;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 *= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 -= r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_DrawFlippedCardSide(struct Task *task)
{
    sData->allowDMACopy = FALSE;
    if (Overworld_IsRecvQueueAtMax() == TRUE)
        return FALSE;

    switch (sData->flipDrawState)
    {
    case 0:
        FillWindowPixelBuffer(WIN_CARD_TEXT, PIXEL_FILL(0));
        FillWindowPixelBuffer(WIN_FOOTER, PIXEL_FILL(0));
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        break;
    case 1:
        if (!PrintAllOnCardBack())
            return FALSE;
        PrintControls();
        break;
    case 2:
        DrawCard(sData->backTilemap);
        break;
    case 3:
        //DrawIntroCardWindow(WIN_FOOTER);
        //DrawIntroCardWindow(WIN_CARD_TEXT);
        break;
    case 4:
        FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
        //DrawIntroCardWindow(WIN_TRAINER_PIC);
        break;
    default:
        task->tFlipState++;
        sData->allowDMACopy = TRUE;
        sData->flipDrawState = 0;
        return FALSE;
    }
    sData->flipDrawState++;

    return FALSE;
}

static bool8 Task_SetCardFlipped(struct Task *task)
{
    sData->allowDMACopy = FALSE;

    DrawIntroCardWindow(WIN_TRAINER_PIC);
    DrawIntroCardWindow(WIN_CARD_TEXT);
    DrawIntroCardWindow(WIN_FOOTER);
    sData->onBack ^= 1;
    DebugPrintfLevel(MGBA_LOG_DEBUG, "On back: %d", sData->onBack);
    task->tFlipState++;
    sData->allowDMACopy = TRUE;
    PlaySE(SE_RG_CARD_FLIPPING);
    return FALSE;
}

static bool8 Task_AnimateCardFlipUp(struct Task *task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop <= 5)
        task->tCardTop = 0;
    else
        task->tCardTop -= 5;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 /= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 += r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop <= 0)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_EndCardFlip(struct Task *task)
{
    ShowBg(1);
    ShowBg(3);
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(Task_DoCardFlipTask));
    return FALSE;
}

#undef tFlipState
#undef tCardTop

static bool8 LoadCardGfx(void)
{
    //DebugPrintfLevel(MGBA_LOG_DEBUG,"gfxLoadState: %d", sData->gfxLoadState);
    switch (sData->gfxLoadState)
    {
    case 0:
        DecompressDataWithHeaderWram(gTamagotchiTrainerCardBg_Tilemap, sData->bgTilemap);
        break;
    case 1:
        DecompressDataWithHeaderVram(gTamagotchiTrainerCardBack_Tilemap, sData->backTilemap);
        break;
    case 2:
        DecompressDataWithHeaderVram(gTamagotchiTrainerCardFront_Tilemap, sData->frontTilemap);
        break;
    case 3:
        DecompressDataWithHeaderWram(gTamagotchiTrainerCard_Gfx, sData->cardTiles);
        break;
    default:
        sData->gfxLoadState = 0;
        return TRUE;
    }
    sData->gfxLoadState++;
    return FALSE;
}

void CB2_InitIntroCard_FirstRun(void)
{
    //DebugPrintf("CB2_InitIntroCard_FirstRun");
    sData = AllocZeroed(sizeof(*sData));
    sData->playerName[0] = EOS;
    SetMainCallback2(CB2_InitIntroCard);
}

void CB2_InitIntroCard_BackFromNaming(void)
{
    //DebugPrintfLevel(MGBA_LOG_DEBUG, "BackFromNaming");
    sData = AllocZeroed(sizeof(*sData));
    StringCopy(sData->playerName, gSaveBlock2Ptr->playerName);
    sData->callback2 = CB2_NewGame;
    SetMainCallback2(CB2_InitIntroCard);
}

void CB2_InitIntroCard(void)
{
    //DebugPrintf("Reached CB2_InitIntroCard");
    switch (gMain.state)
    {
    case 0:
        //DebugPrintf("state: 0");
        ResetGpuRegs();
        SetUpIntroCardTask();
        gMain.state++;
        break;
    case 1:
        //DebugPrintf("state: 1");
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        //DebugPrintf("state: 2");
        //DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 3:
        //DebugPrintf("state: 3");
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        //DebugPrintf("state: 4");
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        //DebugPrintf("state: 5");
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 6:
        //DebugPrintf("state: 6");
        InitGpuRegs();
        gMain.state++;
        break;
    case 7:
        //DebugPrintf("state: 7");
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
        //DebugPrintf("state: default");
        SetIntroCardCb2();
        break;
    }
}

static void InitGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, DISPLAY_HEIGHT);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

static void UpdateCardFlipRegs(u16 cardTop)
{
    s8 blendY = (cardTop + 40) / 10;

    if (blendY <= 4)
        blendY = 0;
    sData->flipBlendY = blendY;
    SetGpuReg(REG_OFFSET_BLDY, sData->flipBlendY);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(sData->cardTop, DISPLAY_HEIGHT - sData->cardTop));
}

static void ResetGpuRegs(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

static void InitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sIntroCardBgTemplates, ARRAY_COUNT(sIntroCardBgTemplates));
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    InitWindows(sIntroCardWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void DrawIntroCardWindow(u8 windowId)
{
    //DebugPrintfLevel(MGBA_LOG_DEBUG, "Inside DrawIntroCardWindow");
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static u8 SetCardBgsAndPals(void)
{
    switch (sData->bgPalLoadState)
    {
    case 0:
        LoadBgTiles(0, sData->cardTiles, 0x1800, 0);
        break;
    case 1:
        LoadPalette(gTamagotchiTrainerCard_Pal, BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
        break;
    case 2:
        SetBgTilemapBuffer(0, sData->cardTilemapBuffer);
        SetBgTilemapBuffer(2, sData->bgTilemapBuffer);
        break;
    case 3:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return TRUE;
    }
    sData->bgPalLoadState++;
    return FALSE;
}

static void DrawCard(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->cardTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(0);
}

static void DrawCardScreenBackground(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->bgTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(2);
}

static void CreateIntroCardTrainerPic(void)
{
    //DebugPrintfLevel(MGBA_LOG_DEBUG, "Inside Trainer Pic");
    sData->trainerSprite = CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), TRUE, 1, 0, 8, WIN_TRAINER_PIC);
}