#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "overworld.h"
#include "pokemon.h"
#include "event_scripts.h"

EWRAM_DATA static u8 sStudyModeCaughtMons = 0;
EWRAM_DATA u16 gStudyModeCatchLimit = 0; 

bool32 GetStudyModeFlag(void)
{
    return FlagGet(FLAG_SYS_STUDY_MODE);
}

void SetStudyModeFlag(void)
{
    FlagSet(FLAG_SYS_STUDY_MODE);
}

void ResetStudyModeFlag(void)
{
    FlagClear(FLAG_SYS_STUDY_MODE);
}

void EnterStudyMode(void)
{
    u16 catchLimit = gSpecialVar_0x8004;
    SetStudyModeFlag();
    sStudyModeCaughtMons = 0;
    gStudyModeCatchLimit = catchLimit;
}

void ExitStudyMode(void)
{
    ResetStudyModeFlag();
}

void CB2_EndStudyModeBattle(void)
{
    if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        sStudyModeCaughtMons++;
        if (!FlagGet(FLAG_SYS_POKEMON_GET))
        {
            FlagSet(FLAG_SYS_POKEMON_GET);
            FlagSet(FLAG_SYS_POKEDEX_GET);
            ScriptContext_SetupScript(Banzo_EventScript_AfterCatch);
        }
    }
    if (sStudyModeCaughtMons >= gStudyModeCatchLimit)
    {
        ExitStudyMode();
    }
    SetMainCallback2(CB2_ReturnToField);
}
