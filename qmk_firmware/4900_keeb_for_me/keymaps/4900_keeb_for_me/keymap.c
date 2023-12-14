#include QMK_KEYBOARD_H

// layers defined in keymaps
enum layer_names { 
    _BASE,
    _NUM,
    _NAV,
    _FKEY,
    _RESET
};

// defining keymap with the LAYOUT_4900_keeb_for_me_default pinout matrix
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [_BASE] = LAYOUT_4900_keeb_for_me_default(
    KC_Q,           KC_W, KC_E, KC_R,         KC_T,               KC_Y,         KC_U,         KC_I,    KC_O,   KC_P,
    LT(_NAV, KC_A), KC_S, KC_D, LSFT_T(KC_F), LCTL_T(KC_G),       RCTL_T(KC_H), RSFT_T(KC_J), KC_K,    KC_L,   KC_SCLN,
    KC_Z,           KC_X, KC_C, KC_V,         LALT_T(KC_B),       RALT_T(KC_N), LGUI_T(KC_M), KC_COMM, KC_DOT, KC_SLSH,
                                              LT(_NUM, KC_SPC),   MO(_FKEY)
  ),
  
  // number/symbol layer
  [_NUM] = LAYOUT_4900_keeb_for_me_default(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  
    KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TILD,                  KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, 
                                        KC_TRNS,                  KC_LSFT            
  ),

  // navigation layer
  [_NAV] = LAYOUT_4900_keeb_for_me_default(
    KC_TRNS,   KC_TRNS,  KC_UP  ,  KC_TRNS,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_PGUP,    KC_TRNS,   KC_TRNS,   
    KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,            KC_TRNS,    KC_HOME,    KC_PGDN,    KC_END ,   KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS, 
                                             KC_LCTL,            KC_LSFT
  ),
  
  // F-key layer
  [_FKEY] = LAYOUT_4900_keeb_for_me_default(
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   MO(_Reset)  ,   
    KC_F5,   KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
    KC_F1,   KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS, 
                                        KC_TRNS,            KC_TRNS
  ),

  // have to get through F-key layer to get to reset layer/key to make sure no accidental microcontroller resets
  [_RESET] = LAYOUT_4900_keeb_for_me_default(
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   
    KC_TRNS,   KC_TRNS,  QK_BOOT,  QK_RBT ,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS, 
                                             KC_TRNS,            KC_TRNS
  ),
};

// Combos! 
enum combos {
  LCLN_QUOT,
  KL_ENTER,
  QW_ESC,
  WE_TAB,
  IO_BKSP,
  GH_CAPS
};

// combo definitions
const uint16_t PROGMEM lcln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM kl_combo[]   = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM qw_combo[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[]   = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[]   = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM gh_combo[]   = {KC_G, KC_H, COMBO_END};

// pressing the keys listed in the parameters within the defined combo time term leads to an output of the COMBO()'s second parameter. Default term is 50ms though which feels good.
combo_t key_combos[] = {
  [LCLN_QUOT] = COMBO(lcln_combo, KC_QUOT),
  [KL_ENTER]  = COMBO(kl_combo, KC_ENT),
  [QW_ESC]    = COMBO(qw_combo, KC_ESC),
  [WE_TAB]    = COMBO(we_combo, KC_TAB),
  [IO_BKSP]   = COMBO(io_combo, KC_BSPC),
  [GH_CAPS]   = COMBO(gh_combo, KC_CAPS),
};