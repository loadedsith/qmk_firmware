/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EMOJI,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  EMOJI,
  RAISE_ALT,
  ABOVE,
  BUG,
  CONFUSED,
  CRY,
  CLAP,
  ELIP,
  FLIP,
  FNGLEFT,
  FNGRIGHT,
  FROWN,
  GRIN,
  HEART,
  JOY,
  LLAP,
  ROFL,
  SHIT,
  SING,
  SHRUG,
  THINK,
  THMBDN,
  THMBUP,
  TOUNGE,
  THANKS,
  WINK
};

#define ALT_TAB MT(MOD_LALT, KC_TAB)  // Hold for Left Alt, Tap tab
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Hold for Left Ctrl, Tap for GraveESC
#define HYPR_0 HYPR(KC_TILD)  // Send Hyper + ~.
#define HYPR_1 HYPR(KC_EXLM)  // Send Hyper + !.
#define HYPR_2 HYPR(KC_AT)  // Send Hyper + @.
#define KC_AS LALT(KC_LSFT)
#define KC_BACK LGUI(KC_LBRC) // Back
#define KC_EMOJI_PICKER LGUI(LCTL(KC_SPC))
#define KC_EMOJ MO(_EMOJI)  // Hold for Emoji Layer, or tap 5 times.
#define KC_FORWARD LGUI(KC_RBRC) // Forward
#define KC_QS LGUI(KC_SPC)  // Send Command + Space (for QuickSilver).
#define KC_TABL LGUI(KC_LCBR)  // Send Command + { (for tab changing).
#define KC_TABR LGUI(KC_RCBR)  // Send Command + } (for tab changing).
#define KC_WTAB LGUI(KC_TILD)  // Send Command + ~ (for window changing).
#define MvLnDn LCTL(LGUI(KC_DOWN))    // Ctrl + Gui + Down: move line down
#define MvLnUp LCTL(LGUI(KC_UP))      // Ctrl + Gui + Up: move line up
#define RAISE_ALT LM(_RAISE, MOD_LALT)
#define SEL_DN LSFT(KC_DOWN)          // Shift + Down: move line up
#define SEL_UP LSFT(KC_UP)            // Shift + Up: move line up

// Fillers to make layering more clear
#define _______ KC_TRNS
// Also transparent, but for reserving a key across layers.
#define xxxxxxx KC_TRNS

