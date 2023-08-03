/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH      |
 * |----- +-----+-----+-----+-----|      |--------------------------------|
 * |      |   BSPC   TAB  M |  M  |      |    LES   COLN  GRT    |        | 
 * |------+-----+-----+---B-+--B--+      |--------------------------------|
 * |      |   MINS    |   2 |  1  |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    q |  w  |  e  |  r  |  t  |      |  y  |  u  |  i  |  o  |    p   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/a|  s  |  d  |  f  |  g  |      |  h  |  j  |  k  |  l  | CTRL/; | 
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |SHFT/z|  x  |  c  |  v  |  b  |      |  n  |  m  |  ,  |  .  | SHFT// |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
 *  '-------------------------'           '-----------------'
 */
[_ALPHA] = LAYOUT_split_3x5_3(
    KC_Q,              KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,   KC_P, 
    MT(MOD_LCTL, KC_A),KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L,   MT(MOD_LCTL, KC_SCLN),
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

    MT(MOD_LALT, KC_ESC), MT(MOD_LGUI, KC_ENT), LT(_SPECIAL, KC_SPC), // Left
    LT(_NUMBERS, KC_SPC), MT(MOD_RGUI, KC_BSPC), MT(MOD_RSFT, KC_TAB) // Right
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  {  |  }  |  |  |      |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | UP  |      |  +  |  -  |  /  |  *  |    '   |
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |  %   |  ^  |  [  |  ]  | DOWN|      |  &  |  =  |     |     |   -    |
 * `------+-----+-----+------+----'      `--------------------------------'
 *          .-----------------.           .------------------.   
 *          |COMBO|  ;  |  =  |           |  =  |  ;  |  DEL |
 *          '-----------------'           '------------------' 
 */
[_SPECIAL] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_UP,     KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_DOWN,   KC_AMPR, KC_EQL,  KC_TRNS, KC_TRNS,  KC_MINS,
                      CM_TOGG, KC_SCLN, KC_EQL,    KC_EQL,  KC_SCLN, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP | 
 * |-----+-----+-----+-----+------+      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      | F11 | F12 |     |     | VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *          .-----------------.           .-----------------.   
 *          |     |    |      |           |     | PLY | SKP |
 *          '-----------------'           '-----------------' 
 */
[_NUMBERS] = LAYOUT_split_3x5_3(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,       KC_6,   KC_7,    KC_8,    KC_9,    KC_0,
    MT(MOD_LALT, KC_F1), KC_F2, KC_F3, KC_F4, KC_F5,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    MT(MOD_RSFT, KC_F6), KC_F7, KC_F8, KC_F9, KC_F10,     KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_VOLD,
                  KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_MPLY,KC_MNXT
    )
};
