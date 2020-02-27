#include QMK_KEYBOARD_H 
enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    EM_ICLD,               //Type out my personal icloud email address
    EM_GMAL,               // Type out gmail address
    EM_WORK,               // Type out SBS email address
    RGB_DEF,               //Set RGB back to white
    RGB_FV1,               // Set RGB to blue stripe
    RGB_FV2,               // Set RGB to rainbow flow
    ___X___ = KC_NO,       //Block keys in the stack // this needs to be at the bottOm of the list for some reason. Codes after it werent working
};

// enum custom_keycodes {
// };

// layer declarations
enum {
    qty = 0, // qwerty
    qtw = 1, // qwerty (windows)
    rgb = 2, // RGB controls
    mse = 3, // mouse
    msf = 4, // mouse functions
    fnc = 5, // functions
    fnw = 6, // function (windows)
    mro = 7, // macros
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [qty] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        TT(mse), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(fnc),          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             MO(mro), MO(rgb),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [qtw] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        TT(mse), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(fnw),          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             MO(mro), MO(rgb),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [rgb] = LAYOUT(
        _______, RGB_FV1, RGB_FV2, _______, _______, _______, _______, _______, _______, _______, _______,_______,_______,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [mse] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______,    _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_BTN2, TT(msf),          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN4, KC_MS_BTN5, MO(msf),_______,        _______, _______, \
        _______, _______, _______,                            KC_MS_BTN1,                            _______, ___X___, _______, _______, _______  \
    ),
    [msf] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_UP, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______, TT(msf),          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ASUP, KC_ASTG, \
        _______, _______, _______,                            KC_MS_BTN3,                            _______, ___X___, _______, KC_ASDN, KC_ASRP  \
    ),
    [fnc] = LAYOUT(
        KC_GRV,  KC_F1,  KC_F2  ,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, \
        ___X___, ___X___, KC_UP  , ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_END, \
        ___X___, KC_LEFT, KC_DOWN, KC_RIGHT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        KC_LSFT, KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU, KC_MUTE, ___X___, ___X___, ___X___, S(KC_SLSH), _______,          ___X___, DF(qtw), \
        ___X___, ___X___, ___X___,                            ___X___,                            ___X___, ___X___, ___X___, ___X___, ___X___  \
    ),
    [fnw] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, \
        ___X___, ___X___, KC_UP  , ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_END, \
        ___X___, KC_LEFT, KC_DOWN, KC_RIGHT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, ___X___, ___X___, ___X___, S(KC_SLSH), _______,          ___X___, DF(qty), \
        ___X___, ___X___, ___X___,                            ___X___,                            ___X___, ___X___, ___X___, ___X___, ___X___  \
    ),
    // RGB_DEF from this layer with preserve mode
    [mro] = LAYOUT(
        RGB_DEF, EM_ICLD, EM_GMAL,   EM_WORK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, LCA(KC_S), _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, ___X___, _______, _______, _______  \
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
uint32_t d_hue = 0;
uint32_t d_sat = 0;
uint32_t d_val = 255;
bool def_rgb_flg = true;

void turn_off_underglow(void) {
    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
    rgb_matrix_set_color_all(0, 0, 0);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgblight_sethsv(d_hue, d_sat, d_val);
    rgblight_mode(desired);
    rgblight_enable();

    turn_off_underglow();
    // reset_hsv();
};

// Runs once at the end of the firmware startup.
void keyboard_post_init_user(void) {
    // For debugging 
    // debug_enable=true;
    // debug_matrix=true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// Custom rgb settings
void set_default_rbg(void) {
    rgblight_mode(1);
    rgblight_sethsv(0, 0, 255); // white
}

bool is_default_rgb_set(void) {
    uint32_t current_mode = rgblight_get_mode();
    uint32_t current_hue = rgb_matrix_config.hsv.h;
    uint32_t current_sat = rgb_matrix_config.hsv.s;
    uint32_t current_val = rgb_matrix_config.hsv.v;

    if (current_mode==1 && current_hue==0 && current_sat==0 && current_val==255) {
        return true;
    } else {
        return false;
    }
}

void toggle_default_rgb(void) {
    if (is_default_rgb_set()) {
        rgblight_mode(desired);
        rgblight_sethsv(d_hue, d_sat, d_val);
        def_rgb_flg = false;
    } else {
        set_default_rbg();
        def_rgb_flg = true;
    }
}

void set_mouse_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(180, 100, 255); // violet
}

void set_qwerty_rgb(void) {
    // set the default rgb if the flag is true, otherwise use the last chosen one
    if (def_rgb_flg) {
        set_default_rbg();
    } else {
        rgblight_mode(desired);
        rgblight_sethsv(d_hue, d_sat, d_val);
    }
}

void set_mouse_fn_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(240, 100, 255); // pink
}

void set_macro_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(120, 100, 255); // cyan
}

void set_testing_rgb(void) {
    rgblight_mode(1);
    rgblight_sethsv(60, 100, 100); // yellow
}


#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
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
        case RGB_DEF:
            if (record->event.pressed) {
                // set_default_rbg();
                toggle_default_rgb();
            } 
            return false;
        case RGB_FV1:
            if (record->event.pressed) {
                rgblight_mode(5);
                rgblight_sethsv(350, 255, 255); // blue
            } 
            return false;
        case RGB_FV2:
            if (record->event.pressed) {
                rgblight_mode(12);
                rgblight_sethsv(240, 255, 255); // blue
            }
            return false;
        case EM_ICLD:
            if (record->event.pressed) {
                SEND_STRING("joshua.pepperman@icloud.com");
            }
            return false;
        case EM_GMAL:
            if (record->event.pressed) {
                SEND_STRING("joshuapepperman@gmail.com");
            }
            return false;
        case EM_WORK:
            if (record->event.pressed) {
                SEND_STRING("jpepperman@southlandbenefit.com");
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
    // return true;
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
          if (prev==rgb) {
            // If we are coming from the rgb layer into the qty layer, capture the mode, hue, sat, and val that was set in the rgb layer
            // Also only set them to desired if it isnt default already
            if (!is_default_rgb_set()) {
                desired = rgblight_get_mode();
                d_hue = rgb_matrix_config.hsv.h;
                d_sat = rgb_matrix_config.hsv.s;
                d_val = rgb_matrix_config.hsv.v;
                break;
            }
          }
          else {
            set_qwerty_rgb();
          }
          break;

        case rgb:
          break;

        case mse: 
          set_mouse_rgb();
          break;

        case msf: 
          set_mouse_fn_rgb();
          break;

        case mro:
          set_macro_rgb();
          break;

        case fnc:
          break;
      }
  } else {
  }
  prev = layer;
  return state;
}