/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
//#include "g/keymap_combo.h"

enum layers {
    BASE = 0,
    SIMP,
    QWER,
    GAMB,
    GAMX,
    NAVR,
    MOUR,
    MEDR,
    FUNL,
    NSL,
    NSSL,
    LOCK,
};

enum custom_keycodes {
    TODEFAL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TODEFAL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
        } else {
            // when keycode QMKBEST is released
            layer_move(default_layer_state); // Switch to default layer
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |NSL/ESC |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCtrl/BS|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  | LCtrl/;|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt |      |  |      | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | MEDR |LShift| NAVR | MOUR |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume| LGUI | Esc  |Space |Enter |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
      LT(NSL, KC_ESC), KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
      LCTL_T(KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LCTL_T(KC_SCLN),
      KC_TAB,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LALT, _______,     _______, KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
      TG(LOCK), LT(MEDR, KC_LGUI), LSFT_T(KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_ENT), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Base Layer: Colemak (simple)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | BSpc   |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | NAVR |  |      |      |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume|      |      |      |      |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [SIMP] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
      KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  MO(NAVR), MO(MOUR), KC_LCTL, KC_LALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                  TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Alternate Layer: Qwerty
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |NSL/ESC |   Q  |   W  |   E  |   R  |   T  |                              |  \ | |   Y  |   U  |   I  |   O  |   P    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCtrl/BS|   A  |   S  |   D  |   F  |   G  |                              |  ' " |   H  |   J  |   K  |   L  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   V  |   B  |      | BASE |  |      | - _  |  / ? |   B  |  N   |   M  |  , < |  . >   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume|      |      |      |      |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWER] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LALT, _______,  _______, KC_MINS, KC_SLSH, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Base game Layer: GAMB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   T  |   Q  |   W  |   E  |   R  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   | Ctrl |   A  |   S  |   D  |   F  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   M    |   Z  |   X  |   C  |   V  |   B  |   N  | BASE |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LAlt |LShift|Space |Enter |  |      |      |      |      |      |
 *                        |Volume|      |      |      | GAMX |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [GAMB] = LAYOUT(
      KC_ESC,    KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                                   _______, _______, _______, _______, _______, _______,
      KC_TAB, KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,                                   _______, _______, _______, _______, _______, _______,
      KC_M,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_N, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     TO(LOCK), KC_LALT, KC_LSFT, KC_SPC, LT(GAMX, KC_ENT), _______, _______, _______, _______, TG(LOCK)
    ),
/*
 * Base game Layer: GAMX
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   F3   |   I  |   7  |   8  |   9  |   Y  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   F2   |   H  |   4  |   5  |   6  |   G  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   F1   |   0  |   1  |   2  |   3  |   O  |  F4  |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  F5  |  F6  |  F7  |  F8  |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [GAMX] = LAYOUT(
      KC_F3,    KC_I,    KC_7,    KC_8,    KC_9,    KC_Y,                                   _______, _______, _______, _______, _______, _______,
      KC_F2,    KC_H,    KC_4,    KC_5,    KC_6,    KC_G,                                   _______, _______, _______, _______, _______, _______,
      KC_F1,    KC_0,    KC_1,    KC_2,    KC_3,    KC_O, KC_F4, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                     KC_F5, KC_F6, KC_F7, KC_F8, _______, _______, _______, _______, _______, _______
    ),
    [NAVR] = LAYOUT(
      _______, KC_RST,  _______, _______, _______, _______,                                     KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, KC_ALGR, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                 _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______
    ),
    [MOUR] = LAYOUT(
      _______, KC_RST,  _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
      _______, _______, KC_ALGR, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                 _______, _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
    ),
    [MEDR] = LAYOUT(
      _______, KC_RST,  _______, _______, _______, _______,                                     KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,  _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
      _______, _______, KC_ALGR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
    ),
    [FUNL] = LAYOUT(
      _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_APP,  KC_SPC,  KC_TAB,  _______, _______, _______, _______, _______
    ),
    [NSL] = LAYOUT(
      _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_DOT,  KC_0,    KC_MINS, _______, _______, _______, _______, _______
    ),
    [NSSL] = LAYOUT(
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [LOCK] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                TODEFAL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TODEFAL
    ),

/*
    // Frogpad zone
    [FROG] = LAYOUT(
             KC_ESC,    KC_F,    KC_D,    KC_N,    KC_I,    KC_G,                                     _______, _______, _______, _______, _______, _______,
      LT(FEXT, KC_BSPC),KC_S,    KC_T,    KC_H,    KC_E,    KC_O,                                     _______, _______, _______, _______, _______, _______,
      OSM(MOD_LSFT),    KC_C,    KC_W,    KC_R,    KC_A,    KC_U,TO(BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, OSL(FNUM), KC_SPC, OSL(FSYM), _______, _______, _______, _______, _______
    ),
    [FSYM] = LAYOUT(
            KC_TAB,KC_LBRC,S(KC_LBRC), S(KC_9), S(KC_2), S(KC_6),                                     _______, _______, _______, _______, _______, _______,
         KC_BSLS,S(KC_SCLN),KC_SCLN,S(KC_SLSH), S(KC_1), KC_SLSH,                                     _______, _______, _______, _______, _______, _______,
         S(KC_GRV),KC_RBRC,S(KC_RBRC), S(KC_0), S(KC_7), S(KC_8), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [FNUM] = LAYOUT(
            KC_PEQL,    KC_6,    KC_7,    KC_8,    KC_9,  KC_DOT,                                     _______, _______, _______, _______, _______, _______,
            KC_PPLS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     _______, _______, _______, _______, _______, _______,
            KC_PMNS, S(KC_3), S(KC_4), S(KC_5),    KC_0, KC_COMM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, OSM(MOD_LGUI), _______, _______, _______, _______, _______
    ),
    [FEXT] = LAYOUT(
        _______,     KC_WBAK, KC_HOME,   KC_UP,  KC_END, KC_WFWD,                                     _______, _______, _______, _______, _______, _______,
        _______, LCA(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                                     _______, _______, _______, _______, _______, _______,
        _______,   C(KC_Z),C(KC_X),C(KC_C),C(KC_V),OSM(MOD_LALT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, OSM(MOD_LSFT),C(KC_BSPC),OSM(MOD_LCTL), _______, _______, _______, _______, _______
    ),
*/

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void keyboard_post_init_user(void) {
	#ifdef RGBLIGHT_ENABLE
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(130, 255, 150);
	//rgblight_sethsv_range(255.3, 18.4, 100, 0, 10);
	//rgblight_sethsv_range(180, 26.5, 93.3, 10, 20);
	#endif
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_feral_logo(void) {
    static const char PROGMEM feral_logo[] = {
    	// 'feralflux1edit', 128x64px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
		0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 
		0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 
		0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x0c, 0x0c, 
		0x0c, 0x00, 0x00, 0x00, 0xff, 0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xc0, 0x00, 0x00, 0xff, 0xff, 0x1c, 
		0x3c, 0x7c, 0xef, 0xc7, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x0c, 0x0c, 0xff, 0xff, 0x00, 0x00, 0xff, 
		0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x40, 0x40, 0x40, 0xf8, 0x08, 0x48, 0x6f, 0x08, 0x6f, 0x08, 0x6f, 0x08, 0x6f, 0x08, 0x08, 0xfc, 
		0xfc, 0x08, 0x08, 0x6f, 0x08, 0x6f, 0x08, 0x6f, 0x08, 0xef, 0x08, 0x08, 0xf8, 0x40, 0x40, 0x40, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x17, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x4a, 0x57, 0x08, 0xb5, 0x03, 0x4a, 0x1d, 0x00, 0x00, 0x56, 0x19, 0x00, 
		0x00, 0x00, 0x26, 0x9d, 0x00, 0x00, 0x15, 0x4f, 0x00, 0x00, 0x00, 0x4b, 0x2e, 0x00, 0x00, 0x53, 
		0xba, 0x01, 0x26, 0x49, 0x35, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x15, 0x15, 0x95, 0xff, 0x80, 0x91, 0x97, 0x80, 0xbf, 0x81, 0xb5, 0x81, 0xbd, 0x01, 0x80, 0xdf, 
		0xdf, 0x80, 0x01, 0xbd, 0x85, 0xb5, 0x85, 0x95, 0x95, 0x95, 0x94, 0x80, 0xff, 0x95, 0x15, 0x15, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x11, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x09, 0x22, 0x04, 0x08, 0x01, 0x24, 0x01, 0x00, 0x00, 0x82, 0x11, 0x00, 
		0x00, 0x00, 0x82, 0x10, 0x00, 0x00, 0x02, 0x21, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x48, 
		0x21, 0x06, 0x91, 0x08, 0x22, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xa8, 0xa8, 0xa9, 0xff, 0x01, 0xa9, 0xa9, 0x89, 0xb9, 0x81, 0xad, 0x21, 0xad, 0x20, 0x01, 0xfb, 
		0xfb, 0x01, 0xa0, 0xbd, 0x81, 0xa9, 0x09, 0xa9, 0xa9, 0xa9, 0xa9, 0x01, 0xff, 0xa9, 0xa8, 0xa8, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 
		0xfe, 0x66, 0x66, 0x66, 0x66, 0x06, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x06, 0x9e, 0xf8, 0x60, 0xf8, 0x9e, 
		0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x02, 0x02, 0x02, 0x1f, 0x10, 0x12, 0xf2, 0x10, 0xf6, 0x10, 0xf2, 0x12, 0xf3, 0x10, 0x10, 0x3f, 
		0x3f, 0x10, 0x12, 0xf6, 0x10, 0xf7, 0x10, 0xf6, 0x10, 0xf6, 0x10, 0x10, 0x1f, 0x02, 0x02, 0x02, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 
		0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x37, 0xce, 0x5e, 0x06, 0x5e, 0x96, 0x00, 
		0x00, 0xb7, 0x1f, 0x2e, 0xb6, 0x1e, 0xb7, 0x6f, 0x00, 0x00, 0x2e, 0x77, 0x01, 0x00, 0x01, 0x2f, 
		0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 
		0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x08, 0x20, 0x06, 0x90, 0x05, 0x48, 0x00, 
		0x00, 0x48, 0x09, 0x13, 0x88, 0x01, 0x08, 0x21, 0x00, 0x00, 0x85, 0x22, 0x00, 0x00, 0x00, 0x25, 
		0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(feral_logo, sizeof(feral_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.2\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Default: "), false);
    switch(default_layer_state) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case SIMP:
            oled_write_P(PSTR("Simple\n"), false);
            break;
        case QWER:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case GAMB:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case SIMP:
            oled_write_P(PSTR("Simple\n"), false);
            break;
        case QWER:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case GAMB:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case GAMX:
            oled_write_P(PSTR("Gaming Ext\n"), false);
            break;
        case NAVR:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case MOUR:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case MEDR:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case FUNL:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case NSL:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case NSSL:
            oled_write_P(PSTR("Shifted Nums\n"), false);
            break;
        case LOCK:
            oled_write_P(PSTR("Locked\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_feral_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state) != LOCK) {
        if (index == 0) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
        else if (index == 1) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    }
    else {
        if (index == 1) {
            // Layer switching
            if (clockwise) {
                //scroll down base layer list
                default_layer_set((default_layer_state-1) % 4);
            } else {
                //scroll up base layer list
                default_layer_set((default_layer_state+1) % 4);
            }
        }
    }
}
#endif
