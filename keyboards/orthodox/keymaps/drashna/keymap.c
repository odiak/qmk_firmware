/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _WORKMAN 3
#define _LOWER 8
#define _RAISE 9
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  WORKMAN,
  LOWER,
  RAISE,
  ADJUST,
  KC_MAKE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#ifdef RGBLIGHT_ENABLE
#define rgblight_set_blue        rgblight_sethsv (0xFF,  0xFF, 0xFF);
#define rgblight_set_red         rgblight_sethsv (0x00,  0xFF, 0xFF);
#define rgblight_set_green       rgblight_sethsv (0x78,  0xFF, 0xFF);
#define rgblight_set_orange      rgblight_sethsv (0x1E,  0xFF, 0xFF);
#define rgblight_set_teal        rgblight_sethsv (0xC3,  0xFF, 0xFF);
#define rgblight_set_magenta     rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_yellow      rgblight_sethsv (0x3C,  0xFF, 0xFF);
#define rgblight_set_purple      rgblight_sethsv (0x10E, 0xFF, 0xFF);
#endif


#ifdef TAP_DANCE_ENABLE
enum {
    TD_FLSH = 0,
};





// on the fourth tap, set the keyboard on flash state
// and set the underglow to red, because red == bad
void dance_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        rgblight_setrgb(0xff, 0x00, 0x00);
#endif
        reset_tap_dance(state);
        reset_keyboard();
    }
}



//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Once for Blue, Twice for Green, Thrice for Red, and four to flash
    [TD_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_flsh_finished, NULL),

};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_UP, XXXXXXX,  KC_DOWN,        KC_LEFT, XXXXXXX, KC_RIGHT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,    CTL_T(KC_Z), KC_X, KC_C,   KC_V,    KC_B,      LOWER, KC_SPACE, KC_BSPC,        KC_DEL,  KC_ENT,  RAISE,    KC_N,    KC_M,    KC_COMM, KC_DOT, CTL_T(KC_SLASH), KC_LGUI \
),

[_COLEMAK] = KEYMAP(\
  KC_ESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,      KC_UP, XXXXXXX,  KC_DOWN,        KC_LEFT, XXXXXXX, KC_RIGHT, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT,  CTL_T(KC_Z), KC_X, KC_C,   KC_V,    KC_B,      LOWER, KC_SPACE, KC_BSPC,        KC_DEL,  KC_ENT,  RAISE,    KC_K,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLASH), KC_LGUI \
),

[_DVORAK] = KEYMAP(\
    KC_ESC,   KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y,                                                                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
    KC_TAB,   KC_A,    KC_O,    KC_E,   KC_U,     KC_I,      KC_UP, XXXXXXX,  KC_DOWN,        KC_LEFT, XXXXXXX, KC_RIGHT, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
    KC_LSFT, CTL_T(KC_SCLN), KC_Q, KC_J, KC_K,    KC_X,      LOWER, KC_SPACE, KC_BSPC,        KC_DEL,  KC_ENT,  RAISE,    KC_B,    KC_M,    KC_W,    KC_V,    CTL_T(KC_Z), KC_LGUI \
),
[_WORKMAN] = KEYMAP(\
    KC_ESC,   KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y,                                                                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
    KC_TAB,   KC_A,    KC_O,    KC_E,   KC_U,     KC_I,      KC_UP, XXXXXXX,  KC_DOWN,        KC_LEFT, XXXXXXX, KC_RIGHT, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
    KC_LSFT, CTL_T(KC_SCLN), KC_Q, KC_J, KC_K,    KC_X,      LOWER, KC_SPACE, KC_BSPC,        KC_DEL,  KC_ENT,  RAISE,    KC_B,    KC_M,    KC_W,    KC_V,    CTL_T(KC_Z), KC_LGUI \
),

[_LOWER] = KEYMAP( \
  KC_TILD,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                                KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,   XXXXXXX, KC_F12,          _______, XXXXXXX, KC_RCTL, KC_F11,  KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  TD(TD_FLSH),KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,          _______, _______, _______, KC_F12,  KC_HOME,    KC_COMM,    KC_DOT,  KC_END,  _______ \
),

[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  XXXXXXX, KC_F12,           _______, XXXXXXX, _______, KC_F11,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,          _______, _______, _______, KC_F12,  KC_PGUP, KC_COMM, KC_DOT,  KC_PGDN, _______ \
),

[_ADJUST] =  KEYMAP( \
  KC_MAKE, RESET,   TD(TD_FLSH), _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, XXXXXXX, _______,          _______, XXXXXXX, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, MAGIC_TOGGLE_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY  \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_workman[][2]    = SONG(PLOVER_SONG);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_qwerty);
        #endif
            persistent_default_layer_set(1UL<<_QWERTY);
        }
        return false;
        break;
    case COLEMAK:
        if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_colemak);
        #endif
            persistent_default_layer_set(1UL<<_COLEMAK);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_dvorak);
        #endif
            persistent_default_layer_set(1UL << _DVORAK);
        }
        return false;
        break;
    case WORKMAN:
        if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_workman);
        #endif
            persistent_default_layer_set(1UL << _WORKMAN);
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case ADJUST:
        if (record->event.pressed) {
            layer_on(_ADJUST);
        } else {
            layer_off(_ADJUST);
        }
        return false;
        break;
    case KC_MAKE:
        if (!record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
#else
            SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP " RGBLIGHT_ENABLE=no"SS_TAP(X_ENTER));
#endif
        }
        return false;
        break;

  }
  return true;
}

void matrix_init_user(void) { // Runs boot tasks for keyboard
#ifdef RGBLIGHT_ENABLE
    uint8_t default_layer = eeconfig_read_default_layer();

    rgblight_enable();
    if (default_layer & (1UL << _COLEMAK)) {
        rgblight_set_magenta;
}
    else if (default_layer & (1UL << _DVORAK)) {
        rgblight_set_green;
    }
    else if (default_layer & (1UL << _WORKMAN)) {
        rgblight_set_purple;
    }
    else {
        rgblight_set_teal;
    }
#endif

};

void matrix_scan_user(void) {  // runs frequently to update info

};

uint32_t layer_state_set_kb(uint32_t state) { // runs on layer switch
#ifdef RGBLIGHT_ENABLE
    uint8_t default_layer = eeconfig_read_default_layer();

    switch (biton32(state)) {
    case _COLEMAK:
        rgblight_set_magenta;
        rgblight_mode(1);
        break;
    case _DVORAK:
        rgblight_set_green;
        rgblight_mode(1);
        break;
    case _RAISE:
        rgblight_set_yellow;
        rgblight_mode(5);
        break;
    case _LOWER:
        rgblight_set_orange;
        rgblight_mode(5);
        break;
    case _ADJUST:
        rgblight_set_red;
        rgblight_mode(23);
        break;
    case 6:
        rgblight_set_blue;
        break;
    case _QWERTY:
        if (default_layer & (1UL << _COLEMAK)) {
            rgblight_set_magenta;
        }
        else if (default_layer & (1UL << _DVORAK)) {
            rgblight_set_green;
        }
        else if (default_layer & (1UL << _WORKMAN)) {
            rgblight_set_purple;
        }
        else {
            rgblight_set_teal;
        }
        rgblight_mode(1);
        break;
    }
#endif
    return state;
}
