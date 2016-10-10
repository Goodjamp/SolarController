#ifndef MENUITEMBBOX_H_
#define MENUITEMBBOX_H_
#include "stdint.h"
#include "MenuItemBox.h"
#include "MenuDriverComon.h"
#include "TextBox.h"


// Descried group one type widget
typedef struct{
	WIDGETTYPE Type;
	uint8_t    Size;     // number widget inside group
	void       **Widget;  // pointer on first widget inside group
}WidgetGroup;

typedef struct{
	void *Up;    	//pointer on UP menu item
	void *Down;  	//pointer on DOWN menu item
	void *Left;  	//pointer on LEFT menu item
	void *Right; 	//pointer on RIGYT menu item
	TextBox** ItemName; // Menu item name ( show before )
	uint8_t Size;	// Number of widgets inside current menu
	TypWidgetPropertys **Memders;  // List of widgets
	uint8_t CursorPosition; // Position cursor inside current menu
}MenuItem;

//Create group widget from input
#define WIDGETGROUPTOMENU(NAME,WIDGETGROUP)  MenuItem NAME={ \
													.Up=(void*)0,\
													.Down=(void*)0,\
											  		.Size=sizeof(WIDGETGROUP)/sizeof(WIDGETGROUP[0]),\
												    .Memders=WIDGETGROUP\
													};



// Combine all list widget inside menu in "NAME" WidgetGroup structure.
#define MENUITEM(NAME,...) static TypWidgetPropertys *NAME##Group[]=__VA_ARGS__; \
						   WIDGETGROUPTOMENU(NAME,NAME##Group)


void InitMenuItem(MenuItem *NewMenuItem);

#endif
