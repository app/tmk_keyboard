#include "keymap_common.h"
#include "action_util.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* 0: qwerty */
    KEYMAP(
	             LSFT, RSFT,  FN6,       LEFT,             \
	        Q,    TAB,    A,  ESC,    Z, RGHT,  GRV,    1, \
		W,    FN4,    S,          X,                2, \
                E,   LGUI,    D,          C,  APP,          3, \
		R,      T,    F,   G,     V,    B,    5,    4, \
		U,      Y,    J,   H,     M,    N,    6,    7, \
		I,  RBRC,     K, SPC,  COMM, DOWN,  EQL,    8, \
                O,            L,        DOT,       CAPS,    9, \
                P,  LBRC,  SCLN, QUOT,       SLSH, MINS,    0, \
              FN0,          FN0, LALT,       RALT,             \
                   BSLS,   BSPC,        FN3,        FN5
    ),
    // navi and num pad
    KEYMAP(
	             LSFT, RSFT,   UP,       LEFT,             \
	        Q,    TAB,   P0,  ESC,    Z, RGHT,  GRV,    F1, \
	       P7,   LCTL,   P4,         P1,                F2, \
               P8,   LGUI,   P5,         P2,  APP,          F3, \
	       P9,   NLCK,   P6,    G,   P3,    B,    5,    F4, \
	     PGUP,   PSCR, LEFT, HOME, PGDN,    N,    6,    F7, \
	       UP,   RBRC, DOWN,  SPC,  FN2, DOWN,  F12,    F8, \
                O,         RGHT,        DOT,       CAPS,    F9, \
                P,   FN1,  END, QUOT,       SLSH,  F11,    F10, \
              FN0,          FN0, LALT,       RALT,             \
                     BSLS, BSPC,        ENT,        DEL
    ),

};

/* id for user defined functions */
enum function_id {
    RUSLAT,
};

const uint16_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    [2] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS),    // >
    [3] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER),
    /*[4] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),*/
    [4] = ACTION_FUNCTION_TAP(RUSLAT),
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DEL),
    [6] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_UP),
/*
    [1] = ACTION_LAYER_TOGGLE(4),     // toggle arrow overlay
    [2] = ACTION_LAYER_TOGGLE(5),     // toggle Esc overlay
    [3] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC), // Task(RControl,RShift+Esc)
    [4] = ACTION_LAYER_MOMENTARY(7),  // to Layout selector
    [5] = ACTION_DEFAULT_LAYER_SET(0),  // set qwerty layout
    [6] = ACTION_DEFAULT_LAYER_SET(1),  // set colemak layout
    [7] = ACTION_DEFAULT_LAYER_SET(2),  // set dvorak layout
    [8] = ACTION_DEFAULT_LAYER_SET(3),  // set workman layout
*/
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