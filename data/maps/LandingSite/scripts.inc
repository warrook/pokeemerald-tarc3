LandingSite_MapScripts::
# 2 "data/maps/LandingSite/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD
# 6 "data/maps/LandingSite/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LandingSite_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LandingSite_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LandingSite/scripts.pory"
	setrespawn HEAL_LOCATION_LANDING_SITE
	end

LandingSite_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/LandingSite/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 0, Tamagotchi_BabyEvo_Explanation
# 8 "data/maps/LandingSite/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1, Tamagotchi_KidEvo_Explanation
# 9 "data/maps/LandingSite/scripts.pory"
	map_script_2 VAR_TAMAGOTCHI_STAGE_EXPLAINED, 2, Tamagotchi_YoungEvo_Explanation
	.2byte 0


Banzo_EventScript_Intro::
# 15 "data/maps/LandingSite/scripts.pory"
	lockall
# 16 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_0
# 17 "data/maps/LandingSite/scripts.pory"
	delay 50
# 18 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_1
# 19 "data/maps/LandingSite/scripts.pory"
	delay 50
# 20 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_2
# 21 "data/maps/LandingSite/scripts.pory"
	delay 50
# 22 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 23 "data/maps/LandingSite/scripts.pory"
	delay 60
# 24 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_2
# 25 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 26 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 27 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_0
# 29 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 30 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_OFF
# 31 "data/maps/LandingSite/scripts.pory"
	waitse
# 33 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 34 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_1
# 46 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 47 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_3
# 48 "data/maps/LandingSite/scripts.pory"
	delay 60
# 49 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_2
# 53 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 55 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8004, 1
# 56 "data/maps/LandingSite/scripts.pory"
	special EnterStudyMode
# 57 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 58 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 61 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Banzo_EventScript_AfterCatch::
# 66 "data/maps/LandingSite/scripts.pory"
	lockall
# 67 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 68 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_AfterCatch_Text_0
# 73 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 74 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 75 "data/maps/LandingSite/scripts.pory"
	waitse
# 76 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_SCALE_OPPONENTS
# 77 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_EXP_SHARE
# 78 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 81 "data/maps/LandingSite/scripts.pory"
	additem ITEM_POKE_BALL, 20
# 82 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Capsule::
# 87 "data/maps/LandingSite/scripts.pory"
	lock
# 90 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 97 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 98 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 101 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 116 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 122 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 124 "data/maps/LandingSite/scripts.pory"
	case 4, Capsule_7
# 126 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_8
Capsule_1:
# 130 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 99 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 100 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 102 "data/maps/LandingSite/scripts.pory"
	playse SE_PC_ON
# 103 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
# 104 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
# 106 "data/maps/LandingSite/scripts.pory"
	switch VAR_TAMAGOTCHI_STAGE_EXPLAINED
# 107 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_11
# 109 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_12
# 112 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage1
Capsule_9:
# 114 "data/maps/LandingSite/scripts.pory"
	playse SE_PC_OFF
# 115 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_3
	goto Capsule_1

Capsule_5:
# 117 "data/maps/LandingSite/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 118 "data/maps/LandingSite/scripts.pory"
	additem ITEM_RARE_CANDY, 10
# 119 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_4
# 120 "data/maps/LandingSite/scripts.pory"
	closemessage
# 121 "data/maps/LandingSite/scripts.pory"
	goto Capsule
	goto Capsule_1

Capsule_6:
# 123 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_7:
# 125 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_5
	goto Capsule_1

Capsule_8:
	goto Capsule_1

Capsule_11:
# 108 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage2
	goto Capsule_9

Capsule_12:
# 110 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage3
	goto Capsule_9


	.align 2
# 134 "data/maps/LandingSite/scripts.pory"
SynthesizerStage1:
# 135 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 136 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 137 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 138 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 139 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 140 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE

	.align 2
