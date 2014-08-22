#include "keymap_common.h"
#include "action_util.h"

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
             FN5,LGUI, GRV,            5,   6, EQL,     MINS,    UP,
	                  1,  2,   3,   4,   7,   8,   9,   0,  DOWN,
		          Q,  W,   E,   R,   U,   I,   O,   P,  RGHT,
        BSPC,     LSFT, TAB,            T,   Y,RBRC,LEFT,LBRC,  RALT,
        BSLS,             A,  S,   D,   F,   J,   K,   L,SCLN,  LALT,
              FN0,      ESC,            G,   H,          QUOT,
	FN3,      RSFT,   Z,  X,   C,   V,   M,      DOT,       COMM,
        FN4,  FN0,                      B,   N,           SLSH
	),


    /* Overlay 1: LFn layer 
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
  TRNS,LGUI, DEL,           F5,  F6, F12,      F11,  PGUP,

/*1,  2,   3,   4,   7,   8,   9,   0,  DOWN,*/
 F1, F2,  F3,  F4,  F7,  F8,  F9, F10,  PGDN,

/*Q,  W,   E,   R,   U,   I,   O,   P,  RGHT,*/
  Q, P7,  P8,  P9,PGUP,  UP,   O,   P,   END,

/*BSPC,     LSFT, TAB,            T,   Y,RBRC,LEFT,LBRC,  RALT,*/
   DEL,     LSFT, TAB,         NLCK,PSCR, GRV,HOME, FN1,  RALT,

/*BSLS,             A,  S,   D,   F,   J,   K,   L,SCLN,  LALT,*/
   INS,            P0, P4,  P5,  P6,LEFT,DOWN,RGHT, END,  LALT,

/*FN0,      ESC,            G,   H,          QUOT,*/
 TRNS,      ESC,            G,HOME,          QUOT,

/*FN3,      RSFT,   Z,  X,   C,   V,   M,      DOT,       COMM,*/
 TRNS,      RSFT,   Z, P1,  P2,  P3,PGDN,     NUBS,        FN2,

/*SPC,  FN0,                      B,   N,           SLSH*/
 TRNS, TRNS,                      B, DEL,           FN1
	
	),

};


/* id for user defined functions */
enum function_id {
    RUSLAT,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    [2] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS),    // >
    [3] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER),
    [4] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    // [5] = ACTION_FUNCTION(RUSLAT),
    [5] = ACTION_FUNCTION_TAP(RUSLAT),
    /*[2] = ACTION_LAYER_TAP_KEY(2, KC_ESC),*/
    /*[1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde*/
};

//Left Control key Tap (down+up) works as LShift+LGUI 
//I use LShift+LGUI for RUS/ENG keyboard layout switching
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    switch (id) {
        case RUSLAT:
            if (event.pressed) {
                add_mods(MOD_BIT(KC_LCTRL));
                send_keyboard_report();
            }
            else
            {
                if (get_mods() & MOD_LCTL) {
                    del_mods(MOD_BIT(KC_LCTRL));
                    send_keyboard_report();
                }
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_mods( MOD_BIT(KC_LSFT));
                    add_mods( MOD_BIT(KC_LGUI));
                    send_keyboard_report();
                    del_mods( MOD_BIT(KC_LSFT));
                    del_mods( MOD_BIT(KC_LGUI));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                }
            }
    }
}