#pragma once

#define XSTR(V...) #V

#if DISPLAY_TYPE == DISPLAY_LCD
#define HAL_HID_PATH(PATH) XSTR(PATH/HID/LCDKeypadShield/LCDKeypadShield.hpp)
#define DISPLAY(NAME, MENU) LCDKeypadShield NAME(menu)
#endif