# 143 "data/maps/LandingSite/scripts.pory"
SynthesizerStage2:
# 144 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 145 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 146 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 147 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 148 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 149 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 150 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 151 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 152 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 153 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EVERSTONE
# 154 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SAVORY_FOOD
# 155 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_LEAFY_FOOD
# 156 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GOOEY_FOOD
	.2byte ITEM_NONE

	.align 2
# 159 "data/maps/LandingSite/scripts.pory"
SynthesizerStage3:
# 160 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 161 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 162 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 163 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 164 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 165 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 166 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 167 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 168 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 169 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 170 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 171 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 172 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 173 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 174 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EVERSTONE
# 175 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 176 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 177 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SAVORY_FOOD
# 178 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_LEAFY_FOOD
# 179 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GOOEY_FOOD
# 180 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_JOY_SCENT
# 181 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EXCITE_SCENT
# 182 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_VIVID_SCENT
# 183 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_COMPLEX_SCENT
	.2byte ITEM_NONE

LandingSite_CatchIntro_PushLeft::
# 187 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 188 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushLeft_Movement_0
# 189 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 190 "data/maps/LandingSite/scripts.pory"
	release
	end


LandingSite_CatchIntro_PushUp::
# 195 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 196 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushUp_Movement_0
# 197 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 198 "data/maps/LandingSite/scripts.pory"
	release
	end


LandingSite_Jomo::
# 203 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_JOMO, LandingSite_Jomo_Text_0, LandingSite_Jomo_Text_1, LandingSite_Jomo_Defeated
	return


LandingSite_Jomo_Defeated::
# 210 "data/maps/LandingSite/scripts.pory"
	lock
# 211 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 212 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 213 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_Jomo_Defeated_Text_0
# 215 "data/maps/LandingSite/scripts.pory"
	fadescreen FADE_TO_BLACK
# 216 "data/maps/LandingSite/scripts.pory"
	playse SE_FLEE
# 217 "data/maps/LandingSite/scripts.pory"
	removeobject LOCALID_JOMO
# 218 "data/maps/LandingSite/scripts.pory"
	waitse
# 219 "data/maps/LandingSite/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 220 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_Jomo_Defeated_Text_1
# 221 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 222 "data/maps/LandingSite/scripts.pory"
	suitcall LandingSite_Jomo_Defeated_Text_2
# 225 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 226 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 227 "data/maps/LandingSite/scripts.pory"
	fadescreen FADE_TO_BLACK
# 228 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_Jomo_Defeated_Text_3
# 229 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 230 "data/maps/LandingSite/scripts.pory"
	delay 60
# 231 "data/maps/LandingSite/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 232 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_Jomo_Defeated_Text_4
	return


Tamagotchi_SuitCallBegin::
# 237 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 238 "data/maps/LandingSite/scripts.pory"
	waitse
# 239 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
	return


Tamagotchi_SuitCallEnd::
# 245 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_HANG_UP
	return


Tamagotchi_Palookaport_Out::
# 250 "data/maps/LandingSite/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 251 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 252 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8006, 65535
# 253 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 254 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 255 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 256 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 257 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 0
# 258 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 259 "data/maps/LandingSite/scripts.pory"
	delay 24
# 260 "data/maps/LandingSite/scripts.pory"
	removeobject VAR_LAST_TALKED
# 261 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_Palookaport_In::
# 266 "data/maps/LandingSite/scripts.pory"
	addobject VAR_LAST_TALKED
# 267 "data/maps/LandingSite/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_BEACH
# 268 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 269 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 270 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 271 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 272 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 1
# 273 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 274 "data/maps/LandingSite/scripts.pory"
	delay 24
# 275 "data/maps/LandingSite/scripts.pory"
	showobjectat VAR_LAST_TALKED, MAP_BEACH
# 276 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_BabyEvo_Explanation::
# 281 "data/maps/LandingSite/scripts.pory"
	goto_if_unset FLAG_EVOLVED_MON, Tamagotchi_BabyEvo_Explanation_2
# 285 "data/maps/LandingSite/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_LAST_EVO
# 286 "data/maps/LandingSite/scripts.pory"
	switch VAR_LAST_EVO
# 287 "data/maps/LandingSite/scripts.pory"
	case SPECIES_LAND_KID, Tamagotchi_BabyEvo_Explanation_6
# 289 "data/maps/LandingSite/scripts.pory"
	case SPECIES_WATER_KID, Tamagotchi_BabyEvo_Explanation_7
# 291 "data/maps/LandingSite/scripts.pory"
	case SPECIES_SKY_KID, Tamagotchi_BabyEvo_Explanation_8
# 294 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
	end

Tamagotchi_BabyEvo_Explanation_2:
	end

Tamagotchi_BabyEvo_Explanation_4:
# 297 "data/maps/LandingSite/scripts.pory"
	lock
# 298 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 299 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_BabyEvo_Explanation_Text_3
# 302 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 303 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 304 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 305 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
# 306 "data/maps/LandingSite/scripts.pory"
	release
	return

Tamagotchi_BabyEvo_Explanation_6:
# 288 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_0
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_7:
# 290 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_1
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_8:
# 292 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_2
	goto Tamagotchi_BabyEvo_Explanation_4


Tamagotchi_KidEvo_Explanation::
# 310 "data/maps/LandingSite/scripts.pory"
	lock
# 311 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 312 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_KidEvo_Explanation_Text_0
# 316 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 317 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 318 "data/maps/LandingSite/scripts.pory"
	playfanfare FANFARE_REGISTER_MATCH_CALL
# 319 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_KidEvo_Explanation_Text_1, MSGBOX_SIGN
# 320 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 321 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 322 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_YoungEvo_Explanation::
# 326 "data/maps/LandingSite/scripts.pory"
	lock
# 327 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 328 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_YoungEvo_Explanation_Text_0
# 331 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 332 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 333 "data/maps/LandingSite/scripts.pory"
	playfanfare FANFARE_REGISTER_MATCH_CALL
# 334 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_YoungEvo_Explanation_Text_1, MSGBOX_SIGN
# 335 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 336 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 337 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_FirstPalooka::
# 341 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
	return


Tamagotchi_FirstPalooka_Defeated::
# 356 "data/maps/LandingSite/scripts.pory"
	lock
# 357 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 358 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 359 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_0
# 361 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 362 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_1
# 363 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 364 "data/maps/LandingSite/scripts.pory"
	closemessage
# 365 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 366 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_SecondPalooka::
# 370 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_SECOND_PALOOKA, Tamagotchi_SecondPalooka_Intro, Tamagotchi_SecondPalooka_Defeat, Tamagotchi_SecondPalooka_Defeated
	return


Tamagotchi_SecondPalooka_Defeated::
# 383 "data/maps/LandingSite/scripts.pory"
	lock
# 384 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 385 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 386 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_SecondPalooka_Defeated_Text_0
# 388 "data/maps/LandingSite/scripts.pory"
	closemessage
# 389 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 390 "data/maps/LandingSite/scripts.pory"
	delay 30
# 391 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 392 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_1
# 397 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 398 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 399 "data/maps/LandingSite/scripts.pory"
	waitse
# 400 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 401 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_2
# 402 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 403 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 404 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_BossIntro::
# 408 "data/maps/LandingSite/scripts.pory"
	switch VAR_BOSSES_DEFEATED
# 409 "data/maps/LandingSite/scripts.pory"
	case 0, Tamagotchi_BossIntro_3
# 411 "data/maps/LandingSite/scripts.pory"
	case 1, Tamagotchi_BossIntro_4
# 413 "data/maps/LandingSite/scripts.pory"
	case 2, Tamagotchi_BossIntro_5
Tamagotchi_BossIntro_1:
	return

Tamagotchi_BossIntro_3:
# 410 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_BossIntro_Text_0
	goto Tamagotchi_BossIntro_1

