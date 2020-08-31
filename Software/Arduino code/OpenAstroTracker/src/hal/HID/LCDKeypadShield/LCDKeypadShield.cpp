#include "LCDKeypadShield.hpp"

#include <log4arduino.h>

LCDKeypadShield::LCDKeypadShield(Menu &menu) : HID(menu), lcd(8, 9, 4, 5, 6, 7) {}

void LCDKeypadShield::update() {
    
}