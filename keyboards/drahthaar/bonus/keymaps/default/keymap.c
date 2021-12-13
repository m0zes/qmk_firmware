/* Copyright 2021 Adam Tygart (@m0zes)
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
#include "bonus.h"

#define MEDIA_KEY_DELAY 5

enum { _QWERTY, _FN, _LOCK, _UNLOCK };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        MO(1),   KC_F13,  KC_F14,  KC_F15,
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,            KC_PDOT
    ),
    [_FN] = LAYOUT_all(
        KC_TRNS, RGB_TOG, KC_NO,   DF(2),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        RGB_SAI, RGB_VAI, RGB_MOD, KC_NO,
        RGB_HUD, KC_NO,   RGB_HUI,
        RGB_SAD, RGB_VAD, RGB_RMOD,KC_NO,
        RGB_SPI,          RGB_SPD
    ),
    [_LOCK] = LAYOUT_all(
        MO(3),   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,            KC_NO
    ),
    [_UNLOCK] = LAYOUT_all(
        KC_TRNS, KC_NO,   KC_NO,   DF(0),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,            KC_NO
    )
};
// clang-format on