Tamagotchi_BossIntro_4:
# 412 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_BossIntro_Text_1
	goto Tamagotchi_BossIntro_1

Tamagotchi_BossIntro_5:
# 414 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_BossIntro_Text_2
	goto Tamagotchi_BossIntro_1


Tamagotchi_AgitatorInteract::
# 421 "data/maps/LandingSite/scripts.pory"
	compare VAR_BOSSES_DEFEATED, 0
	goto_if_eq Tamagotchi_AgitatorInteract_2
Tamagotchi_AgitatorInteract_1:
# 426 "data/maps/LandingSite/scripts.pory"
	playse SE_M_STAT_DECREASE
# 427 "data/maps/LandingSite/scripts.pory"
	applymovement VAR_0x8006, Tamagotchi_AgitatorInteract_Movement_0
# 428 "data/maps/LandingSite/scripts.pory"
	waitse
# 429 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 430 "data/maps/LandingSite/scripts.pory"
	compare VAR_BOSSES_DEFEATED, 2
	goto_if_eq Tamagotchi_AgitatorInteract_5
Tamagotchi_AgitatorInteract_4:
	return

Tamagotchi_AgitatorInteract_2:
# 422 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_AgitatorInteract_Text_0
	goto Tamagotchi_AgitatorInteract_1

Tamagotchi_AgitatorInteract_5:
# 431 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 432 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_AgitatorInteract_Text_1
# 435 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 436 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 437 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_AgitatorInteract_Text_2
# 441 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 442 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 443 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_AgitatorInteract_Text_3
# 445 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 446 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 447 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_JOMO
	goto Tamagotchi_AgitatorInteract_4


Tamagotchi_AgitatorDisabled::
# 453 "data/maps/LandingSite/scripts.pory"
	lock
# 454 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_AgitatorDisabled_Text_0
# 455 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 456 "data/maps/LandingSite/scripts.pory"
	release
	return


# 16 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_0:
# 16 "data/maps/LandingSite/scripts.pory"
	face_up
	step_end

# 18 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_1:
# 18 "data/maps/LandingSite/scripts.pory"
	face_left
	step_end

# 20 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_2:
# 20 "data/maps/LandingSite/scripts.pory"
	face_down
	step_end

# 47 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_3:
# 47 "data/maps/LandingSite/scripts.pory"
	emote_x
	step_end

# 188 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushLeft_Movement_0:
# 188 "data/maps/LandingSite/scripts.pory"
	walk_left
	step_end

# 196 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushUp_Movement_0:
# 196 "data/maps/LandingSite/scripts.pory"
	walk_up
	step_end

# 427 "data/maps/LandingSite/scripts.pory"
Tamagotchi_AgitatorInteract_Movement_0:
# 427 "data/maps/LandingSite/scripts.pory"
	face_up
# 427 "data/maps/LandingSite/scripts.pory"
	delay_8
# 427 "data/maps/LandingSite/scripts.pory"
	face_down
	step_end

Banzo_EventScript_Intro_Text_0:
# 27 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}?{PAUSE 15} {PLAYER}??{PAUSE 30}\n"
	.string "I just saw you land, can you hear me?!$"

Banzo_EventScript_Intro_Text_1:
# 34 "data/maps/LandingSite/scripts.pory"
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
# 49 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_SMALL}That's a joke.{PAUSE 30} But please be careful.{FONT_NORMAL}\n"
	.string "If Pokéballs don't work on aliens, uh.{PAUSE 30}.{PAUSE 30}.{PAUSE 15}\l"
	.string "Well,{PAUSE 30} they'll work. Good luck!$"

Banzo_EventScript_AfterCatch_Text_0:
# 68 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Phew. So they do work. I'm\n"
	.string "going to analyze the data.\p"
	.string "Remember: you're there to figure out\n"
	.string "why the native life has started getting\l"
	.string "aggressive with each other...and what\l"
	.string "those odd devices we've observed are.\p"
	.string "Rest up in the lander when you need to,\n"
	.string "and use the synthesizer too.\p"
	.string "Good luck, and be safe.$"

