/* 
 * Modified from germ's layout
 * Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */
 
/* DONE: 
- Ctrl, shift, alt on left thumb cluster (my left pinky hurts). Shift is on the most natural key .
- Reorder right thumb cluster to reduce movement for common keys (backscpace, space, enter)
- no longer tie Enter with alt (to support alt-enter)
- move TAB on left side - can hit windows-tab with pinky
- LMB comes before RMB - makes more sense to me that way
- Remove redundant symbols that can already be easily accessed through SHIFT, e.g. ?, <, >
- Add PrintScreen, Insert
- Reorganize symbols so they more closely map to a regular qwerty, e.g. _ above -, + above =, etc.
- Move media keys in symbol layers, to make space in navigation layer for Home, end, page up, page down...
- Free up space for future layers
- Fix Function keys, put mouse buttons on same layer as mouse navigation


Todos:
- Key for CTRL+ALT?
- Separate layer for greek letters?
- French accents on separate layer
- Pause/Break doesn't actually work. Fix or remove.
*/

#include QMK_KEYBOARD_H

#define BASE 0 // default layer a
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define GREEK_LOWER 3

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |SYMB/Esc|   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  | Future |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  | LMB  |           | DEL  |   H  |   J  |   K  |   L  | ;  : | Future |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Windows |   Z  |   X  |   C  |   V  |   B  | RMB  |           |      |   N  |   M  | ,  < | . >  | /  ? | Future |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .-------.   .-------.                                 .----------.   .-----.
 *                    |  Ctrl |   |LShift |                                 |SYMB/Space|   |BKSP |
 *                    '-------'   '-------'                                 `----------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      |       |
 *                                 ,------|-------|                      |-------|------.
 *                                 | LALT | NUMB  |                      |       | NUMB |
 *                                 |      | ENT   |                      |       | ENT  |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(SYMB, KC_ESC),       KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_TRNS,
    KC_TAB,  KC_A,  KC_S,   KC_D,  KC_F, KC_G, KC_BTN1,                         	 KC_DEL,  KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_TRNS,
    KC_LGUI,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_BTN2, KC_BTN3,     KC_PGDN, KC_BSPC,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
							KC_LCTRL, KC_LSHIFT, KC_LALT, LT(NUMB, KC_ENT),        KC_TRNS, LT(NUMB, KC_ENT),  LT(SYMB, KC_SPC),   KC_BSPC
    ),

	
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |   +  |  _   |  "   |PrtScr| Ins  |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |Pa/Brk|   =  |  - _ | ' "  |  *   | \ |  |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Windows |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |VolDn |VolUp | Skip |Ply/Pa|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        | Ctrl |   |LShift|                                 |SYMB  |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 | LALT |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                            KC_PLUS, KC_UNDS, KC_DQUO, KC_PSCR, KC_INS,  KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,                          KC_PAUS, KC_EQL,  KC_MINS, KC_QUOT, KC_ASTR, KC_BSLS, KC_TRNS,
    KC_LGUI, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_AMPR, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_TRNS, 
                                        KC_LCTRL, KC_LSHIFT, KC_LALT, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | LMB  |           |      | LEFT | DOWN |  UP  | RIGHT| Home | PgUp   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | RMB  |           |      | MLFT | MDWN | MUP  | MRGHT| End  | PgDn   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        | Ctrl |   |LShift|                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |  MMB  |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 | LALT |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_BTN1,                        KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGUP,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN2, KC_BTN3,     KC_TRNS, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_END,  KC_PGDN,
                                        KC_LCTRL, KC_LSHIFT, KC_LALT, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Keymap 3: Greek lowercase
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
 
 
/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */

