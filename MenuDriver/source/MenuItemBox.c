#include "MenuItemBox.h"


void MenuItemBoxAddUpItem(void *item, void *upItem){
	((MenuItem*)item)->Up=upItem;
}

void MenuItemBoxAddDownItem(void *item, void *downItem){
	((MenuItem*)item)->Down=downItem;
}

void MenuItemBoxAddText(void *item, void *leftItem){

}
