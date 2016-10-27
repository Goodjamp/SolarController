//element description
#include "stdio.h"
#include "string.h"
//Menu description
#include "ListBox.h"
#include "MenuItemBox.h"
#include "NumBox.h"
#include "TextBox.h"
#include "SolarControllerMenuDescription.h"

// Root menu screen
ADDNEWTEXTBOX(rootMenuTextName,rootMenuNameTextROW,rootMenuNameTextCOLUMN,strlen((const char*)rootMenuNameText));
ADDNEWTEXTBOX(rootMenuTextClock,rootMenuNameClockROW,rootMenuNameClockCOLUMN,strlen((const char*)rootMenuNameClock));
ADDNAMETEXTBOX(rootMenu, { &rootMenuTextName, &rootMenuTextClock} );
ADDNEWMENUITEM(rootMenu,rootMenuTextName_,{ &rootMenuTextName.Position, &rootMenuTextClock.Position});
