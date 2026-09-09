Beach_MapScripts::
# 2 "data/maps/Beach/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Beach_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/Beach/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Beach_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Beach/scripts.pory"
	goto_if_set FLAG_WATER_GUARD_DEFEATED, Beach_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Beach_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/Beach/scripts.pory"
	setobjectmovementtype LOCALID_WATER_AGITATOR, MOVEMENT_TYPE_FACE_DOWN
	return

Beach_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
# 9 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1, Tamagotchi_KidEvo_Explanation
# 10 "data/maps/Beach/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 2, Tamagotchi_YoungEvo_Explanation
	.2byte 0


Beach_Palooka_A::
# 15 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_A, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1, Beach_Palooka_A_Defeated
	return


Beach_Palooka_A_Defeated::
# 19 "data/maps/Beach/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 20 "data/maps/Beach/scripts.pory"
	waitmovement
# 21 "data/maps/Beach/scripts.pory"
	msgbox Beach_Palooka_A_Defeated_Text_0
# 22 "data/maps/Beach/scripts.pory"
	closemessage
# 23 "data/maps/Beach/scripts.pory"
	call Tamagotchi_Palookaport_Out
	return


Beach_Palooka_B::
# 27 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_B, Beach_Palooka_B_Text_0, Beach_Palooka_B_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_C::
# 31 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_C, Beach_Palooka_C_Text_0, Beach_Palooka_C_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_D::
# 35 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_D, Beach_Palooka_D_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_Palooka_E::
# 39 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_E, Beach_Palooka_D_Text_0, Beach_Palooka_A_Text_1, Tamagotchi_Palookaport_Out
	return


Beach_WaterGuard::
# 43 "data/maps/Beach/scripts.pory"
	call Tamagotchi_BossIntro
# 44 "data/maps/Beach/scripts.pory"
	trainerbattle_no_intro TRAINER_WATER_GUARD, Beach_WaterGuard_Text_0
# 45 "data/maps/Beach/scripts.pory"
	msgbox Beach_WaterGuard_Text_1
# 46 "data/maps/Beach/scripts.pory"
	closemessage
# 47 "data/maps/Beach/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_WATER_GUARD
# 48 "data/maps/Beach/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 49 "data/maps/Beach/scripts.pory"
	goto_if_set FLAG_TEMP_2, Beach_WaterGuard_2
# 52 "data/maps/Beach/scripts.pory"
	goto_if_set FLAG_TEMP_3, Beach_WaterGuard_3
# 56 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_PLAYER, Beach_WaterGuard_Movement_2
Beach_WaterGuard_1:
# 58 "data/maps/Beach/scripts.pory"
	waitmovement
# 59 "data/maps/Beach/scripts.pory"
	setvar VAR_0x8006, LOCALID_WATER_AGITATOR
# 60 "data/maps/Beach/scripts.pory"
	call Tamagotchi_AgitatorInteract
# 61 "data/maps/Beach/scripts.pory"
	addvar VAR_BOSSES_DEFEATED, 1
# 62 "data/maps/Beach/scripts.pory"
	setflag FLAG_WATER_GUARD_DEFEATED
# 63 "data/maps/Beach/scripts.pory"
	releaseall
	return

Beach_WaterGuard_2:
# 50 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_PLAYER, Beach_WaterGuard_Movement_0
	goto Beach_WaterGuard_1

Beach_WaterGuard_3:
# 53 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_PLAYER, Beach_WaterGuard_Movement_1
	goto Beach_WaterGuard_1


Beach_WaterGuard_Alerted::
# 67 "data/maps/Beach/scripts.pory"
	lockall
# 68 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_GUARD, Beach_WaterGuard_Alerted_Movement_0
# 69 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 70 "data/maps/Beach/scripts.pory"
	waitse
	return


Beach_WaterGuard_Trigger_Top::
# 75 "data/maps/Beach/scripts.pory"
	call Beach_WaterGuard_Alerted
# 76 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_2
# 77 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_GUARD, Beach_WaterGuard_Trigger_Top_Movement_0
# 78 "data/maps/Beach/scripts.pory"
	waitmovement
# 79 "data/maps/Beach/scripts.pory"
	goto Beach_WaterGuard
	return


Beach_WaterGuard_Trigger_Middle::
# 83 "data/maps/Beach/scripts.pory"
	call Beach_WaterGuard_Alerted
# 84 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_3
# 85 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_GUARD, Beach_WaterGuard_Trigger_Middle_Movement_0
# 86 "data/maps/Beach/scripts.pory"
	waitmovement
# 87 "data/maps/Beach/scripts.pory"
	goto Beach_WaterGuard
	return


Beach_WaterGuard_Trigger_Bottom::
# 91 "data/maps/Beach/scripts.pory"
	call Beach_WaterGuard_Alerted
# 92 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_4
# 93 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_GUARD, Beach_WaterGuard_Trigger_Bottom_Movement_0
# 94 "data/maps/Beach/scripts.pory"
	waitmovement
# 95 "data/maps/Beach/scripts.pory"
	goto Beach_WaterGuard
	return


Beach_NeutralPalooka_A::
# 99 "data/maps/Beach/scripts.pory"
	lockall
# 100 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_2
Beach_NeutralPalooka_A_1:
# 104 "data/maps/Beach/scripts.pory"
	checktrainerflag TRAINER_FIRST_PALOOKA
	goto_if 1, Beach_NeutralPalooka_A_5
Beach_NeutralPalooka_A_4:
# 125 "data/maps/Beach/scripts.pory"
	releaseall
	end

Beach_NeutralPalooka_A_2:
# 102 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_0
	goto Beach_NeutralPalooka_A_1

Beach_NeutralPalooka_A_5:
# 106 "data/maps/Beach/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Beach_NeutralPalooka_A_7
# 122 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_2
	goto Beach_NeutralPalooka_A_4

Beach_NeutralPalooka_A_7:
# 107 "data/maps/Beach/scripts.pory"
	playse SE_PIN
# 108 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_ExclamationMark
# 109 "data/maps/Beach/scripts.pory"
	waitmovement
# 110 "data/maps/Beach/scripts.pory"
	delay 30
# 111 "data/maps/Beach/scripts.pory"
	faceplayer
# 112 "data/maps/Beach/scripts.pory"
	msgbox Beach_NeutralPalooka_A_Text_1
# 117 "data/maps/Beach/scripts.pory"
	applymovement LOCALID_WATER_NEUTRAL_PALOOKA_A, Common_Movement_FaceUp
# 118 "data/maps/Beach/scripts.pory"
	waitmovement
# 119 "data/maps/Beach/scripts.pory"
	setflag FLAG_TEMP_1
	goto Beach_NeutralPalooka_A_4


# 50 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Movement_0:
# 50 "data/maps/Beach/scripts.pory"
	walk_left
# 50 "data/maps/Beach/scripts.pory"
	walk_left
# 50 "data/maps/Beach/scripts.pory"
	walk_left
# 50 "data/maps/Beach/scripts.pory"
	walk_left
# 50 "data/maps/Beach/scripts.pory"
	face_up
	step_end

# 53 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Movement_1:
# 53 "data/maps/Beach/scripts.pory"
	walk_left
# 53 "data/maps/Beach/scripts.pory"
	walk_left
# 53 "data/maps/Beach/scripts.pory"
	walk_left
# 53 "data/maps/Beach/scripts.pory"
	walk_left
# 53 "data/maps/Beach/scripts.pory"
	walk_up
	step_end

# 56 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Movement_2:
# 56 "data/maps/Beach/scripts.pory"
	walk_left
# 56 "data/maps/Beach/scripts.pory"
	walk_left
