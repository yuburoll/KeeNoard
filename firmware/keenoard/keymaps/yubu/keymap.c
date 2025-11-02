#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_leftboard(
        LALT_T(KC_Q),       KC_W,           KC_E,           KC_R,           KC_T,                                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_SCLN, 
        LSFT_T(KC_A),       LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                                       KC_H,           RSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   KC_P, 
        LCTL_T(KC_Z),       KC_X,           KC_C,           KC_V,           KC_B,         LGUI_T(KC_Y), LGUI_T(KC_B),   KC_N,           KC_M,           RALT_T(KC_COMM),RCTL_T(KC_DOT), RSFT_T(KC_SLSH), 
                                            KC_CAPS,        LT(6,KC_ESC),   LT(4,KC_SPC), LT(5,KC_TAB), LT(2,KC_ENT),   LT(3,KC_BSPC),  LT(1,KC_DEL),   KC_RALT),
    [1] = LAYOUT_leftboard(
        KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCR,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, 
        KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCRL,                                           KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_NO, 
        KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_BRK,         KC_NO,          KC_LGUI,         KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO, 
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    [2] = LAYOUT_leftboard(
        S(KC_LBRC),     S(KC_7),         S(KC_8),        S(KC_9),      S(KC_RBRC),                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, 
        S(KC_QUOT),     S(KC_4),         S(KC_5),        S(KC_6),      S(KC_EQL),                                          KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_NO, 
        S(KC_GRV),      S(KC_1),         S(KC_2),        S(KC_3),      S(KC_BSLS),      KC_NO,          KC_LGUI,          KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO, 
                                        KC_TRNS,        S(KC_9),       S(KC_0),         S(KC_MINS),     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    [3] = LAYOUT_leftboard(
        KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, 
        KC_QUOT,        KC_4,           KC_5,           KC_6,           KC_EQL,                                           KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_NO,  
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_NO,          KC_LGUI,         KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO, 
                                        KC_TRNS,        KC_DOT,        KC_0,            KC_MINS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    [4] = LAYOUT_leftboard(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          MS_WHLL,          MS_UP,          MS_WHLR,          KC_NO, 
        KC_NO,          KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,                                          KC_PSCR,        MS_LEFT,        MS_DOWN,        MS_RGHT,        KC_NO, 
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LGUI,        KC_NO,          C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        C(KC_Y), 
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_BTN2,        MS_BTN1,        MS_BTN3,        KC_TRNS),
    [5] = LAYOUT_leftboard(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_BRK, 
        KC_NO,          KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,                                          KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_INS, 
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LGUI,        KC_NO,          C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        C(KC_Y), 
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    [6] = LAYOUT_leftboard(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, 
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          NK_TOGG,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, 
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_RBT,         QK_BOOT,         KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO, 
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_J):
            return true;
        case LSFT_T(KC_F):
            return true;
        case LT(2,KC_ENT):
            return true;
        case LT(3,KC_BSPC):
            return true;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_J):
            return QUICK_TAP_TERM - 120;
        case LSFT_T(KC_F):
            return QUICK_TAP_TERM - 120;
        default:
            return QUICK_TAP_TERM;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [3] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [4] = { ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [5] = { ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [6] = { ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
};
#endif

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C