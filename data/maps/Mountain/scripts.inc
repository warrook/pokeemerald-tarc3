Mountain_MapScripts::
# 2 "data/maps/Mountain/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Mountain_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/Mountain/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Mountain_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Mountain/scripts.pory"
	goto_if_set FLAG_SKY_GUARD_DEFEATED, Mountain_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Mountain_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/Mountain/scripts.pory"
	setobjectmovementtype LOCALID_SKY_AGITATOR, MOVEMENT_TYPE_FACE_DOWN
	return

Mountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/Mountain/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
# 9 "data/maps/Mountain/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1, Tamagotchi_KidEvo_Explanation
# 10 "data/maps/Mountain/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 2, Tamagotchi_YoungEvo_Explanation
	.2byte 0


Mountain_Palooka_A::
# 15 "data/maps/Mountain/scripts.pory"
	trainerbattle_single TRAINER_MOUNTAIN_A, Mountain_Palooka_A_Text_0, Mountain_Palooka_A_Text_1, Beach_Palooka_A_Defeated
	return


Mountain_Palooka_A_Defeated::
# 19 "data/maps/Mountain/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 20 "data/maps/Mountain/scripts.pory"
	waitmovement
# 21 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_Palooka_A_Defeated_Text_0
# 22 "data/maps/Mountain/scripts.pory"
	closemessage
# 23 "data/maps/Mountain/scripts.pory"
	call Tamagotchi_Palookaport_Out
	return


Mountain_Palooka_B::
# 27 "data/maps/Mountain/scripts.pory"
	trainerbattle_single TRAINER_MOUNTAIN_B, Mountain_Palooka_B_Text_0, Mountain_Palooka_B_Text_1, Tamagotchi_Palookaport_Out
	return


Mountain_Palooka_C::
# 31 "data/maps/Mountain/scripts.pory"
	trainerbattle_single TRAINER_MOUNTAIN_C, Mountain_Palooka_C_Text_0, Mountain_Palooka_C_Text_1, Tamagotchi_Palookaport_Out
	return


Mountain_Palooka_D::
# 35 "data/maps/Mountain/scripts.pory"
	trainerbattle_single TRAINER_MOUNTAIN_D, Mountain_Palooka_D_Text_0, Mountain_Palooka_D_Text_1, Tamagotchi_Palookaport_Out
	return


Mountain_Palooka_E::
# 39 "data/maps/Mountain/scripts.pory"
	trainerbattle_single TRAINER_MOUNTAIN_E, Mountain_Palooka_E_Text_0, Mountain_Palooka_E_Text_1, Tamagotchi_Palookaport_Out
	return


Mountain_SkyGuard::
# 43 "data/maps/Mountain/scripts.pory"
	lockall
# 44 "data/maps/Mountain/scripts.pory"
	applymovement LOCALID_SKY_GUARD, Mountain_SkyGuard_Movement_0
# 45 "data/maps/Mountain/scripts.pory"
	call Tamagotchi_BossIntro
# 46 "data/maps/Mountain/scripts.pory"
	trainerbattle_no_intro TRAINER_SKY_GUARD, Mountain_SkyGuard_Text_0
# 47 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_SkyGuard_Text_1
# 49 "data/maps/Mountain/scripts.pory"
	waitmessage
# 50 "data/maps/Mountain/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SKY_GUARD
# 51 "data/maps/Mountain/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 52 "data/maps/Mountain/scripts.pory"
	applymovement LOCALID_PLAYER, Mountain_SkyGuard_Movement_1
# 53 "data/maps/Mountain/scripts.pory"
	waitmovement
# 54 "data/maps/Mountain/scripts.pory"
	setvar VAR_0x8006, LOCALID_SKY_AGITATOR
# 55 "data/maps/Mountain/scripts.pory"
	call Tamagotchi_AgitatorInteract
# 56 "data/maps/Mountain/scripts.pory"
	addvar VAR_BOSSES_DEFEATED, 1
# 57 "data/maps/Mountain/scripts.pory"
	setflag FLAG_SKY_GUARD_DEFEATED
# 58 "data/maps/Mountain/scripts.pory"
	releaseall
	return


Mountain_Kuriten::
# 62 "data/maps/Mountain/scripts.pory"
	goto_if_set FLAG_CAUGHT_KURITEN, Mountain_Kuriten_2
# 68 "data/maps/Mountain/scripts.pory"
	goto_if_set FLAG_JOMO_DEFEATED, Mountain_Kuriten_4
# 91 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_Kuriten_Text_3
# 92 "data/maps/Mountain/scripts.pory"
	closemessage
