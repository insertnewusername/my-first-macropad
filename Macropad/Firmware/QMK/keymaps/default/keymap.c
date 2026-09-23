// Copyright 2026 Yu Chen Liu
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum custom_keycodes {
    TYPE_5901 = QK_USER,
    SCREENSHOT,
    WORKSPACE_LEFT,
    CLOSE_WINDOW,
    SAVE_DOCUMENT,
    OPEN_TAB,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TYPE_5901, OPEN_TAB, SAVE_DOCUMENT,
        SCREENSHOT, WORKSPACE_LEFT, CLOSE_WINDOW
    )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case TYPE_5901:
            SEND_STRING("5901");
            return false;
        case OPEN_TAB:
            tap_code16(LCTL(KC_W));
            wait_ms(50);
            tap_code16(LCTL(KC_T));
            return false;
        case SAVE_DOCUMENT:
            tap_code16(LCTL(KC_S));
            return false;
        case SCREENSHOT:
            tap_code16(LGUI(LSFT(KC_S)));
            return false;
        case WORKSPACE_LEFT:
            tap_code16(LCTL(LGUI(KC_LEFT)));
            return false;
        case CLOSE_WINDOW:
            tap_code16(LALT(KC_F4));
            return false;
    }
    return true;
}
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
    return true;
}
void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(GP8);
}
void matrix_scan_user(void) {
    static bool encoder_pressed;
    static uint16_t encoder_press_timer;
    const bool pressed = !gpio_read_pin(GP8);
    if (pressed && !encoder_pressed && timer_elapsed(encoder_press_timer) > 20) {
        tap_code(KC_MUTE);
        encoder_press_timer = timer_read();
    }
    encoder_pressed = pressed;
}
