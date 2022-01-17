// Copyright 2022 Ryan Nordeen (@Ryan Nordeen)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

/*
Key Codes:
https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

TLDR;
_______ : Transparent
XXXXXXX : No operation (No Op)
RESET   : Reset into bootloader
KC_LCMD : Left GUI (Windows/Command/Meta Key)

 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W, MO(_FN),
        KC_A,    KC_S, KC_D
    ),
    [_FN] = LAYOUT(
        KC_PGUP,  KC_PGDN,   _______,
        RESET,    KC_LCMD,   XXXXXXX
    )
};
