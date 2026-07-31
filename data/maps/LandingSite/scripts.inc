LandingSite_MapScripts::
# 2 "data/maps/LandingSite/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LandingSite/scripts.pory"
	setrespawn HEAL_LOCATION_LANDING_SITE
	end


SuitCallBegin::
# 10 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 11 "data/maps/LandingSite/scripts.pory"
	waitse
# 12 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
	return


SuitCallEnd::
# 18 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_HANG_UP
	return


Banzo_EventScript_Intro::
# 24 "data/maps/LandingSite/scripts.pory"
	lockall
# 25 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 26 "data/maps/LandingSite/scripts.pory"
	delay 60
# 27 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 28 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_0
# 30 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 31 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_OFF
# 32 "data/maps/LandingSite/scripts.pory"
	waitse
# 34 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 35 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_1
# 47 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 48 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_0
# 49 "data/maps/LandingSite/scripts.pory"
	delay 60
# 50 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_2
# 54 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 56 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8004, 1
# 57 "data/maps/LandingSite/scripts.pory"
	special EnterStudyMode
# 58 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 59 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Banzo_EventScript_AfterCatch::
# 64 "data/maps/LandingSite/scripts.pory"
	lockall
# 65 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 66 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_AfterCatch_Text_0
# 70 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 71 "data/maps/LandingSite/scripts.pory"
	call SuitCallEnd
# 72 "data/maps/LandingSite/scripts.pory"
	waitse
# 73 "data/maps/LandingSite/scripts.pory"
	msgbox Banzo_EventScript_AfterCatch_Text_1
# 74 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Capsule::
# 79 "data/maps/LandingSite/scripts.pory"
	lock
# 81 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 87 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 91 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 93 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 95 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 97 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_7
Capsule_1:
# 100 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 89 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 90 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 92 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
	goto Capsule_1

Capsule_5:
# 94 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_6:
# 96 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
	goto Capsule_1

Capsule_7:
	goto Capsule_1


# 48 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_0:
# 48 "data/maps/LandingSite/scripts.pory"
	emote_x
	step_end

Banzo_EventScript_Intro_Text_0:
# 28 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}?{PAUSE 15} {PLAYER}??{PAUSE 30}\n"
	.string "I just saw you land, can you hear me?!$"

Banzo_EventScript_Intro_Text_1:
# 35 "data/maps/LandingSite/scripts.pory"
	.string "Ahem.{PAUSE 30} Okay, good, you're alive. Excellent.\n"
	.string "And you know how to respond to comms.\p"
	.string "Odd how this planet is so like ours, huh?\p"
	.string "Your first task is to find an Exo-Pokémon\n"
	.string "to protect you.\p"
	.string "The ones nearby should be docile enough\n"
	.string "for you to catch by yourself. Just don't\l"
	.string "go very far, it's too dangerous and we\l"
	.string "didn't bring a spare astronaut.$"

Banzo_EventScript_Intro_Text_2:
# 50 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_SMALL}That's a joke.{PAUSE 30} But please be careful.{FONT_NORMAL}\n"
	.string "If Pokéballs don't work on aliens, uh.{PAUSE 30}.{PAUSE 30}.{PAUSE 15}\l"
	.string "Well,{PAUSE 30} they'll work. Good luck!$"

Banzo_EventScript_AfterCatch_Text_0:
# 66 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Phew. So they do work.\p"
	.string "I'm going to analyze the data. I'm here\n"
	.string "if you need to talk to me!\p"
	.string "Remember: you're there to figure out\n"
	.string "why the native life has started getting\l"
	.string "aggressive with each other...and what\l"
	.string "those odd devices we've observed are.\p"
	.string "Good luck, and be safe.$"

Banzo_EventScript_AfterCatch_Text_1:
# 73 "data/maps/LandingSite/scripts.pory"
	.string "Open your I.D. card in the start menu\n"
	.string "for a reminder of what to do, or call\l"
	.string "Banzo for a more elaborate explanation.$"

Capsule_Text_0:
# 90 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 92 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 96 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"
