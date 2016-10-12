#include "stdint.h"
#include "string.h"
#include "listBox.h"
#include "MenuDriverComon.h"

//
void ListBoxCallback(void* item, KEYBOARD_STATE key){
	((ListBox*)item)->userListBoxChangeIndexCallback(item, ((ListBox*)item)->CurrentIndex);
}



uint8_t ListBoxGetIndex(ListBox *ListBoxState){
	return ListBoxState->CurrentIndex;
}