# 93 "data/maps/Mountain/scripts.pory"
	release
	return

Mountain_Kuriten_2:
# 63 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_Kuriten_Text_0
# 64 "data/maps/Mountain/scripts.pory"
	closemessage
# 65 "data/maps/Mountain/scripts.pory"
	release
	end

Mountain_Kuriten_4:
# 69 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_Kuriten_Text_1
# 70 "data/maps/Mountain/scripts.pory"
	playse SE_PIN
# 71 "data/maps/Mountain/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 72 "data/maps/Mountain/scripts.pory"
	delay 40
# 73 "data/maps/Mountain/scripts.pory"
	seteventmon SPECIES_KURITEN, 30
# 74 "data/maps/Mountain/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 75 "data/maps/Mountain/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 76 "data/maps/Mountain/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/Mountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 0 "data/maps/Mountain/scripts.pory"
	switch VAR_RESULT
# 78 "data/maps/Mountain/scripts.pory"
	case B_OUTCOME_WON, Mountain_Kuriten_9
# 79 "data/maps/Mountain/scripts.pory"
	case B_OUTCOME_RAN, Mountain_Kuriten_9
# 80 "data/maps/Mountain/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Mountain_Kuriten_9
# 86 "data/maps/Mountain/scripts.pory"
	setflag FLAG_CAUGHT_KURITEN
# 87 "data/maps/Mountain/scripts.pory"
	release
	end

Mountain_Kuriten_9:
# 81 "data/maps/Mountain/scripts.pory"
	msgbox Mountain_Kuriten_Text_2
# 82 "data/maps/Mountain/scripts.pory"
	closemessage
# 83 "data/maps/Mountain/scripts.pory"
	release
	end


# 44 "data/maps/Mountain/scripts.pory"
Mountain_SkyGuard_Movement_0:
# 44 "data/maps/Mountain/scripts.pory"
	face_down
	step_end

# 52 "data/maps/Mountain/scripts.pory"
Mountain_SkyGuard_Movement_1:
# 52 "data/maps/Mountain/scripts.pory"
	walk_up
	step_end

Mountain_Palooka_A_Text_0:
# 15 "data/maps/Mountain/scripts.pory"
	.string "Alien, go back the way you came!$"

Mountain_Palooka_A_Text_1:
# 15 "data/maps/Mountain/scripts.pory"
	.string "Curses...$"

Mountain_Palooka_A_Defeated_Text_0:
# 21 "data/maps/Mountain/scripts.pory"
	.string "Victory is yours. I guess.$"

Mountain_Palooka_B_Text_0:
# 27 "data/maps/Mountain/scripts.pory"
	.string "My disguise isn't good enough for you!$"

Mountain_Palooka_B_Text_1:
# 27 "data/maps/Mountain/scripts.pory"
	.string "Jomo will get you.$"

Mountain_Palooka_C_Text_0:
# 31 "data/maps/Mountain/scripts.pory"
	.string "I am ordered to fight you.$"

Mountain_Palooka_C_Text_1:
# 31 "data/maps/Mountain/scripts.pory"
	.string "I just wanted to look at the island.$"

Mountain_Palooka_D_Text_0:
# 35 "data/maps/Mountain/scripts.pory"
	.string "Get out of here!$"

Mountain_Palooka_D_Text_1:
# 35 "data/maps/Mountain/scripts.pory"
	.string "I'll get out of here!$"

Mountain_Palooka_E_Text_0:
# 39 "data/maps/Mountain/scripts.pory"
	.string "Ack, go away!$"

Mountain_Palooka_E_Text_1:
# 39 "data/maps/Mountain/scripts.pory"
	.string "I was just napping...$"

Mountain_SkyGuard_Text_0:
# 46 "data/maps/Mountain/scripts.pory"
	.string "...$"

Mountain_SkyGuard_Text_1:
# 47 "data/maps/Mountain/scripts.pory"
	.string "Such a beautiful place...isn't it?\p"
	.string "Good luck, alien.$"

Mountain_Kuriten_Text_0:
# 63 "data/maps/Mountain/scripts.pory"
	.string "The strange power is gone.$"

Mountain_Kuriten_Text_1:
# 69 "data/maps/Mountain/scripts.pory"
	.string "A strange power emanates from this\n"
	.string "tree...$"

Mountain_Kuriten_Text_2:
# 81 "data/maps/Mountain/scripts.pory"
	.string "It will let you try to catch it again.$"

Mountain_Kuriten_Text_3:
# 91 "data/maps/Mountain/scripts.pory"
	.string "An unusual tree.$"
