#include "global.h"
#include "malloc.h"
//#include "battle.h"
//#include "battle_setup.h"
#include "bg.h"
//#include "birch_pc.h"
//#include "data.h"
//#include "event_data.h"
//#include "event_object_movement.h"
//#include "field_player_avatar.h"
#include "main.h"
//#include "match_call.h"
#include "menu.h"
//#include "new_game.h"
//#include "overworld.h"
#include "palette.h"
//#include "pokedex.h"
//#include "pokemon.h"
//#include "random.h"
//#include "region_map.h"
//#include "rtc.h"
//#include "script.h"
//#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
//#include "wild_encounter.h"
#include "window.h"
//#include "field_name_box.h"
//#include "constants/abilities.h"
//#include "constants/battle_frontier.h"
//#include "constants/event_objects.h"
//#include "constants/region_map_sections.h"
#include "constants/songs.h"
//#include "constants/trainers.h"

static void ExecuteSuitCall(u8);
static bool32 SuitCall_LoadGfx(u8);
static bool32 SuitCall_DrawWindow(u8);
static bool32 SuitCall_SlideWindowIn(u8);
static bool32 SuitCall_ReadyMessage(u8);
static bool32 SuitCall_PrintMessage(u8);
static bool32 SuitCall_SlideWindowOut(u8);
static bool32 SuitCall_EndCall(u8);

#define ACCENT_COLOR TEXT_COLOR_TRANSPARENT
#define FOREGROUND_COLOR 10
#define BACKGROUND_COLOR 4
#define SHADOW_COLOR TEXT_COLOR_TRANSPARENT

static void DrawSuitCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId);
static void InitSuitCallTextPrinter(int windowId, const u8 *str);
static bool32 RunSuitCallTextPrinter(int windowId);

void StartSuitCall(void)
{
    //PlaySE(SE_POKENAV_ON);
    CreateTask(ExecuteSuitCall, 1);
}

static const u16 sSuitCallWindow_Pal[] = INCGFX_U16("graphics/suit_call/window.png", ".gbapal");
static const u8 sSuitCallWindow_Gfx[] = INCGFX_U8("graphics/suit_call/window.png", ".4bpp");

#define tState      data[0]
#define tWindowId   data[2]
//#define tIconTaskId data[5]

static bool32 (*const sSuitCallTaskFuncs[])(u8) =
{
    SuitCall_LoadGfx, // 0
    SuitCall_DrawWindow, // 1
    SuitCall_SlideWindowIn, // 2
    SuitCall_ReadyMessage, // 3
    SuitCall_PrintMessage, // 4
    SuitCall_SlideWindowOut, // 5
    SuitCall_EndCall, // 6
};

static void ExecuteSuitCall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sSuitCallTaskFuncs[tState](taskId))
    {
        tState++;
        //DebugPrintfLevel(MGBA_LOG_WARN, "Entering Suitcall stage %d", tState);
        if ((u16)tState > 6)
        {
            DestroyTask(taskId);
        }
    }
}

static const struct WindowTemplate sSuitCallTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x200,
};

#define TILE_SC_WINDOW    0x270
//#define TILE_POKENAV_ICON 0x279

static bool32 SuitCall_LoadGfx(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tWindowId = AddWindow(&sSuitCallTextWindow);
    if (tWindowId == WINDOW_NONE)
    {
        // Too many windows in use
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, sSuitCallWindow_Gfx, sizeof(sSuitCallWindow_Gfx), TILE_SC_WINDOW) == 0xFFFF)
    {
        RemoveWindow(tWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(tWindowId, PIXEL_FILL(BACKGROUND_COLOR));
    LoadPalette(sSuitCallWindow_Pal, BG_PLTT_ID(14), sizeof(sSuitCallWindow_Pal));
    ChangeBgY(0, -0x2000, BG_COORD_SET);
    return TRUE;
}

static bool32 SuitCall_DrawWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;
    
        PutWindowTilemap(tWindowId);
        DrawSuitCallTextBoxBorder_Internal(tWindowId, TILE_SC_WINDOW, 14);
        CopyWindowToVram(tWindowId, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
}

static bool32 SuitCall_SlideWindowIn(u8 taskId)
{
    if (ChangeBgY(0, 0x600, BG_COORD_ADD) >= 0)
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return TRUE;
    }

    return FALSE;
}

static bool32 SuitCall_ReadyMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        InitSuitCallTextPrinter(tWindowId, gStringVar4);
        return TRUE;
    }

    return FALSE;
}

static bool32 SuitCall_PrintMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!RunSuitCallTextPrinter(tWindowId) && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        // Kill the window
        FillWindowPixelBuffer(tWindowId, PIXEL_FILL(BACKGROUND_COLOR));
        CopyWindowToVram(tWindowId, COPYWIN_GFX);
        //PlaySE(SE_POKENAV_OFF);
        return TRUE;
    }

    return FALSE;
}

static bool32 SuitCall_SlideWindowOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (ChangeBgY(0, 0x600, BG_COORD_SUB) <= -0x4000)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 12, 30, 8);
        RemoveWindow(tWindowId);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
    }

    return FALSE;
}

static bool32 SuitCall_EndCall(u8 taskId)
{
    if (!IsDma3ManagerBusyWithBgCopy() && !IsSEPlaying())
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return TRUE;
    }

    return FALSE;
}

static void DrawSuitCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

//#undef TILE_POKENAV_ICON
#undef TILE_SC_WINDOW

//#undef tIconTaskId
#undef tWindowId
#undef tState

static void InitSuitCallTextPrinter(int windowId, const u8 *str)
{
    struct TextPrinterTemplate printerTemplate;
    printerTemplate.currentChar = str;
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = FONT_NORMAL;
    printerTemplate.x = 2;
    printerTemplate.y = 1;
    printerTemplate.currentX = 2;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.color.accent = TEXT_COLOR_TRANSPARENT;
    printerTemplate.color.foreground = FOREGROUND_COLOR;
    printerTemplate.color.background = BACKGROUND_COLOR;
    printerTemplate.color.shadow = SHADOW_COLOR;
    gTextFlags.useAlternateDownArrow = FALSE;

    AddTextPrinter(&printerTemplate, GetPlayerTextSpeedDelay(), NULL);
}

static bool32 RunSuitCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = TRUE;
    else
        gTextFlags.canABSpeedUpPrint = FALSE;
    
    RunTextPrinters();
    return IsTextPrinterActiveOnWindow(windowId);
}

bool32 IsSuitCallTaskActive(void)
{
    return FuncIsActiveTask(ExecuteSuitCall);
}

#undef ACCENT_COLOR
#undef FOREGROUND_COLOR
#undef BACKGROUND_COLOR
#undef SHADOW_COLOR
