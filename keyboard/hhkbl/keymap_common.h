/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */


#define KEYMAP( \
         K01, K02, K03,           K06, K07, K08,      K0A, K0B, \
                   K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
                   K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30,      K32, K33,           K36, K37, K38, K39, K3A, K3B, \
    K40,           K43, K44, K45, K46, K47, K48, K49, K4A, K4B, \
         K51,      K53,           K56, K57,           K5A,      \
    K60,      K62, K63, K64, K65, K66, K67,      K69,      K6B, \
    K70, K71,                     K76, K77,           K7A       \
) { \
    {    KC_NO, KC_##K01, KC_##K02, KC_##K03,    KC_NO,    KC_NO, KC_##K06, KC_##K07, KC_##K08,    KC_NO, KC_##K0A, KC_##K0B }, \
    {    KC_NO,    KC_NO,    KC_NO, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B }, \
    {    KC_NO,    KC_NO,    KC_NO, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B }, \
    { KC_##K30,    KC_NO, KC_##K32, KC_##K33,    KC_NO,    KC_NO, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B }, \
    { KC_##K40,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_##K45,    KC_NO,    KC_NO,    KC_NO, KC_##K49, KC_##K4A, KC_##K4B }, \
    {    KC_NO, KC_##K51,    KC_NO, KC_##K53,    KC_NO,    KC_NO, KC_##K56, KC_##K57,    KC_NO,    KC_NO, KC_##K5A,    KC_NO }, \
    { KC_##K60,    KC_NO, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67,    KC_NO, KC_##K69,    KC_NO, KC_##K6B }, \
    { KC_##K70, KC_##K71,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_##K76, KC_##K77,    KC_NO,    KC_NO, KC_##K7A,    KC_NO }  \
}


#endif
