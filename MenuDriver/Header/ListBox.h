#ifndef LISTBOX_H_
#define LISTBOX_H_
#include "stdint.h"
#include "menudrivercomon.h"




// Pointer description of ListBox callback function. This function call when
// changed current list index.
typedef void (*UserListBoxKeyPressCallback)(const void* item, uint8_t currentIndex, KEYBOARD_STATE key);

// ----Prototype of List example--------------
typedef struct{
	TypWidgetPropertys   Position;
    uint8_t        CurrentIndex;
    const uint8_t  ListSize;      // number item in ListBox
    const uint8_t  **ListItems;
    UserListBoxKeyPressCallback userListBoxKeyPressCallback;
}ListBox;

//----------List items macros definition-------------
#define ADDNEWLISTITEM(NAME,...) const uint8_t *NAME[]=__VA_ARGS__;

//-----------Macros for create new ListBox example------
#define ADDNEWLISTBOX(NAME,LIST,POS_ROW,POS_COLUMN,LENGTH) static ListBox NAME={\
																	  .Position.row=POS_ROW,\
																	  .Position.clumn=POS_COLUMN,\
																	  .Position.length=LENGTH,\
																	  .Position.type=TYPELISTBOX,\
																	  .Position.widgetCallback=&ListBoxCallback,\
																	  .userListBoxKeyPressCallback = NULL,\
																	  .CurrentIndex = 0,\
																	  .ListSize=sizeof(LIST)/sizeof(LIST[0]),\
                                                                      .ListItems=LIST\
                                                                  };


void ListBoxCallback(const void* item, KEYBOARD_STATE key);
void ListBoxSetCallback(void *item,const UserListBoxKeyPressCallback function);
uint8_t ListBoxGetIndex(void *item);

#endif // LISTBOX_H
