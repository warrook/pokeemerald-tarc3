LandingSite_MapScripts::
	.byte 0


Capsule::
# 4 "data/maps/LandingSite/scripts.pory"
	lockall
# 6 "data/maps/LandingSite/scripts.pory"
	special ScriptMenu_CreateCapsuleMultichoice
# 12 "data/maps/LandingSite/scripts.pory"
	switch VAR_RESULT
# 13 "data/maps/LandingSite/scripts.pory"
	case 0, Capsule_3
# 16 "data/maps/LandingSite/scripts.pory"
	case 1, Capsule_4
# 18 "data/maps/LandingSite/scripts.pory"
	case 2, Capsule_5
# 20 "data/maps/LandingSite/scripts.pory"
	case 3, Capsule_6
# 22 "data/maps/LandingSite/scripts.pory"
	case MULTI_B_PRESSED, Capsule_7
Capsule_1:
# 25 "data/maps/LandingSite/scripts.pory"
	release
	end

Capsule_3:
# 14 "data/maps/LandingSite/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 15 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_0
	goto Capsule_1

Capsule_4:
# 17 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_1
	goto Capsule_1

Capsule_5:
# 19 "data/maps/LandingSite/scripts.pory"
	call EventScript_AccessPokemonBoxLink
	goto Capsule_1

Capsule_6:
# 21 "data/maps/LandingSite/scripts.pory"
	msgbox Capsule_Text_2
	goto Capsule_1

Capsule_7:
	goto Capsule_1


Capsule_Text_0:
# 15 "data/maps/LandingSite/scripts.pory"
	.string "You feel refreshed!$"

Capsule_Text_1:
# 17 "data/maps/LandingSite/scripts.pory"
	.string "You fire up the synthesizer.$"

Capsule_Text_2:
# 21 "data/maps/LandingSite/scripts.pory"
	.string "No answer.$"
