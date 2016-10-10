// TextBox.h
#ifndef TEXT_BOX_H_
#define TEXT_BOX_H_

#include "stdint.h"
#include "menudrivercomon.h"


// ----Prototype of TextBox example--------------
typedef struct{
	TypWidgetPropertys   Position;
    uint8_t*       CurrentVal;
}TextBox;



//-----------Macros for create new TextBox example------
#define ADDNEWTEXTBOX(NAME,POS_ROW,POS_COLUMN,LENGTH) static TextBox NAME={\
																	     .Position.row=POS_ROW,\
																	     .Position.clumn=POS_COLUMN,\
																	     .Position.length=LENGTH,\
																	     .Position.type=TYPETEXTBOX,\
																	     .Position.widgetCallback=&TextBoxCallback,\
																	     .CurrentVal=" "\
                                                                         };


void TextBoxCallback(void* item, KEYBOARD_STATE key);

#endif
