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

enum planck_layers { 
    _QWERTY,
    _LOWER,
    _RAISE,
    _PLOVER,
    _ADJUST,
    _NUMPAD,
    _SYMBOLS
};

enum planck_keycodes { 
    QWERTY = SAFE_RANGE, 
    PLOVER, 
    BACKLIT, 
    EXT_PLV, 
    NUMPAD, 
    SYMBOLS, 
    CONST, 
    FATARO, 
    NOTEQL, 
    PASS,
    PASS1
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// added
enum tapdane_keycodes {
    TD_ESC_CAPS,
    TD_CMD_ENT,
};

tap_dance_action_t tap_dance_actions[] = {
[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), 
[TD_CMD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |ENTER |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | CTRL | Alt  |  CMD |Lower | BSPC | SPC  |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */

    [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV, 
    TD(TD_ESC_CAPS), KC_A, CTL_T(KC_S), ALT_T(KC_D), CMD_T(KC_F), KC_G, KC_H, CTL_T(KC_J), ALT_T(KC_K), CMD_T(KC_L), KC_SCLN, KC_ENT, 
    KC_LSFT, KC_Z, KC_X, KC_C, LT(_NUMPAD, KC_V), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
    _______, KC_LCTL, KC_LALT, TD(TD_CMD_ENT), LOWER, KC_BSPC, KC_SPC, RAISE, LT(_SYMBOLS, KC_LEFT), KC_DOWN, KC_UP, KC_RIGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      | Back | Fwd  |   %  |   +  |   -  |   =  |   _  |   &  | !==  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |  =>  |   (  |   )  |   [  |   ]  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |PASS1 | PASS |CONST |   {  |   }  |   .  |   \  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    
    [_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, LCTL(KC_MINUS), LCTL(S(KC_MINUS)), KC_PERC, KC_PLUS, KC_MINUS, KC_EQUAL, KC_UNDS, KC_AMPR, NOTEQL, 
    _______, _______, _______, _______, _______, _______, FATARO, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_PIPE, 
    _______, _______, _______, _______, PASS1, PASS, CONST, S(KC_LBRC), S(KC_RBRC), _______, KC_BSLS, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  | Home |  UP  |  END |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  APP | LEFT | DOWN |RIGHT |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |SCRLUP|SCRLDN|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, 
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_NO,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
        ),

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_planck_grid(
    KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, 
    XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, 
    XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Adjust (Lower + Raise)
     *                      v------------------------RGB CONTROL--------------------v
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      | MS_1 | MS_U | MS_2 |      |  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |AGnorm|AGswap| MS_L | MS_D | MS_R |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_ADJUST] = LAYOUT_planck_grid(
    _______, RESET, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_DEL, 
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Numpad
     * ,-----------------------------------------------------------------------------------.
     * |      |   7  |   8  |   9  |      |      |   /  |   7  |   8  |   9  | BSPC |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   4  |   5  |   6  |      |      |  *   |   4  |   5  |   6  |   +  | Ent  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |      |      |   -  |   1  |   2  |   3  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |   0  | BKSP |  SPC |   0  |   .  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMPAD] = LAYOUT_planck_grid(
    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_SLASH, KC_7, KC_8, KC_9, KC_BSPC, KC_NO, 
    KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_NO, 
    KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_MINUS, KC_1, KC_2, KC_3, KC_ENTER, KC_NO, 
    _______, _______, _______, _______, KC_0, KC_BSPC, KC_SPC, KC_0, KC_DOT, KC_NO, KC_NO, KC_NO
    ),

    /* Symbols
     * ,-----------------------------------------------------------------------------------.
     * |      |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_SYMBOLS] = LAYOUT_planck_grid(
    KC_NO, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_NO, 
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};


layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
                layer_off(_PLOVER);
            }
            return false;
            break;

            // CUSTOM KEYCODES
        case FATARO:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
            break;

        case CONST:
            if (record->event.pressed) {
                SEND_STRING("const ");
            }
            return false;
            break;

        case NOTEQL:
            if (record->event.pressed) {
                SEND_STRING("!==");
            }
            return false;
            break;

        case PASS:
            if (record->event.pressed) {
                SEND_STRING("Brandnewpassword1!");
            }
            return false;
            break;

        case PASS1:
            if (record->event.pressed) {
                SEND_STRING("Brandnewpassword1!1!");
            }
            return false;
            break;

    }
    return true;
}

void matrix_scan_user(void) {
}
