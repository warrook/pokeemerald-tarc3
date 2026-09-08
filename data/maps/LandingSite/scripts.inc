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
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_0
# 12 "data/maps/LandingSite/scripts.pory"
	delay 50
# 13 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_1
# 14 "data/maps/LandingSite/scripts.pory"
	delay 50
# 15 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_2
# 16 "data/maps/LandingSite/scripts.pory"
	delay 50
# 17 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 18 "data/maps/LandingSite/scripts.pory"
	delay 60
# 19 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_2
# 20 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 21 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 22 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_0
# 24 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 25 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_OFF
# 26 "data/maps/LandingSite/scripts.pory"
	waitse
# 28 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 29 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_1
# 41 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 42 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, Banzo_EventScript_Intro_Movement_3
# 43 "data/maps/LandingSite/scripts.pory"
	delay 60
# 44 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_Intro_Text_2
# 48 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 50 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8004, 1
# 51 "data/maps/LandingSite/scripts.pory"
	special EnterStudyMode
# 52 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 53 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 54 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_HIDE_FIRST_PALOOKA
# 55 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_HIDE_SECOND_PALOOKA
# 56 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Banzo_EventScript_AfterCatch::
# 61 "data/maps/LandingSite/scripts.pory"
	lockall
# 62 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
# 63 "data/maps/LandingSite/scripts.pory"
	suitcall Banzo_EventScript_AfterCatch_Text_0
# 68 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 69 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 70 "data/maps/LandingSite/scripts.pory"
	waitse
# 71 "data/maps/LandingSite/scripts.pory"
	msgbox Banzo_EventScript_AfterCatch_Text_1
# 72 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_SYS_SCALE_OPPONENTS
# 73 "data/maps/LandingSite/scripts.pory"
	setflag FLAG_EXP_SHARE
# 74 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 75 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_FIRST_PALOOKA
# 76 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_HIDE_SECOND_PALOOKA
# 77 "data/maps/LandingSite/scripts.pory"
	additem ITEM_POKE_BALL, 20
# 78 "data/maps/LandingSite/scripts.pory"
	releaseall
	end


Capsule::
# 83 "data/maps/LandingSite/scripts.pory"
	lock
# 86 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 93 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 94 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 97 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 112 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 118 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 120 "data/maps/LandingSite/scripts.pory"
	case 4, Capsule_7
# 122 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_8
Capsule_1:
# 126 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 95 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 96 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 98 "data/maps/LandingSite/scripts.pory"
	playse SE_PC_ON
# 99 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
# 100 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
# 102 "data/maps/LandingSite/scripts.pory"
	switch VAR_TAMAGOTCHI_STAGE_EXPLAINED
# 103 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_11
# 105 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_12
# 108 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage1
Capsule_9:
# 110 "data/maps/LandingSite/scripts.pory"
	playse SE_PC_OFF
# 111 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_3
	goto Capsule_1

Capsule_5:
# 113 "data/maps/LandingSite/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 114 "data/maps/LandingSite/scripts.pory"
	additem ITEM_RARE_CANDY, 10
# 115 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_4
# 116 "data/maps/LandingSite/scripts.pory"
	closemessage
# 117 "data/maps/LandingSite/scripts.pory"
	goto Capsule
	goto Capsule_1

Capsule_6:
# 119 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_7:
# 121 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_5
	goto Capsule_1

Capsule_8:
	goto Capsule_1

Capsule_11:
# 104 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage2
	goto Capsule_9

Capsule_12:
# 106 "data/maps/LandingSite/scripts.pory"
	pokemart SynthesizerStage3
	goto Capsule_9


	.align 2
# 130 "data/maps/LandingSite/scripts.pory"
SynthesizerStage1:
# 131 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 132 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 133 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 134 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 135 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 136 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE

	.align 2
# 139 "data/maps/LandingSite/scripts.pory"
SynthesizerStage2:
# 140 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 141 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 142 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 143 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 144 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 145 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 146 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 147 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 148 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 149 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EVERSTONE
# 150 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SAVORY_FOOD
# 151 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_LEAFY_FOOD
# 152 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GOOEY_FOOD
	.2byte ITEM_NONE

	.align 2
# 155 "data/maps/LandingSite/scripts.pory"
SynthesizerStage3:
# 156 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POKE_BALL
# 157 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 158 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 159 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 160 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_POTION
# 161 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 162 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 163 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REPEL
# 164 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 165 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 166 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 167 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_REVIVE
# 168 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 169 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 170 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EVERSTONE
# 171 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 172 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 173 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_SAVORY_FOOD
# 174 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_LEAFY_FOOD
# 175 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_GOOEY_FOOD
# 176 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_JOY_SCENT
# 177 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_EXCITE_SCENT
# 178 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_VIVID_SCENT
# 179 "data/maps/LandingSite/scripts.pory"
	.2byte ITEM_COMPLEX_SCENT
	.2byte ITEM_NONE

