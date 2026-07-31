#ifndef GUARD_FIELD_STUDY_MODE_H
#define GUARD_FIELD_STUDY_MODE_H

extern u8 gStudyModeCatchLimit;

bool32 GetStudyModeFlag(void);
void SetStudyModeFlag(void);
void ResetStudyModeFlag(void);

void EnterStudyMode(void);
void ExitStudyMode(void);

void CB2_EndStudyModeBattle(void);

#endif //GUARD_FIELD_STUDY_MODE_H
