LandingSite_MapScripts::
# 2 "data/maps/LandingSite/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LandingSite/scripts.pory"
	setrespawn HEAL_LOCATION_LANDING_SITE
	end


Banzo_EventScript_Intro::
# 10 "data/maps/LandingSite/scripts.pory"
	lockall
# 11 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 12 "data/maps/LandingSite/scripts.pory"
	delay 60
# 13 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 14 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_0
# 16 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 17 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_OFF
# 18 "data/maps/LandingSite/scripts.pory"
	waitse
# 20 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 21 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_1
# 33 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 34 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_0
# 35 "data/maps/LandingSite/scripts.pory"
	delay 60
# 36 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_2
# 40 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 42 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8004, 1
# 43 "data/maps/LandingSite/scripts.pory"
	special EnterStudyMode
# 44 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 45 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 46 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_HIDE_FIRST_PALOOKA
# 47 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_HIDE_SECOND_PALOOKA
# 48 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Banzo_EventScript_AfterCatch::
# 53 "data/maps/LandingSite/scripts.pory"
	lockall
# 54 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 55 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_AfterCatch_Text_0
# 59 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 60 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 61 "data/maps/LandingSite/scripts.pory"
	waitse
# 62 "data/maps/LandingSite/scripts.pory"
	msgbox Banzo_EventScript_AfterCatch_Text_1
# 63 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_SCALE_OPPONENTS
# 64 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_FIRST_PALOOKA
# 65 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_SECOND_PALOOKA
# 66 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Capsule::
# 71 "data/maps/LandingSite/scripts.pory"
	lock
# 73 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 79 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 80 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 83 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 85 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 87 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 89 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_7
Capsule_1:
# 92 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 81 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 82 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 84 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
	goto Capsule_1

Capsule_5:
# 86 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_6:
# 88 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
	goto Capsule_1

Capsule_7:
	goto Capsule_1


LandingSite_CatchIntro_PushLeft::
# 97 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 98 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushLeft_Movement_0
# 99 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 100 "data/maps/LandingSite/scripts.pory"
	release
	end


LandingSite_CatchIntro_PushUp::
# 105 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 106 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushUp_Movement_0
# 107 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 108 "data/maps/LandingSite/scripts.pory"
	release
	end


Tamagotchi_SuitCallBegin::
# 114 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 115 "data/maps/LandingSite/scripts.pory"
	waitse
# 116 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
	return


Tamagotchi_SuitCallEnd::
# 122 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_HANG_UP
	return


Tamagotchi_Palookaport_Out::
# 127 "data/maps/LandingSite/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 128 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 129 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8006, 65535
# 130 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 131 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 132 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 133 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 134 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 0
# 135 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 136 "data/maps/LandingSite/scripts.pory"
	delay 24
# 137 "data/maps/LandingSite/scripts.pory"
	removeobject VAR_LAST_TALKED
# 138 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_Palookaport_In::
# 142 "data/maps/LandingSite/scripts.pory"
	addobject VAR_LAST_TALKED
# 143 "data/maps/LandingSite/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_BEACH
# 144 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 145 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 146 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 147 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 148 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 1
# 149 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 150 "data/maps/LandingSite/scripts.pory"
	delay 24
# 151 "data/maps/LandingSite/scripts.pory"
	showobjectat VAR_LAST_TALKED, MAP_BEACH
# 152 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_BabyEvo_Explanation::
# 156 "data/maps/LandingSite/scripts.pory"
	goto_if_unset FLAG_EVOLVED_MON, Tamagotchi_BabyEvo_Explanation_2
# 160 "data/maps/LandingSite/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_LAST_EVO
# 161 "data/maps/LandingSite/scripts.pory"
	switch VAR_LAST_EVO
# 162 "data/maps/LandingSite/scripts.pory"
	case SPECIES_LAND_KID, Tamagotchi_BabyEvo_Explanation_6
# 164 "data/maps/LandingSite/scripts.pory"
	case SPECIES_WATER_KID, Tamagotchi_BabyEvo_Explanation_7
