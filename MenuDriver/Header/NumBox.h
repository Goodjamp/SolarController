#ifndef NUMBOX_H_
#define NUMBOX_H_
#include "stdint.h"
#include "menudrivercomon.h"

void NumBoxCallback(void* item, KEYBOARD_STATE key);
void userNumBoxNumChangCallbak(void* item);

// Pointer description of ListBox callback function. This function call when
// changed current list index.
typedef void (*UserNumBoxNumChangCallbak)(void* item, float *currentVal);

// ----Prototype of Num Box example--------------
typedef struct{
	TypWidgetPropertys   Position;
    float          Step;
    float          MaxVal;
    float          MinVal;
    float          CurrentVal;
    UserNumBoxNumChangCallbak userNumBoxNumChangCallbak;
}NumBox;



//-----------Macros for create new NumBox example------
#define ADDNEWNUMBOX(NAME,MIN,MAX,STEP,POS_ROW,POS_COLUMN,LENGTH) static NumBox NAME={\
																	     .Position.row=POS_ROW,\
																	     .Position.clumn=POS_COLUMN,\
																	     .Position.length=LENGTH,\
																	     .Position.type=TYPENUMBOX,\
																	     .Position.widgetCallback=&NumBoxCallback,\
																	     .userNumBoxNumChangCallbak=NULL,\
																	     .CurrentVal=MIN, \
																	     .MaxVal=MAX,\
																	     .MinVal=MIN,\
																	     .Step=STEP\
                                                                         };



#endif // NUMBOX_H_
