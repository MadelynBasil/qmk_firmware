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
#include "keymap_jp.h"

enum layers {
    BASE = 0,
    SIMP,
    QWER,
    TRON,
    GAMB,
    LTRN,
    RTRN,
    GAMX,
    NAVR,
    MOUR,
    MEDR,
    FUNL,
    NSL,
    NSSL,
    ACNT,
    LOCK,
};

enum custom_keycodes {
    TODEFAL = SAFE_RANGE,
};

enum unicode_names {
    LNT,
    UNT,
    UAA,
    LAA,
    UAE,
    LAE,
    UAI,
    LAI,
    UAO,
    LAO,
    UAU,
    LAU,
    INQS,
    INEX,
    BANG,
    IRONY,
    SNEK,
    // Stuff for Japanese!
    HLA,HLI,HLU,HLE,HLO,
    HLKA,HLKI,HLKU,HLKE,HLKO,
    HLSA,HLSI,HLSU,HLSE,HLSO,
    HLTA,HLTI,HLTU,HLTE,HLTO,
    HLNA,HLNI,HLNU,HLNE,HLNO,
    HLHA,HLHI,HLHU,HLHE,HLHO,
    HLMA,HLMI,HLMU,HLME,HLMO,
    HLYA,HLYU,HLYO,
    HLRA,HLRI,HLRU,HLRE,HLRO,
    HLWA,HLWI,HLWE,HLWO,
    HLN,
    HLGA,HLGI,HLGU,HLGE,HLGO,
    HLZA,HLZI,HLZU,HLZE,HLZO,
    HLDA,HLDI,HLDU,HLDE,HLDO,
    HLBA,HLBI,HLBU,HLBE,HLBO,
    HLPA,HLPI,HLPU,HLPE,HLPO,
    HLAS,HLIS,HLUS,HLES,HLOS,
    HLSTU,
    HLSYA,HLSYU,HLSYO,
    HLSWA,
    HLVU,
    HLSKA,HLSKE,
    WSPC,
    JCOM,
    JPER,
    JDIT,
    LAB,RAB,
    DLAB,DRAB,
    LCB,RCB,
    DLCB,DRCB,
    LLB,RLB,
    BTLD,
    CVSM,CSVSM,
    VSM,SVSM,
    KMD,
    PSM,
    FWC,FWP,
    HLYE,HLSI1
};

