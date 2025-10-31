#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_leftboard(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P, 
        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                               KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN, 
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       QK_BOOT,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH, 
                                KC_NO,      KC_ESC,     KC_SPC,     KC_TAB,     KC_ENT,     KC_BSPC,    KC_DEL,     KC_NO)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)  },
};

#endif

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

