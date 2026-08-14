// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define LAYOUT( \
    k00, k01, k02, \
    k10, k11, k12  \
) \
{ \
    { k00, k01, k02 }, \
    { k10, k11, k12 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_P7, KC_P8, KC_P9,
        KC_P4, KC_P5, KC_P6
    )

};
