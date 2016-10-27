// MenuTask.c
#include "stdint.h"
#include "stdio.h"
#include "MenuItemBox.h"
#include "ListBox.h"
#include "NumBox.h"
#include "MenuDriverComon.h"
#include "MenuTask.h"

/*!
 * \brief Main principal
 * 		Display screen update every period (timeout). Totally screen have 3 state: MENU_TREE, MENU, Control
 * 		Current state update after key press. Every period hardware display driver ref to display and update
 */




void delay_ms(uint32_t time_ms){
}


/*!
 * \brief KeyboarState
 */
void GetKeyboarState(KEYBOARD_STATE *outGetKeyboarState)
{
	/*!
	 *  \todo add keyboard request
	 */
	*outGetKeyboarState=KEY_NON;
	return;
}

/*
 * Globally menu have 3 state: MENU_TREE, MENU and CONTROL ref MENU_STATE enum
 * Every of state have personal reaction on KEY_PRESS event and TIMEOUT event
 * All reaction descried in MenuAction Array
 *
state|MENU_TREE |MENU      |CONTROL   |
key  |          |          |          |
_____|__________|__________|__________|
UP   |          |          |          |
_____|__________|__________|__________|
DOWN |          |          |          |
_____|__________|__________|__________|
ENTR |          |          |          |
_____|__________|__________|__________|
ESC  |          |          |          |
_____|__________|__________|__________|
 */


/*!
 *  \brief StateMenuTreeAction function array reaction on key press in MENU_TREE state
 */
const pfMenuAction StateMenuTreeAction[]={
		[KEY_UP]=&MenuTree_UP_Processig,
		[KEY_DOWN]=&MenuTree_DOWN_Processig,
		[KEY_ENTR]=&MenuTree_ENTR_Processig,
		[KEY_ESC]=&MenuTree_ESC_Processig
};

/*!
 *  \brief StateMenuAction function array reaction on key press in MENU state
 */
const pfMenuAction StateMenuAction[]={
		[KEY_UP]=&Menu_UP_Processig,
		[KEY_DOWN]=&Menu_DOWN_Processig,
		[KEY_ENTR]=&Menu_ENTR_Processig,
		[KEY_ESC]=&Menu_ESC_Processig
};

/*!
 *  \brief StateControlAction function array reaction on key press in CONTROL state
 */
const pfMenuAction StateControlAction[]={
		[KEY_UP]=&Control_UP_Processig,
		[KEY_DOWN]=&Control_DOWN_Processig,
		[KEY_ENTR]=&Control_ENTR_Processig,
		[KEY_ESC]=&Control_ESC_Processig
};


const pfMenuAction *MenuAction[]={
		StateMenuTreeAction,
		StateMenuAction,
		StateControlAction
};

/*!
 *  \brief CurentMenuState menu state structure
 */
SMenuState CurentMenuState={
		.CurrentState=STATE_MENU_TREE
};

/*!
 *  \brief TaskMenu main loop for Menu processing
 */
void TaskMenu(void* rootMenuItem){
	KEYBOARD_STATE CurrentPressKey;
	//pointer on ROOT MENU ITEM in state structure
	CurentMenuState.CurrentMenu=(MenuItem*)rootMenuItem;
	CurentMenuState.RootMenu=CurentMenuState.CurrentMenu;
	// Infinite Display Menu loop
	while(1){
		delay_ms(50);
		// Get current keyboard state
		GetKeyboarState(&CurrentPressKey);
		if(CurrentPressKey==KEY_NON){continue;}
		//Reaction on user key press
		MenuAction[CurentMenuState.CurrentState][CurrentPressKey](&CurentMenuState);
		// Update display
		// In this place i have to lock all changed in widgets property. Have can i do it ???
		// Call All user callback
	}
}

/*!
 *  \brief MenuTree_UP_Processig processing  (key UP press) in MENU_TREE state
 */
void MenuTree_UP_Processig(SMenuState *tempState)
{
	MenuItem *tempMenu=tempState->CurrentMenu;
	if(tempState->CurrentMenu->Up == NULL)
	{ // if upper menu screen, find tree root menu
		while(tempMenu->Down!=NULL)
		{
			tempMenu=tempMenu->Down;
		}
		tempState->CurrentMenu=tempMenu;
		return;
	}
	else
	{
		tempState->CurrentMenu=tempMenu->Up;
	}
}

/*!
 *  \brief MenuTree_DOWN_Processig processing  (key DOWN press) in MENU_TREE state
 */
void MenuTree_DOWN_Processig(SMenuState *tempState)
{
	MenuItem *TempMenu=tempState->CurrentMenu;
	if(tempState->CurrentMenu->Down == NULL)
	{ // if upper menu screen, find root
		while(TempMenu->Up != NULL)
		{
			TempMenu=TempMenu->Up;
		}
		tempState->CurrentMenu=TempMenu;
		return;
	}
	else
	{
		tempState->CurrentMenu=(MenuItem*)tempState->CurrentMenu->Down;
	}
}


/*!
 *  \brief MenuTree_ENTR_Processig processing  (key ENTR press) in MENU_TREE state
 */
