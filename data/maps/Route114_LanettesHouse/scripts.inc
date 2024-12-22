Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	goto_if_set FLAG_LANDMARK_LANETTES_HOUSE, Route114_LanettesHouse_EventScript_End
	setvar VAR_HARD_LEVEL_CAP, 0
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_End::
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_EventScript_ExitedRoom0::
	lockall
	msgbox Route114_LanettesHouse_Text_HeyPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route114_LanettesHouse_Movement_Start0
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_HARD_LEVEL_CAP, 10
	call_if_set FLAG_LANDMARK_LANETTES_HOUSE, Route114_LanettesHouse_EventScript_GetStarter
	releaseall
	end

Route114_LanettesHouse_EventScript_ExitedRoom1::
	lockall
	msgbox Route114_LanettesHouse_Text_HeyPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route114_LanettesHouse_Movement_Start1
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_HARD_LEVEL_CAP, 10
	call_if_set FLAG_LANDMARK_LANETTES_HOUSE, Route114_LanettesHouse_EventScript_GetStarter
	releaseall
	end

Route114_LanettesHouse_EventScript_ExitedRoom2::
	lockall
	msgbox Route114_LanettesHouse_Text_HeyPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route114_LanettesHouse_Movement_Start2
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_HARD_LEVEL_CAP, 10
	call_if_set FLAG_LANDMARK_LANETTES_HOUSE, Route114_LanettesHouse_EventScript_GetStarter
	releaseall
	end

Route114_LanettesHouse_EventScript_GetStarter::
	msgbox Route114_LanettesHouse_Text_GivingStarter, MSGBOX_DEFAULT
	special ChooseStarter
	waitstate
	setflag FLAG_SYS_POKEMON_GET
	bufferleadmonspeciesname STR_VAR_1
	msgbox Route114_LanettesHouse_Text_ReceivedMon, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route114_LanettesHouse_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NicknameStarter
	call_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_GoStartAdventure
	return

Route114_LanettesHouse_EventScript_GoStartAdventure::
	giveitem ITEM_INFINITE_REPEL
	giveitem ITEM_POKE_BALL, 25
	msgbox Route114_LanettesHouse_Text_GoAdventure, MSGBOX_DEFAULT
	closemessage
	return

Route114_LanettesHouse_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	call Route114_LanettesHouse_EventScript_GoStartAdventure
	end

Route114_LanettesHouse_Text_GoAdventure:
	.string "Well, I don't want to hold you, I'm\n"
	.string "sure you're eager to get going…$"

Route114_LanettesHouse_Text_ReceivedMon:
	.string "{PLAYER} received the {STR_VAR_1}!$"

Route114_LanettesHouse_Text_WhyNotGiveNicknameToMon:
	.string "DAD: While you're at it, why not give\n"
	.string "a nickname to that {STR_VAR_1}?$"

Route114_LanettesHouse_Text_HeyPlayer:
	.string "Hey! {PLAYER}!\p"
	.string "Come here!$"

Route114_LanettesHouse_Text_GivingStarter:
	.string "DAD: Look who finally woke up!\p"
	.string "Are you excited for your big day?\n"
	.string "You're finally old enough for your\l"
	.string "very own adventure…\p"
	.string "Oh, right! I was going to give you\n"
	.string "your starter POKéMON!$"

Route114_LanettesHouse_Movement_Start0:
	walk_right
	walk_down
	walk_right
	walk_right
	step_end

Route114_LanettesHouse_Movement_Start1:
	walk_down
	walk_right
	walk_right
	step_end

Route114_LanettesHouse_Movement_Start2:
	walk_down
	walk_down
	walk_right
	step_end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

