/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Drashna Jael're  <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _BASE,  // default layer
    _LOWER,  // symbols
    _RAISE,  // media keys
    _ADJUST,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GUIESC GUI_T(KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        GUIESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENTER,
        _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,            _______,           _______, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_RALT,  KC_TAB, KC_SPC
    ),

    [_LOWER] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,           _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                              KC_F12,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, _______, KC_END,  KC_HOME, _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [_RAISE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5 ,  _______,           _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                              KC_F12,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, KC_PGDN, KC_PGUP, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        EEP_RST, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//    ML_LED_1(false);
//    ML_LED_2(false);
//    ML_LED_3(false);
//    ML_LED_4(false);
//    ML_LED_5(false);
//    ML_LED_6(false);
//
//    switch (get_highest_layer(state)) {
//        case 1:
//            ML_LED_1(1);
//            ML_LED_4(1);
//            break;
//        case 2:
//            ML_LED_2(1);
//            ML_LED_5(1);
//            break;
//        case 3:
//            ML_LED_3(1);
//            break;
//        case 4:
//            ML_LED_4(1);
//            break;
//        case 5:
//            ML_LED_5(1);
//            break;
//        case 6:
//            ML_LED_6(1);
//            break;
//        default:
//            break;
//    }
//
//    return state;
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

