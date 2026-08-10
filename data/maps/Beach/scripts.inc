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


Beach_Palooka_B::
# 19 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 20 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_B
# 21 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 22 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 23 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 24 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 25 "data/maps/Beach/scripts.pory"
	waitmessage
# 26 "data/maps/Beach/scripts.pory"
	release
	return


Beach_Palooka_C::
# 30 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 31 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_C
# 32 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 33 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 34 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 35 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 36 "data/maps/Beach/scripts.pory"
	waitmessage
# 37 "data/maps/Beach/scripts.pory"
	release
	return


Beach_Palooka_D::
# 41 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 42 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_D
# 43 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 44 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 45 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 46 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 47 "data/maps/Beach/scripts.pory"
	waitmessage
# 48 "data/maps/Beach/scripts.pory"
	release
	return


Beach_Palooka_E::
# 52 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
# 53 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8004, TRAINER_BEACH_E
# 54 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_1, Beach_Palooka_A_Text_0
# 55 "data/maps/Beach/scripts.pory"
	bufferstring STR_VAR_2, Beach_Palooka_A_Text_1
# 56 "data/maps/Beach/scripts.pory"
	call Tamagotchi_TryEarlyPalookas
# 57 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Text_2
# 58 "data/maps/Beach/scripts.pory"
	waitmessage
# 59 "data/maps/Beach/scripts.pory"
	release
	return


Beach_WaterGuard::
# 63 "data/maps/Beach/scripts.pory"
	msgbox Beach_WaterGuard_Text_0
	return


Beach_NeutralPalooka_A::
# 67 "data/maps/Beach/scripts.pory"
	lockall
# 68 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_2
Beach_NeutralPalooka_A_1:
# 72 "data/maps/Beach/scripts.pory"
	checktrainerflag TRAINER_FIRST_PALOOKA
	goto_if 1, Beach_NeutralPalooka_A_5
Beach_NeutralPalooka_A_4:
# 93 "data/maps/Beach/scripts.pory"
	releaseall
	end

Beach_NeutralPalooka_A_2:
# 70 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_0
	goto Beach_NeutralPalooka_A_1

Beach_NeutralPalooka_A_5:
# 74 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_7
# 90 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_2
	goto Beach_NeutralPalooka_A_4

Beach_NeutralPalooka_A_7:
# 75 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 76 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_ExclamationMark
# 77 "data/maps/Beach/scripts.pory"
	waitmovement
# 78 "data/maps/Beach/scripts.pory"
	delay 30
# 79 "data/maps/Beach/scripts.pory"
	faceplayer
# 80 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_1
# 85 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_FaceUp
# 86 "data/maps/Beach/scripts.pory"
	waitmovement
# 87 "data/maps/Beach/scripts.pory"
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

Beach_WaterGuard_Text_0:
# 63 "data/maps/Beach/scripts.pory"
	.string "Hello!!$"

Beach_NeutralPalooka_A_Text_0:
# 70 "data/maps/Beach/scripts.pory"
	.string "{FONT_PALOOKA}E... ROVA AR,WA...?$"

Beach_NeutralPalooka_A_Text_1:
# 80 "data/maps/Beach/scripts.pory"
	.string "Don't worry, I'm not a threat, alien. I'm\n"
	.string "a technician.\p"
	.string "You see the tracks on the ground?\p"
	.string "They're from the drones we sent before\n"
	.string "we got here in person.\p"
	.string "This one's path seems to have...gone\n"
	.string "into the wall.\p"
	.string "You haven't seen it anywhere, have you?$"

Beach_NeutralPalooka_A_Text_2:
# 90 "data/maps/Beach/scripts.pory"
	.string "Maybe there's something scarier than\n"
	.string "us here...$"
