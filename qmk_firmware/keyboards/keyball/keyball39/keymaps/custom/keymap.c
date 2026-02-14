/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_japanese.h からコピペ
// Start
#define JP_ZKHK KC_GRV  // Zenkaku ↔ Hankaku ↔ Kanji (半角 ↔ 全角 ↔ 漢字)
#define JP_1    KC_1    // 1
#define JP_2    KC_2    // 2
#define JP_3    KC_3    // 3
#define JP_4    KC_4    // 4
#define JP_5    KC_5    // 5
#define JP_6    KC_6    // 6
#define JP_7    KC_7    // 7
#define JP_8    KC_8    // 8
#define JP_9    KC_9    // 9
#define JP_0    KC_0    // 0
#define JP_MINS KC_MINS // -
#define JP_CIRC KC_EQL  // ^
#define JP_YEN  KC_INT3 // ¥
#define JP_Q    KC_Q    // Q
#define JP_W    KC_W    // W
#define JP_E    KC_E    // E
#define JP_R    KC_R    // R
#define JP_T    KC_T    // T
#define JP_Y    KC_Y    // Y
#define JP_U    KC_U    // U
#define JP_I    KC_I    // I
#define JP_O    KC_O    // O
#define JP_P    KC_P    // P
#define JP_AT   KC_LBRC // @
#define JP_LBRC KC_RBRC // [
#define JP_EISU KC_CAPS // Eisū (英数)
#define JP_A    KC_A    // A
#define JP_S    KC_S    // S
#define JP_D    KC_D    // D
#define JP_F    KC_F    // F
#define JP_G    KC_G    // G
#define JP_H    KC_H    // H
#define JP_J    KC_J    // J
#define JP_K    KC_K    // K
#define JP_L    KC_L    // L
#define JP_SCLN KC_SCLN // ;
#define JP_COLN KC_QUOT // :
#define JP_RBRC KC_NUHS // ]
#define JP_Z    KC_Z    // Z
#define JP_X    KC_X    // X
#define JP_C    KC_C    // C
#define JP_V    KC_V    // V
#define JP_B    KC_B    // B
#define JP_N    KC_N    // N
#define JP_M    KC_M    // M
#define JP_COMM KC_COMM // ,
#define JP_DOT  KC_DOT  // .
#define JP_SLSH KC_SLSH // /
#define JP_BSLS KC_INT1 // (backslash)
#define JP_MHEN KC_INT5 // Muhenkan (無変換)
#define JP_HENK KC_INT4 // Henkan (変換)
#define JP_KANA KC_INT2 // Katakana ↔ Hiragana ↔ Rōmaji (カタカナ ↔ ひらがな ↔ ローマ字)
#define JP_EXLM S(JP_1)    // !
#define JP_DQUO S(JP_2)    // "
#define JP_HASH S(JP_3)    // #
#define JP_DLR  S(JP_4)    // $
#define JP_PERC S(JP_5)    // %
#define JP_AMPR S(JP_6)    // &
#define JP_QUOT S(JP_7)    // '
#define JP_LPRN S(JP_8)    // (
#define JP_RPRN S(JP_9)    // )
#define JP_EQL  S(JP_MINS) // =
#define JP_TILD S(JP_CIRC) // ~
#define JP_PIPE S(JP_YEN)  // |
#define JP_GRV  S(JP_AT)   // `
#define JP_LCBR S(JP_LBRC) // {
#define JP_CAPS S(JP_EISU) // Caps Lock
#define JP_PLUS S(JP_SCLN) // +
#define JP_ASTR S(JP_COLN) // *
#define JP_RCBR S(JP_RBRC) // }
#define JP_LABK S(JP_COMM) // <
#define JP_RABK S(JP_DOT)  // >
#define JP_QUES S(JP_SLSH) // ?
#define JP_UNDS S(JP_BSLS) // _
// End

