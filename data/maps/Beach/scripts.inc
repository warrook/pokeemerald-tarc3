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
	trainerbattle_single TRAINER_BEACH_A, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Beach_Palooka_A_Defeated
	return


Beach_Palooka_A_Defeated::
# 12 "data/maps/Beach/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 13 "data/maps/Beach/scripts.pory"
	waitmovement
# 14 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Defeated_Text_0
# 15 "data/maps/Beach/scripts.pory"
	closemessage
# 16 "data/maps/Beach/scripts.pory"
	call Tamagotchi_Palookaport_Out
	return


Beach_Palooka_B::
# 20 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_B, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_C::
# 24 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_C, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_D::
# 28 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_D, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_E::
# 32 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_E, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_WaterGuard::
# 36 "data/maps/Beach/scripts.pory"
	msgbox Beach_WaterGuard_Text_0
	return


Beach_NeutralPalooka_A::
# 40 "data/maps/Beach/scripts.pory"
	lockall
# 41 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_2
Beach_NeutralPalooka_A_1:
# 45 "data/maps/Beach/scripts.pory"
	checktrainerflag TRAINER_FIRST_PALOOKA
	goto_if 1, Beach_NeutralPalooka_A_5
Beach_NeutralPalooka_A_4:
# 66 "data/maps/Beach/scripts.pory"
	releaseall
	end

Beach_NeutralPalooka_A_2:
# 43 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_0
	goto Beach_NeutralPalooka_A_1

Beach_NeutralPalooka_A_5:
# 47 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_7
# 63 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_2
	goto Beach_NeutralPalooka_A_4

Beach_NeutralPalooka_A_7:
# 48 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 49 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_ExclamationMark
# 50 "data/maps/Beach/scripts.pory"
	waitmovement
# 51 "data/maps/Beach/scripts.pory"
	delay 30
# 52 "data/maps/Beach/scripts.pory"
	faceplayer
# 53 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_1
# 58 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_FaceUp
# 59 "data/maps/Beach/scripts.pory"
	waitmovement
# 60 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_1
	goto Beach_NeutralPalooka_A_4


Beach_Palooka_A_Text_0:
# 8 "data/maps/Beach/scripts.pory"
	.string "Bleh!$"

Beach_Palooka_A_Text_1:
# 8 "data/maps/Beach/scripts.pory"
	.string "Bleh...$"

Beach_Palooka_A_Defeated_Text_0:
# 14 "data/maps/Beach/scripts.pory"
	.string "Yikes! You're strong!$"

Beach_WaterGuard_Text_0:
# 36 "data/maps/Beach/scripts.pory"
	.string "Hello!!$"

Beach_NeutralPalooka_A_Text_0:
# 43 "data/maps/Beach/scripts.pory"
	.string "{FONT_PALOOKA}E... ROVA AR,WA...?$"

Beach_NeutralPalooka_A_Text_1:
# 53 "data/maps/Beach/scripts.pory"
	.string "Don't worry, I'm not a threat, alien. I'm\n"
	.string "a technician.\p"
	.string "You see the tracks on the ground?\p"
	.string "They're from the drones we sent before\n"
	.string "we got here in person.\p"
	.string "This one's path seems to have...gone\n"
	.string "into the wall.\p"
	.string "You haven't seen it anywhere, have you?$"

Beach_NeutralPalooka_A_Text_2:
# 63 "data/maps/Beach/scripts.pory"
	.string "Maybe there's something scarier than\n"
	.string "us here...$"
