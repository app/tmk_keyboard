#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* 0: qwerty */
    KEYMAP(
	                           UP,       LEFT,             \
	        Q,    TAB,    A,  ESC,    Z, RGHT,  GRV,    1, \
		W,   LCTL,    S,          X,                2, \
                E,            D,          C,                3, \
		R,      T,    F,   G,     V,    B,    5,    4, \
		U,      Y,    J,   H,     M,    N,    6,    7, \
		I,  RBRC,     K, SPC,  COMM, DOWN,  EQL,    8, \
                O,  LSFT,     L,        DOT, RSFT, CAPS,    9, \
                P,  LBRC,  SCLN, QUOT,       SLSH, MINS,    0, \
              FN0,          FN0, LALT,       RALT,             \
             LGUI, BSLS,   BSPC,        ENT,  APP,  DEL
    ),
    // navi
    KEYMAP(
	                           UP,       LEFT,             \
	        Q,    TAB,    A,  ESC,    Z, RGHT,  GRV,    1, \
		W,   LCTL,    S,          X,                2, \
                E,            D,          C,                3, \
		R,      T,    F,   G,     V,    B,    5,    4, \
	     PGUP,      Y, LEFT,HOME,  PGDN,    N,    6,    7, \
	       UP,  RBRC,  DOWN, SPC,  COMM, DOWN,  EQL,    8, \
                O,  LSFT,  RGHT,        DOT, RSFT, CAPS,    9, \
                P,  LBRC,   END, QUOT,       SLSH, MINS,    0, \
              FN0,          FN0, LALT,       RALT,             \
             LGUI, BSLS,   BSPC,        ENT,  APP,  DEL
    ),

/*
    KEYMAP_ANSI(
	        Q,      W,    E,    R,    U,    I,    O,    P,   FN0, LGUI,        \
	      TAB, CAPS,            T,    Y, RBRC, LSFT, LBRC,        BSPC,        \
        UP,     A,      S,    D,    F,    J,    K,    L, SCLN,   FN0, BSLS,  \
              ESC,                  G,    H,  SPC,       QUOT,  LALT,              \
                Z,      X,    C,    V,    M, COMM,  DOT,               ENT,        \
	LEFT,RGHT,                  B,    N, DOWN, RSFT, SLSH,  RALT,  APP,     \
	      GRV,                5,    6,  EQL, LCTL, MINS,         DEL,        \
	        1,      2,    3,    4,    7,    8,    9,    0                      \
	),
*/
    /* 0: qwerty */
/*
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RGUI,APP, RCTL),
*/
    /* 1: colemak */
/*
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RGUI,APP, RCTL),
*/
    /* 2: dvorak */
/*
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC, \
        TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS, \
        CAPS,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,     ENT,  \
        LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,             RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RGUI,APP, RCTL),
*/
    /* 3: workman */
/*
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,     ENT,  \
        LSFT,Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RGUI,APP, RCTL),
*/
    /* 4: Poker with Arrow */
/*
    KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          UP,   \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,LEFT,DOWN,RGHT),
*/
    /* 5: Poker with Esc */
/*
    KEYMAP_ANSI(
        ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
*/
    /* 6: Poker Fn
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
     * |-----------------------------------------------------------|
     * |     |FnQ| Up|   |   |   |   |   |   |Cal|   |Hom|Ins|FnL  |
     * |-----------------------------------------------------------|
     * |      |Lef|Dow|Rig|   |   |Psc|Slk|Pau|   |Tsk|End|        |
     * |-----------------------------------------------------------|
     * |        |Del|   |Web|Mut|VoU|VoD|   |PgU|PgD|Del|          |
     * |-----------------------------------------------------------|
     * |    |    |    |         FnS            |    |    |    |    |
     * `-----------------------------------------------------------'
     * Fn:  to Fn overlay
     * FnL: to Layout selector overaly
     * FnQ: toggle Esc overlay
     * FnS: toggle Arrow overlay
     */
/*
    KEYMAP_ANSI(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS, \
        TRNS,FN2, UP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,CALC,TRNS,HOME,INS, FN4,  \
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,FN3, END,      TRNS, \
        TRNS,DEL, TRNS,WHOM,MUTE,VOLU,VOLD,TRNS,PGUP,PGDN,DEL,           TRNS, \
        TRNS,TRNS,TRNS,          FN1,                     TRNS,TRNS,TRNS,TRNS),
*/
    /* 7: Layout selector
     * ,-----------------------------------------------------------.
     * | Lq| Lc| Ld| Lw|   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |Lq |Lw |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |Ld |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |Lc |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Lq: set Qwerty layout
     * Lc: set Colemak layout
     * Ld: set Dvorak layout
     * Lw: set Workman layout
     */
/*
    KEYMAP_ANSI(
        FN5, FN6, FN7, FN8, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,FN5, FN8, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,FN7, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
*/
};
const uint16_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_LAYER_TOGGLE(4),     // toggle arrow overlay
    [2] = ACTION_LAYER_TOGGLE(5),     // toggle Esc overlay
    [3] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC), // Task(RControl,RShift+Esc)
    [4] = ACTION_LAYER_MOMENTARY(7),  // to Layout selector
    [5] = ACTION_DEFAULT_LAYER_SET(0),  // set qwerty layout
    [6] = ACTION_DEFAULT_LAYER_SET(1),  // set colemak layout
    [7] = ACTION_DEFAULT_LAYER_SET(2),  // set dvorak layout
    [8] = ACTION_DEFAULT_LAYER_SET(3),  // set workman layout
};
