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
	releaseall
	end


Banzo_EventScript_AfterCatch::
# 51 "data/maps/LandingSite/scripts.pory"
	lockall
# 52 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 53 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_AfterCatch_Text_0
# 57 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 58 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 59 "data/maps/LandingSite/scripts.pory"
	waitse
# 60 "data/maps/LandingSite/scripts.pory"
	msgbox Banzo_EventScript_AfterCatch_Text_1
# 61 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_SCALE_OPPONENTS
# 62 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Capsule::
# 67 "data/maps/LandingSite/scripts.pory"
	lock
# 69 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 75 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 76 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 79 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 81 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 83 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 85 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_7
Capsule_1:
# 88 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 77 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 78 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 80 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
	goto Capsule_1

Capsule_5:
# 82 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_6:
# 84 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
	goto Capsule_1

Capsule_7:
	goto Capsule_1


LandingSite_CatchIntro_PushDown::
# 93 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushDown_Text_0
# 94 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushDown_Movement_0
# 95 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 96 "data/maps/LandingSite/scripts.pory"
	release
	end


LandingSite_CatchIntro_PushUp::
# 101 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushDown_Text_0
# 102 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushUp_Movement_0
# 103 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 104 "data/maps/LandingSite/scripts.pory"
	release
	end


Tamagotchi_SuitCallBegin::
# 110 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 111 "data/maps/LandingSite/scripts.pory"
	waitse
# 112 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
	return


Tamagotchi_SuitCallEnd::
# 118 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_HANG_UP
	return


Tamagotchi_Palookaport_Out::
# 123 "data/maps/LandingSite/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 124 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 125 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8006, 65535
# 126 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 127 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 128 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 129 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 130 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 0
# 131 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 132 "data/maps/LandingSite/scripts.pory"
	delay 24
# 133 "data/maps/LandingSite/scripts.pory"
	removeobject VAR_LAST_TALKED
# 134 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_Palookaport_In::
# 138 "data/maps/LandingSite/scripts.pory"
	addobject VAR_LAST_TALKED
# 139 "data/maps/LandingSite/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_BEACH
# 140 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 141 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 142 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 143 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 144 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 1
# 145 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 146 "data/maps/LandingSite/scripts.pory"
	delay 24
# 147 "data/maps/LandingSite/scripts.pory"
	showobjectat VAR_LAST_TALKED, MAP_BEACH
# 148 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_BabyEvo_Explanation::
# 152 "data/maps/LandingSite/scripts.pory"
	goto_if_unset FLAG_EVOLVED_MON, Tamagotchi_BabyEvo_Explanation_2
# 156 "data/maps/LandingSite/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_LAST_EVO
# 157 "data/maps/LandingSite/scripts.pory"
	switch VAR_LAST_EVO
# 158 "data/maps/LandingSite/scripts.pory"
	case SPECIES_LAND_KID, Tamagotchi_BabyEvo_Explanation_6
# 160 "data/maps/LandingSite/scripts.pory"
	case SPECIES_WATER_KID, Tamagotchi_BabyEvo_Explanation_7
# 162 "data/maps/LandingSite/scripts.pory"
	case SPECIES_SKY_KID, Tamagotchi_BabyEvo_Explanation_8
# 165 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
	end

Tamagotchi_BabyEvo_Explanation_2:
	end

Tamagotchi_BabyEvo_Explanation_4:
# 168 "data/maps/LandingSite/scripts.pory"
	lock
# 169 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 170 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_BabyEvo_Explanation_Text_3
# 173 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 174 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 175 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 176 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
# 177 "data/maps/LandingSite/scripts.pory"
	release
	return

Tamagotchi_BabyEvo_Explanation_6:
# 159 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_0
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_7:
# 161 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_1
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_8:
# 163 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_2
	goto Tamagotchi_BabyEvo_Explanation_4


Tamagotchi_KidEvo_Explanation::
# 181 "data/maps/LandingSite/scripts.pory"
	lock
# 182 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 183 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_KidEvo_Explanation_Text_0
# 186 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 187 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 188 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 189 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_YoungEvo_Explanation::
# 193 "data/maps/LandingSite/scripts.pory"
	lock
