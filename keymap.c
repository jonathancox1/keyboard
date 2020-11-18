/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _NAVIGATE, _NUMPAD, _SYMBOLS };

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    NUMPAD,
    SYMBOLS,
    RUNDEV,
    RUNSTART,
    FATARO,
    GITADD,
    GITCOMMIT,
};

enum tapdane_keycodes {
    TD_ESC_CAPS,
    TD_TOG_NAV,
    TD_TOG_DEV,
    TD_CTRL_ENTR,
};

qk_tap_dance_action_t tap_dance_actions[] = {[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), [TD_CTRL_ENTR] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ENT)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_preonic_grid(KC_MPLY, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, TD(TD_ESC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, LT(_NUMPAD, KC_V), LT(_SYMBOLS, KC_B), LT(_SYMBOLS, KC_N), KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, _______, KC_LGUI, KC_LALT, TD(TD_CTRL_ENTR), LOWER, KC_BSPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    [_LOWER] = LAYOUT_preonic_grid(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_TILD, GITADD, GITCOMMIT, RUNSTART, RUNDEV, KC_PERC, KC_PLUS, KC_MINS, KC_EQL, KC_UNDS, KC_RPRN, KC_DEL, RGB_M_P, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD, FATARO, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_PIPE, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_M_B, KC_F11, KC_F12, S(KC_LBRC), S(KC_RBRC), KC_HOME, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    [_RAISE] = LAYOUT_preonic_grid(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_BTN1, KC_PGUP, KC_BTN2, KC_0, KC_BSPC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_APP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_NO, _______, _______, _______, _______, _______, KC_DEL, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    [_ADJUST] = LAYOUT_preonic_grid(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, RESET, DEBUG, _______, _______, _______, _______, TERM_ON, KC_MS_U, _______, _______, KC_DEL, _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_NAVIGATE] = LAYOUT_preonic_grid(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______, _______, KC_DEL, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_NUMPAD] = LAYOUT_preonic_grid(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_ESCAPE, KC_NO, KC_LGUI, KC_NO, KC_NO, KC_SLASH, KC_7, KC_8, KC_9, KC_BSPACE, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_LCTRL, KC_LSHIFT, KC_LALT, KC_NO, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, KC_MINUS, KC_1, KC_2, KC_3, KC_ENTER, KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESCAPE, KC_NO, KC_0, KC_DOT, KC_DOT, KC_TRANSPARENT, KC_NO),

    [_SYMBOLS] = LAYOUT_preonic_grid(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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

        // CUSTOM KEYCODES
        case RUNDEV:
            if (record->event.pressed) {
                SEND_STRING("npm run dev" SS_TAP(X_ENT));
            }
            return false;
            break;

        case RUNSTART:
            if (record->event.pressed) {
                SEND_STRING("npm run start" SS_TAP(X_ENT));
            }
            return false;
            break;

        case FATARO:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
            break;

        case GITADD:
            if (record->event.pressed) {
                SEND_STRING("git add ." SS_TAP(X_ENT));
            }
            return false;
            break;

        case GITCOMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m '");
            }
            return false;
            break;
    }
    return true;
};

// Roatary Encoder
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
