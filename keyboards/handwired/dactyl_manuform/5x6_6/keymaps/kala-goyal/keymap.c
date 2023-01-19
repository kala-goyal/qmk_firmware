/*
Copyright 2022 fgoodwin <fgoodwin@north-tech.net>

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
#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "keymap.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_AMPERSAND,          KC_PERCENT  },
    {KC_LEFT_BRACKET,       KC_1        },
    {KC_LEFT_CURLY_BRACE,   KC_2        },
    {KC_RIGHT_CURLY_BRACE,  KC_3        },
    {KC_LEFT_PAREN,         KC_4        },
    {KC_EQUAL,              KC_5        },
    {KC_ASTERISK,           KC_F        },
    {KC_RIGHT_PAREN,        KC_7        },
    {KC_PLUS,               KC_8        },
    {KC_RIGHT_BRACKET,      KC_9        },
    {KC_EXCLAIM,            KC_0        },
    {KC_HASH,               KC_GRAVE    },
    {KC_DOLLAR,             KC_TILDE    },
    {KC_CIRCUMFLEX,         KC_AT       },
    {KC_DOUBLE_QUOTE,       KC_QUOTE    },
    {KC_HOME,               KC_PAGE_UP  },
    {KC_END,                KC_PAGE_DOWN}
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) {return false;}
    
    return true;
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#ifdef RIGHTHANDKALA
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
};

bool dip_switch_update_user(uint8_t index, bool active) { 
    if (index == 0) {
        tap_code(KC_MUTE);
    }
    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_AMPR,    KC_LBRC,    KC_LCBR,    KC_RCBR,    KC_LPRN,    KC_EQL,   KC_ASTR,  KC_RPRN,    KC_PLUS,    KC_RBRC,    KC_EXLM,    KC_HASH,
        KC_DLR,     KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,     KC_G,     KC_C,       KC_R,       KC_L,       KC_SLSH,    KC_BSLS,
        KC_TAB,     KC_A,       KC_O,       KC_E,       KC_U,       KC_I,     KC_D,     KC_H,       KC_T,       KC_N,       KC_S,       KC_MINS,
        KC_CIRC,    KC_DQT,     KC_Q,       KC_J,       KC_K,       KC_X,     KC_B,     KC_M,       KC_W,       KC_V,       KC_Z,       KC_SCLN,
                                KC_HOME,    KC_END,     TG(1),      KC_ENT,   KC_SPC,   TG(2),      KC_DEL,     KC_BSPC,
                                                        KC_LSFT,    KC_LCTL,  KC_RCTL,  KC_RSFT,
                                                        KC_LWIN,    KC_LALT,  KC_RALT,  KC_CAPS
    ),
    //NUMS AND FNUMS
    [1] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   KC_1,        KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        _______,   KC_F1,       KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
        _______,   _______,     _______,    _______,    _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,    _______
    ),
    //NUMPAD
    [2] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,    KC_P7,      KC_P8,      KC_P9,      _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,    KC_P4,      KC_P5,      KC_P6,      _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,    KC_P1,      KC_P2,      KC_P3,      _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    KC_P0,      _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,    _______,
                                                        KC_NUM,     _______,    _______,    _______
    )
};
