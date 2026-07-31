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
#include "new_game.h"
#include "m4a.h"
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
    WIN_HEADER,
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
        .baseBlock = 0,//0x150,
    },
    [WIN_HEADER] = {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28, //224 px
        .height = 2, //16 px
        .paletteNum = 0,
        .baseBlock = 282,
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
static void PrepareHeaderWindow(void);
static void DrawHeaderWindow(void);
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
static bool8 IsNamed(void);
void CB2_InitIntroCard_BackFromNaming(void);
void CB2_InitIntroCard_BackFromRenaming(void);
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
    // 504 = shift down by 8 pixels (8 = shift up by 8)
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF] + 504;
    REG_BG0VOFS = bgVOffset;
    REG_BG1VOFS = bgVOffset;
    REG_BG3VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_IntroCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CloseIntroCard(u8 taskId)
{
    DebugPrintfLevel(MGBA_LOG_DEBUG, "Close Intro Card");
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    SetMainCallback2(CB2_NewGame);
    DestroyTask(taskId);
}

static void SetIntroCardCb2(void)
{
    SetMainCallback2(CB2_IntroCard);
}

static void SetUpIntroCardTask(void)
{
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(Task_IntroCard, 0);
}

// Returns true if player has entered a name at least once
static bool8 IsNamed(void)
{
    return sData->playerName[0] != EOS;
}

static bool8 PrintAllOnCardFront(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCard();
        break;
    case 1:
        PrintIdOnCard();
        break;
    case 2:
        PrintOthersOnCard();
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
    if (IsNamed())
    {
        // Player has been named
        StringCopy(txtPtr, sData->playerName);
    }
    // Print "NAME: " and player name if it has been set
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 33, sIntroCardTextColors, TEXT_SKIP_DRAW, buffer);
}

static void PrintIdOnCard(void)
{
    u8 fullStr[32];
    u8 *txtPtr;
    txtPtr = StringCopy(fullStr, gText_TrainerCardIDNo);
    ConvertIntToDecimalStringN(txtPtr, (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0], STR_CONV_MODE_LEADING_ZEROS, 5);
    s32 centerOffset = GetStringCenterAlignXOffset(FONT_NORMAL, fullStr, 96) + 120;
    u32 top = 9;
    if (!IsNamed())
        fullStr[5] = EOS; // Chop off blank id
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, centerOffset, top, sIntroCardTextColors, TEXT_SKIP_DRAW, fullStr);
}

static void PrintOthersOnCard(void)
{
    s32 xOffset;

    // Money (Charge)
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
    u8 buffer[64];

    if (!IsNamed())
    {
        StringCopy(buffer, COMPOUND_STRING("{FONT_NORMAL}{A_COLOR}{FONT_SMALL}ENTER NAME  "));
    }
    else if (IsCardFlipTaskActive())
    {
        // Naming has happened once, and before the flip
        StringCopy(buffer, COMPOUND_STRING("{FONT_NORMAL}{B_COLOR}{FONT_SMALL}RENAME  "));
        StringAppend(buffer, COMPOUND_STRING("{FONT_NORMAL}{A_COLOR}{FONT_SMALL}FLIP"));
    }
    else
    {
        StringCopy(buffer, COMPOUND_STRING("{FONT_NORMAL}{A_COLOR}{FONT_SMALL}FINISH"));
    }
    
    // Print controls
    static const u8 colors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, 11 /*matches TEXT_COLOR_DARK_GRAY, in palette 0*/};
    AddTextPrinterParameterized3(WIN_HEADER, FONT_SMALL, 0, 0, colors, TEXT_SKIP_DRAW, buffer);
}

static void PrintObjectiveOnCard(u8 top, const u8 *text)
{
    static const u8 textOffset = 16;
    //static const u8 checkOffset = 0;

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, textOffset, top * 16 + 33, sIntroCardTextColors, TEXT_SKIP_DRAW, text);
}

