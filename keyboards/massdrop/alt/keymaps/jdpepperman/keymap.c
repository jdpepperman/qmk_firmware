#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    ___X___ = KC_NO,
};

// layer declarations
enum {
    qty = 0, // qwerty
    rgb = 1, // RGB controls
    mse = 2, // mouse
    msf = 3, // mouse functions
    fnc = 4, // functions
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [qty] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        TT(mse),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TT(fnc),          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, MO(rgb),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [rgb] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [mse] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______,    _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_BTN2, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN4, KC_MS_BTN5, MO(msf),      _______,          _______, _______, \
        _______, _______, _______,                            KC_MS_BTN1,                            _______, _______, _______, _______, _______  \
    ),
    [msf] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_UP, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_MS_BTN3,                            _______, _______, _______, _______, _______  \
    ),
    [fnc] = LAYOUT(
        ___X___,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, \
        ___X___, ___X___, KC_UP, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
        ___X___, KC_LEFT, KC_DOWN, KC_RIGHT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, TT(fnc),          ___X___, ___X___, \
        ___X___, ___X___, ___X___,                            ___X___,                            ___X___, ___X___, ___X___, ___X___, ___X___  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

uint8_t prev = qty;
uint32_t check;
uint32_t desired = 1;

void turn_off_underglow(void) {
    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
    rgb_matrix_set_color_all(0, 0, 0);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgblight_sethsv(0, 0, 255);
    rgblight_mode(desired);
    rgblight_enable();

    turn_off_underglow();
    // reset_hsv();
};

// Runs once at the end of the firmware startup.
void keyboard_post_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void set_mouse_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(180, 100, 255);
}
void set_qwerty_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(0, 0, 255);
}
void set_mouse_fn_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(240, 100, 255);
}

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=fnc) {
      switch (layer) {
        case qty:
          set_qwerty_rgb();
          break;

        case rgb:
          break;

        case mse: 
          set_mouse_rgb();
          break;

        case msf: 
          set_mouse_fn_rgb();
          break;

        case fnc:
          break;
      }
  } else {
      desired = rgblight_get_mode();
  }
  prev = layer;
  return state;
}