LandingSite_CatchIntro_PushLeft::
# 183 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 184 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushLeft_Movement_0
# 185 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 186 "data/maps/LandingSite/scripts.pory"
	release
	end


LandingSite_CatchIntro_PushUp::
# 191 "data/maps/LandingSite/scripts.pory"
	msgbox LandingSite_CatchIntro_PushLeft_Text_0
# 192 "data/maps/LandingSite/scripts.pory"
	applymovement LOCALID_PLAYER, LandingSite_CatchIntro_PushUp_Movement_0
# 193 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 194 "data/maps/LandingSite/scripts.pory"
	release
	end


Tamagotchi_SuitCallBegin::
# 200 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_CALL
# 201 "data/maps/LandingSite/scripts.pory"
	waitse
# 202 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_ON
	return


Tamagotchi_SuitCallEnd::
# 208 "data/maps/LandingSite/scripts.pory"
	playse SE_POKENAV_HANG_UP
	return


Tamagotchi_Palookaport_Out::
# 213 "data/maps/LandingSite/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 214 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 215 "data/maps/LandingSite/scripts.pory"
	setvar VAR_0x8006, 65535
# 216 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 217 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 218 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 219 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 220 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 0
# 221 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 222 "data/maps/LandingSite/scripts.pory"
	delay 24
# 223 "data/maps/LandingSite/scripts.pory"
	removeobject VAR_LAST_TALKED
# 224 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_Palookaport_In::
# 228 "data/maps/LandingSite/scripts.pory"
	addobject VAR_LAST_TALKED
# 229 "data/maps/LandingSite/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_BEACH
# 230 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 0, VAR_0x8006
# 231 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 1, VAR_LAST_TALKED
# 232 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 2, 124
# 233 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 3, 2
# 234 "data/maps/LandingSite/scripts.pory"
	setfieldeffectargument 4, 1
# 235 "data/maps/LandingSite/scripts.pory"
	dofieldeffect FLDEFF_PALOOKAPORT
# 236 "data/maps/LandingSite/scripts.pory"
	delay 24
# 237 "data/maps/LandingSite/scripts.pory"
	showobjectat VAR_LAST_TALKED, MAP_BEACH
# 238 "data/maps/LandingSite/scripts.pory"
	waitfieldeffect FLDEFF_PALOOKAPORT
	return


Tamagotchi_BabyEvo_Explanation::
# 242 "data/maps/LandingSite/scripts.pory"
	goto_if_unset FLAG_EVOLVED_MON, Tamagotchi_BabyEvo_Explanation_2
# 246 "data/maps/LandingSite/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_LAST_EVO
# 247 "data/maps/LandingSite/scripts.pory"
	switch VAR_LAST_EVO
# 248 "data/maps/LandingSite/scripts.pory"
	case SPECIES_LAND_KID, Tamagotchi_BabyEvo_Explanation_6
# 250 "data/maps/LandingSite/scripts.pory"
	case SPECIES_WATER_KID, Tamagotchi_BabyEvo_Explanation_7
# 252 "data/maps/LandingSite/scripts.pory"
	case SPECIES_SKY_KID, Tamagotchi_BabyEvo_Explanation_8
# 255 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
	end

Tamagotchi_BabyEvo_Explanation_2:
	end

Tamagotchi_BabyEvo_Explanation_4:
# 258 "data/maps/LandingSite/scripts.pory"
	lock
# 259 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 260 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_BabyEvo_Explanation_Text_3
# 263 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 264 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 265 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 266 "data/maps/LandingSite/scripts.pory"
	clearflag FLAG_EVOLVED_MON
# 267 "data/maps/LandingSite/scripts.pory"
	release
	return

Tamagotchi_BabyEvo_Explanation_6:
# 249 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_0
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_7:
# 251 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_1
	goto Tamagotchi_BabyEvo_Explanation_4

Tamagotchi_BabyEvo_Explanation_8:
# 253 "data/maps/LandingSite/scripts.pory"
	bufferstring STR_VAR_2, Tamagotchi_BabyEvo_Explanation_Text_2
	goto Tamagotchi_BabyEvo_Explanation_4


Tamagotchi_KidEvo_Explanation::
# 271 "data/maps/LandingSite/scripts.pory"
	lock
# 272 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 273 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_KidEvo_Explanation_Text_0
# 277 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 278 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 279 "data/maps/LandingSite/scripts.pory"
	playfanfare FANFARE_REGISTER_MATCH_CALL
