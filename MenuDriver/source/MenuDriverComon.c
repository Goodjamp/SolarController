#include "MenuDriverComon.h"

/*!
 * \brief DefaultCallback
 */
void DefaultCallback(void* item){
	return;
}



/*!
 * \brief GetWidgetAccess check is widget free and take it to modify
 * \param  item pointer processing to widget
 */
WIDGETTYPE GetWidgetAccess(TypWidgetPropertys* item)
{
	// If widget is free - take it to modify
	vTaskSuspendAll();
	if(item->fState==WIDGETSTATE_FREE)
	{
		item->fState=WIDGETSTATE_BUSY;
	}
	xTaskResumeAll();
	return item->fState;

}



/*!
 * \brief ListBoxCallback call widget KEY_PRESS callback function with accses check
 * \param  item pointer processing to widget
 * \param  key user press key
 */
void UserKeyPressCallBack(void* item, KEYBOARD_STATE key){
	//check is widget free
	if(GetWidgetAccess(item)==WIDGETSTATE_BUSY)
	{
		return WIDGETSTATE_BUSY;
	}
	// Call function
	((TypWidgetPropertys*)item)->widgetCallback(item, key);

	((TypWidgetPropertys*)item)->fState=WIDGETSTATE_FREE;
}


