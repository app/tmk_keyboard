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
        BSPC,     LSFT, TAB,            T,   Y,RBRC,LEFT,LBRC,  RALT,
        BSLS,             A,  S,   D,   F,   J,   K,   L,SCLN,  LALT,
              FN0,      ESC,            G,   H,          QUOT,
	ENT,      RSFT,   Z,  X,   C,   V,   M,      DOT,       COMM,
        SPC,  FN0,                      B,   N,           SLSH
	),


    /* Overlay 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|Psc|Pgu| Up|  O|  P|  [|  ]| Del |
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|Hom|Lef|Dow|Rig|End|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|Del|Pgd|  ,|Fn1|  /|Shift |Fn0|
     * `-----------------------------------------------------------'-.
     *     |Fn0|Gui|Alt|         Space         |Alt  |Gui|      |PgUp|
     *     `---------------------------------------------' |Home|PgDn| End |
     *                                                     `---------------'
     */

    KEYMAP(
             LCTL,LGUI, DEL,           F5,  F6, F12,      F11,  PGUP,
	                  F1, F2, F3,  F4,  F7,  F8,  F9, F10,  PGDN,
		          Q,  W,   E,   R,PGUP,  UP,   O,   P,   END,
         DEL,     LSFT, TAB,            T,PSCR,RBRC,HOME,LBRC,  RALT,
         INS,             A,  S,   D,   F,LEFT,DOWN,RGHT, END,  LALT,
             TRNS,      ESC,            G,HOME,          QUOT,
	ENT,      RSFT,   Z,  X,   C,   V,PGDN,      FN1,       PGUP,
        SPC, TRNS,                      B, DEL,           SLSH
	
	),

    
    /*KEYMAP_ANSI(*/
        /*GRV, F5,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \*/
        /*TRNS,TRNS,TRNS,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,  \*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS, \*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,TRNS,          TRNS, \*/
        /*TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),*/
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    /*[0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),*/
    /*[1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde*/
};