void MenuTree_ENTR_Processig(SMenuState *tempState)
{
	MenuItem *tempMenu=tempState->CurrentMenu;
	if(tempState->CurrentMenu->Down == NULL)
	{   // If current mennu a root off some menu tree - entr on new menu tree
		if(tempMenu->Down != NULL)
		{
			tempState->CurrentMenu=tempMenu->Down;
			return;
		}
		// if current menu is controll menu
		else if(tempMenu->widgetsNumber !=0)
		{
			tempState->CurrentState=STATE_MENU;
			tempState->CurrentMenu->CursorPosition=0;
			return;
		}
		// if no SUBmenu and no control elements NO ACTION
		else
		{
			return;
		}
	}
	else
	{
		tempState->CurrentMenu=(MenuItem*)tempState->CurrentMenu->Down;
	}
}



/*!
 *  \brief MenuTree_ESC_Processig processing  (key ESC press) in MENU_TREE state
 */
void MenuTree_ESC_Processig(SMenuState *TempState)
{
	MenuItem *TempMenu=TempState->CurrentMenu;
	while(TempMenu->Up != NULL)
	{
		TempMenu=TempMenu->Up;
	}
	if(TempMenu->Up != NULL)
	{
		TempState->CurrentMenu=TempMenu->Up;
	}
	else
	{
		TempState->CurrentMenu=TempMenu;
	}
}


/*!
 *  \brief NumCursorWidget calculate number widgets with "cursor" property inside input Menu
 */
uint8_t NumCursorWidget(const MenuItem *InMenuItem)
{
	uint8_t WidCnt=0;
	uint8_t CursorWidCnt=0;  // cursor widget size
	//find all widgets with cursor property
	for(;WidCnt<InMenuItem->widgetsNumber;WidCnt++){
		if(ISCURSORWIDGET(InMenuItem->Memders[WidCnt]->type))
		{
			CursorWidCnt++;
		}
	}
	return CursorWidCnt;
}


/*!
 *  \brief CursorShift processing  shift current cursor position
 */
void CursorShift(MenuItem *tempMenu,KEYBOARD_STATE key)
{
	uint8_t widgetCount=tempMenu->CursorPosition;
	if(NumCursorWidget(tempMenu)<2){return;}

	while(1)
	{
		if(key == KEY_UP)
		{
			widgetCount++;
			if(widgetCount == tempMenu->widgetsNumber)
			{
				widgetCount=0;
			}
		}
		if(key == KEY_DOWN)
		{
			if(widgetCount == 0)
			{
				widgetCount=tempMenu->widgetsNumber;
			}
			widgetCount--;
		}
		// find next cursor widget
		if(ISCURSORWIDGET(tempMenu->Memders[widgetCount]->type))
		{
			tempMenu->CursorPosition=widgetCount;
			break;
		}
	}
}


/*!
 *  \brief Menu_UP_Processig processing  (key UP press) in MENU state
 */
void Menu_UP_Processig(SMenuState *tempState)
{
	CursorShift(tempState->CurrentMenu,KEY_UP);
}

/*!
 *  \brief Menu_DOWN_Processig processing  (key DOWN press) in MENU state
 *  //
 */
void Menu_DOWN_Processig(SMenuState *tempState)
{
	CursorShift(tempState->CurrentMenu,KEY_DOWN);
}


/*!
 *  \brief Menu_ENTR_Processig processing  (key ENTR press) in MENU state
 */
void Menu_ENTR_Processig(SMenuState *tempState)
{
	//if cursor widget epsent - return
	if(NumCursorWidget(tempState->CurrentMenu)==0){return;}

	tempState->CurrentState=STATE_CONTROL;
}



/*!
 *  \brief Menu_ESC_Processig processing  (key ESC press) in MENU state
 */
void Menu_ESC_Processig(SMenuState *tempState)
{

	tempState->CurrentState=STATE_MENU_TREE;
}


/*!
 *  \brief Control_UP_Processig processing  (key UP press) in CONTROL state
 */
void Control_UP_Processig(SMenuState *tempState)
{
	MenuItem *tempMenu=tempState->CurrentMenu;
	// Call personal widget processing function
	UserKeyPressCallBack((void*)tempMenu->Memders[tempMenu->CursorPosition],
																KEY_UP);
}

/*!
 *  \brief Control_DOWN_Processig processing  (key DOWN press) in CONTROL state
 */
void Control_DOWN_Processig(SMenuState *tempState)
{
	MenuItem *tempMenu=tempState->CurrentMenu;
	// Call personal widget processing function
	UserKeyPressCallBack((void*)tempMenu->Memders[tempMenu->CursorPosition],
																KEY_DOWN);
}


/*!
 *  \brief Control_ENTR_Processig processing  (key ENTR press) in CONTROL state
 */
void Control_ENTR_Processig(SMenuState *tempState)
{
	MenuItem *tempMenu=tempState->CurrentMenu;
	// Call personal widget processing function
	UserKeyPressCallBack((void*)tempMenu->Memders[tempMenu->CursorPosition],
																KEY_ENTR);
	tempState->CurrentState=STATE_MENU;
}



/*!
 *  \brief Control_ESC_Processig processing  (key ESC press) in CONTROL state
 */
void Control_ESC_Processig(SMenuState *tempState)
{
	tempState->CurrentState=STATE_MENU;
}
