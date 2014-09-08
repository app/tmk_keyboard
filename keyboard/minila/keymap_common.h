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
/*
#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,           K45,                K49, K4A, K4B, K4C, K4D  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_NO,    KC_NO,    KC_##K45, KC_NO,    KC_NO,    KC_NO,    KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D }  \
}
*/


#define KEYMAP( \
                  K02,           K05,            \
        K10, K11, K12, K13, K14, K15, K16, K17,  \
        K20, K21, K22,      K24,           K27,  \
        K30,      K32,      K34,           K37,  \
        K40, K41, K42, K43, K44, K45, K46, K47,  \
        K50, K51, K52, K53, K54, K55, K56, K57,  \
        K60, K61, K62, K63, K64, K65, K66, K67,  \
        K70, K71, K72,      K74, K75, K76, K77,  \
        K80, K81, K82, K83,      K85, K86, K87,  \
        K90,      K92, K93,      K95,            \
        KA0, KA1, KA2,      KA4, KA5, KA6        \
) { \
    {    KC_NO,    KC_NO, KC_##K02,    KC_NO,    KC_NO, KC_##K05,    KC_NO,    KC_NO }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K20, KC_##K21, KC_##K22,    KC_NO, KC_##K24,    KC_NO,    KC_NO, KC_##K27 }, \
    { KC_##K30,    KC_NO, KC_##K32,    KC_NO, KC_##K34,    KC_NO,    KC_NO, KC_##K37 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
    { KC_##K70, KC_##K71, KC_##K72,    KC_NO, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
    { KC_##K80, KC_##K81, KC_##K82, KC_##K83,    KC_NO, KC_##K85, KC_##K86, KC_##K87 }, \
    { KC_##K90,    KC_NO, KC_##K92, KC_##K93,    KC_NO, KC_##K95,    KC_NO,    KC_NO }, \
    { KC_##KA0, KC_##KA1, KC_##KA2,    KC_NO, KC_##KA4, KC_##KA5, KC_##KA6,    KC_NO }  \
}



/*
#define KEYMAP( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,  \
        K10, K11,      K13, K14, K15, K16, K17,      K19,  \
   K2A, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29,  \
        K30,           K33, K34, K35,      K37, K38,       \
        K40, K41, K42, K43, K44, K45, K46,           K49,  \
   K5A, K50,           K53, K54, K55, K56, K57, K58, K59,  \
        K60,           K63, K64, K65, K66, K67,      K69,  \
        K70, K71, K72, K73, K74, K75, K76, K77             \
) { \
    {    KC_NO, KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09 }, \
    {    KC_NO, KC_##K10, KC_##K11,    KC_NO, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17,    KC_NO, KC_##K19 }, \
    { KC_##K2A, KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29 }, \
    {    KC_NO, KC_##K30,    KC_NO,    KC_NO, KC_##K33, KC_##K34, KC_##K35,    KC_NO, KC_##K37, KC_##K38,    KC_NO }, \
    {    KC_NO, KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46,    KC_NO,    KC_NO, KC_##K49 }, \
    { KC_##K5A, KC_##K50,    KC_NO,    KC_NO, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57, KC_##K58, KC_##K59 }, \
    {    KC_NO, KC_##K60,    KC_NO,    KC_NO, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67,    KC_NO, KC_##K69 }, \
    {    KC_NO, KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77,    KC_NO,    KC_NO }  \
}
*/

/* ANSI valiant. No extra keys for ISO */
/*
#define KEYMAP_ANSI( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,           K3D, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, NO,  K3D, \
    K40, K41, K42,           K45,                NO,  K4A, K4B, K4C, K4D  \
)
*/

/*
#define KEYMAP_ANSI( \
                  K02,           K05,            \
        K10, K11, K12, K13, K14, K15, K16, K17,  \
        K20, K21, K22,      K24,           K27,  \
        K30,      K32,      K34,           K37,  \
        K40, K41, K42, K43, K44, K45, K46, K47,  \
        K50, K51, K52, K53, K54, K55, K56, K57,  \
        K60, K61, K62, K63, K64, K65, K66, K67,  \
        K70, K71, K72,      K74, K75, K76, K77,  \
        K80, K81, K82, K83,      K85, K86, K87,  \
        K90,      K92, K93,      K95,            \
        KA0, KA1, KA2,      KA4, KA5, KA6        \
) KEYMAP( \
                  K02,           K05,            \
        K10, K11, K12, K13, K14, K15, K16, K17,  \
        K20, K21, K22,      K24,           K27,  \
        K30,      K32,      K34,           K37,  \
        K40, K41, K42, K43, K44, K45, K46, K47,  \
        K50, K51, K52, K53, K54, K55, K56, K57,  \
        K60, K61, K62, K63, K64, K65, K66, K67,  \
        K70, K71, K72,      K74, K75, K76, K77,  \
        K80, K81, K82, K83,      K85, K86, K87,  \
        K90,    , K92, K93,      K95,            \
        KA0, KA1, KA2,      KA4, KA5, KA6        \
)
*/

/*
#define KEYMAP_HHKB( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K49,\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3C, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,           K45,                K49, K4A, K4B, K4C, K4D  \
)
*/

#endif
