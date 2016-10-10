#include "stdint.h"
#include "string.h"
#include "listBox.h"
#include "MenuDriverComon.h"


void ListBoxCallback(void* item, KEYBOARD_STATE key){

}

void UserCallbackFunction(void* item)
{
	if(GetWidgetAccess==WIDGETSTATE_BUSY)
	{
		return WIDGETSTATE_BUSY;
	}
	// Call user callback function
	((ListBox*)item)->userListboxIndexCallbak(item, ((ListBox*)item)->CurrentIndex);
}


uint8_t ListBoxGetIndex(ListBox *ListBoxState){
	return ListBoxState->CurrentIndex;
}