// コンボキーの定義-S ref:https://note.com/mamelog0103/n/n5a51fcd24f26
#ifdef COMBO_ENABLE
enum combos{
UI_MC_BTN4,   // U + I = マウスボタン4（戻るクリック）
IO_MC_BTN5,   // I + O = マウスボタン5（進むクリック）
IK_MC_BTN3,   // I + K = マウスボタン3（真ん中クリック）
HJ_MC_ASTER,   // H + J = *（アスタリスク）
//JK_MC_COMMA,   // J + K = ,（カンマ）
JK_MC_SEMICOLON,   // J + K = ;（セミコロン）
//KL_MC_DOT,     // K + L = .（ドット）
KL_MC_COLON,     // K + L = :（コロン）
LMINUS_MC_UNDER,   // L + - = _（アンダーバー）
NM_MC_PLUS,    // N + M = +（プラス）
//MBTN1_MC_SEMICOLON,  // M + BTN1 = ;（セミコロン）
MBTN1_MC_CCOMMA,  // M + BTN1 = ,（カンマ）
//BTN12_MC_COLON,   // BTN1 + BTN2 = :（コロン）
BTN12_MC_DOT,   // BTN1 + BTN2 = .（ドット）
FD_LAYER, // F + D = レイヤー4に移動
};

const uint16_t PROGMEM my_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM my_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM my_ik[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM my_hj[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM my_jk[] = {KC_J, KC_K, COMBO_END};
// L は Mod-Tap (RCTL_T) のため、コンボではキーマップと同じキーコードを指定する
const uint16_t PROGMEM my_kl[] = {KC_K, RCTL_T(KC_L), COMBO_END};   // K+L = :
const uint16_t PROGMEM my_lminus[] = {RCTL_T(KC_L), JP_MINS, COMBO_END};
const uint16_t PROGMEM my_nm[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM my_mbtn1[] = {KC_M, KC_MS_BTN1, COMBO_END};
const uint16_t PROGMEM my_btn12[] = {KC_MS_BTN1, KC_MS_BTN2, COMBO_END};
const uint16_t PROGMEM my_fd[] = {KC_F, KC_D, COMBO_END};

// 割当は https://zenn.dev/yoichi/articles/keymap-that-allow-recovery-from-layout-mismatch を参考に
combo_t key_combos[] = {
[UI_MC_BTN4] = COMBO(my_ui, KC_MS_BTN4),
[IO_MC_BTN5] = COMBO(my_io, KC_MS_BTN5),
[IK_MC_BTN3] = COMBO(my_ik, KC_MS_BTN3), // 割当試し中
[HJ_MC_ASTER] = COMBO(my_hj, JP_ASTR),
//[JK_MC_COMMA] = COMBO(my_jk, JP_COMM),
[JK_MC_SEMICOLON] = COMBO(my_jk, JP_SCLN),
//[KL_MC_DOT] = COMBO(my_kl, KC_DOT), // 割当試し中
[KL_MC_COLON] = COMBO(my_kl, JP_COLN), // K+L = :（コロン）
[LMINUS_MC_UNDER] = COMBO(my_lminus, S(KC_INT1)), // 割当試し中
[NM_MC_PLUS] = COMBO(my_nm, KC_PLUS), // 割当試し中
//[MBTN1_MC_SEMICOLON] = COMBO(my_mbtn1, JP_SCLN),
[MBTN1_MC_CCOMMA] = COMBO(my_mbtn1, JP_COMM),
//[BTN12_MC_COLON] = COMBO(my_btn12, JP_COLN),
[BTN12_MC_DOT] = COMBO(my_btn12, KC_DOT),
[FD_LAYER] = COMBO(my_fd, MO(4)),
};
#endif
// コンボキーの定義-E

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     ,RCTL_T(KC_L), KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);

    // ref:https://mazcon.hatenablog.com/entry/2023/11/10/080000
    #if 0
    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 1:
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        default:
            set_auto_mouse_enable(true);
            break;
    }
    #endif
    #endif

    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// ref:https://mazcon.hatenablog.com/entry/2023/11/10/080000
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

// keymap.c で
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL, KC_A):
    case MT(MOD_LSFT, KC_Z):
      return 400;  // holdを長くする
    default:
      return TAPPING_TERM;
  }
}

// コンボキーデバッグ用
void combo_event(uint8_t combo_index, bool pressed) {
    if (pressed) {
        // コンボキーが押された時の処理
        // デバッグ用に何か出力したい場合はここに追加
    }
}
