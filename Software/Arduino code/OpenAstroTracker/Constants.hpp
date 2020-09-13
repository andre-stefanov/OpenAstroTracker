#pragma once

/*
* This file contains constants that should not be changed.
*/

// Supported display types
#define DISPLAY_NONE            0
#define DISPLAY_LCD1602_KEYPAD  1
#define DISPLAY_TFT_ILI9341     2

// Supported stepper models, do not modify these values.
#define STEPPER_TYPE_28BYJ48  0
#define STEPPER_TYPE_NEMA17   1

// Supported stepper driver models, do not modify these values.
#define DRIVER_TYPE_ULN2003              0
#define DRIVER_TYPE_GENERIC              1
#define DRIVER_TYPE_TMC2209_STANDALONE   2
#define DRIVER_TYPE_TMC2209_UART         3

