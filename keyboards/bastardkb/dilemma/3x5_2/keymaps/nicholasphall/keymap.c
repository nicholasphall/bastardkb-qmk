/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
};

//#define NAV MO(LAYER_NAV)
//#define SYM MO(LAYER_SYM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭──────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├──────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├──────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰──────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                   KC_TAB,  KC_SPC,      KC_ENT, KC_BSPC
  //                             ╰──────────────────╯ ╰──────────────────╯
  ),

};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=false;
  debug_mouse=true;
}

// Key Combos
enum combos {
  QW_ESC,

  CO_LSFT,
  CO_RSFT,

  CO_LGUI,
  CO_RGUI,

  CO_LCTL,
  CO_RCTL,

  CO_LALT,
  CO_RALT,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM co_lsft[] = {KC_A, KC_SPC, COMBO_END};
const uint16_t PROGMEM co_rsft[] = {KC_QUOT, KC_ENT, COMBO_END};

const uint16_t PROGMEM co_lgui[] = {KC_SPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM co_rgui[] = {KC_ENT, KC_BSPC, COMBO_END};

const uint16_t PROGMEM co_lctl[] = {KC_Z, KC_TAB, COMBO_END};
const uint16_t PROGMEM co_rctl[] = {KC_SLSH, KC_BSPC, COMBO_END};

const uint16_t PROGMEM co_lalt[] = {KC_Z, KC_SPC, COMBO_END};
const uint16_t PROGMEM co_ralt[] = {KC_SLSH, KC_ENT, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),

  [CO_LSFT] = COMBO(co_lsft, KC_LSFT),
  [CO_RSFT] = COMBO(co_rsft, KC_RSFT),

  [CO_LGUI] = COMBO(co_lgui, KC_LGUI),
  [CO_RGUI] = COMBO(co_rgui, KC_RGUI),

  [CO_LCTL] = COMBO(co_lctl, KC_LCTL),
  [CO_RCTL] = COMBO(co_rctl, KC_RCTL),

  [CO_LALT] = COMBO(co_lalt, KC_LALT),
  [CO_RALT] = COMBO(co_ralt, KC_RALT),
};

uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);
