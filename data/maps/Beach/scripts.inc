Beach_MapScripts::
# 2 "data/maps/Beach/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
	.2byte 0


Beach_Palooka_A::
# 8 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 9 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_A
# 10 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 11 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 12 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 13 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 14 "data/maps/Beach/scripts.pory"
	waitmessage
# 15 "data/maps/Beach/scripts.pory"
	release
	return


Beach_NeutralPalooka_A::
# 19 "data/maps/Beach/scripts.pory"
	lockall
# 20 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_2
Beach_NeutralPalooka_A_1:
# 24 "data/maps/Beach/scripts.pory"
	checktrainerflag TRAINER_FIRST_PALOOKA
	goto_if 1, Beach_NeutralPalooka_A_5
Beach_NeutralPalooka_A_4:
# 45 "data/maps/Beach/scripts.pory"
	releaseall
	end

Beach_NeutralPalooka_A_2:
# 22 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_0
	goto Beach_NeutralPalooka_A_1

Beach_NeutralPalooka_A_5:
# 26 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_7
# 42 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_2
	goto Beach_NeutralPalooka_A_4

Beach_NeutralPalooka_A_7:
# 27 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 28 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_NEUTRAL_PALOOKA_A, Common_Movement_ExclamationMark
# 29 "data/maps/Beach/scripts.pory"
	waitmovement
# 30 "data/maps/Beach/scripts.pory"
	delay 30
# 31 "data/maps/Beach/scripts.pory"
	faceplayer
# 32 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_1
# 37 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_NEUTRAL_PALOOKA_A, Common_Movement_FaceUp
# 38 "data/maps/Beach/scripts.pory"
	waitmovement
# 39 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_1
	goto Beach_NeutralPalooka_A_4


Beach_Palooka_A_Text_0:
# 10 "data/maps/Beach/scripts.pory"
	.string "Bleh!$"

Beach_Palooka_A_Text_1:
# 11 "data/maps/Beach/scripts.pory"
	.string "Bleh...$"

Beach_Palooka_A_Text_2:
# 13 "data/maps/Beach/scripts.pory"
	.string "Go away!$"

Beach_NeutralPalooka_A_Text_0:
# 22 "data/maps/Beach/scripts.pory"
	.string "{FONT_PALOOKA}E... ROVA AR,WA...?$"

Beach_NeutralPalooka_A_Text_1:
# 32 "data/maps/Beach/scripts.pory"
	.string "Don't worry, I'm not a threat, alien. I'm\n"
	.string "a technician.\p"
	.string "You see the tracks on the ground?\p"
	.string "They're from the drones we sent before\n"
	.string "we got here in person.\p"
	.string "This one's path seems to have...gone\n"
	.string "into the wall.\p"
	.string "You haven't seen it anywhere, have you?$"

Beach_NeutralPalooka_A_Text_2:
# 42 "data/maps/Beach/scripts.pory"
	.string "Maybe there's something scarier than\n"
	.string "us here...$"
