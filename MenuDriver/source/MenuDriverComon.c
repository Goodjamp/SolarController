#include "MenuDriverComon.h"

//
void DefaultCallback(void* item){
	return;
}



WIDGETTYPE GetWidgetAccess(TypWidgetPropertys* item)
{
	while(item->fState==WIDGETSTATE_BUSY)
	{
		// TODO add unblocking algoritm (counter or timer)
	}
	return item->fState;
}
