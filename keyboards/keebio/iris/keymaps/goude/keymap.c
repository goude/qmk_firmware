#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Main keyboard
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, LOWER,                 RAISE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                    RALT_T(KC_LBRC),  KC_LSPO, KC_BSPC,                   KC_SPC,  KC_RSPC,  LCTL_T(KC_RBRC)
  ),

  // Cursor etc
  [_LOWER] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_EQUAL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                                    _______, _______, _______,                   _______, _______, _______
  ),

  // Single right hand typing
  [_RAISE] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQUAL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    OSM(KC_RALT),
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OSM(KC_RSHIFT),
                                    KC_LALT, KC_LGUI,  KC_DEL,                   LOWER, XXXXXXX, XXXXXXX
  ),

  // Function keys
  [_ADJUST] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
    _______, RGB_TOG, RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX,                            KC_TAB,  KC_PGDN, KC_PGUP, XXXXXXX,  XXXXXXX, KC_BSPC,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, OSM(KC_RCTRL),
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, OSM(KC_RSHIFT),
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   _______, XXXXXXX, XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
