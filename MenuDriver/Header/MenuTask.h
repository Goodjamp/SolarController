//   MenuTask.h
#ifndef MENU_TASK_H_
#define MENU_TASK_H_
#include "MenuItemBox.h"
#include "MenuDriverComon.h"


/*!
 *  \brief enum MENU_STATE possibility state of menu
 */
typedef enum{
	STATE_MENU_TREE=0,
	STATE_MENU,
	STATE_CONTROL
}MENU_STATE;

/*!
 *  \brief SMenuState structure contain all need current state paramiters
 */
typedef struct{
	MENU_STATE CurrentState;
	MenuItem *CurrentMenu;
	MenuItem *RootMenu;
} SMenuState;


/*!
 *  \brief pfMenuAction pointer on menu action function type
 */
typedef void (*pfMenuAction)(SMenuState *);


//function prototype
void TaskMenu(void* in_arg);
void MenuTree_UP_Processig(SMenuState *TempState);
void MenuTree_DOWN_Processig(SMenuState *TempState);
void MenuTree_ENTR_Processig(SMenuState *TempState);
void MenuTree_ESC_Processig(SMenuState *TempState);
void Menu_UP_Processig(SMenuState *TempState);
void Menu_DOWN_Processig(SMenuState *TempState);
void Menu_ENTR_Processig(SMenuState *TempState);
void Menu_ESC_Processig(SMenuState *TempState);
void Control_UP_Processig(SMenuState *TempState);
void Control_DOWN_Processig(SMenuState *TempState);
void Control_ENTR_Processig(SMenuState *TempState);
void Control_ESC_Processig(SMenuState *TempState);

#endif
