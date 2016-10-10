#ifndef STATICTEXTBOX_H_
#define STATICTEXTBOX_H_
#include "stdint.h"
#include "menudrivercomon.h"


// ----Prototype of StaticTextBox example--------------
typedef struct{
	TypWidgetPropertys    Position;
    const uint8_t*  Text;
}StaticTextBox;

//-----------Macros for create new Static Text Box example------
#define ADDNEWSTATICTEXTBOX(NAME,TEXT,POS_ROW,POS_COLUMN,LENGTH) StaticTextBox NAME={\
																	  .Position.row=POS_ROW,\
																	  .Position.clumn=POS_COLUMN,\
																	  .Position.length=LENGTH,\
																	  .Position.type=TYPESTATICTEXTBOX,\
        															  .Position.widgetCallback=&ListBoxCallback,\
                                                                      .Text=TEXT\
                                                                  };


void StaticTextBoxCallback(void* item, KEYBOARD_STATE key);

#endif // STATICTEXTBOX_H_