static void PrintObjectivesOnCard(void)
{
    PrintObjectiveOnCard(0,
        COMPOUND_STRING("Catch first partner"));
    PrintObjectiveOnCard(1, 
        COMPOUND_STRING("Study alien devices"));
    PrintObjectiveOnCard(2, 
        COMPOUND_STRING("Find cause of Exo-Pokémon agitation"));
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
    switch(sData->mainState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(13));
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
        DrawCardScreenBackground(sData->bgTilemap);
        sData->mainState++;
        break;
    case 4:
        PrepareHeaderWindow();
        PrintControls();
        DrawHeaderWindow();
        sData->mainState++;
        break;
    case 5:
        FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
        CreateIntroCardTrainerPic();
        DrawIntroCardWindow(WIN_TRAINER_PIC);
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
        SetHBlankCallback(HblankCb_IntroCard);
        // Ensure buffer is clean for the shift down in Hblank
        ScanlineEffect_Stop();
        ScanlineEffect_Clear();
        for (u32 i = 0; i < DISPLAY_HEIGHT; i++)
            gScanlineEffectRegBuffers[1][i] = 0;
        sData->mainState++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            if (!IsNamed())
                PlaySE(SE_RG_CARD_OPEN);
            SetHBlankCallback(NULL);
            sData->mainState++;
        }
        break;
    case STATE_HANDLE_INPUT_FRONT:
        if (!IsNamed())
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
            m4aSongNumStop(SE_RG_CARD_OPEN);
            PlaySE(SE_M_PETAL_DANCE);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!UpdatePaletteFade() && !IsSEPlaying())
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
        
        // Set whether naming or renaming
        MainCallback callback = !IsNamed() ? CB2_InitIntroCard_BackFromNaming : CB2_InitIntroCard_BackFromRenaming;

        FREE_AND_SET_NULL(sData);
        
        // Set default name so things don't explode
        StringCopy(gSaveBlock2Ptr->playerName, COMPOUND_STRING("Robin"));
        gSaveBlock2Ptr->playerName[PLAYER_NAME_LENGTH] = EOS;
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, MALE, 0, 0, callback);
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
    PrepareHeaderWindow();
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

    do {
        switch (sData->flipDrawState)
        {
        case 0:
            FillWindowPixelBuffer(WIN_CARD_TEXT, PIXEL_FILL(0));
            FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
            PrepareHeaderWindow();
            PrintControls();
            break;
        case 1:
            if (!PrintAllOnCardBack())
                return FALSE;
            break;
        case 2:
            DrawCard(sData->backTilemap);
            break;
        case 3:
            break;
        case 4:
            FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
            break;
        default:
            task->tFlipState++;
            sData->allowDMACopy = TRUE;
            sData->flipDrawState = 0;
            return FALSE;
        }
        sData->flipDrawState++;
    } while (sData->flipDrawState != 0);

    return FALSE;
}

static bool8 Task_SetCardFlipped(struct Task *task)
{
    sData->allowDMACopy = FALSE;
    DrawIntroCardWindow(WIN_TRAINER_PIC);
    DrawIntroCardWindow(WIN_CARD_TEXT);
    sData->onBack ^= 1;
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
    DrawHeaderWindow();
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(Task_DoCardFlipTask));
    return FALSE;
}

#undef tFlipState
#undef tCardTop

static bool8 LoadCardGfx(void)
{
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
    sData = AllocZeroed(sizeof(*sData));
    sData->playerName[0] = EOS;
    SetMainCallback2(CB2_InitIntroCard);
}

void CB2_InitIntroCard_BackFromNaming(void)
{
    //NewGameInitData();
    CB2_InitIntroCard_BackFromRenaming();
}

void CB2_InitIntroCard_BackFromRenaming(void)
{
    sData = AllocZeroed(sizeof(*sData));
    StringCopy(sData->playerName, gSaveBlock2Ptr->playerName);
    sData->callback2 = CB2_NewGame;
    SetMainCallback2(CB2_InitIntroCard);
}

void CB2_InitIntroCard(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetGpuRegs();
        SetUpIntroCardTask();
        gMain.state++;
        break;
    case 1:
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 6:
        InitGpuRegs();
        gMain.state++;
        break;
    case 7:
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
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
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

// Tile used for the screen background
// A #define just in case I edit the tileset and have to move it
#define SCREEN_TILE TILE_OFFSET_4BPP(89)

static void PrepareHeaderWindow(void)
{
    u32 size = GetWindowAttribute(WIN_HEADER, WINDOW_WIDTH) * GetWindowAttribute(WIN_HEADER, WINDOW_HEIGHT);
    u32 startTile = GetWindowAttribute(WIN_HEADER, WINDOW_BASE_BLOCK);

    // Fill WIN_HEADER with tiles from the "screen" background
    for (u32 i = 0; i < 56; i++)
    {
        CpuCopy32(&sData->cardTiles[SCREEN_TILE], (void *)(BG_VRAM) + TILE_OFFSET_4BPP(startTile + i), 32);
    }

    // Copy tiles to gfx buffer
    CopyToWindowPixelBuffer(WIN_HEADER, (void *)(BG_VRAM) + TILE_OFFSET_4BPP(startTile), TILE_OFFSET_4BPP(size), 0);
}

#undef SCREEN_TILE

static void DrawHeaderWindow(void)
{
    DrawIntroCardWindow(WIN_HEADER);
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
    sData->trainerSprite = CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), TRUE, 1, 0, 8, WIN_TRAINER_PIC);
}