Capsule_Text_0:
# 100 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 103 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 104 "data/maps/LandingSite/scripts.pory"
	.string "Synthesizer: Hello!\p"
	.string "How may I serve you?$"

Capsule_Text_3:
# 115 "data/maps/LandingSite/scripts.pory"
	.string "You shut down the synthesizer.$"

Capsule_Text_4:
# 119 "data/maps/LandingSite/scripts.pory"
	.string "10 Rare Candies dispensed.$"

Capsule_Text_5:
# 125 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"

LandingSite_CatchIntro_PushLeft_Text_0:
# 187 "data/maps/LandingSite/scripts.pory"
	.string "It's too dangerous to go on alone.$"

LandingSite_Jomo_Text_0:
# 203 "data/maps/LandingSite/scripts.pory"
	.string "I am here, alien!\p"
	.string "Prepare yourself. I will capture you,\n"
	.string "and make you a champion.\p"
	.string "You will make me the richest Palooka\n"
	.string "there ever was. I know it to be true.$"

LandingSite_Jomo_Text_1:
# 206 "data/maps/LandingSite/scripts.pory"
	.string "...no.$"

LandingSite_Jomo_Defeated_Text_0:
# 213 "data/maps/LandingSite/scripts.pory"
	.string "Ahaha...I am defeated.\p"
	.string "You have trained your creatures with\n"
	.string "such brutality.\p"
	.string "We will leave this planet, forever.\n"
	.string "Definitely. We definitely won't return\l"
	.string "with more.$"

LandingSite_Jomo_Defeated_Text_1:
# 220 "data/maps/LandingSite/scripts.pory"
	.string "He just...ran away.$"

LandingSite_Jomo_Defeated_Text_2:
# 222 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! You're alive!\p"
	.string "We need to report this to Mossdeep.$"

LandingSite_Jomo_Defeated_Text_3:
# 228 "data/maps/LandingSite/scripts.pory"
	.string "Thank you for playing!$"

LandingSite_Jomo_Defeated_Text_4:
# 232 "data/maps/LandingSite/scripts.pory"
	.string "You can keep playing, but that's all.$"

Tamagotchi_BabyEvo_Explanation_Text_0:
# 288 "data/maps/LandingSite/scripts.pory"
	.string "Land Hills$"

Tamagotchi_BabyEvo_Explanation_Text_1:
# 290 "data/maps/LandingSite/scripts.pory"
	.string "Water Beach$"

Tamagotchi_BabyEvo_Explanation_Text_2:
# 292 "data/maps/LandingSite/scripts.pory"
	.string "Sky Mountain$"

Tamagotchi_BabyEvo_Explanation_Text_3:
# 299 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The Exo-Pokémon\n"
	.string "of this planet evolve like ours back\l"
	.string "home, but somewhat differently.\p"
	.string "A “baby” evolves depending on the area\n"
	.string "of the island it spends time in.\p"
	.string "That little {STR_VAR_1} evolved in\n"
	.string "{STR_VAR_2}...makes sense, right?$"

Tamagotchi_KidEvo_Explanation_Text_0:
# 312 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “kids” of\n"
	.string "this world evolve based on their diet.\p"
	.string "They'll evolve into different “young”\n"
	.string "depending on the food you give them, if\l"
	.string "they're experienced enough.\p"
	.string "Or if you give them none at all, it\n"
	.string "seems...\p"
	.string "The synthesizer should be able to\n"
	.string "fabricate suitable nourishment.$"

Tamagotchi_KidEvo_Explanation_Text_1:
# 319 "data/maps/LandingSite/scripts.pory"
	.string "Food synth-patterns unlocked.$"

Tamagotchi_YoungEvo_Explanation_Text_0:
# 328 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “young” of\n"
	.string "this world evolve from scents.\p"
	.string "Like diet, scents take some time to\n"
	.string "trigger their evolution.\p"
	.string "The correct pheromones can be\n"
	.string "synthesized with enough charge.$"

