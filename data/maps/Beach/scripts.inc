Beach_MapScripts::
# 2 "data/maps/Beach/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
	.2byte 0


Beach_Palooka_A::
# 9 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 10 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_A
# 11 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 12 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 13 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 14 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 15 "data/maps/Beach/scripts.pory"
	waitmessage
# 16 "data/maps/Beach/scripts.pory"
	release
	return


Beach_Palooka_A_Text_0:
# 11 "data/maps/Beach/scripts.pory"
	.string "Bleh!$"

Beach_Palooka_A_Text_1:
# 12 "data/maps/Beach/scripts.pory"
	.string "Bleh...$"

Beach_Palooka_A_Text_2:
# 14 "data/maps/Beach/scripts.pory"
	.string "Go away!$"