# 280 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_KidEvo_Explanation_Text_1, MSGBOX_SIGN
# 281 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 282 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 283 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_YoungEvo_Explanation::
# 287 "data/maps/LandingSite/scripts.pory"
	lock
# 288 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 289 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_YoungEvo_Explanation_Text_0
# 292 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 293 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 294 "data/maps/LandingSite/scripts.pory"
	playfanfare FANFARE_REGISTER_MATCH_CALL
# 295 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_YoungEvo_Explanation_Text_1, MSGBOX_SIGN
# 296 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 297 "data/maps/LandingSite/scripts.pory"
	addvar VAR_TAMAGOTCHI_STAGE_EXPLAINED, 1
# 298 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_FirstPalooka::
# 302 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_FIRST_PALOOKA, Tamagotchi_FirstPalooka_Intro, Tamagotchi_FirstPalooka_Defeat, Tamagotchi_FirstPalooka_Defeated
	return


Tamagotchi_FirstPalooka_Defeated::
# 317 "data/maps/LandingSite/scripts.pory"
	lock
# 318 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 319 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 320 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_0
# 322 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 323 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_FirstPalooka_Defeated_Text_1
# 324 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 325 "data/maps/LandingSite/scripts.pory"
	closemessage
# 326 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 327 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 328 "data/maps/LandingSite/scripts.pory"
	release
	return


Tamagotchi_SecondPalooka::
# 332 "data/maps/LandingSite/scripts.pory"
	trainerbattle_single TRAINER_SECOND_PALOOKA, Tamagotchi_SecondPalooka_Intro, Tamagotchi_SecondPalooka_Defeat, Tamagotchi_SecondPalooka_Defeated
	return


Tamagotchi_SecondPalooka_Defeated::
# 345 "data/maps/LandingSite/scripts.pory"
	lock
# 346 "data/maps/LandingSite/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 347 "data/maps/LandingSite/scripts.pory"
	waitmovement
# 348 "data/maps/LandingSite/scripts.pory"
	msgbox Tamagotchi_SecondPalooka_Defeated_Text_0
# 350 "data/maps/LandingSite/scripts.pory"
	closemessage
# 351 "data/maps/LandingSite/scripts.pory"
	addvar VAR_PALOOKAS_DEFEATED, 1
# 352 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_Palookaport_Out
# 353 "data/maps/LandingSite/scripts.pory"
	delay 30
# 354 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 355 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_1
# 360 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 361 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 362 "data/maps/LandingSite/scripts.pory"
	waitse
# 363 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallBegin
# 364 "data/maps/LandingSite/scripts.pory"
	suitcall Tamagotchi_SecondPalooka_Defeated_Text_2
# 365 "data/maps/LandingSite/scripts.pory"
	waitmessage
# 366 "data/maps/LandingSite/scripts.pory"
	call Tamagotchi_SuitCallEnd
# 367 "data/maps/LandingSite/scripts.pory"
	release
	return


# 11 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_0:
# 11 "data/maps/LandingSite/scripts.pory"
	face_up
	step_end

# 13 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_1:
# 13 "data/maps/LandingSite/scripts.pory"
	face_left
	step_end

# 15 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_2:
# 15 "data/maps/LandingSite/scripts.pory"
	face_down
	step_end

# 42 "data/maps/LandingSite/scripts.pory"
Banzo_EventScript_Intro_Movement_3:
# 42 "data/maps/LandingSite/scripts.pory"
	emote_x
	step_end

# 184 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushLeft_Movement_0:
# 184 "data/maps/LandingSite/scripts.pory"
	walk_left
	step_end

# 192 "data/maps/LandingSite/scripts.pory"
LandingSite_CatchIntro_PushUp_Movement_0:
# 192 "data/maps/LandingSite/scripts.pory"
	walk_up
	step_end

Banzo_EventScript_Intro_Text_0:
# 22 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}?{PAUSE 15} {PLAYER}??{PAUSE 30}\n"
	.string "I just saw you land, can you hear me?!$"

Banzo_EventScript_Intro_Text_1:
# 29 "data/maps/LandingSite/scripts.pory"
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
# 44 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_SMALL}That's a joke.{PAUSE 30} But please be careful.{FONT_NORMAL}\n"
	.string "If Pokéballs don't work on aliens, uh.{PAUSE 30}.{PAUSE 30}.{PAUSE 15}\l"
	.string "Well,{PAUSE 30} they'll work. Good luck!$"