Tamagotchi_YoungEvo_Explanation_Text_1:
# 334 "data/maps/LandingSite/scripts.pory"
	.string "Scent synth-patterns unlocked.$"

Tamagotchi_FirstPalooka_Defeated_Text_0:
# 359 "data/maps/LandingSite/scripts.pory"
	.string "Translator calibrated.\p"
	.string "Identify yourself!$"

Tamagotchi_FirstPalooka_Defeated_Text_1:
# 362 "data/maps/LandingSite/scripts.pory"
	.string "I gotta tell Jomo about this!$"

Tamagotchi_SecondPalooka_Defeated_Text_0:
# 386 "data/maps/LandingSite/scripts.pory"
	.string "These monsters are ours, alien. We've\n"
	.string "worked hard to make them battle-ready.\p"
	.string "You'd better go home before Jomo\n"
	.string "decides to take care of you himself.$"

Tamagotchi_SecondPalooka_Defeated_Text_1:
# 392 "data/maps/LandingSite/scripts.pory"
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
# 401 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Jomo seems scary... I'll try\n"
	.string "to pinpoint his location from up here.\l"
	.string "Keep doing what you're doing!$"

Tamagotchi_BossIntro_Text_0:
# 410 "data/maps/LandingSite/scripts.pory"
	.string "Alien, I do not know why you're here, but\n"
	.string "we will stop you.$"

Tamagotchi_BossIntro_Text_1:
# 412 "data/maps/LandingSite/scripts.pory"
	.string "Alien. If you continue this way, you'll\n"
	.string "incur Jomo's wrath!$"

Tamagotchi_BossIntro_Text_2:
# 414 "data/maps/LandingSite/scripts.pory"
	.string "Alien. I know we cannot defeat you, but\n"
	.string "honor demands we fight anyway.$"

Tamagotchi_AgitatorInteract_Text_0:
# 422 "data/maps/LandingSite/scripts.pory"
	.string "It's the alien device you're looking for.\p"
	.string "Though written in the Palooka language,\n"
	.string "there are enough graphics to indicate\l"
	.string "that this thing causes the Pokémon\l"
	.string "here to want to battle.\p"
	.string "There's an obvious off switch.$"

Tamagotchi_AgitatorInteract_Text_1:
# 432 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Bad news, {PLAYER}...\l"
	.string "I found Jomo, and he's at the lander.\p"
	.string "Worse news, his ship is in orbit and it's\n"
	.string "way bigger--$"

Tamagotchi_AgitatorInteract_Text_2:
# 437 "data/maps/LandingSite/scripts.pory"
	.string "Jomo: Alien! You hear now the voice of\n"
	.string "Jomo, leader of this operation!\p"
	.string "You have bested my lieutenants and\n"
	.string "disabled my machines.\p"
	.string "Watch your back. I will take you and\n"
	.string "make you the best fighter ever known.\l"
	.string "You will make me rich.$"

Tamagotchi_AgitatorInteract_Text_3:
# 443 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: ...I don't think he knew I\n"
	.string "was listening.\p"
	.string "I don't know what beating him will do,\n"
	.string "but...good luck.$"

Tamagotchi_AgitatorDisabled_Text_0:
# 454 "data/maps/LandingSite/scripts.pory"
	.string "It's been shut down.$"

Tamagotchi_FirstPalooka_Intro::
# 344 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KA! KE TO,WA?$"

Tamagotchi_FirstPalooka_Defeat::
# 350 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}JO LADA KE APGE,WA?$"

Tamagotchi_SecondPalooka_Intro::
# 373 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KE TO,WA? {FONT_NORMAL}Oh, you're the alien!\p"
	.string "My orders are to stop you from\ninterfering!$"

Tamagotchi_SecondPalooka_Defeat::
# 378 "data/maps/LandingSite/scripts.pory"
	.string "Jomo will be hearing about this...!$"
