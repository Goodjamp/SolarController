#include "NumBox.h"
#include "stdint.h"
#include "string.h"
#include "NumBox.h"
#include "MenuDriverComon.h"


void NumBoxCallback(void* item, KEYBOARD_STATE key){
	// Call user callback function
	((NumBox*)item)->userNumBoxNumChangCallbak(item, ((NumBox*)item)->CurrentVal);
}


