Beach_MapScripts::
	.byte 0


Beach_Palooka_A::
# 4 "data/maps/Beach/scripts.pory"
	trainerbattle_single TRAINER_BEACH_A, Beach_Palooka_A_Text_0, Beach_Palooka_A_Text_1
# 5 "data/maps/Beach/scripts.pory"
	removeobject LOCALID_PALOOKA_A
# 6 "data/maps/Beach/scripts.pory"
	release
	end


Beach_Palooka_A_Text_0:
# 4 "data/maps/Beach/scripts.pory"
	.string "Nyeh!$"

Beach_Palooka_A_Text_1:
# 4 "data/maps/Beach/scripts.pory"
	.string "Nyeh...$"
