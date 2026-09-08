Beach_MapScripts::
# 2 "data/maps/Beach/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
# 4 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1, Tamagotchi_KidEvo_Explanation
# 5 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 2, Tamagotchi_YoungEvo_Explanation
	.2byte 0


Beach_Palooka_A::
# 10 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_A, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Beach_Palooka_A_Defeated
	return


Beach_Palooka_A_Defeated::
# 14 "data/maps/Beach/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 15 "data/maps/Beach/scripts.pory"
	waitmovement
# 16 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Defeated_Text_0
# 17 "data/maps/Beach/scripts.pory"
	closemessage
# 18 "data/maps/Beach/scripts.pory"
	call Tamagotchi_Palookaport_Out
	return


Beach_Palooka_B::
# 22 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_B, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_C::
# 26 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_C, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_D::
# 30 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_D, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_E::
# 34 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_E, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_WaterGuard::
# 38 "data/maps/Beach/scripts.pory"
	msgbox Beach_WaterGuard_Text_0
	return


Beach_NeutralPalooka_A::
# 42 "data/maps/Beach/scripts.pory"
	lockall
# 43 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_2
Beach_NeutralPalooka_A_1:
# 47 "data/maps/Beach/scripts.pory"
	checktrainerflag TRAINER_FIRST_PALOOKA
	goto_if 1, Beach_NeutralPalooka_A_5
Beach_NeutralPalooka_A_4:
# 68 "data/maps/Beach/scripts.pory"
	releaseall
	end

Beach_NeutralPalooka_A_2:
# 45 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_0
	goto Beach_NeutralPalooka_A_1

Beach_NeutralPalooka_A_5:
# 49 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_7
# 65 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_2
	goto Beach_NeutralPalooka_A_4

Beach_NeutralPalooka_A_7:
# 50 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 51 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_ExclamationMark
# 52 "data/maps/Beach/scripts.pory"
	waitmovement
# 53 "data/maps/Beach/scripts.pory"
	delay 30
# 54 "data/maps/Beach/scripts.pory"
	faceplayer
# 55 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_1
# 60 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_FaceUp
# 61 "data/maps/Beach/scripts.pory"
	waitmovement
# 62 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_1
	goto Beach_NeutralPalooka_A_4


Beach_Palooka_A_Text_0:
# 10 "data/maps/Beach/scripts.pory"
	.string "Bleh!$"

Beach_Palooka_A_Text_1:
# 10 "data/maps/Beach/scripts.pory"
	.string "Bleh...$"

Beach_Palooka_A_Defeated_Text_0:
# 16 "data/maps/Beach/scripts.pory"
	.string "Yikes! You're strong!$"

Beach_WaterGuard_Text_0:
# 38 "data/maps/Beach/scripts.pory"
	.string "Hello!!$"

Beach_NeutralPalooka_A_Text_0:
# 45 "data/maps/Beach/scripts.pory"
	.string "{FONT_PALOOKA}E... ROVA AR,WA...?$"

Beach_NeutralPalooka_A_Text_1:
# 55 "data/maps/Beach/scripts.pory"
	.string "Don't worry, I'm not a threat, alien. I'm\n"
	.string "a technician.\p"
	.string "You see the tracks on the ground?\p"
	.string "They're from the drones we sent before\n"
	.string "we got here in person.\p"
	.string "This one's path seems to have...gone\n"
	.string "into the wall.\p"
	.string "You haven't seen it anywhere, have you?$"

Beach_NeutralPalooka_A_Text_2:
# 65 "data/maps/Beach/scripts.pory"
	.string "Maybe there's something scarier than\n"
	.string "us here...$"
