#include "keymap_common.h"
#include "action_util.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* 0: qwerty */
    KEYMAP(
         FN8, RSFT,  FN6,       LEFT,             \
    Q,    TAB,    A,  ESC,    Z, RGHT,  BSLS,    1, \
    W,    FN4,    S,          X,                2, \
    E,   LGUI,    D,          C,  APP,          3, \
		R,      T,    F,   G,     V,    B,    5,    4, \
		U,      Y,    J,   H,     M,    N,    6,    7, \
		I,  RBRC,     K, SPC,  COMM, DOWN,  EQL,    8, \
    O,            L,        DOT,        FN8,    9, \
    P,  LBRC,  SCLN, QUOT,       SLSH, MINS,    0, \
     FN7,          FN7, LALT,       RALT,             \
                     GRV,   BSPC,        FN3,        FN5
    ),
    // navi and num pad
    KEYMAP(
	             LSFT, RSFT,  FN9,      HOME,              \
       PSLS,   PENT,   P0,  INS, PDOT,  END,  BSLS,   F1, \
	       P7,   LCTL,   P4,   P1,                F2, \
               P8,   LGUI,   P5,         P2,  APP,          F3, \
	       P9,   PAST,   P6, PMNS,   P3, PPLS,   F5,    F4, \
	     PGUP,   PSCR, LEFT, HOME, PGDN, NLCK,   F6,    F7, \
	       UP,    GRV, DOWN,  SPC,  FN2, PGDN,  F12,    F8, \
                O,         RGHT,       NUBS,       TRNS,    F9, \
                P,   FN1,   END, QUOT,         FN1, F11,   F10, \
             TRNS,         TRNS, LALT,       RALT,              \
                     GRV,   DEL,        ENT,        DEL
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
    [4] = ACTION_FUNCTION_TAP(RUSLAT),
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DEL),
    [6] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_UP),
    [7] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [8] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),
    [9] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_PGUP),
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
    /*keyevent_t event = record->event;*/
    switch (id) {
        case RUSLAT:
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        register_mods(MOD_BIT(KC_LCTRL));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LCTRL));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
										add_mods( MOD_BIT(KC_LSFT));
										add_mods( MOD_BIT(KC_LALT));
										send_keyboard_report();

										del_mods( MOD_BIT(KC_LALT));
										del_mods( MOD_BIT(KC_LSFT));
										send_keyboard_report();

										record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LCTRL));
                }
            }
            break;
    }
}
