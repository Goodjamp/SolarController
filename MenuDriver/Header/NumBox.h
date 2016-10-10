#ifndef NUMBOX_H_
#define NUMBOX_H_
#include "stdint.h"
#include "menudrivercomon.h"


// ----Prototype of Num Box example--------------
typedef struct{
	TypWidgetPropertys   Position;
    float          Step;
    float          MaxVal;
    float          MinVal;
    float          CurrentVal;
}NumBox;



//-----------Macros for create new NumBox example------
#define ADDNEWNUMBOX(NAME,MIN,MAX,STEP,POS_ROW,POS_COLUMN,LENGTH) static NumBox NAME={\
																	     .Position.row=POS_ROW,\
																	     .Position.clumn=POS_COLUMN,\
																	     .Position.length=LENGTH,\
																	     .Position.type=TYPENUMBOX,\
																	     .Position.widgetCallback=&NumBBoxCallback,\
																	     .CurrentVal=MIN, \
																	     .MaxVal=MAX,\
																	     .MinVal=MIN,\
																	     .Step=STEP\
                                                                         };

void NumBBoxCallback(void* item, KEYBOARD_STATE key);

#endif // NUMBOX_H_