# 166 "data/maps/LandingSite/scripts.pory"
	case SPECIES_SKY_KID, Tamagotchi_BabyEvo_Explanation_8
# 169 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
	end

Tamagotchi_BabyEvo_Explanation_2:
	end

Tamagotchi_BabyEvo_Explanation_4:
# 172 "data/maps/LandingSite/scripts.pory"
	lock
# 173 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 174 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_BabyEvo_Explanation_Text_3
# 177 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 178 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 179 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 180 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
# 181 "data/maps/LandingSite/scripts.pory"
	release
	return

Tamagotchi_BabyEvo_Explanation_6:
# 163 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_0
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_7:
# 165 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_1
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_8:
# 167 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_2
	goto Tamagotchi_BabyEvo_Explanation_4


Tamagotchi_KidEvo_Explanation::
# 185 "data/maps/LandingSite/scripts.pory"
	lock
# 186 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 187 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_KidEvo_Explanation_Text_0
# 190 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 191 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 192 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 193 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_YoungEvo_Explanation::
# 197 "data/maps/LandingSite/scripts.pory"
	lock
# 198 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 199 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_YoungEvo_Explanation_Text_0
# 202 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 203 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 204 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 205 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_FirstPalooka::
# 209 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
	return


Tamagotchi_FirstPalooka_Defeated::
# 224 "data/maps/LandingSite/scripts.pory"
	lock
# 225 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 226 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 227 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_0
# 229 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 230 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_1
# 231 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 232 "data/maps/LandingSite/scripts.pory"
	closemessage
# 233 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 234 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 235 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_SecondPalooka::
# 239 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_SECOND_PALOOKA, Tamagotchi_SecondPalooka_Intro, Tamagotchi_SecondPalooka_Defeat, Tamagotchi_SecondPalooka_Defeated
	return


Tamagotchi_SecondPalooka_Defeated::
# 252 "data/maps/LandingSite/scripts.pory"
	lock
# 253 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 254 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 255 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_SecondPalooka_Defeated_Text_0
# 257 "data/maps/LandingSite/scripts.pory"
	closemessage
# 258 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 259 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 260 "data/maps/LandingSite/scripts.pory"
	delay 30
# 261 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 262 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_1
# 267 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 268 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 269 "data/maps/LandingSite/scripts.pory"
	waitse
# 270 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 271 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_2
# 272 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 273 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 274 "data/maps/LandingSite/scripts.pory"
	release
	return


# 34 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_0:
# 34 "data/maps/LandingSite/scripts.pory"
	emote_x
	step_end

# 98 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushLeft_Movement_0:
# 98 "data/maps/LandingSite/scripts.pory"
	walk_left
	step_end

# 106 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushUp_Movement_0:
# 106 "data/maps/LandingSite/scripts.pory"
	walk_up
	step_end

Banzo_EventScript_Intro_Text_0:
# 14 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}?{PAUSE 15} {PLAYER}??{PAUSE 30}\n"
	.string "I just saw you land, can you hear me?!$"

Banzo_EventScript_Intro_Text_1:
# 21 "data/maps/LandingSite/scripts.pory"
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
# 36 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_SMALL}That's a joke.{PAUSE 30} But please be careful.{FONT_NORMAL}\n"
	.string "If Pokéballs don't work on aliens, uh.{PAUSE 30}.{PAUSE 30}.{PAUSE 15}\l"
	.string "Well,{PAUSE 30} they'll work. Good luck!$"

Banzo_EventScript_AfterCatch_Text_0:
# 55 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Phew. So they do work.\p"
	.string "I'm going to analyze the data. I'm here\n"
	.string "if you need to talk to me!\p"
	.string "Remember: you're there to figure out\n"
	.string "why the native life has started getting\l"
	.string "aggressive with each other...and what\l"
	.string "those odd devices we've observed are.\p"
	.string "Good luck, and be safe.$"

Banzo_EventScript_AfterCatch_Text_1:
# 62 "data/maps/LandingSite/scripts.pory"
	.string "Open your I.D. card in the start menu\n"
	.string "for a reminder of what to do, or call\l"
	.string "Banzo for a more elaborate explanation.$"

