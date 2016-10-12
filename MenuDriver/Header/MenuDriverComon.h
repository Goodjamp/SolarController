#ifndef MENUDRIVERCOMON_H_
#define MENUDRIVERCOMON_H_
#include "stdint.h"

/*!
 *  \brief enum KEYBOARD_STATE possibility state of menu
 */
typedef enum{
	KEY_UP=0,
	KEY_DOWN,
	KEY_ENTR,
	KEY_ESC,
	KEY_NON
}KEYBOARD_STATE;

/*!
 *  \brief enum WIDGETSTATE flag indicate current widget  statea
 */
typedef enum{
	WIDGETSTATE_FREE,
	WIDGETSTATE_BUSY
}WIDGETSTATE;


//! \brief Type of user widget
typedef enum{
	TYPELISTBOX=0,
	TYPENUMBOX=1,
	TYPETEXTBOX=2,
	TYPESTATICTEXTBOX=3,
}WIDGETTYPE;

#define ISCURSORWIDGET(TYPE) ((TYPE==TYPELISTBOX)||(TYPE==TYPENUMBOX)||\
							  (TYPE==TYPETEXTBOX))




//Pointer description of callback function
typedef void (*WidgetCallback)(void* item, KEYBOARD_STATE key);
//Pointer description of callback function
typedef void (*UserCallback)(void* item, void *data);

//----Position descriptor---------
typedef struct{
    uint8_t row;
    uint8_t clumn;
    uint8_t length;
    uint8_t *text;
    WIDGETTYPE type;
    volatile WIDGETSTATE fState;
    WidgetCallback widgetCallback;
}TypWidgetPropertys;


void DefaultCallback(void* item);
WIDGETTYPE GetWidgetAccess(TypWidgetPropertys* item);
void UserKeyPressCallBack(void* item, KEYBOARD_STATE key);

#endif // MENUDRIVERCOMON_H
