#include "stdint.h"
#include "string.h"
#include "MenuDriverComon.h"
#include "listBox.h"


/*!
 * \brief ListBoxCallback call if focus is pointed on listbox widget and user press key
 * \param  item pointer processing to widget
 * \param  key press key
 */
void ListBoxCallback(const void* item, KEYBOARD_STATE key){
	ListBox* currentListBox=(ListBox*)item;
// update current ListBox item index
	switch(key)
	{
		case KEY_UP:
			currentListBox->CurrentIndex++;
			if(currentListBox->CurrentIndex >= currentListBox->ListSize)
			{
				currentListBox->CurrentIndex = 0;
			}
			break;
		case KEY_DOWN:
			currentListBox->CurrentIndex++;
			if(currentListBox->CurrentIndex == 0)
			{
				currentListBox->CurrentIndex = currentListBox->ListSize;
			}
			else
			currentListBox->CurrentIndex--;
			break;
		case KEY_ENTR: break;
		case KEY_ESC: break;
		default: break;
	}
	//Call user Callback
	if(((ListBox*)item)->userListBoxKeyPressCallback != NULL)
	{
		((ListBox*)item)->userListBoxKeyPressCallback(item, ((ListBox*)item)->CurrentIndex, key);
	}
}

/*!
 * \brief ListBoxSetCallback set new userListBoxKeyPressCallback function
 * \param  item     Listbox iyem
 * \param  function Callback function
 */
void ListBoxSetCallback(void *item,const UserListBoxKeyPressCallback function){
	((ListBox*)item)->userListBoxKeyPressCallback=function;
}


/*!
 * \brief ListBoxGetIndex return current Listbox index
 * \param  item     Listbox iyem
 */
uint8_t ListBoxGetIndex(void *item){
	uint8_t current_index;
	//wait order for using control
	while(GetWidgetAccess(&((ListBox*)item)->Position) == WIDGETSTATE_BUSY){};
	current_index=((ListBox*)item)->CurrentIndex;
	((ListBox*)item)->Position.fState = WIDGETSTATE_FREE;
	return current_index;
}

