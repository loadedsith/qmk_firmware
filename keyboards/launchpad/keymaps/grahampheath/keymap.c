// Below layout is based upon /u/That-Canadian's planck layout
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RGB 1
#define _FUNC 15

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))



// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// tap dance enum
enum {
  TD_FUNC_PLAY_RGB = 0
};

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// for tap dance. Put it here so it can be used in any keymap
void finished (qk_tap_dance_state_t *state, void *user_data);
void reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-------------.
     * |[left]| vol- |
     * |------+------|
     * |[down]| [up] |
     * |------+------|
     * |[rght]| vol+ |
     * |------+------|
     * |    FUNC     |
     * `-------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_LEFT,      KC_VOLD, \
        KC_DOWN,      KC_UP, \
        KC_RGHT,      KC_VOLU, \
        TD(TD_FUNC_PLAY_RGB), KC_TRNS \
      ),

    /* RGB
     * ,-------------.
     * | Mode-| Mode+|
     * |------+------|
     * | HUE- | HUE+ |
     * |------+------|
     * | SAT- | SAT+ |
     * |------+------|
     * |RGBTOG|      |
     * `-------------'
     */
    [_RGB] = LAYOUT( \
        RGB_RMOD, RGB_MOD, \
        RGB_HUD,  RGB_HUI, \
        RGB_SAD,  RGB_SAI, \
        RGB_TOG,  KC_TRNS \
      ),

    /* Function
     * ,-------------.
     * |   Q  |CALDEL|
     * |------+------|
     * |   A  |TSKMGR|
     * |------+------|
     * |   Z  |  X   |
     * |------+------|
     * |      |  C   |
     * `-------------'
     */
    [_FUNC] = LAYOUT( \
        RGB_VAI,    KC_MUTE, \
        RGB_HUI,    RGB_SAI, \
        RGB_MOD,    KC_MNXT, \
        _______, KC_TRNS \
      )

};

void finish (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_MPLY);
      break;
    case SINGLE_HOLD:
      layer_on(_FUNC);
      break;
    case DOUBLE_SINGLE_TAP:
      rgblight_toggle();
  }
}

void reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_MPLY);
      break;
    case SINGLE_HOLD:
      layer_off(_FUNC);
      break;
    case DOUBLE_SINGLE_TAP:
      break;
  }
}

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
  else { return 3; } // any number higher than the maximum state value you return above
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_FUNC_PLAY_RGB]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, finish, reset)
};

void matrix_init_user(void) {}
