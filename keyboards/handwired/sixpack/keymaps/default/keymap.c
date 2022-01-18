// Copyright 2022 Ryan Nordeen (@Ryan Nordeen)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MACROS
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

/*
Macros
*/
#define _OPEN_APP( app_name )\
    do{\
    SEND_STRING( SS_TAP( X_LGUI ) SS_DELAY( 500 ) app_name  SS_DELAY( 500 ) SS_TAP( X_ENT ) ); \
    } while ( 0 )

enum custome_keycodes {
    STEAM=SAFE_RANGE, // SAFE_RANGE prevents it from using a clashing keycode
    NAUTILUS,
    FIREFOX,
    VLC,
};

bool process_record_user( uint16_t keycode, keyrecord_t *record ) {
    switch( keycode ){
    case STEAM:
        if ( record->event.pressed ) {
            _OPEN_APP( "steam" );
        } else {
            // when keycode is released
        }
        break;
    case NAUTILUS:
        if ( record->event.pressed ) {
            _OPEN_APP( "nautilus" );
        } else {
            // when released
        }
        break;
    case FIREFOX:
        if ( record->event.pressed ) {
            _OPEN_APP( "firefox" );
        } else {
            // when released
        }
        break;
    case VLC:
        if ( record->event.pressed ) {
            _OPEN_APP( "vlc" );
        } else {
            // when released
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        MO(_MACROS), KC_UP,   MO(_FN),
        KC_LEFT,     KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT(
        KC_TILDE, KC_INSERT, _______,
        RESET,    KC_LCMD,   XXXXXXX
    ),
    [_MACROS] = LAYOUT(
         _______,  STEAM,     NAUTILUS,
         FIREFOX,  VLC,       XXXXXXX
    )

};