# 194 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 195 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_YoungEvo_Explanation_Text_0
# 198 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 199 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 200 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 201 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_TryEarlyPalookas::
# 206 "data/maps/LandingSite/scripts.pory"
	checktrainerflag VAR_0x8004
	goto_if 1, Tamagotchi_TryEarlyPalookas_2
# 209 "data/maps/LandingSite/scripts.pory"
	switch VAR_PALOOKAS_DEFEATED
# 211 "data/maps/LandingSite/scripts.pory"
	case 1, Tamagotchi_TryEarlyPalookas_6
# 213 "data/maps/LandingSite/scripts.pory"
	case 2, Tamagotchi_TryEarlyPalookas_7
# 216 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single VAR_0x8004, Tamagotchi_TryEarlyPalookas_Text_0, Tamagotchi_TryEarlyPalookas_Text_1
Tamagotchi_TryEarlyPalookas_4:
# 218 "data/maps/LandingSite/scripts.pory"
	gotopostbattlescript
	return

Tamagotchi_TryEarlyPalookas_2:
	return

Tamagotchi_TryEarlyPalookas_6:
# 212 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_SECOND_PALOOKA, Tamagotchi_SecondPalooka_Intro, Tamagotchi_SecondPalooka_Defeat, Tamagotchi_SecondPalooka_Defeated
	goto Tamagotchi_TryEarlyPalookas_4

Tamagotchi_TryEarlyPalookas_7:
# 214 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_THIRD_PALOOKA, Tamagotchi_ThirdPalooka_Intro, Tamagotchi_ThirdPalooka_Defeat, Tamagotchi_ThirdPalooka_Defeated
	goto Tamagotchi_TryEarlyPalookas_4


Tamagotchi_FirstPalooka_Defeated::
# 233 "data/maps/LandingSite/scripts.pory"
	lock
# 234 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 235 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 236 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_0
# 238 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 239 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_1
# 240 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 241 "data/maps/LandingSite/scripts.pory"
	closemessage
# 242 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 243 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 244 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_SecondPalooka_Defeated::
# 256 "data/maps/LandingSite/scripts.pory"
	lock
# 257 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 258 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 259 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_SecondPalooka_Defeated_Text_0
# 261 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 262 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 263 "data/maps/LandingSite/scripts.pory"
	settrainerflag VAR_0x8004
# 264 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_ThirdPalooka_Defeated::
# 276 "data/maps/LandingSite/scripts.pory"
	lock
# 277 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 278 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 279 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_ThirdPalooka_Defeated_Text_0
# 281 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 282 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 283 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_ThirdPalooka_Defeated_Text_1
# 288 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 289 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 290 "data/maps/LandingSite/scripts.pory"
	waitse
# 291 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 292 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_ThirdPalooka_Defeated_Text_2
# 293 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 294 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 295 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 296 "data/maps/LandingSite/scripts.pory"
	settrainerflag VAR_0x8004
# 297 "data/maps/LandingSite/scripts.pory"
	release
	return


# 34 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_0:
# 34 "data/maps/LandingSite/scripts.pory"
	emote_x
	step_end

# 94 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushDown_Movement_0:
# 94 "data/maps/LandingSite/scripts.pory"
	walk_down
	step_end

# 102 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushUp_Movement_0:
# 102 "data/maps/LandingSite/scripts.pory"
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
# 53 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Phew. So they do work.\p"
	.string "I'm going to analyze the data. I'm here\n"
	.string "if you need to talk to me!\p"
	.string "Remember: you're there to figure out\n"
	.string "why the native life has started getting\l"
	.string "aggressive with each other...and what\l"
	.string "those odd devices we've observed are.\p"
	.string "Good luck, and be safe.$"

Banzo_EventScript_AfterCatch_Text_1:
# 60 "data/maps/LandingSite/scripts.pory"
	.string "Open your I.D. card in the start menu\n"
	.string "for a reminder of what to do, or call\l"
	.string "Banzo for a more elaborate explanation.$"

Capsule_Text_0:
# 78 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 80 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 84 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"

LandingSite_CatchIntro_PushDown_Text_0:
# 93 "data/maps/LandingSite/scripts.pory"
	.string "It's too dangerous to go on alone.$"

Tamagotchi_BabyEvo_Explanation_Text_0:
# 159 "data/maps/LandingSite/scripts.pory"
	.string "Land Hills$"