const uint32_t PROGMEM unicode_map[] = {
    [UNT]   = 0x00D1,  // Ñ
    [LNT]   = 0x00F1,  // ñ
    [UAA]   = 0x00C1,  // Á
    [LAA]   = 0x00E1,  // á
    [UAE]   = 0x00C9,  // É
    [LAE]   = 0x00E9,  // é
    [UAI]   = 0x00CD,  // Í
    [LAI]   = 0x00ED,  // í
    [UAO]   = 0x00D3,  // Ó
    [LAO]   = 0x00F3,  // ó
    [UAU]   = 0x00DA,  // Ú
    [LAU]   = 0x00FA,  // ú
    [INQS]  = 0x00BF,  // ¿
    [INEX]  = 0x00A1,  // ¡
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [WSPC] = 0x3000,
    [JCOM] = 0x3001,
    [JPER] = 0x3002,
    [JDIT] = 0x3003,
    [LAB] = 0x3008,
    [RAB] = 0x3009,
    [DLAB] = 0x300A,
    [DRAB] = 0x300B,
    [LCB] = 0x300C,
    [RCB] = 0x300D,
    [DLCB] = 0x300E,
    [DRCB] = 0x300F,
    [LLB] = 0x3010,
    [RLB] = 0x3011,
    [BTLD] = 0x301D,
    [HLAS] = 0x3041,
    [HLA] = 0x3042,
    [HLIS] = 0x3043,
    [HLI] = 0x3044,
    [HLUS] = 0x3045,
    [HLU] = 0x3046,
    [HLES] = 0x3047,
    [HLE] = 0x3048,
    [HLOS] = 0x3049,
    [HLO] = 0x304A,
    [HLKA] = 0x304B,
    [HLGA] = 0x304C,
    [HLKI] = 0x304D,
    [HLGI] = 0x304E,
    [HLKU] = 0x304F,
    [HLGU] = 0x3050,
    [HLKE] = 0x3051,
    [HLGE] = 0x3052,
    [HLKO] = 0x3053,
    [HLGO] = 0x3054,
    [HLSA] = 0x3055,
    [HLZA] = 0x3056,
    [HLSI] = 0x3057,
    [HLZI] = 0x3058,
    [HLSU] = 0x3059,
    [HLZU] = 0x305A,
    [HLSE] = 0x305B,
    [HLZE] = 0x305C,
    [HLSO] = 0x305D,
    [HLZO] = 0x305E,
    [HLTA] = 0x305F,
    [HLDA] = 0x3060,
    [HLTI] = 0x3061,
    [HLDI] = 0x3062,
    [HLSTU] = 0x3063,
    [HLTU] = 0x3064,
    [HLDU] = 0x3065,
    [HLTE] = 0x3066,
    [HLDE] = 0x3067,
    [HLTO] = 0x3068,
    [HLDO] = 0x3069,
    [HLNA] = 0x306A,
    [HLNI] = 0x306B,
    [HLNU] = 0x306C,
    [HLNE] = 0x306D,
    [HLNO] = 0x306E,
    [HLHA] = 0x306F,
    [HLBA] = 0x3070,
    [HLPA] = 0x3071,
    [HLHI] = 0x3072,
    [HLBI] = 0x3073,
    [HLPI] = 0x3074,
    [HLHU] = 0x3075,
    [HLBU] = 0x3076,
    [HLPU] = 0x3077,
    [HLHE] = 0x3078,
    [HLBE] = 0x3079,
    [HLPE] = 0x307A,
    [HLHO] = 0x307B,
    [HLBO] = 0x307C,
    [HLPO] = 0x307D,
    [HLMA] = 0x307E,
    [HLMI] = 0x307F,
    [HLMU] = 0x3080,
    [HLME] = 0x3081,
    [HLMO] = 0x3082,
    [HLSYA] = 0x3083,
    [HLYA] = 0x3084,
    [HLSYU] = 0x3085,
    [HLYU] = 0x3086,
    [HLSYO] = 0x3087,
    [HLYO] = 0x3088,
    [HLRA] = 0x3089,
    [HLRI] = 0x308A,
    [HLRU] = 0x308B,
    [HLRE] = 0x308C,
    [HLRO] = 0x308D,
    [HLSWA] = 0x308E,
    [HLWA] = 0x308F,
    [HLWI] = 0x3090,
    [HLWE] = 0x3091,
    [HLWO] = 0x3092,
    [HLN] = 0x3093,
    [HLVU] = 0x3094,
    [HLSKA] = 0x3095,
    [HLSKE] = 0x3096,
    [CVSM] = 0x3099,
    [CSVSM] = 0x309A,
    [VSM] = 0x309B,
    [SVSM] = 0x309C,
    [KMD] = 0x30FB,
    [PSM] = 0x30FC,
    [FWC] = 0xFF0C,
    [FWP] = 0xFF0E,
    [HLYE] = 0x1B001,
    [HLSI1] = 0x1B044
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |ACNT/ESC|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " | ACNT/\ |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCtrl/BS|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  | LCtrl/;|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | TRON |  |      | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | MEDR |LShift| NAVR | MOUR |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume| LGUI | Esc  |Space |Enter |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
      LT(ACNT, KC_ESC),KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, LT(ACNT, KC_BSLS),
      LCTL_T(KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LCTL_T(KC_SCLN),
      KC_TAB,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LALT, TG(TRON),    _______, KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
      TG(LOCK), LT(MEDR, KC_LGUI), LSFT_T(KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_ENT), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Base Layer: Colemak (simple)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | BASE |  |  NSL | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [SIMP] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_LALT,TG(BASE), MO(NSL), KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Alternate Layer: Qwerty
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |  \ | |   Y  |   U  |   I  |   O  |   P    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |  ' " |   H  |   J  |   K  |   L  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   V  |   B  | LALT | BASE |  |  NSL | - _  |  / ? |   B  |  N   |   M  |  , < |  . >   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWER] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LALT, TG(BASE), MO(NSL), KC_MINS, KC_SLSH, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT,  KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Layer: TRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |  ら  |  る  |  こ  |  は  |  ょ  |                              |  き  |  の  |  く  |  あ  |  れ  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |  た  |  と  |  か  |  て  |  も  |                              |  を  |  い  |  う  |  し  |  ん  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |  ま  |  り  |  に  |  さ  |  な  | LAlt | BASE |  | UFOR |hirkat|  す  |  つ  |  、  |  。  |  っ  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK |無変換|LTron |FWSpc |Enter |  |Enter | BSpc |RTron | 変換 | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [TRON] = LAYOUT(
      KC_ESC,  X(HLRA), X(HLRU), X(HLKO), X(HLHA), X(HLSYO),                                                 X(HLKI), X(HLNO), X(HLKU), X(HLA),  X(HLRE),  _______,
      KC_LCTL, X(HLTA), X(HLTO), X(HLKA), X(HLTE), X(HLMO),                                                  X(HLWO), X(HLI),  X(HLU),  X(HLSI), X(HLN),   _______,
      KC_TAB,  X(HLMA), X(HLRI), X(HLNI), X(HLSA), X(HLNA), KC_LALT, TG(TRON),UNICODE_MODE_FORWARD, JP_KANA, X(HLSU), X(HLTU), X(JCOM), X(JPER), X(HLSTU), _______,
                                 TG(LOCK),JP_MHEN, MO(LTRN),X(WSPC),   KC_ENT,              KC_ENT, KC_BSPC, MO(RTRN),JP_HENK, TG(LOCK)
    ),
/*
 * Base game Layer: GAMB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   T  |   Q  |   W  |   E  |   R  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   | Ctrl |   A  |   S  |   D  |   F  |                              |      | Left | Down |  Up  |Right |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   M    |   Z  |   X  |   C  |   V  |   B  |   N  | BASE |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LAlt |LShift|Space |Enter |  |      |      |      |      |      |
 *                        |Volume|      |      |      | GAMX |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [GAMB] = LAYOUT(
      KC_ESC,    KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                                   _______, _______, _______, _______, _______, _______,
      KC_TAB, KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,                                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      KC_M,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_N, TG(BASE), _______, _______, _______, _______, _______, _______, _______, _______,
                    TO(LOCK), KC_LALT, KC_LSFT, KC_SPC, LT(GAMX, KC_ENT), _______, _______, _______, _______, TG(LOCK)
    ),
/*
 * Layer: LTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  ひ  |  そ  |  ・  |  ゃ  |  ほ  |                              |  ぎ  |  げ  |  ぐ  |      |  ゐ  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ぬ  |  ね  |  ゅ  |  よ  |  ふ  |                              |  ゛  |  ぢ  |  ゔ  |  じ  |  ゑ  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ぇ  |  ぉ  |  せ  |  ゆ  |  へ  |  𛀁  |      |  |      |      |  ず  |  づ  |  ，  |  ．  |  ゎ  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LTRN] = LAYOUT(
      _______, X(HLHI), X(HLSO), X(KMD),  X(HLSYA),X(HLHO),                                     X(HLGI), X(HLGE), X(HLGU), KC_SPC,  X(HLWI), _______,
      _______, X(HLNU), X(HLNE), X(HLSYU),X(HLYO), X(HLHU),                                     X(CVSM), X(HLDI), X(HLVU), X(HLZI), X(HLWE), _______,
      _______, X(HLES), X(HLOS), X(HLSE), X(HLYU), X(HLHE), X(HLYE), _______, _______, _______, X(HLZU), X(HLDU), X(FWC),  X(FWP),  X(HLSWA),_______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Layer: RTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  び  |  ぞ  |  ご  |  ば  |  ぼ  |                              |  え  |  け  |  め  |  む  |  ろ  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  だ  |  ど  |  が  |  で  |  ぶ  |                              |  お  |  ち  |  ー  |  み  |  や  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ゕ  |  ゖ  |  ぜ  |  ざ  |  べ  |      |      |  |      |      |  わ  |  ぃ  |  ぁ  |  ゜  |  ぅ  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RTRN] = LAYOUT(
      _______, X(HLBI), X(HLZO), X(HLGO), X(HLBA), X(HLBO),                                     X(HLE),  X(HLKE), X(HLME), X(HLMU), X(HLRO), _______,
      _______, X(HLDA), X(HLDO), X(HLGA), X(HLDE), X(HLBU),                                     X(HLO),  X(HLTI), X(PSM),  X(HLMI), X(HLYA), _______,
      _______, X(HLSKA),X(HLSKE),X(HLZE), X(HLZA), X(HLBE), _______, _______, _______, _______, X(HLWA), X(HLIS), X(HLAS), X(CSVSM),X(HLUS), _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
                                 _______, KC_PLUS, KC_MINS, KC_0,    KC_DOT,  _______, _______, _______, _______, _______
    ),
    [NSSL] = LAYOUT(
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [LOCK] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TODEFAL:
        if (record->event.pressed) {
            // when keycode TODEFAL is pressed
        } else {
            // when keycode TODEFAL is released
            layer_move(default_layer_state); // Switch to default layer
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
	#ifdef RGBLIGHT_ENABLE
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(198, 255, 230);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
            break;
        case LTRN:
            oled_write_P(PSTR("Left Shift\n"), false);
            break;
        case RTRN:
            oled_write_P(PSTR("Right Shift\n"), false);
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
    oled_write_P(PSTR("Unicode: "), false);
    switch (get_unicode_input_mode()) {
        case UC_LNX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        case UC_WINC:
            oled_write_P(PSTR("Win Compose\n"), false);
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
        } else if (index == 1) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    } else {
        // Layer switching
        if (clockwise) {
            //scroll down base layer list
            default_layer_set((default_layer_state-1) % 5);
        } else {
            //scroll up base layer list
            default_layer_set((default_layer_state+1) % 5);
        }
    }
}
#endif

    UAE,
    LAE,
    UAI,
    LAI,
    UAO,
    LAO,
    UAU,
    LAU,
    INQS,
    INEX,
    BANG,
    IRONY,
    SNEK,
    // Stuff for Japanese!
    HLA,HLI,HLU,HLE,HLO,
    HLKA,HLKI,HLKU,HLKE,HLKO,
    HLSA,HLSI,HLSU,HLSE,HLSO,
    HLTA,HLTI,HLTU,HLTE,HLTO,
    HLNA,HLNI,HLNU,HLNE,HLNO,
    HLHA,HLHI,HLHU,HLHE,HLHO,
    HLMA,HLMI,HLMU,HLME,HLMO,
    HLYA,HLYU,HLYO,
    HLRA,HLRI,HLRU,HLRE,HLRO,
    HLWA,HLWI,HLWE,HLWO,
    HLN,
    HLGA,HLGI,HLGU,HLGE,HLGO,
    HLZA,HLZI,HLZU,HLZE,HLZO,
    HLDA,HLDI,HLDU,HLDE,HLDO,
    HLBA,HLBI,HLBU,HLBE,HLBO,
    HLPA,HLPI,HLPU,HLPE,HLPO,
    HLAS,HLIS,HLUS,HLES,HLOS,
    HLSTU,
    HLSYA,HLSYU,HLSYO,
    HLSWA,
    HLVU,
    HLSKA,HLSKE,
    WSPC,
    JCOM,
    JPER,
    JDIT,
    LAB,RAB,
    DLAB,DRAB,
    LCB,RCB,
    DLCB,DRCB,
    LLB,RLB,
    BTLD,
    CVSM,CSVSM,
    VSM,SVSM,
    KMD,
    PSM,
    FWC,FWP,
    HLYE,HLSI1
};

const uint32_t PROGMEM unicode_map[] = {
    [UNT]   = 0x00D1,  // Ñ
    [LNT]   = 0x00F1,  // ñ
    [UAA]   = 0x00C1,  // Á
    [LAA]   = 0x00E1,  // á
    [UAE]   = 0x00C9,  // É
    [LAE]   = 0x00E9,  // é
    [UAI]   = 0x00CD,  // Í
    [LAI]   = 0x00ED,  // í
    [UAO]   = 0x00D3,  // Ó
    [LAO]   = 0x00F3,  // ó
    [UAU]   = 0x00DA,  // Ú
    [LAU]   = 0x00FA,  // ú
    [INQS]  = 0x00BF,  // ¿
    [INEX]  = 0x00A1,  // ¡
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [WSPC] = 0x3000,
    [JCOM] = 0x3001,
    [JPER] = 0x3002,
    [JDIT] = 0x3003,
    [LAB] = 0x3008,
    [RAB] = 0x3009,
    [DLAB] = 0x300A,
    [DRAB] = 0x300B,
    [LCB] = 0x300C,
    [RCB] = 0x300D,
    [DLCB] = 0x300E,
    [DRCB] = 0x300F,
    [LLB] = 0x3010,
    [RLB] = 0x3011,
    [BTLD] = 0x301D,
    [HLAS] = 0x3041,
    [HLA] = 0x3042,
    [HLIS] = 0x3043,
    [HLI] = 0x3044,
    [HLUS] = 0x3045,
    [HLU] = 0x3046,
    [HLES] = 0x3047,
    [HLE] = 0x3048,
    [HLOS] = 0x3049,
    [HLO] = 0x304A,
    [HLKA] = 0x304B,
    [HLGA] = 0x304C,
    [HLKI] = 0x304D,
    [HLGI] = 0x304E,
    [HLKU] = 0x304F,
    [HLGU] = 0x3050,
    [HLKE] = 0x3051,
    [HLGE] = 0x3052,
    [HLKO] = 0x3053,
    [HLGO] = 0x3054,
    [HLSA] = 0x3055,
    [HLZA] = 0x3056,
    [HLSI] = 0x3057,
    [HLZI] = 0x3058,
    [HLSU] = 0x3059,
    [HLZU] = 0x305A,
    [HLSE] = 0x305B,
    [HLZE] = 0x305C,
    [HLSO] = 0x305D,
    [HLZO] = 0x305E,
    [HLTA] = 0x305F,
    [HLDA] = 0x3060,
    [HLTI] = 0x3061,
    [HLDI] = 0x3062,
    [HLSTU] = 0x3063,
    [HLTU] = 0x3064,
    [HLDU] = 0x3065,
    [HLTE] = 0x3066,
    [HLDE] = 0x3067,
    [HLTO] = 0x3068,
    [HLDO] = 0x3069,
    [HLNA] = 0x306A,
    [HLNI] = 0x306B,
    [HLNU] = 0x306C,
    [HLNE] = 0x306D,
    [HLNO] = 0x306E,
    [HLHA] = 0x306F,
    [HLBA] = 0x3070,
    [HLPA] = 0x3071,
    [HLHI] = 0x3072,
    [HLBI] = 0x3073,
    [HLPI] = 0x3074,
    [HLHU] = 0x3075,
    [HLBU] = 0x3076,
    [HLPU] = 0x3077,
    [HLHE] = 0x3078,
    [HLBE] = 0x3079,
    [HLPE] = 0x307A,
    [HLHO] = 0x307B,
    [HLBO] = 0x307C,
    [HLPO] = 0x307D,
    [HLMA] = 0x307E,
    [HLMI] = 0x307F,
    [HLMU] = 0x3080,
    [HLME] = 0x3081,
    [HLMO] = 0x3082,
    [HLSYA] = 0x3083,
    [HLYA] = 0x3084,
    [HLSYU] = 0x3085,
    [HLYU] = 0x3086,
    [HLSYO] = 0x3087,
    [HLYO] = 0x3088,
    [HLRA] = 0x3089,
    [HLRI] = 0x308A,
    [HLRU] = 0x308B,
    [HLRE] = 0x308C,
    [HLRO] = 0x308D,
    [HLSWA] = 0x308E,
    [HLWA] = 0x308F,
    [HLWI] = 0x3090,
    [HLWE] = 0x3091,
    [HLWO] = 0x3092,
    [HLN] = 0x3093,
    [HLVU] = 0x3094,
    [HLSKA] = 0x3095,
    [HLSKE] = 0x3096,
    [CVSM] = 0x3099,
    [CSVSM] = 0x309A,
    [VSM] = 0x309B,
    [SVSM] = 0x309C,
    [KMD] = 0x30FB,
    [PSM] = 0x30FC,
    [FWC] = 0xFF0C,
    [FWP] = 0xFF0E,
    [HLYE] = 0x1B001,
    [HLSI1] = 0x1B044
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |ACNT/ESC|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " | ACNT/\ |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCtrl/BS|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  | LCtrl/;|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | TRON |  | UFOR | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | MEDR |LShift| NAVR | MOUR |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume| LGUI | Esc  |Space |Enter |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
      LT(ACNT, KC_ESC),KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, LT(ACNT, KC_BSLS),
      LCTL_T(KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                              KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LCTL_T(KC_SCLN),
      KC_TAB,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LALT, TO(TRON),UNICODE_MODE_FORWARD, KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
      TG(LOCK), LT(MEDR, KC_LGUI), LSFT_T(KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_ENT), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Base Layer: Colemak (simple)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | NAVR |  |  NSL | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [SIMP] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_LALT, MO(NAVR), MO(NSL), KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Alternate Layer: Qwerty
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |  \ | |   Y  |   U  |   I  |   O  |   P    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |  ' " |   H  |   J  |   K  |   L  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   V  |   B  | LALT | NAVR |  |  NSL | - _  |  / ? |   B  |  N   |   M  |  , < |  . >   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWER] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LALT, MO(NAVR), MO(NSL), KC_MINS, KC_SLSH, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Layer: TRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |  ら  |  る  |  こ  |  は  |  ょ  |                              |  き  |  の  |  く  |  あ  |  れ  |半角全角|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |  た  |  と  |  か  |  て  |  も  |                              |  を  |  い  |  う  |  し  |  ん  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |  ま  |  り  |  に  |  さ  |  な  | LAlt | BASE |  | UBAK |hirkat|  す  |  つ  |  、  |  。  |  っ  |  英数  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK |Enter |LTron |FWSpc |無変換|  | 変換 | BSpc |RTron |Enter | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [TRON] = LAYOUT(
      KC_ESC,  X(HLRA), X(HLRU), X(HLKO), X(HLHA), X(HLSYO),                                                             X(HLKI), X(HLNO), X(HLKU), X(HLA),  X(HLRE),  JP_ZKHK,
      KC_LCTL, X(HLTA), X(HLTO), X(HLKA), X(HLTE), X(HLMO),                                                              X(HLWO), X(HLI),  X(HLU),  X(HLSI), X(HLN),   _______,
      KC_TAB,  X(HLMA), X(HLRI), X(HLNI), X(HLSA), X(HLNA), KC_LALT, TO(BASE),UNICODE_MODE_FORWARD, JP_KANA, X(HLSU), X(HLTU), X(JCOM), X(JPER), X(HLSTU), JP_EISU,
                                 TG(LOCK),KC_ENT,  MO(LTRN),X(WSPC), JP_MHEN,                          JP_HENK, KC_BSPC, MO(RTRN),KC_ENT,  TG(LOCK)
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
      KC_ESC,    KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                                    _______, _______, _______, _______, _______, _______,
      KC_TAB, KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,                                    _______, _______, _______, _______, _______, _______,
      KC_M,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_N, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
                     TO(LOCK), KC_LALT, KC_LSFT, KC_SPC, LT(GAMX, KC_ENT), _______, _______, _______, _______, TG(LOCK)
    ),
/*
 * Layer: LTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  ひ  |  そ  |  ・  |  ゃ  |  ほ  |                              |  ぎ  |  げ  |  ぐ  |      |  ゐ  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   𛀁   |  ぬ  |  ね  |  ゅ  |  よ  |  ふ  |                              |  ゛  |  ぢ  |  ゔ  |  じ  |  ゑ  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   𛁄   |  ぇ  |  ぉ  |  せ  |  ゆ  |  へ  |      |      |  |      |      |  ず  |  づ  |  ，  |  ．  |  ゎ  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LTRN] = LAYOUT(
      _______, X(HLHI), X(HLSO), X(KMD),  X(HLSYA),X(HLHO),                                     X(HLGI), X(HLGE), X(HLGU), KC_SPC,  X(HLWI), _______,
      X(HLYE), X(HLNU), X(HLNE), X(HLSYU),X(HLYO), X(HLHU),                                     X(CVSM), X(HLDI), X(HLVU), X(HLZI), X(HLWE), _______,
      X(HLSI1),X(HLES), X(HLOS), X(HLSE), X(HLYU), X(HLHE), _______, _______, _______, _______, X(HLZU), X(HLDU), X(FWC),  X(FWP),  X(HLSWA),_______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Layer: RTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  び  |  ぞ  |  ご  |  ば  |  ぼ  |                              |  え  |  け  |  め  |  む  |  ろ  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  だ  |  ど  |  が  |  で  |  ぶ  |                              |  お  |  ち  |  ー  |  み  |  や  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ゕ  |  ゖ  |  ぜ  |  ざ  |  べ  |      |      |  |      |      |  わ  |  ぃ  |  ぁ  |  ゜  |  ぅ  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RTRN] = LAYOUT(
      _______, X(HLBI), X(HLZO), X(HLGO), X(HLBA), X(HLBO),                                     X(HLE),  X(HLKE), X(HLME), X(HLMU), X(HLRO), _______,
      _______, X(HLDA), X(HLDO), X(HLGA), X(HLDE), X(HLBU),                                     X(HLO),  X(HLTI), X(PSM),  X(HLMI), X(HLYA), _______,
      _______, X(HLSKA),X(HLSKE),X(HLZE), X(HLZA), X(HLBE), _______, _______, _______, _______, X(HLWA), X(HLIS), X(HLAS), X(CSVSM),X(HLUS), _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
                                 _______, KC_PLUS, KC_MINS, KC_0,    KC_DOT,  _______, _______, _______, _______, _______
    ),
    [NSSL] = LAYOUT(
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [LOCK] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TODEFAL:
        if (record->event.pressed) {
            // when keycode TODEFAL is pressed
        } else {
            // when keycode TODEFAL is released
            layer_move(default_layer_state); // Switch to default layer
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
	#ifdef RGBLIGHT_ENABLE
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(198, 255, 230);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
            break;
        case LTRN:
            oled_write_P(PSTR("Left Shift\n"), false);
            break;
        case RTRN:
            oled_write_P(PSTR("Right Shift\n"), false);
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
    oled_write_P(PSTR("Unicode: "), false);
    switch (get_unicode_input_mode()) {
        case UC_LNX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        case UC_WINC:
            oled_write_P(PSTR("Win Compose\n"), false);
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
        } else if (index == 1) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    } else {
        // Layer switching
        if (clockwise) {
            //scroll down base layer list
            default_layer_set((default_layer_state-1) % 5);
        } else {
            //scroll up base layer list
            default_layer_set((default_layer_state+1) % 5);
        }
    }
}
#endif

    SNEK,
    // Stuff for Japanese!
    A,JHI,U,E,O,
    KA,KI,KU,KE,KO,
    SA,SHI,SU,HSE,SO,
    TA,CHI,TSU,TE,TO,
    NA,NI,NU,NE,NO,
    HA,HI,FU,HE,HO,
    MA,MI,MU,ME,MO,
    YA,YU,YO,
    RA,RI,RU,RE,RO,
    WA,WI,WE,WO,
    N,
    GA,GI,GE,GU,GO,
    ZA,SJI,ZU,ZE,ZO,
    DA,TJI,TZU,DE,DO,
    BA,BI,BU,BE,BO,
    PA,PI,PU,PE,PO,
    AS,IS,US,ES,OS,
    TSUS,
    YAS,YUS,YOS,
    WAS,
    VU,
    KAS,KES,
    WSPC,
    JCOM,
    JPER,
    JDIT,
    LAB,RAB,
    DLAB,DRAB,
    LCB,RCB,
    DLCB,DRCB,
    LLB,RLB,
    BTLD,
    VCM,SVCM
};

const uint32_t PROGMEM unicode_map[] = {
    [UNT]   = 0x00D1,  // Ñ
    [LNT]   = 0x00F1,  // ñ
    [UAA]   = 0x00C1,  // Á
    [LAA]   = 0x00E1,  // á
    [UAE]   = 0x00C9,  // É
    [LAE]   = 0x00E9,  // é
    [UAI]   = 0x00CD,  // Í
    [LAI]   = 0x00ED,  // í
    [UAO]   = 0x00D3,  // Ó
    [LAO]   = 0x00F3,  // ó
    [UAU]   = 0x00DA,  // Ú
    [LAU]   = 0x00FA,  // ú
    [INQS]  = 0x00BF,  // ¿
    [INEX]  = 0x00A1,  // ¡
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [WSPC] = 0x3000,
    [JCOM] = 0x3001,
    [JPER] = 0x3002,
    [JDIT] = 0x3003,
    [LAB] = 0x3008,
    [RAB] = 0x3009,
    [DLAB] = 0x300A,
    [DRAB] = 0x300B,
    [LCB] = 0x300C,
    [RCB] = 0x300D,
    [DLCB] = 0x300E,
    [DRCB] = 0x300F,
    [LLB] = 0x3010,
    [RLB] = 0x3011,
    [BTLD] = 0x301D,
    [AS] = 0x3041,
    [A] = 0x3042,
    [IS] = 0x3043,
    [JHI] = 0x3044,
    [US] = 0x3045,
    [U] = 0x3046,
    [ES] = 0x3047,
    [E] = 0x3048,
    [OS] = 0x3049,
    [O] = 0x304A,
    [KA] = 0x304B,
    [GA] = 0x304C,
    [KI] = 0x304D,
    [GI] = 0x304E,
    [KU] = 0x304F,
    [GU] = 0x3050,
    [KE] = 0x3051,
    [GE] = 0x3052,
    [KO] = 0x3053,
    [GO] = 0x3054,
    [SA] = 0x3055,
    [ZA] = 0x3056,
    [SHI] = 0x3057,
    [SJI] = 0x3058,
    [SU] = 0x3059,
    [ZU] = 0x305A,
    [HSE] = 0x305B,
    [ZE] = 0x305C,
    [SO] = 0x305D,
    [ZO] = 0x305E,
    [TA] = 0x305F,
    [DA] = 0x3060,
    [CHI] = 0x3061,
    [TJI] = 0x3062,
    [TSUS] = 0x3063,
    [TSU] = 0x3064,
    [TZU] = 0x3065,
    [TE] = 0x3066,
    [DE] = 0x3067,
    [TO] = 0x3068,
    [DO] = 0x3069,
    [NA] = 0x306A,
    [NI] = 0x306B,
    [NU] = 0x306C,
    [NE] = 0x306D,
    [NO] = 0x306E,
    [HA] = 0x306F,
    [BA] = 0x3070,
    [PA] = 0x3071,
    [HI] = 0x3072,
    [BI] = 0x3073,
    [PI] = 0x3074,
    [FU] = 0x3075,
    [BU] = 0x3076,
    [PU] = 0x3077,
    [HE] = 0x3078,
    [BE] = 0x3079,
    [PE] = 0x307A,
    [HO] = 0x307B,
    [BO] = 0x307C,
    [PO] = 0x307D,
    [MA] = 0x307E,
    [MI] = 0x307F,
    [MU] = 0x3080,
    [ME] = 0x3081,
    [MO] = 0x3082,
    [YAS] = 0x3083,
    [YA] = 0x3084,
    [YUS] = 0x3085,
    [YU] = 0x3086,
    [YOS] = 0x3087,
    [YO] = 0x3088,
    [RA] = 0x3089,
    [RI] = 0x308A,
    [RU] = 0x308B,
    [RE] = 0x308C,
    [RO] = 0x308D,
    [WAS] = 0x308E,
    [WA] = 0x308F,
    [WI] = 0x3090,
    [WE] = 0x3091,
    [WO] = 0x3092,
    [N] = 0x3093,
    [VU] = 0x3094,
    [KAS] = 0x3095,
    [KES] = 0x3096,
    [VCM] = 0x309B,
    [SVCM] = 0x309C,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |ACNT/ESC|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " | ACNT/\ |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCtrl/BS|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  | LCtrl/;|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | UFOR |  | UBAK | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | MEDR |LShift| NAVR | MOUR |  | NSSL |  NSL |LShift| FUNL | LOCK |
 *                        |Volume| LGUI | Esc  |Space |Enter |  | Enter| BSpc |  Del | LGUI |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
      LT(ACNT, KC_ESC),KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, LT(ACNT, KC_BSLS),
      LCTL_T(KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                              KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LCTL_T(KC_SCLN),
      KC_TAB,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LALT, UNICODE_MODE_FORWARD,UNICODE_MODE_REVERSE, KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
      TG(LOCK), LT(MEDR, KC_LGUI), LSFT_T(KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_ENT), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LSFT_T(KC_DEL), LT(FUNL, KC_LGUI), TG(LOCK)
    ),
/*
 * Base Layer: Colemak (simple)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ' " |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   D  |   V  | LAlt | NAVR |  |  NSL | RAlt |   K  |   H  | ,  < | . >  |  / ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [SIMP] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_LALT, MO(NAVR), MO(NSL), KC_RALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Alternate Layer: Qwerty
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |  \ | |   Y  |   U  |   I  |   O  |   P    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |  ' " |   H  |   J  |   K  |   L  |  ; :   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Tab   |   Z  |   X  |   C  |   V  |   B  | LALT | NAVR |  |  NSL | - _  |  / ? |   B  |  N   |   M  |  , < |  . >   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LOCK | LGUI |LShift|Space |Enter |  | Enter| BSpc |  Del | LGUI | LOCK |
 *                        |Volume|      |      |      |      |  |      |      |      |      |Scroll|
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWER] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LALT, MO(NAVR), MO(NSL), KC_MINS, KC_SLSH, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                 TG(LOCK), KC_LGUI, KC_LSFT, KC_SPC, KC_ENT, KC_ENT, KC_BSPC, KC_DEL, KC_LGUI, TG(LOCK)
    ),
/*
 * Layer: TRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [TRON] = LAYOUT(
      _______,   X(RA),   X(RU),   X(KO),   X(HA),  X(YOS),                                       X(KI),   X(NO),   X(KU),    X(A),   X(RE), _______,
      _______,   X(TA),   X(TO),   X(KA),   X(TE),   X(MO),                                       X(WO),    X(JHI),    X(U),  X(SHI),    X(N), _______,
      _______,   X(MA),   X(RI),   X(NI),   X(SA),   X(NA), _______, _______, _______, _______,   X(SU),  X(TSU), X(JCOM), X(JPER), X(TSUS), _______,
                               TG(LOCK), _______, MO(LTRN), _______, _______, _______, _______, MO(RTRN), _______, TG(LOCK)
    ),
/*
 * Layer: LTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LTRN] = LAYOUT(
      _______, X(HI), X(SO), _______, X(YAS), X(HO),                                       X(GI), _______, X(GU), _______, X(WI), _______,
      _______, X(NU), X(NE), X(YUS), X(YO), X(FU),                                     X(VCM), _______, X(VU), X(MI), X(WE), _______,
      _______, X(ES), X(OS), X(HSE), X(YU), X(HE), _______, _______, _______, _______, X(ZU), X(TZU), _______, _______, X(WAS), _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Layer: RTRON
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RTRN] = LAYOUT(
      _______, _______, _______, X(GO), X(BA), _______,                                     X(E), X(KE), X(ME), X(MU), X(RO), _______,
      _______, X(DA), X(DO), X(GA), X(DE), _______,                                     X(O), X(CHI), _______, X(MI), X(YA), _______,
      _______, _______, _______, _______, X(ZA), _______, _______, _______, _______, _______, X(WA), X(IS), X(AS), _______, X(US), _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
                                 _______, KC_PLUS, KC_MINS, KC_0,    KC_DOT,  _______, _______, _______, _______, _______
    ),
    [NSSL] = LAYOUT(
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, KC_RST,  _______,
      _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, KC_ALGR, _______, _______,
                                 _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [ACNT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______,XP(LAU,UAU), _______, _______, _______,
      _______,XP(LAA,UAA), _______, _______, _______, _______,                                 _______, XP(LNT,UNT),XP(LAE,UAE),XP(LAI,UAI),XP(LAO,UAO), _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, X(BANG), _______,
                                 _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [LOCK] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TODEFAL:
        if (record->event.pressed) {
            // when keycode TODEFAL is pressed
        } else {
            // when keycode TODEFAL is released
            layer_move(default_layer_state); // Switch to default layer
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
	#ifdef RGBLIGHT_ENABLE
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(198, 255, 230);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
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
        case TRON:
            oled_write_P(PSTR("Tron\n"), false);
            break;
        case LTRN:
            oled_write_P(PSTR("Left Shift\n"), false);
            break;
        case RTRN:
            oled_write_P(PSTR("Right Shift\n"), false);
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
        case ACNT:
            oled_write_P(PSTR("Accented Chars\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_P(PSTR("Unicode: "), false);
    switch (get_unicode_input_mode()) {
        case UC_LNX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        case UC_WINC:
            oled_write_P(PSTR("Win Compose\n"), false);
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
        } else if (index == 1) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    } else {
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
#endif