# 56 "data/maps/Beach/scripts.pory"
	walk_left
# 56 "data/maps/Beach/scripts.pory"
	walk_left
# 56 "data/maps/Beach/scripts.pory"
	walk_up
# 56 "data/maps/Beach/scripts.pory"
	walk_up
	step_end

# 68 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Alerted_Movement_0:
# 68 "data/maps/Beach/scripts.pory"
	face_right
# 68 "data/maps/Beach/scripts.pory"
	emote_exclamation_mark
	step_end

# 77 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Trigger_Top_Movement_0:
# 77 "data/maps/Beach/scripts.pory"
	walk_right
# 77 "data/maps/Beach/scripts.pory"
	walk_right
# 77 "data/maps/Beach/scripts.pory"
	walk_right
	step_end

# 85 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Trigger_Middle_Movement_0:
# 85 "data/maps/Beach/scripts.pory"
	walk_right
# 85 "data/maps/Beach/scripts.pory"
	walk_right
# 85 "data/maps/Beach/scripts.pory"
	walk_down
# 85 "data/maps/Beach/scripts.pory"
	walk_right
	step_end

# 93 "data/maps/Beach/scripts.pory"
Beach_WaterGuard_Trigger_Bottom_Movement_0:
# 93 "data/maps/Beach/scripts.pory"
	walk_right
# 93 "data/maps/Beach/scripts.pory"
	walk_right
# 93 "data/maps/Beach/scripts.pory"
	walk_down
# 93 "data/maps/Beach/scripts.pory"
	walk_down
# 93 "data/maps/Beach/scripts.pory"
	walk_right
	step_end

Beach_Palooka_A_Text_0:
# 15 "data/maps/Beach/scripts.pory"
	.string "Oh no, it's you!$"

Beach_Palooka_A_Text_1:
# 15 "data/maps/Beach/scripts.pory"
	.string "Bleh...$"

Beach_Palooka_A_Defeated_Text_0:
# 21 "data/maps/Beach/scripts.pory"
	.string "Yikes! You're strong!$"

Beach_Palooka_B_Text_0:
# 27 "data/maps/Beach/scripts.pory"
	.string "If I beat you, surely I'll get promoted!$"

Beach_Palooka_B_Text_1:
# 27 "data/maps/Beach/scripts.pory"
	.string "Aw...but I could use the money...$"

Beach_Palooka_C_Text_0:
# 31 "data/maps/Beach/scripts.pory"
	.string "No, this ocean view is mine!$"

Beach_Palooka_C_Text_1:
# 31 "data/maps/Beach/scripts.pory"
	.string "I've never seen an ocean...$"

Beach_Palooka_D_Text_0:
# 35 "data/maps/Beach/scripts.pory"
	.string "Bleh!$"

Beach_WaterGuard_Text_0:
# 44 "data/maps/Beach/scripts.pory"
	.string "Jomo will do what I could not.$"

Beach_WaterGuard_Text_1:
# 45 "data/maps/Beach/scripts.pory"
	.string "You have bested me, alien. You shall not\n"
	.string "win forever.$"

Beach_NeutralPalooka_A_Text_0:
# 102 "data/maps/Beach/scripts.pory"
	.string "{FONT_PALOOKA}E... ROVA AR,WA...?$"

Beach_NeutralPalooka_A_Text_1:
# 112 "data/maps/Beach/scripts.pory"
	.string "Don't worry, I'm not a threat, alien. I'm\n"
	.string "a technician.\p"
	.string "You see the tracks on the ground?\p"
	.string "They're from the drones we sent before\n"
	.string "we got here in person.\p"
	.string "This one's path seems to have...gone\n"
	.string "into the wall.\p"
	.string "You haven't seen it anywhere, have you?$"

Beach_NeutralPalooka_A_Text_2:
# 122 "data/maps/Beach/scripts.pory"
	.string "Maybe there's something scarier than\n"
	.string "us here...$"
