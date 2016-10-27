#ifndef MENUITEMBBOX_H_
#define MENUITEMBBOX_H_
#include "stdint.h"
#include "MenuItemBox.h"
#include "MenuDriverComon.h"
#include "TextBox.h"

typedef struct{
	void *Up;    		  			//pointer on UP menu item
	void *Down;  		  			//pointer on DOWN menu item
	TextBox** ItemName;   			// Menu item name ( name of menu, could dynamically change)
	uint8_t ItemNameNumber; 		// Number of TextBox item in Name of Menu
	TypWidgetPropertys **Memders;  	// List of widgets
	uint8_t widgetsNumber;		  	// Number of widgets inside current menu
	uint8_t CursorPosition; 		// Position cursor inside current menu
}MenuItem;

// Combine all list widget inside menu in "NAME" WidgetGroup structure.
#define ADDNAMETEXTBOX(NAME, ... )	static TextBox *NAME##TextName_[] = __VA_ARGS__;


// Combine all list widget inside menu in "NAME" WidgetGroup structure.
#define ADDNEWMENUITEM(NAME, NAMETEXTBOX, ... )	static TypWidgetPropertys *NAME##Group[] = __VA_ARGS__; \
						   	   	   	   		WIDGETGROUPTOMENU(NAME, NAMETEXTBOX,NAME##Group)

//Create group widget from input
#define WIDGETGROUPTOMENU(NAME, NAMETEXTBOX, WIDGETGROUP)  MenuItem NAME={ \
													.Up=NULL,\
													.Down=NULL,\
											  		.widgetsNumber=sizeof(WIDGETGROUP)/sizeof(WIDGETGROUP[0]),\
												    .Memders=WIDGETGROUP,\
												    .ItemName = NAMETEXTBOX,\
												    .ItemNameNumber = sizeof(NAMETEXTBOX)/sizeof(NAMETEXTBOX[0]),\
													};

void InitMenuItem(MenuItem *NewMenuItem);
void MenuItemBoxAddUpItem(void *item, void *upItem);
void MenuItemBoxAddDownItem(void *item, void *downItem);

#endif
