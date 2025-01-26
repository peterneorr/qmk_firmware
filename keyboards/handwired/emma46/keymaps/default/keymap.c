// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// constants for layers
#define _BASE 0



/* Physical Layout  
 13x4 matrix - 22 keys  on left side + 24 on right side = 46 keys
 Diagram of physical wiring of switch positions in the matrix
┌─────┐   ┌─────┬─────┬─────┬─────┬─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┐   
│ 0,0 │   │ 0,1 │ 0,2 │ 0,3 │ 0,4 │ 0,5 │  │ 0,7 │ 0,8 │ 0,9 │ 0,10│ 0,11│ 0,12│
├─────┤   └┬────┴┬────┴┬────┴┬────┴┬────┴┐ └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐
│ 1.1 │    │ 1,2 │ 1,3 │ 1,4 │ 1,4 │ 1,5 │  │ 1,7 │ 1,8 │ 1,9 │ 1,10│ 1,11│ 1,12│
├─────┤    └┬────┴┬────┴┬────┴┬────┴┬────┴┐ └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐  ┌─────┐
│ 2,0 │     │ 2,1 │ 2,2 │ 2,3 │ 2,4 │ 2,5 │  │ 2,6 │ 2.7 │ 2.8 │ 2.9 │ 2.10│ 2,11│  │ 2,12│
├─────┤     └─────┴─────┴┬────┴┬────┴┬────┴┐ ├─────┴─────┴┬────┴┬────┴─────┴──┬──┘──┼─────┼─────┐
│ 3,0 │                  │ 3,3 │ 3,4 │ 3,5 | | 3,6        | 3,8 |             | 3,10| 3,11| 3,12|   
└─────┘                  └─────┴─────┴─────┘ └────────────┴─────┘             └─────┴─────┴─────┘
 NOTE that some keys are not present in the physical matrix:
        (0,6), (1,6), (3,1), (3,2), (3,7), (3,9)
 
 */

 #define LAYOUT_emma46( \
    K00, K01, K02, K03, K04, K05,       K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,       K17, K18, K19, K1A, K1B, K1C, \
    K20, K21, K22, K23, K24, K25,  K26, K27, K28, K29, K2A, K2B, K2C, \
    K30,           K33, K34, K35,  K36,      K38,      K3A, K3B, K3C  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   KC_NO, K07,   K08,   K09,   K0A,   K0B,   K0C   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   KC_NO, K17,   K18,   K19,   K1A,   K1B,   K1C   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C   }, \
    { K30,   KC_NO, KC_NO, K33,   K34,   K35,   K36,   KC_NO, K38,   KC_NO, K3A,   K3B,   K3C   }  \
}

    // layouts array for 13x4 matrix
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_emma46(  
        KC_ESC,      KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_BSPC,  //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_TAB,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT, //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_PGUP,       KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,           KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_UP, //13 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_PGDN,                      KC_LCTL,KC_LALT, KC_ENT,        KC_SPC,         KC_RALT,                KC_LEFT,KC_DOWN, KC_RIGHT  //9 keys
//     └───────┘                   └───────┴───────┴───────┘       └───────────────┴───────┘               └──────┴───────┴────────┘        
    ) 
};