Tamagotchi_BabyEvo_Explanation_Text_1:
# 161 "data/maps/LandingSite/scripts.pory"
	.string "Water Beach$"

Tamagotchi_BabyEvo_Explanation_Text_2:
# 163 "data/maps/LandingSite/scripts.pory"
	.string "Sky Mountain$"

Tamagotchi_BabyEvo_Explanation_Text_3:
# 170 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The Exo-Pokémon\n"
	.string "of this planet evolve like ours back\l"
	.string "home, but somewhat differently.\p"
	.string "A “baby” evolves depending on the area\n"
	.string "of the island it spends time in.\p"
	.string "That little {STR_VAR_1} evolved in\n"
	.string "{STR_VAR_2}...makes sense, right?$"

Tamagotchi_KidEvo_Explanation_Text_0:
# 183 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “kids” of\n"
	.string "this world evolve based on their diet.\p"
	.string "They'll evolve into different “young”\n"
	.string "depending on the food you give them.\p"
	.string "The synthesizer should be able to\n"
	.string "fabricate suitable nourishment.$"

Tamagotchi_YoungEvo_Explanation_Text_0:
# 195 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “young” of\n"
	.string "this world evolve from scents.\p"
	.string "Like diet, scents take some time to\n"
	.string "trigger their evolution.\p"
	.string "The correct pheromones can be\n"
	.string "synthesized with enough charge.$"

Tamagotchi_TryEarlyPalookas_Text_0:
# 216 "data/maps/LandingSite/scripts.pory"
	.string "{STR_VAR_1}$"

Tamagotchi_TryEarlyPalookas_Text_1:
# 216 "data/maps/LandingSite/scripts.pory"
	.string "{STR_VAR_2}$"

Tamagotchi_FirstPalooka_Defeated_Text_0:
# 236 "data/maps/LandingSite/scripts.pory"
	.string "Translator calibrated.\p"
	.string "Identify yourself!$"

Tamagotchi_FirstPalooka_Defeated_Text_1:
# 239 "data/maps/LandingSite/scripts.pory"
	.string "You're a kid? Humiliating!$"

Tamagotchi_SecondPalooka_Defeated_Text_0:
# 259 "data/maps/LandingSite/scripts.pory"
	.string "Yikes! You're a good fighter!\p"
	.string "I gotta tell Jomo about this!$"

Tamagotchi_ThirdPalooka_Defeated_Text_0:
# 279 "data/maps/LandingSite/scripts.pory"
	.string "These monsters are ours, alien. We've\n"
	.string "worked hard to make them battle-ready.\p"
	.string "You'd better go home before Jomo\n"
	.string "decides to take care of you himself.$"

Tamagotchi_ThirdPalooka_Defeated_Text_1:
# 283 "data/maps/LandingSite/scripts.pory"
	.string "???: Ahahaha! Alien! You hear now the\n"
	.string "voice of Jomo, leader of this operation!\p"
	.string "Before we arrived, these monsters were\n"
	.string "miserably joyful. You're here to stop us\l"
	.string "from making lucrative fighters of them.\p"
	.string "I respect this, though you will fail.\n"
	.string "No one can defeat a Palooka whose eyes\l"
	.string "are set on victory.\p"
	.string "We'll be in touch, alien.$"

Tamagotchi_ThirdPalooka_Defeated_Text_2:
# 292 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Jomo seems scary... I'll try\n"
	.string "to pinpoint his location from up here.\l"
	.string "Keep doing what you're doing!$"

Tamagotchi_FirstPalooka_Intro::
# 221 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KA! KE TO,WA?$"

Tamagotchi_FirstPalooka_Defeat::
# 227 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}JO LADA KE APGE,WA?$"

Tamagotchi_SecondPalooka_Intro::
# 247 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KE TO,WA? {FONT_NORMAL}Oh, you're the alien!$"

Tamagotchi_SecondPalooka_Defeat::
# 251 "data/maps/LandingSite/scripts.pory"
	.string "No way...$"

Tamagotchi_ThirdPalooka_Intro::
# 267 "data/maps/LandingSite/scripts.pory"
	.string "My orders are to stop you from\n"
	.string "interfering!$"

Tamagotchi_ThirdPalooka_Defeat::
# 271 "data/maps/LandingSite/scripts.pory"
	.string "Jomo will be hearing about this...!$"
