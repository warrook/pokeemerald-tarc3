Land_MapScripts::
# 2 "data/maps/Land/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Land_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/Land/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Land_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Land_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Land/scripts.pory"
	goto_if_set FLAG_LAND_GUARDS_DEFEATED, Land_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Land_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/Land/scripts.pory"
	setobjectmovementtype LOCALID_LAND_AGITATOR, MOVEMENT_TYPE_FACE_DOWN
	return

Land_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/Land/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
# 9 "data/maps/Land/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1, Tamagotchi_KidEvo_Explanation
# 10 "data/maps/Land/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 2, Tamagotchi_YoungEvo_Explanation
	.2byte 0


Land_Palooka_A::
# 15 "data/maps/Land/scripts.pory"
	trainerbattle_single TRAINER_LAND_A, Land_Palooka_A_Text_0, Land_Palooka_A_Text_1, Beach_Palooka_A_Defeated
	return


Land_Palooka_A_Defeated::
# 19 "data/maps/Land/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 20 "data/maps/Land/scripts.pory"
	waitmovement
# 21 "data/maps/Land/scripts.pory"
	msgbox Land_Palooka_A_Defeated_Text_0
# 22 "data/maps/Land/scripts.pory"
	closemessage
# 23 "data/maps/Land/scripts.pory"
	call Tamagotchi_Palookaport_Out
	return


Land_Palooka_B::
# 27 "data/maps/Land/scripts.pory"
	trainerbattle_single TRAINER_LAND_B, Land_Palooka_B_Text_0, Land_Palooka_B_Text_1, Tamagotchi_Palookaport_Out
	return


Land_Palooka_C::
# 31 "data/maps/Land/scripts.pory"
	trainerbattle_single TRAINER_LAND_C, Land_Palooka_C_Text_0, Land_Palooka_C_Text_1, Tamagotchi_Palookaport_Out
	return


Land_Palooka_D::
# 35 "data/maps/Land/scripts.pory"
	trainerbattle_single TRAINER_LAND_D, Land_Palooka_D_Text_0, Land_Palooka_D_Text_1, Tamagotchi_Palookaport_Out
	return


Land_Palooka_E::
# 39 "data/maps/Land/scripts.pory"
	trainerbattle_single TRAINER_LAND_E, Land_Palooka_E_Text_0, Land_Palooka_E_Text_1, Tamagotchi_Palookaport_Out
	return


Land_LandGuards::
# 43 "data/maps/Land/scripts.pory"
	lockall
# 44 "data/maps/Land/scripts.pory"
	applymovement LOCALID_PLAYER, Land_LandGuards_Movement_0
# 45 "data/maps/Land/scripts.pory"
	waitmovement
# 46 "data/maps/Land/scripts.pory"
	applymovement LOCALID_LAND_GUARD_RIGHT, Land_LandGuards_Movement_1
# 47 "data/maps/Land/scripts.pory"
	applymovement LOCALID_LAND_GUARD_LEFT, Common_Movement_WalkInPlaceDown
# 48 "data/maps/Land/scripts.pory"
	waitmovement
# 49 "data/maps/Land/scripts.pory"
	call Tamagotchi_BossIntro
# 50 "data/maps/Land/scripts.pory"
	trainerbattle_two_trainers TRAINER_LAND_GUARD_LEFT, Land_LandGuards_Text_0, TRAINER_LAND_GUARD_RIGHT, Land_LandGuards_Text_1
# 51 "data/maps/Land/scripts.pory"
	applymovement LOCALID_LAND_GUARD_LEFT, Common_Movement_WalkInPlaceDown
# 52 "data/maps/Land/scripts.pory"
	waitmovement
# 53 "data/maps/Land/scripts.pory"
	msgbox Land_LandGuards_Text_2
# 54 "data/maps/Land/scripts.pory"
	waitmessage
# 55 "data/maps/Land/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_LAND_GUARD_LEFT
# 56 "data/maps/Land/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 57 "data/maps/Land/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_LAND_GUARD_RIGHT
# 58 "data/maps/Land/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 59 "data/maps/Land/scripts.pory"
	applymovement LOCALID_PLAYER, Land_LandGuards_Movement_2
# 60 "data/maps/Land/scripts.pory"
	waitmovement
# 61 "data/maps/Land/scripts.pory"
	setvar VAR_0x8006, LOCALID_LAND_AGITATOR
# 62 "data/maps/Land/scripts.pory"
	call Tamagotchi_AgitatorInteract
# 63 "data/maps/Land/scripts.pory"
	addvar VAR_BOSSES_DEFEATED, 1
# 64 "data/maps/Land/scripts.pory"
	setflag FLAG_LAND_GUARDS_DEFEATED
# 65 "data/maps/Land/scripts.pory"
	releaseall
	return


# 44 "data/maps/Land/scripts.pory"
Land_LandGuards_Movement_0:
# 44 "data/maps/Land/scripts.pory"
	walk_left
# 44 "data/maps/Land/scripts.pory"
	walk_left
# 44 "data/maps/Land/scripts.pory"
	walk_up
# 44 "data/maps/Land/scripts.pory"
	walk_up
# 44 "data/maps/Land/scripts.pory"
	walk_up
	step_end

# 46 "data/maps/Land/scripts.pory"
Land_LandGuards_Movement_1:
# 46 "data/maps/Land/scripts.pory"
	face_down
	step_end

# 59 "data/maps/Land/scripts.pory"
Land_LandGuards_Movement_2:
# 59 "data/maps/Land/scripts.pory"
	walk_up
	step_end

Land_Palooka_A_Text_0:
# 15 "data/maps/Land/scripts.pory"
	.string "Alien, you're not allowed here!$"

Land_Palooka_A_Text_1:
# 15 "data/maps/Land/scripts.pory"
	.string "You're scary!$"

Land_Palooka_A_Defeated_Text_0:
# 21 "data/maps/Land/scripts.pory"
	.string "I gotta get out of here!$"

Land_Palooka_B_Text_0:
# 27 "data/maps/Land/scripts.pory"
	.string "Boo!$"

Land_Palooka_B_Text_1:
# 27 "data/maps/Land/scripts.pory"
	.string "Jomo will get you!$"

Land_Palooka_C_Text_0:
# 31 "data/maps/Land/scripts.pory"
	.string "You're not getting through, alien.$"

Land_Palooka_C_Text_1:
# 31 "data/maps/Land/scripts.pory"
	.string "Fine, go through!$"

Land_Palooka_D_Text_0:
# 35 "data/maps/Land/scripts.pory"
	.string "This place is kind of spooky...\l"
	.string "I'll fight you to relax!$"

Land_Palooka_D_Text_1:
# 35 "data/maps/Land/scripts.pory"
	.string "Maybe too relaxed!$"

Land_Palooka_E_Text_0:
# 39 "data/maps/Land/scripts.pory"
	.string "Don't steal my spot!$"

Land_Palooka_E_Text_1:
# 39 "data/maps/Land/scripts.pory"
	.string "Don't get too comfortable, alien.$"

Land_LandGuards_Text_0:
# 50 "data/maps/Land/scripts.pory"
	.string "Tch.$"

Land_LandGuards_Text_1:
# 50 "data/maps/Land/scripts.pory"
	.string "Uh-oh...$"

Land_LandGuards_Text_2:
# 53 "data/maps/Land/scripts.pory"
	.string "Grunt, let's go.$"
