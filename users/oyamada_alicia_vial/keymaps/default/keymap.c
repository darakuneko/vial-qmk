/* Copyright 2021 daraku-neko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    MT(MOD_LALT,KC_ESC), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,   KC_RBRC,    
    MT(MOD_LCTL,KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   KC_BSLS,
    KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LGUI,             KC_LALT, MO(1),   KC_SPC,    KC_ENT,    LT(1, KC_BSPC),  KC_RALT, KC_RGUI               
  ),

  [1] = LAYOUT(
    KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10, KC_F11,  KC_F12, 
    KC_NO,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,  KC_NO,   KC_NO, 
    MO(3),   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, S(KC_MINS), KC_EQL, S(KC_EQL), KC_NO,  KC_NO, 
    KC_NO,   KC_NO,    KC_LSFT,  KC_NO,    KC_DEL,   KC_LSFT,    KC_NO,    KC_NO         
  ),
 
  [2] = LAYOUT( 
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,  KC_NO, KC_NO, 
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,  KC_NO, KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,  KC_NO, 
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
  ),

  [3] = LAYOUT( 
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    RGB_MOD,    RGB_TOG,  KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,  KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    RGB_RMOD,   KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,  KC_NO,   
    KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO, 
    KC_NO,    KC_NO,      KC_NO,    EE_CLR,    QK_BOOT,  KC_NO,    KC_NO,    KC_NO
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { 
  int is_layer = get_highest_layer(layer_state|default_layer_state);  
  HSV hsv = {0, 255, rgblight_get_val()};
  if (is_layer == 1) {
    hsv.h = 128; //CYAN
  } else if (is_layer == 2)  {
    hsv.h = 85; //GREEN
  } else if (is_layer == 3)  {
    hsv.h = 43; //YELLOW
  } else {
    hsv.h = 191; //PURPLE
  }
  RGB rgb = hsv_to_rgb(hsv);

  
  for (uint8_t i = led_min; i <= led_max -1; i++) {
      if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
  }
  return false;
}  


