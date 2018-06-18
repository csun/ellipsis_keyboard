#include QMK_KEYBOARD_H


// Layers
// Mac is used as the base layer because it's on when both middle toggle
// contacts are open.
#define MAC     0
#define LIN     1
#define WIN     2
#define LSPC    3
#define MACMED  4
#define WINMED  5


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAC] = LAYOUT(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   MO(LSPC), MO(LIN), MO(WIN),  KC_7,    KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_GRV,     KC_DEL,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,
		KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_END,           KC_UP,             KC_HOME, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_LEFT,  KC_DOWN, KC_RIGHT,                  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,
		KC_LCTL,  KC_LALT, KC_LGUI, KC_LGUI, KC_LSFT, KC_LALT,               KC_PGDN, KC_PGUP,               KC_ENT, KC_SPC, KC_BSPC, KC_RGUI, KC_RALT, MO(MACMED), KC_RCTL
	),
	[LIN] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_LGUI, KC_LALT, KC_LALT, KC_TRNS, KC_LCTL,                KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, MO(WINMED), KC_TRNS
	),
	[WIN] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_LGUI, KC_LALT, KC_LALT, KC_TRNS, KC_LCTL,                KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, MO(WINMED), KC_TRNS
	),

	// NOTE - The idea here was to have a function layer that abstracts away
	// platform keypress differences, having a single combination for stuff
	// like alt-tab, moving one word at a time with arrow keys, etc.
	// However, decided to opt for just putting modifiers under thumbs
	// instead.
// 	[MACFN] = LAYOUT(
// 		KC_TRNS,      LGUI(KC_1), LGUI(KC_2), LGUI(KC_3),   LGUI(KC_4),    LGUI(KC_5), LGUI(KC_6),   KC_TRNS,       KC_TRNS,       KC_TRNS,        LGUI(KC_7),    LGUI(KC_8), LGUI(KC_9),   LGUI(KC_0),   LGUI(KC_MINS), LGUI(KC_EQL),  LGUI(KC_BSLS), LGUI(KC_GRV),
// 		LGUI(KC_TAB), LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E),   LGUI(KC_R),    LGUI(KC_T),                                                             LGUI(KC_Y),    LGUI(KC_U), LGUI(KC_I),   LGUI(KC_O),   LGUI(KC_P),    LGUI(KC_LBRC), LGUI(KC_RBRC), KC_TRNS,
// 		KC_TRNS,      LGUI(KC_A), LGUI(KC_S), LGUI(KC_D),   LGUI(KC_F),    LGUI(KC_G), LGUI(KC_END),                LALT(KC_UP),                   LGUI(KC_HOME), LGUI(KC_H), LGUI(KC_J),   LGUI(KC_K),   LGUI(KC_L),    LGUI(KC_SCLN), LGUI(KC_QUOT), LGUI(KC_ENT),
// 		KC_TRNS,      LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C),   LGUI(KC_V),    LGUI(KC_B),               LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT),                            LGUI(KC_N),   LGUI(KC_M),   LGUI(KC_COMM), LGUI(KC_DOT),  LGUI(KC_SLSH), LGUI(KC_RSFT),
// 		KC_TRNS,      KC_TRNS,    KC_TRNS,    LALT(KC_DEL), LALT(KC_BSPC), KC_TRNS,                         LGUI(KC_PGDN), LGUI(KC_PGUP),                         KC_TRNS,    LGUI(KC_SPC), LGUI(KC_ENT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
// 	),
// 	[LINFN] = LAYOUT(
// 		KC_TRNS,      LCTL(KC_1), LCTL(KC_2), LCTL(KC_3),   LCTL(KC_4),    LCTL(KC_5), LCTL(KC_6),   KC_TRNS,       KC_TRNS,       KC_TRNS,        LCTL(KC_7),    LCTL(KC_8), LCTL(KC_9),   LCTL(KC_0),   LCTL(KC_MINS), LCTL(KC_EQL),  LCTL(KC_BSLS), LCTL(KC_GRV),
// 		LALT(KC_TAB), LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E),   LCTL(KC_R),    LCTL(KC_T),                                                             LCTL(KC_Y),    LCTL(KC_U), LCTL(KC_I),   LCTL(KC_O),   LCTL(KC_P),    LCTL(KC_LBRC), LCTL(KC_RBRC), KC_TRNS,
// 		KC_TRNS,      LCTL(KC_A), LCTL(KC_S), LCTL(KC_D),   LCTL(KC_F),    LCTL(KC_G), LCTL(KC_END),                LCTL(KC_UP),                   LCTL(KC_HOME), LCTL(KC_H), LCTL(KC_J),   LCTL(KC_K),   LCTL(KC_L),    LCTL(KC_SCLN), LCTL(KC_QUOT), LCTL(KC_ENT),
// 		KC_TRNS,      LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),   LCTL(KC_V),    LCTL(KC_B),               LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT),                            LCTL(KC_N),   LCTL(KC_M),   LCTL(KC_COMM), LCTL(KC_DOT),  LCTL(KC_SLSH), LCTL(KC_RSFT),
// 		KC_TRNS,      KC_TRNS,    KC_TRNS,    LALT(KC_DEL), LALT(KC_BSPC), KC_TRNS,                         LCTL(KC_PGDN), LCTL(KC_PGUP),                         KC_TRNS,    LCTL(KC_SPC), LCTL(KC_ENT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
// 	),
// 	[WINFN] = LAYOUT(
// 		KC_TRNS,      LCTL(KC_1), LCTL(KC_2), LCTL(KC_3),   LCTL(KC_4),    LCTL(KC_5), LCTL(KC_6),   KC_TRNS,       KC_TRNS,       KC_TRNS,        LCTL(KC_7),    LCTL(KC_8), LCTL(KC_9),   LCTL(KC_0),   LCTL(KC_MINS), LCTL(KC_EQL),  LCTL(KC_BSLS), LCTL(KC_GRV),
// 		LALT(KC_TAB), LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E),   LCTL(KC_R),    LCTL(KC_T),                                                             LCTL(KC_Y),    LCTL(KC_U), LCTL(KC_I),   LCTL(KC_O),   LCTL(KC_P),    LCTL(KC_LBRC), LCTL(KC_RBRC), KC_TRNS,
// 		KC_TRNS,      LCTL(KC_A), LCTL(KC_S), LCTL(KC_D),   LCTL(KC_F),    LCTL(KC_G), LCTL(KC_END),                LCTL(KC_UP),                   LCTL(KC_HOME), LCTL(KC_H), LCTL(KC_J),   LCTL(KC_K),   LCTL(KC_L),    LCTL(KC_SCLN), LCTL(KC_QUOT), LCTL(KC_ENT),
// 		KC_TRNS,      LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),   LCTL(KC_V),    LCTL(KC_B),               LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT),                            LCTL(KC_N),   LCTL(KC_M),   LCTL(KC_COMM), LCTL(KC_DOT),  LCTL(KC_SLSH), LCTL(KC_RSFT),
// 		KC_TRNS,      KC_TRNS,    KC_TRNS,    LCTL(KC_DEL), LCTL(KC_BSPC), KC_TRNS,                         LCTL(KC_PGDN), LCTL(KC_PGUP),                         KC_TRNS,    LCTL(KC_SPC), LCTL(KC_ENT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
// 	),

	[LSPC] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_SPC,  KC_ENT,                KC_TRNS, KC_TRNS,                KC_LCTL, KC_LSFT, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[MACMED] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_MRWD, KC_MFFD, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[WINMED] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
};
