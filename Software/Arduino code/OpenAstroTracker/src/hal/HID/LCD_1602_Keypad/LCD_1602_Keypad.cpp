#include "../../../inc/Config.hpp"

#if DISPLAY_TYPE == DISPLAY_LCD1602_KEYPAD

#include "LCD_1602_Keypad.hpp"
#include <log4arduino.h>
#include <LinkedList.h>

LCD_1602_Keypad::LCD_1602_Keypad(Menu *menu) : HID(menu), lcd(8, 9, 4, 5, 6, 7)
{
    if (menu != NULL)
    {
        SubMenu *rootMenu = (SubMenu *)menu->items;
        int count = rootMenu->size();
        if (count > 0)
        {
            current = rootMenu->get(0);
            next = rootMenu->get(1 % count);
            prev = rootMenu->get((count - 1) % count);
        }
        else
        {
            LOG("Menu does not have any items");
            current = NULL;
            next = NULL;
            prev = NULL;
        }
    }
}

void LCD_1602_Keypad::loop()
{
    // update display
    lcd.setCursor(0, 0);
    lcd.print(current->getTitle());
    
    // TODO: handle input
}

#endif