// Blank template at the bottom


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_gergo(
  /* ┌─────────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬─────────────┐ */
  /* │     ⇥       │    q   │   w    │   e    │   r    │   t    │                                           │   y    │   u    │   i    │   o    │   p    │   ⌫         │ */
      ALT_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
  /* │     ⌃⎋     │   a    │   s    │   d    │   f    │   g    │   [    │                         │   ]    │   h    │   j    │   k    │   l    │   ;    │   '         │ */
      CTL_ESC,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                           KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┤┌────────┐     ┌────────┐├────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
  /* │             │   z    │   x    │   c    │   c    │   b    │   ⏎   ││   <-   │     │   😀   ││   ⏯  │   n    │   m    │   ,    │   .    │   /    │   ⇧⏎       │ */
      KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_BACK,       KC_EMOJ,  KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  /* └─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘└────────┘     └────────┘└────────┴────────┴────────┴────────┴────────┴────────┴─────────────┘ */
  /*                                                             /────────/────────/      \────────\────────\ */
  /*                                  ┌────────┬──────────┐     /        /        /        \        \        \   ┌───────────┬────────┐ */
  /*                                  |        |          |    /        /        /          \        \        \  |           |  ⌥    | */
                                       KC_LGUI, MO(_LOWER),      KC_SPC,  KC_LALT,            RAISE_ALT, KC_SPC,     MO(_RAISE), KC_LALT
  /*                                  └────────┴──────────┘   /        /        /            \        \        \ └───────────┴────────┘ */
  /*                                                         /────────/────────/              \────────\────────\ */

  ),

  [_LOWER] = LAYOUT_gergo(
  /* ┌─────────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬─────────────┐ */
  /* │      ~      │    !        @        #        $        %                                                    ^        &        *        (        )                 │ */
      KC_TILD,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
  /* │             │   <--  │   F3   │  ⇧↑    │   ↑    │  ⌘⌃↑   │ F12    │                         │        │        │    -   │    =   │    {   │    }   │     |       │ */
      _______,      KC_BACK, KC_F3,   SEL_UP,  KC_UP,   MvLnUp,  KC_F12,                            _______, _______, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,
  /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┤┌────────┐     ┌────────┐├────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
  /* │             │        │        │   ⇧↓   │   ↓    │  ⌘⌃↓   │ F11    ││        │     │        ││   ⏮    │       │    _   │   +    │   [    │    ]   │             │ */
      _______,      _______, _______, SEL_DN,  KC_DOWN, MvLnDn,  KC_F11,   _______,       _______,  KC_MPRV, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______,
  /* └─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘└────────┘     └────────┘└────────┴────────┴────────┴────────┴────────┴────────┴─────────────┘ */
  /*                                                             /────────/────────/      \────────\────────\   */
  /*                                  ┌────────┬──────────┐     /        /        /        \        \        \   ┌───────────┬────────┐ */
  /*                                  |        |          |    /        /        /          \        \        \  |           |        | */
                                       _______, xxxxxxx,        _______, _______,            _______, _______,    xxxxxxx,    _______
  /*                                  └────────┴──────────┘   /        /        /            \        \        \ └───────────┴────────┘ */
  /*                                                         /────────/────────/              \────────\────────\  */

  ),

  [_RAISE] = LAYOUT_gergo(
    /* ┌─────────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬─────────────┐ */
    /* │     `       │   1    │   2    │   3    │   4    │   5    │                                           │   6    │   7    │   8    │   9    │   0    │             │ */
        KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
    /* │             │   F 1  │   F2   │   F3   │   F4   │   F5   │   F6   │                         │        │   ←    │   ↓    │   ↑    │   →    │        │      \      │ */
        _______,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F5,                             _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  _______, KC_BSLS,
    /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┤┌────────┐     ┌────────┐├────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
    /* │             │   F7   │   F8   │   F9   │  F10   │   F11  │     12 ││        │     │        ││   ⏭   │        │   ←    │   ↓    │   →    │        │             │ */
        _______,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,       _______,  KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    /* └─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘└────────┘     └────────┘└────────┴────────┴────────┴────────┴────────┴────────┴─────────────┘ */
    /*                                                             /────────/────────/      \────────\────────\   */
    /*                                  ┌────────┬──────────┐     /        /        /        \        \        \   ┌───────────┬────────┐ */
    /*                                  |        |          |    /        /        /          \        \        \  |           |        | */
                                         _______, xxxxxxx,        _______, _______,            _______, _______,    xxxxxxx,    _______
    /*                                  └────────┴──────────┘   /        /        /            \        \        \ └───────────┴────────┘ */
    /*                                                         /────────/────────/              \────────\────────\  */

  ),
  [_EMOJI] = LAYOUT_gergo(
    /* ┌─────────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬─────────────┐ */
    /*               │        │  ;-)   │        │   🤣   │  :-P   │                                           │  🙏🏼    │        │  :'-(  │        │        │             │  */
        HYPR_0,       _______, WINK,    _______, ROFL,    TOUNGE,                                              THANKS,  _______, CRY,     FLIP,    _______, _______,
    /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
    /* │             │   👆   │        │   :-D  │   👍🏼   │  :-(   │                                  │        │   ❤    │  :-)   │        │        │        │        │  */
        HYPR_1,       ABOVE,   SHRUG,   GRIN,    THMBUP,   FROWN,  _______,                           _______, HEART,   JOY,     _______, LLAP,    _______, _______,
    /* ├─────────────┼────────┼────────┼────────┼────────┼────────┼────────┤┌────────┐     ┌────────┐├────────┼────────┼────────┼────────┼────────┼────────┼─────────────┤ */
    /* │             │ 🎶^🎶  │ 💭^💭 │  👏    │   👎🏼   │  🐛    │   :-\  ││        │     │        ││        │   💩    │  ...   │        │        │        │             │  */
        HYPR_2,       SING,    THINK,   CLAP,    THMBDN,  BUG,     CONFUSED, _______,       _______,  _______, SHIT,    ELIP,    _______, _______, _______, _______,
    /* └─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘└────────┘     └────────┘└────────┴────────┴────────┴────────┴────────┴────────┴─────────────┘ */
    /*                                                             /────────/────────/      \────────\────────\   */
    /*                                  ┌────────┬──────────┐     /        /        /        \        \        \   ┌───────────┬────────┐ */
    /*                                  |        |          |    /        /        /          \        \        \  |           |        | */
                                         _______, xxxxxxx,        KC_EMOJI_PICKER, _______,            _______, KC_EMOJI_PICKER,    xxxxxxx,    _______
    /*                                  └────────┴──────────┘   /        /        /            \        \        \ └───────────┴────────┘ */
    /*                                                         /────────/────────/              \────────\────────\  */

  ),
};

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

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void eeconfig_init_user(void) {
//  set_unicode_input_mode(UC_OSX);
}

