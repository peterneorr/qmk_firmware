

#include QMK_KEYBOARD_H

    /*
    * Al-ish :  kinda like an Alice keyboard
    *     ┌───┐  ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    *     │Esc│  │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │         │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
    *    ┌┴──┬┘ ┌┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    *    │Fn1│  │ Tab │ Q │ W │ E │ R │ T │          │ Y │ U │ I │ O │ P │ [ │ ] │   \ │
    *   ┌┴──┬┘ ┌┴─────┼───┼───┼───┼───┼───┤          └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┴┐
    *   │Fn2│  │ Caps │ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │ ' │   Enter │
    *  ┌┴──┬┘ ┌┴──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┬───┤
    *  │PUp│  │ Shift  │ Z │ X │ C │ V │ B │        │ B │ N │ M │ , │ . │ / │Shf│ ↑ │Prt│
    *  ├───┤  ├─────┬──┴──┬┴───┴┬──┴───┴──┬┴──┐     ├───┴───┴─┬─┴───┼───┼───┼───┼───┼───┤
    *  │PDn│  │ Ctl │Super│ Alt │         │Mod│     │         │ Alt │Mod│Lyr│ ← │ ↓ │ → │
    *  └───┘  └─────┘─────└─────┴─────────┴───┘     └─────────┴─────┴───┴───┴───┴───┴───┘
    *
    *  Physical wiring matrix - 5 rows 16 columns - 73 keys
    *
    *        ┌───┐  ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * R0:    │ 0 │  │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │         │ 9 │ 10│ 11│ 12│ 13│ 14│     15│  -> 15 keys on Row 0
    *       ┌┴──┬┘ ┌┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * R1:   │ 0 │  │  1  │ 2 │ 3 │ 4 │ 5 │ 6 │          │ 8 │ 9 │ 10│ 11│ 12│ 13│ 14│   15│  -> 15 keys on Row 1
    *      ┌┴──┬┘ ┌┴─────┼───┼───┼───┼───┼───┤          └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┴┐
    * R2:  │ 0 │  │  1   │ 2 │ 3 │ 4 │ 5 │ 6 │           │ 8 │ 9 │ 10│ 11│ 12│ 13│  14     │ -> 14 keys on Row 2
    *     ┌┴──┬┘ ┌┴──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┬───┤
    * R3: │ 0 │  │   1    │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 10│ 11│ 12│ 13│ 14│ 15│ -> 16 keys on Row 3
    *     ├───┤  ├─────┬──┴──┬┴───┴┬──┴───┴──┬┴──┐     ├───┴───┴─┬─┴───┼───┼───┼───┼───┼───┤
    * R4: │ 0 │  │  1  │  2  │  3  │ 4       │ 6 │     │     8   │ 10  │ 11│ 12│ 13│ 14│ 15│ -> 13 keys on Row 4
    *     └───┘  └─────┘─────└─────┴─────────┴───┘     └─────────┴─────┴───┴───┴───┴───┴───┘
    *
    * NOTE that some keys are not present in the physical matrix:
    * (R0,C8), (R1,C7), (R2,C7), (R2,C15), (R4,C5), (R4,C7) (R4,C9)
    */

    // this macro defines a reusable way to list key codes, and always assigns missing keys to KC_NO
    #define LAYOUT_alish( \
        K00, K01, K02, K03, K04, K05, K06,  K07,      K09, K0A, K0B, K0C, K0D, K0E, K0F, \
        K10, K11, K12, K13, K14, K15, K16,       K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, \
        K20, K21, K22, K23, K24, K25, K26,       K28, K29, K2A, K2B, K2C, K2D, K2E,      \
        K30, K31, K32, K33, K34, K35, K36,  K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, \
        K40, K41, K42, K43, K44,      K46,       K48,      K4A, K4B, K4C, K4D, K4E, K4F \
    ) { \
        { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO, K09,   K0A,   K0B,   K0C,  K0D,   K0E,   K0F   }, \
        { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C,  K1D,   K1E,   K1F   }, \
        { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C,  K2D,   K2E,   KC_NO }, \
        { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,  K3D,   K3E,   K3F   },  \
        { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   K4B,   K4C,  K4D,   K4E,   K4F   }  \
    }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_alish(
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, //<-- 15 Keys on Row 0
        KC_NO,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, //<-- 15 Keys on Row 1
        KC_NO,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  //<-- 14 Keys on Row 2
        KC_PGUP, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, KC_PSCR, //<-- 16 Keys on Row 3
        KC_PGDN, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_NO,                        KC_SPC,                    KC_RALT, KC_APP,  KC_RCTL, KC_LEFT,KC_DOWN,KC_RIGHT //<-- 13 Keys on Row 4
    )
};
