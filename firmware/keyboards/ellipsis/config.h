#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xE115
#define DEVICE_VER      0x0001
#define MANUFACTURER    Cameron Sun
#define PRODUCT         Ellipsis
#define DESCRIPTION     q.m.k. keyboard firmware for Ellipsis

#define MATRIX_ROWS 5
#define MATRIX_COLS 18

// Change this to how you wired your keyboard
// COLS: Left to right, ROWS: Top to bottom
#define MATRIX_ROW_PINS { B5, B6, F7, F6, F5 }
#define MATRIX_COL_PINS { B3, B2, B1, B0, F4, F1, F0, B7, D0, D1, D5, D4, D7, B4, C7, C6, D3, D2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#endif