void matrix_init_user() {
//  set_unicode_input_mode(UC_OSX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ABOVE:
      if (record->event.pressed) {
        SEND_STRING("&above; ");
      }
      return false;
      break;
    case BUG:
      if (record->event.pressed) {
        SEND_STRING("&bug;");
      }
      return false;
      break;
    case CONFUSED:
      if (record->event.pressed) {
        SEND_STRING(":-\\");
      }
      return false;
      break;
    case CRY:
      if (record->event.pressed) {
        SEND_STRING(":'-( ");
      }
      return false;
      break;
    case CLAP:
      if (record->event.pressed) {
        SEND_STRING("&clap; ");
      }
      return false;
      break;
    case ELIP:
      if (record->event.pressed) {
        SEND_STRING("...");
      }
      return false;
      break;
    case FLIP:
      if (record->event.pressed) {
        SEND_STRING("&fliptable;");
      }
      return false;
      break;
    case FNGLEFT:
      if (record->event.pressed) {
        SEND_STRING("&fingerleft; ");
      }
      return false;
      break;
    case FNGRIGHT:
      if (record->event.pressed) {
        SEND_STRING("&fingerright; ");
      }
      return false;
      break;
    case FROWN:
      if (record->event.pressed) {
        SEND_STRING(":-( ");
      }
      return false;
      break;
    case GRIN:
      if (record->event.pressed) {
        SEND_STRING(":-D ");
      }
      return false;
      break;
    case HEART:
      if (record->event.pressed) {
        SEND_STRING("<3 ");
      }
      return false;
      break;
    case JOY:
      if (record->event.pressed) {
        SEND_STRING(":-) ");
      }
      return false;
      break;
    case LLAP:
      if (record->event.pressed) {
        SEND_STRING("&llap; ");
      }
      return false;
      break;
    case ROFL:
      if (record->event.pressed) {
        SEND_STRING("&rofl; ");
      }
      return false;
      break;
    case SHIT:
      if (record->event.pressed) {
        SEND_STRING("&shit; ");
      }
      return false;
      break;
    case SING:
      if (record->event.pressed) {
        SEND_STRING("_sing_");
      }
      return false;
      break;
    case SHRUG:
      if (record->event.pressed) {
        SEND_STRING("&shrug; ");
      }
      return false;
      break;
    case THANKS:
      if (record->event.pressed) {
        SEND_STRING("&thanks;");
      }
      return false;
      break;
    case THINK:
      if (record->event.pressed) {
        SEND_STRING("_think_");
      }
      return false;
      break;
    case THMBDN:
      if (record->event.pressed) {
        SEND_STRING("&thumbdown; ");
      }
      return false;
      break;
    case THMBUP:
      if (record->event.pressed) {
        SEND_STRING("&thumbup; ");
      }
      return false;
      break;
    case TOUNGE:
      if (record->event.pressed) {
        SEND_STRING(":-P ");
      }
      return false;
      break;
    case WINK:
      if (record->event.pressed) {
        SEND_STRING(";-) ");
      }
      return false;
      break;

  }
  return true;
}
