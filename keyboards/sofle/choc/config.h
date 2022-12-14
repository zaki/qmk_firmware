#pragma once

#define SOFLE_CHOC 1

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 100
#define DEBOUNCE 5

/* encoder support */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10

/* communication between sides */
#define USE_SERIAL
//#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2

#ifdef RGB_MATRIX_ENABLE
//#define RGB_DI_PIN D3
#define WS2812_DI_PIN D3
#define RGBLED_NUM 29
#define RGB_MATRIX_LED_COUNT 58 //RGBLED_NUM
#define DRIVER_LED_TOTAL 58
#define RGB_MATRIX_SPLIT { 29, 29 }
#endif
