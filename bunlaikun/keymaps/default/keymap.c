/* Copyright 2022
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

enum layers {
    _BASE = 0,
    _NUM = 1,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(

//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  Q       │  W       │  E       │  R       │  T       │   │  Y       │  U       │  I       │  O       │  P       │
          KC_Q,      KC_W,       KC_E,      KC_R,     KC_T,           KC_Y,      KC_U,     KC_I,       KC_O,     KC_P,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  A       │  S       │  D       │  F       │  G       │   │  H       │  J       │  K       │  L       │  ' "     │
          KC_A,   LCTL_T(KC_S),LALT_T(KC_D),LGUI_T(KC_F),KC_G,       KC_H,   RGUI_T(KC_J),RALT_T(KC_K),RCTL_T(KC_L),KC_QUOT,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  C       │  V       │  B       │   │  N       │  M       │  , <     │  . >     │  CAPS_W  │
          KC_Z,      KC_X,       KC_C,      KC_V,     KC_B,           KC_N,      KC_M,     KC_COMM,    KC_DOT,    CW_TOGG,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                          KC_SPC,       KC_ESC,      KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    )

    // [_NUM] = LAYOUT(

//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  X       │  X       │  X       │  X       │  X       │   │     *    │    7     │     8    │     9    │    -     │
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  LSHIFT  │  LCTRL   │  LALT    │  LMETA   │  X       │   │     /    │    4     │     5    │     6    │    +     │
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  X       │  X       │  X       │   │     0    │    1     │     2    │     3    │    .     │
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                          // KC_SPC,       KC_ESC,      KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯

    // )
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  // rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 and 1 are left-half encoders
    // 2 and 3 are right-half encoders
    if (index == 0) {
        tap_code(KC_0);
    } else if (index == 1) {
        tap_code(KC_1);
    } else if (index == 2) {
        tap_code(KC_2);
    } else if (index == 3) {
        tap_code(KC_3);
    }

    if (clockwise) {
        tap_code16(KC_PLUS);
    } else {
        tap_code(KC_MINUS);
    }

    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif
