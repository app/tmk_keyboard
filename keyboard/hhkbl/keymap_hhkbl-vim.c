#include "keymap_common.h"

/*HHKB Lite 2 keyboard*/

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * `-----------------------------------------------------------'-.
     *     |Fn0|Gui|Alt|         Space         |Alt  |Gui|      | Up |
     *     `---------------------------------------------' |Left|Down|Right|
     *                                                     `---------------'
     */

    KEYMAP(
             LCTL,LGUI, GRV,            5,   6, EQL,     MINS,    UP,
	                  1,  2,   3,   4,   7,   8,   9,   0,  DOWN,
		          Q,  W,   E,   R,   U,   I,   O,   P,  RGHT,
        BSPC,     LSFT, TAB,            T,   Y,RBRC,LEFT,LBRC,  FN0,
        BSLS,             A,  S,   D,   F,   J,   K,   L,SCLN,  FN0,
              LALT,     ESC,            G,   H,          QUOT,
	FN3,      RSFT,   Z,  X,   C,   V,   M,      DOT,       COMM,
        SPC,  RALT,                     B,   N,           SLSH
	),


    /* Overlay 1: Fn layer 
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |  Q| P1| P2| P3|Nlk|Psc|Pgu| Up|  O|  P|  [|  ]| Del |
     * |-----------------------------------------------------------|
     * |Contro| P0| P4| P5| P6|  G|Hom|Lef|Dow|Rig|End|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z| P7| P8| P9|  B|Del|Pgd|  ,|Fn1|  /|Shift |Fn0|
     * `-----------------------------------------------------------'-.
     *     |Fn0|Gui|Alt|         Space         |Alt  |Gui|      |PgUp|
     *     `---------------------------------------------' |Home|PgDn| End |
     *                                                     `---------------'
     */

    KEYMAP(
/*LCTL,LGUI, GRV,            5,   6, EQL,     MINS,    UP,*/
  LCTL,LGUI, DEL,           F5,  F6, F12,      F11,  PGUP,

/*1,  2,   3,   4,   7,   8,   9,   0,  DOWN,*/
 F1, F2,  F3,  F4,  F7,  F8,  F9, F10,  PGDN,

/*Q,  W,   E,   R,   U,   I,   O,   P,  RGHT,*/
  Q, P1,  P2,  P3,PGUP,   I,   O,PSCR,   END,

/*BSPC,     LSFT, TAB,            T,   Y,RBRC,LEFT,LBRC,  FN0,*/
   DEL,     LSFT,CAPS,         NLCK,HOME, GRV,HOME, FN1,  TRNS,

/*BSLS,             A,  S,   D,   F,   J,   K,   L,SCLN,  FN0,*/
   INS,            P0, P4,  P5,  P6,DOWN,  UP,RGHT,BSPC,  TRNS,

/*LALT,      ESC,            G,   H,          QUOT,*/
  LALT,      ESC,            G,LEFT,          QUOT,

/*FN3,      RSFT,   Z,  X,   C,   V,   M,      DOT,       COMM,*/
  ENT,      RSFT,   Z, P7,  P8,  P9,PGDN,     NUBS,        FN2,

/*SPC, RALT,                      B,   N,           SLSH*/
  SPC, RALT,                      B, END,           FN1
	
	),

};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    [2] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS),    // >
    [3] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER),
    /*[2] = ACTION_LAYER_TAP_KEY(2, KC_ESC),*/
    /*[0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),*/
    /*[1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde*/
};