Banzo_EventScript_AfterCatch_Text_0:
# 63 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Phew. So they do work.\p"
	.string "I'm going to analyze the data. I'm here\n"
	.string "if you need to talk to me!\p"
	.string "Remember: you're there to figure out\n"
	.string "why the native life has started getting\l"
	.string "aggressive with each other...and what\l"
	.string "those odd devices we've observed are.\p"
	.string "Rest up in the lander when you need to,\n"
	.string "and use the synthesizer too.\p"
	.string "Good luck, and be safe.$"

Banzo_EventScript_AfterCatch_Text_1:
# 71 "data/maps/LandingSite/scripts.pory"
	.string "Open your I.D. card in the start menu\n"
	.string "for a reminder of what to do, or call\l"
	.string "Banzo for a more elaborate explanation.$"

Capsule_Text_0:
# 96 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 99 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 100 "data/maps/LandingSite/scripts.pory"
	.string "Synthesizer: Hello!\p"
	.string "How may I serve you?$"

Capsule_Text_3:
# 111 "data/maps/LandingSite/scripts.pory"
	.string "You shut down the synthesizer.$"

Capsule_Text_4:
# 115 "data/maps/LandingSite/scripts.pory"
	.string "10 Rare Candies dispensed.$"

Capsule_Text_5:
# 121 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"

LandingSite_CatchIntro_PushLeft_Text_0:
# 183 "data/maps/LandingSite/scripts.pory"
	.string "It's too dangerous to go on alone.$"

Tamagotchi_BabyEvo_Explanation_Text_0:
# 249 "data/maps/LandingSite/scripts.pory"
	.string "Land Hills$"

Tamagotchi_BabyEvo_Explanation_Text_1:
# 251 "data/maps/LandingSite/scripts.pory"
	.string "Water Beach$"

Tamagotchi_BabyEvo_Explanation_Text_2:
# 253 "data/maps/LandingSite/scripts.pory"
	.string "Sky Mountain$"

Tamagotchi_BabyEvo_Explanation_Text_3:
# 260 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The Exo-Pokémon\n"
	.string "of this planet evolve like ours back\l"
	.string "home, but somewhat differently.\p"
	.string "A “baby” evolves depending on the area\n"
	.string "of the island it spends time in.\p"
	.string "That little {STR_VAR_1} evolved in\n"
	.string "{STR_VAR_2}...makes sense, right?$"

Tamagotchi_KidEvo_Explanation_Text_0:
# 273 "data/maps/LandingSite/scripts.pory"
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
# 280 "data/maps/LandingSite/scripts.pory"
	.string "Food synth-patterns unlocked.$"

Tamagotchi_YoungEvo_Explanation_Text_0:
# 289 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: {PLAYER}! The “young” of\n"
	.string "this world evolve from scents.\p"
	.string "Like diet, scents take some time to\n"
	.string "trigger their evolution.\p"
	.string "The correct pheromones can be\n"
	.string "synthesized with enough charge.$"

Tamagotchi_YoungEvo_Explanation_Text_1:
# 295 "data/maps/LandingSite/scripts.pory"
	.string "Scent synth-patterns unlocked.$"

Tamagotchi_FirstPalooka_Defeated_Text_0:
# 320 "data/maps/LandingSite/scripts.pory"
	.string "Translator calibrated.\p"
	.string "Identify yourself!$"

Tamagotchi_FirstPalooka_Defeated_Text_1:
# 323 "data/maps/LandingSite/scripts.pory"
	.string "I gotta tell Jomo about this!$"

Tamagotchi_SecondPalooka_Defeated_Text_0:
# 348 "data/maps/LandingSite/scripts.pory"
	.string "These monsters are ours, alien. We've\n"
	.string "worked hard to make them battle-ready.\p"
	.string "You'd better go home before Jomo\n"
	.string "decides to take care of you himself.$"

Tamagotchi_SecondPalooka_Defeated_Text_1:
# 355 "data/maps/LandingSite/scripts.pory"
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
# 364 "data/maps/LandingSite/scripts.pory"
	.string "Prof. Banzo: Jomo seems scary... I'll try\n"
	.string "to pinpoint his location from up here.\l"
	.string "Keep doing what you're doing!$"

Tamagotchi_FirstPalooka_Intro::
# 305 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KA! KE TO,WA?$"

Tamagotchi_FirstPalooka_Defeat::
# 311 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}JO LADA KE APGE,WA?$"

Tamagotchi_SecondPalooka_Intro::
# 335 "data/maps/LandingSite/scripts.pory"
	.string "{FONT_PALOOKA}KE TO,WA? {FONT_NORMAL}Oh, you're the alien!\p"
	.string "My orders are to stop you from\ninterfering!$"

Tamagotchi_SecondPalooka_Defeat::
# 340 "data/maps/LandingSite/scripts.pory"
	.string "Jomo will be hearing about this...!$"