Capsule_Text_0:
# 82 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 84 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 88 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"

LandingSite_CatchIntro_PushLeft_Text_0:
# 97 "data/maps/LandingSite/scripts.pory"
	.string "It's too dangerous to go on alone.$"

Tamagotchi_BabyEvo_Explanation_Text_0:
# 163 "data/maps/LandingSite/scripts.pory"
	.string "Land Hills$"

Tamagotchi_BabyEvo_Explanation_Text_1:
# 165 "data/maps/LandingSite/scripts.pory"
	.string "Water Beach$"

Tamagotchi_BabyEvo_Explanation_Text_2:
# 167 "data/maps/LandingSite/scripts.pory"
	.string "Sky Mountain$"

Tamagotchi_BabyEvo_Explanation_Text_3:
# 174 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The Exo-Pokémon\n"
	.string "of this planet evolve like ours back\l"
	.string "home, but somewhat differently.\p"
	.string "A “baby” evolves depending on the area\n"
	.string "of the island it spends time in.\p"
	.string "That little {STR_VAR_1} evolved in\n"
	.string "{STR_VAR_2}...makes sense, right?$"

Tamagotchi_KidEvo_Explanation_Text_0:
# 187 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “kids” of\n"
	.string "this world evolve based on their diet.\p"
	.string "They'll evolve into different “young”\n"
	.string "depending on the food you give them.\p"
	.string "The synthesizer should be able to\n"
	.string "fabricate suitable nourishment.$"

Tamagotchi_YoungEvo_Explanation_Text_0:
# 199 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “young” of\n"
	.string "this world evolve from scents.\p"
	.string "Like diet, scents take some time to\n"
	.string "trigger their evolution.\p"
	.string "The correct pheromones can be\n"
	.string "synthesized with enough charge.$"

Tamagotchi_FirstPalooka_Defeated_Text_0:
# 227 "data/maps/LandingSite/scripts.pory"
	.string "Translator calibrated.\p"
	.string "Identify yourself!$"

Tamagotchi_FirstPalooka_Defeated_Text_1:
# 230 "data/maps/LandingSite/scripts.pory"
	.string "I gotta tell Jomo about this!$"

Tamagotchi_SecondPalooka_Defeated_Text_0:
# 255 "data/maps/LandingSite/scripts.pory"
	.string "These monsters are ours, alien. We've\n"
	.string "worked hard to make them battle-ready.\p"
	.string "You'd better go home before Jomo\n"
	.string "decides to take care of you himself.$"

Tamagotchi_SecondPalooka_Defeated_Text_1:
# 262 "data/maps/LandingSite/scripts.pory"
	.string "???: Ahahaha! Alien! You hear now the\n"
	.string "voice of Jomo, leader of this operation!\p"
	.string "Before we arrived, these monsters were\n"
	.string "miserably joyful. You're here to stop us\l"
	.string "from making lucrative fighters of them.\p"
	.string "I respect this, though you will fail.\n"
	.string "No one can defeat a Palooka whose eyes\l"
	.string "are set on victory.\p"
	.string "We'll be in touch, alien.$"

Tamagotchi_SecondPalooka_Defeated_Text_2:
# 271 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Jomo seems scary... I'll try\n"
	.string "to pinpoint his location from up here.\l"
	.string "Keep doing what you're doing!$"

Tamagotchi_FirstPalooka_Intro::
# 212 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KA! KE TO,WA?$"

Tamagotchi_FirstPalooka_Defeat::
# 218 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}JO LADA KE APGE,WA?$"

Tamagotchi_SecondPalooka_Intro::
# 242 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KE TO,WA? {FONT_NORMAL}Oh, you're the alien!\p"
	.string "My orders are to stop you from\ninterfering!$"

Tamagotchi_SecondPalooka_Defeat::
# 247 "data/maps/LandingSite/scripts.pory"
	.string "Jomo will be hearing about this...!$"
