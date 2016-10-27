#include "stdint.h"
#include "string.h"
#include "MenuDriverComon.h"
#include "TextBox.h"

uint8_t myString_0[]="qwe";
const uint8_t myString_1[]="qwe";

void TextBoxSetText(void *item, uint8_t *newText)
{
	while(GetWidgetAccess(&((TextBox*)item)->Position) == WIDGETSTATE_BUSY){};
	((TextBox*)item)->CurrentVal = newText;
	((TextBox*)item)->Position.fState = WIDGETSTATE_FREE;
}


void TextBoxGetText(void *item, uint8_t * newText)
{

}
