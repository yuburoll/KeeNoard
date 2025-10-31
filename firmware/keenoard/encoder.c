#include "encoder.h"
#include "action.h"
#include "quantum.h"
#include "timer.h"

#define COL_SHIFTER ((uint16_t)1)

#define ENCODER_0_ROW 3
#define ENCODER_0_COL_A 5
#define ENCODER_0_COL_B 3

#define ENCODER_1_ROW 7
#define ENCODER_1_COL_A 9
#define ENCODER_1_COL_B 11

__attribute__((weak)) void encoder_init(void) {}

__attribute__((weak)) bool encoder_queue_event(uint8_t index, bool clockwise) {
    return false;
}
__attribute__((weak)) bool encoder_dequeue_event(uint8_t *index, bool *clockwise) {
    return false;
}

static bool col0PressedAB = false;
static bool col1PressedAB = false;
static fast_timer_t last_encoding_time = 0;
static const fast_timer_t ENCODER_DEBOUNCE = 50;

void custom_encoder_update_kb(uint8_t index, bool clockwise) {

    switch (index) {
        case 0:
            if (clockwise) {
                #if defined(MOUSEKEY_ENABLE)
                    tap_code16(QK_MOUSE_WHEEL_UP);
                #elif defined(EXTRAKEY_ENABLE)
                    tap_code(KC_VOLU);
                #else
                    tap_code(KC_PGDN);
                #endif
            } else {
                #if defined(MOUSEKEY_ENABLE)
                    tap_code16(QK_MOUSE_WHEEL_DOWN);
                #elif defined(EXTRAKEY_ENABLE)
                    tap_code(KC_VOLD);
                #else
                    tap_code(KC_PGUP);
                #endif
            }
            break;
        case 1:
            if (clockwise) {
                #if defined(MOUSEKEY_ENABLE)
                    tap_code16(QK_MOUSE_WHEEL_LEFT);
                #elif defined(EXTRAKEY_ENABLE)
                    tap_code(KC_MNXT);
                #else
                    tap_code(KC_RIGHT);
                #endif
            } else {
                #if defined(MOUSEKEY_ENABLE)
                    tap_code16(QK_MOUSE_WHEEL_RIGHT);
                #elif defined(EXTRAKEY_ENABLE)
                    tap_code(KC_MPRV);
                #else
                    tap_code(KC_LEFT);
                #endif
            }
            break;
    }
}

// do action when turned
void turned(uint8_t index, bool clockwise) {
    if (TIMER_DIFF_FAST(timer_read_fast(), last_encoding_time) >= ENCODER_DEBOUNCE) {
        last_encoding_time = timer_read_fast();
    } else {
        return;
    }

    #ifdef ENCODER_MAP_ENABLE
        action_exec(clockwise ? MAKE_ENCODER_CW_EVENT(index, true) : MAKE_ENCODER_CCW_EVENT(index, true));
        action_exec(clockwise ? MAKE_ENCODER_CW_EVENT(index, false) : MAKE_ENCODER_CCW_EVENT(index, false));
    #else
        custom_encoder_update_kb(index, clockwise);
    #endif
}

void custom_encoder_action(matrix_row_t current_matrix[]) {
    matrix_row_t encoder_row;
    bool colCheckA;
    bool colCheckB;

    // ENCODER_0 check matrix
    encoder_row = current_matrix[ENCODER_0_ROW];
    colCheckA = encoder_row & (COL_SHIFTER << ENCODER_0_COL_A);
    colCheckB = encoder_row & (COL_SHIFTER << ENCODER_0_COL_B);

    if (colCheckA && colCheckB) {
        col0PressedAB = true;
    } else if (colCheckA) {
        if (col0PressedAB) {
            col0PressedAB = false;
            turned(0, true);
        }
    } else if (colCheckB) {
        if (col0PressedAB) {
            col0PressedAB = false;
            turned(0, false);
        }
    }

    // ENCODER_0 flush encoder point
    encoder_row &= ~(COL_SHIFTER << ENCODER_0_COL_A);
    encoder_row &= ~(COL_SHIFTER << ENCODER_0_COL_B);

    // ENCODER_1 check matrix
    encoder_row = current_matrix[ENCODER_1_ROW];
    colCheckA = encoder_row & (COL_SHIFTER << ENCODER_1_COL_A);
    colCheckB = encoder_row & (COL_SHIFTER << ENCODER_1_COL_B);

    if (colCheckA && colCheckB) {
        col1PressedAB = true;
    } else if (colCheckA) {
        if (col1PressedAB) {
            col1PressedAB = false;
            turned(1, true);
        }
    } else if (colCheckB) {
        if (col1PressedAB) {
            col1PressedAB = false;
            turned(1, false);
        }
    }

    // ENCODER_1 flush encoder point
    encoder_row &= ~(COL_SHIFTER << ENCODER_1_COL_A);
    encoder_row &= ~(COL_SHIFTER << ENCODER_1_COL_B);
}
