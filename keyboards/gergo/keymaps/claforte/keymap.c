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
- App key (windows context menu)


Todos:
- ALT-F4, CTRL-F4
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
#define STENO 4


// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |SYMB/Esc|   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  | BackSpc|
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |PrtScr|           | DEL  |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Windows |   Z  |   X  |   C  |   V  |   B  |Delete|           |      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .--------.   .-----------.                            .----------.   .---------.
 *                    |Ctrl/Ent|   |LShft/Space|                            |SYMB      |   |NUMB     |
 *                    '--------'   '-----------'                            `----------.   '---------'
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      | CAPS  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | LALT |LAltCtl|                      |       | RAlt |
 *                                 |      | BkSpc |                      |       |      |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(SYMB, KC_ESC),       KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A,  KC_S,   KC_D,  KC_F, KC_G, KC_PSCR,                         	 KC_DEL,  KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, _______,
    KC_LGUI,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_DEL, _______,     _______, _______,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
					   LCTL_T(KC_ENT), LSFT_T(KC_SPC), KC_LALT, LCA_T(KC_BSPC),  _______,    KC_RALT,  MO(SYMB),   MO(NUMB)
    ),

	
/* Keymap 1: Symbols layer (🔶)❖
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |   +  |  _   |  "   | Ins  |PrtScr| BackSpc|
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |  App |   =  |  - _ | ' "  |  *   | \ |  |        |
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
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                            KC_PLUS, KC_UNDS, KC_DQUO, KC_INS, KC_PSCR,  KC_BSPC,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,                          KC_APP,  KC_EQL,  KC_MINS, KC_QUOT, KC_ASTR, KC_BSLS, _______,
    KC_LGUI, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,        _______, _______, KC_AMPR, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______, 
                                        KC_LCTRL, KC_LSHIFT, KC_LALT, _______,     _______, _______, _______, _______
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   | BackSpc|
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F11   |  F1  | F2   | F3   | F4   | F5   | LMB  |           |      | LEFT | DOWN |  UP  | RIGHT| Home | PgUp   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Wind/F12|  F6  | F7   | F8   | F9   | F10  | RMB  |           |      | MLFT | MDWN | MUP  | MRGHT| End  | PgDn   |
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
    _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_BTN1,                        _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGUP,
    MT(MOD_LGUI, KC_F12),  KC_F6, KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_BTN2, KC_BTN3,     _______, _______,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_END,  KC_PGDN,
                                        KC_LCTRL, KC_LSHIFT, KC_LALT, _______,         _______,  _______, _______, _______
    ),
};
 
/* French template (relies on Windows French Canada/Canadian French keyboard
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |❖ "   |❖ ^^  |❖¨trem|      |❖  >  |                         |      |      |❖`èàÀ |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |❖ /   |      |      |      |  #   |      |           |      |      |❖ - / |❖`èàÀ |      | < >  |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |❖  ?  |❖ ^^  |❖ ç   |❖ |   |      |           |      |      |      |,  '  |      | é É  |        |
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
    _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______,         _______, _______, _______, _______
    )
 */
 
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
    _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______,         _______, _______, _______, _______
    )
 */
 

