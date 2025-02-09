// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// constants for layers
#define _BASE 0
#define _DVRK 1
#define _MISC 2
#define _FUNC 3
#define _NAV 4



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

#define SFT_Z LSFT_T(KC_Z)          //shift when held, Z when tapped
#define SFT_SCLN LSFT_T(KC_SCLN)    //shift when held, ; when tapped  
#define SFT_SLSH RSFT_T(KC_SLSH)    //shift when held, / when tapped
#define F_PGUP LT(_FUNC,KC_PGUP)    //FUNC layer when held, PGUP when tapped

#define G_PGDN MT(MOD_LGUI,KC_PGDN) //GUI when held, PGDN when tapped
#define MSC_B LT(_MISC,KC_B)        //MISC layer when held, B when tapped
#define MSC_X LT(_MISC,KC_X)        //MISC layer when held, X when tapped
#define ____ KC_TRNS

//combo definitions - for switch default layer between BASE and Dvorak
const uint16_t PROGMEM to_dvorak1[] = {KC_ESC, KC_D, COMBO_END};
const uint16_t PROGMEM to_dvorak2[] = {KC_ESC, KC_E, COMBO_END};
const uint16_t PROGMEM to_qwerty1[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM to_qwerty2[] = {KC_ESC, KC_QUOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(to_dvorak1, PDF(_DVRK)),   // Press ESC then D to switch to Dvorak
    COMBO(to_dvorak2, PDF(_DVRK)),   // Press ESC then E to switch to Dvorak
    COMBO(to_qwerty1, PDF(_BASE)),   // Press ESC then Q to switch to Qwerty
    COMBO(to_qwerty2, PDF(_BASE))    // press ESC then ' to switch to Qwerty
};

    // layouts array for 13x4 matrix
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_emma46(  
        KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_BSPC,  //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_TAB,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT, //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        F_PGUP,      SFT_Z,  KC_X,   KC_C,   KC_V,   MSC_B,          MSC_B,  KC_N,   KC_M,  KC_COMM, KC_DOT,SFT_SLSH,        KC_UP, //13 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┘    
        G_PGDN,                    KC_LCTL,KC_LALT, KC_ENT,         KC_SPC,         KC_RALT,                        KC_LEFT,KC_DOWN, KC_RIGHT  //9 keys
//     └───────┘                   └───────┴───────┴───────┘       └───────────────┴───────┘                        └──────┴───────┴────────┘        
    ),
    [_DVRK] = LAYOUT_emma46(  //DVORAK layout
        KC_ESC,     KC_QUOT,KC_COMM,KC_DOT,  KC_P,   KC_Y,           KC_F,   KC_G,   KC_C,   KC_R,   KC_L,  KC_BSPC,  //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_TAB,      KC_A,   KC_O,   KC_E,   KC_U,   KC_I,           KC_D,   KC_H,   KC_T,   KC_N,   KC_S,  KC_MINS, //12 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        F_PGUP,    SFT_SCLN, KC_Q,   KC_J,   KC_K,   MSC_X,          MSC_X,  KC_B,   KC_M,  KC_W,    KC_V,  SFT_Z,           KC_UP, //13 keys
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┘    
        G_PGDN,                    KC_LCTL,KC_LALT, KC_ENT,         KC_SPC,         KC_RALT,                        KC_LEFT,KC_DOWN, KC_RIGHT  //9 keys
//     └───────┘                   └───────┴───────┴───────┘       └───────────────┴───────┘                        └──────┴───────┴────────┘        
    ),
    [_MISC] = LAYOUT_emma46(  // MISC layer - numbers, symbols, navigation
        KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_DEL,  
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
        KC_CAPS,    KC_EXLM, KC_AT, KC_HASH,KC_DLR, KC_PERC,        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS, 
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
         ____,      KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC, KC_EQL,        KC_LT,  KC_GT,  KC_LCBR,KC_RCBR,KC_MINS,KC_PIPE,        KC_INS, 
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┘    
         ____,                       ____,   ____,   ____,           ____,           ____,                         KC_HOME, KC_DEL, KC_END  
//    └───────┘                   └───────┴───────┴───────┘        └───────────────┴───────┘                        └──────┴───────┴────────┘        
    ),
    [_FUNC] = LAYOUT_emma46(  // FUNCTION layer - function keys, media keys
        QK_BOOT,    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
         ____,       ____,   ____,   ____,   ____,  KC_PSCR,         ____,   ____,   ____,   ____,   ____,   KC_F12, 
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘    
         ____,       ____,   ____,   ____,   ____,   KC_BRK,         ____,   ____,   ____,   ____,   ____,   ____,          KC_VOLU, 
//     └───────┘   └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┘    
         ____,                       ____,   ____,   ____,           ____,           ____,                           KC_MPRV,KC_VOLD,KC_MNXT  
//     └───────┘                   └───────┴───────┴───────┘       └───────────────┴───────┘                        └──────┴───────┴────────┘        
    )    
};
