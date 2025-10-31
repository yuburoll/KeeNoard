/*
keymappable encoder
referenced by Thomas Hakuland's code https://github.com/tompi/qmk_firmware/blob/cheapinov2/keyboards/cheapino/encoder.c

*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "util.h"
#include "matrix.h"

#ifdef ENCODER_ENABLE

    #ifndef NUM_ENCODERS
        #define NUM_ENCODERS 2
    #endif
    #define ENCODER_RESOLUTION 4
    #define NUM_ENCODERS_LEFT NUM_ENCODERS
    #define NUM_ENCODERS_RIGHT 0
    #define NUM_ENCODERS_MAX_PER_SIDE MAX(NUM_ENCODERS_LEFT, NUM_ENCODERS_RIGHT)
    
    #ifdef ENCODER_MAP_ENABLE
        #define MAKE_ENCODER_CW_EVENT(enc_id, press) MAKE_EVENT(KEYLOC_ENCODER_CW, (enc_id), (press), ENCODER_CW_EVENT)
        #define MAKE_ENCODER_CCW_EVENT(enc_id, press) MAKE_EVENT(KEYLOC_ENCODER_CCW, (enc_id), (press), ENCODER_CCW_EVENT)
        #define NUM_DIRECTIONS 2
        extern const uint16_t encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS];
    #endif
    
    __attribute__((weak)) void encoder_init(void);
    __attribute__((weak)) bool encoder_queue_event(uint8_t index, bool clockwise);
    __attribute__((weak)) bool encoder_dequeue_event(uint8_t *index, bool *clockwise);

    void custom_encoder_action(matrix_row_t current_matrix[]);

#endif