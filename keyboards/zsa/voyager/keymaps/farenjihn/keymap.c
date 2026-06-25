// Copyright 2024-2026 Valentin Finini
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "keymap_swiss_fr.h"
#include "sendstring_swiss_fr.h"

#define KC_TABP LCTL(LSFT(KC_TAB))
#define KC_TABN LCTL(KC_TAB)

#define LTHMB_IN  LT(LAYER_NAV, KC_SPACE)
#define LTHMB_OUT LT(LAYER_NUM, KC_TAB)
#define RTHMB_IN  LT(LAYER_SYM, KC_BACKSPACE)
#define RTHMB_OUT LT(LAYER_MEDIA, KC_ENTER)

#define NVIM_VSPLIT SS_TAP(X_ESC) SS_LCTL("w") "v"
#define NVIM_HSPLIT SS_TAP(X_ESC) SS_LCTL("w") "s"
#define NVIM_LBEGIN SS_TAP(X_ESC) "0"
#define NVIM_LEND   SS_TAP(X_ESC) "$"

#define HS_CYAN 137, 88

enum layer {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_MEDIA,
};

enum custom_keycode {
    KC_VSPLIT = SAFE_RANGE,
    KC_HSPLIT,
    KC_LBEGIN,
    KC_LEND,
    KC_RGBD,
    KC_RGBU,
    KC_RGBT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_NO,          CH_1,           CH_2,           CH_3,           CH_4,           CH_5,                   CH_6,           CH_7,           CH_8,           CH_9,           CH_0,           KC_DELETE,
        OSM(MOD_LALT),  CH_B,           CH_L,           CH_D,           CH_W,           CH_Z,                   CH_QUOT,        CH_F,           CH_O,           CH_U,           CH_J,           CH_SLSH,
        KC_ESC,         CH_N,           CH_R,           CH_T,           CH_S,           CH_G,                   CH_Y,           CH_H,           CH_A,           CH_E,           CH_I,           CW_TOGG,
        KC_LCTL,        CH_Q,           CH_X,           CH_M,           CH_C,           CH_V,                   CH_K,           CH_P,           CH_DOT,         CH_COMM,        CH_MINS,        LCTL(KC_LSFT),
                                                                        LTHMB_IN,       LTHMB_OUT,              RTHMB_OUT,      RTHMB_IN
    ),
    [LAYER_NAV] = LAYOUT(
        KC_NO,          _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_VSPLIT,              KC_HSPLIT,      KC_TABP,        KC_TABN,        KC_NO,          KC_NO,          KC_NO,
        KC_NO,          OSM(MOD_LCTL),  KC_LEFT_GUI,    OSM(MOD_LSFT),  OSM(MOD_LALT),  KC_LBEGIN,              KC_LEND,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NO,          KC_END,         KC_PGDN,        KC_PGUP,        KC_HOME,        KC_NO,
                                                                        _______,        _______,                _______,        _______
    ),
    [LAYER_SYM] = LAYOUT(
        KC_NO,          KC_NO,          CH_ACUT,        CH_GRV,         CH_DIAE,        KC_NO,                  KC_NO,          CH_DLR,         CH_PND,         CH_EURO,        KC_NO,          KC_NO,
        KC_NO,          CH_CIRC,        CH_LABK,        CH_RABK,        CH_DQUO,        CH_SLSH,                CH_BSLS,        CH_PIPE,        CH_LBRC,        CH_RBRC,        CH_TILD,        KC_NO,
        KC_NO,          CH_EXLM,        CH_MINS,        CH_PLUS,        CH_EQL,         CH_AT,                  CH_AMPR,        CH_COLN,        CH_LPRN,        CH_RPRN,        CH_QUES,        KC_NO,
        KC_NO,          CH_DEG,         CH_PERC,        CH_ASTR,        CH_HASH,        KC_NO,                  KC_NO,          CH_SCLN,        CH_LCBR,        CH_RCBR,        CH_SECT,        KC_NO,
                                                                        _______,        _______,                _______,        _______
    ),
    [LAYER_NUM] = LAYOUT(
        KC_NO,          KC_NO,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_NO,                  KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_NO,                  CH_DOT,         KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_NO,                  KC_0,           KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,
                                                                        _______,        _______,                _______,        _______
    ),
    [LAYER_MEDIA] = LAYOUT(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NO,          DT_DOWN,        DT_UP,          DT_PRNT,        CM_TOGG,        KC_NO,
        KC_NO,          KC_PSCR,        KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_NO,                  KC_NO,          AS_DOWN,        AS_UP,          AS_RPT,         KC_NO,          KC_NO,
        KC_NO,          KC_MSTP,        KC_MPLY,        KC_MPRV,        KC_MNXT,        KC_NO,                  KC_NO,          KC_RGBD,        KC_RGBU,        KC_RGBT,        KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                        _______,        _______,                _______,        _______
    ),
};
// clang-format on

const uint16_t PROGMEM combo_b_ts[] = {CH_T, CH_S, COMBO_END};
const uint16_t PROGMEM combo_j_ha[] = {CH_H, CH_A, COMBO_END};

const uint16_t PROGMEM combo_leader[] = {CH_S, CH_H, COMBO_END};

const uint16_t PROGMEM combo_thumb_inner[] = {LTHMB_IN, RTHMB_IN, COMBO_END};
const uint16_t PROGMEM combo_thumb_outer[] = {LTHMB_OUT, RTHMB_OUT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_b_ts, CH_B),                            //
    COMBO(combo_j_ha, CH_J),                            //
    COMBO(combo_leader, QK_LEAD),                       //
    COMBO(combo_thumb_inner, OSM(MOD_LALT)),            //
    COMBO(combo_thumb_outer, OSM(MOD_LALT | MOD_LSFT)), //
};

// tap_dance_action_t tap_dance_actions[] = {
// };

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HS_CYAN, 255);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case KC_VSPLIT:
            SEND_STRING(NVIM_VSPLIT);
            break;
        case KC_HSPLIT:
            SEND_STRING(NVIM_HSPLIT);
            break;
        case KC_LBEGIN:
            SEND_STRING(NVIM_LBEGIN);
            break;
        case KC_LEND:
            SEND_STRING(NVIM_LEND);
            break;
        case KC_RGBD:
            rgb_matrix_decrease_val_noeeprom();
            break;
        case KC_RGBU:
            rgb_matrix_increase_val_noeeprom();
            break;
        case KC_RGBT:
            rgb_matrix_toggle_noeeprom();
            break;
    }

    return true;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case CH_QUOT:
            register_code16((!shifted) ? CH_QUOT : CH_DQUO);
            break;
        default:
            if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
            register_code16(keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case CH_QUOT:
            unregister_code16((!shifted) ? CH_QUOT : CH_DQUO);
            break;
        default:
            unregister_code16(keycode);
    }
}

void leader_end_user(void) {
    if (leader_sequence_one_key(CH_E)) {
        tap_code16(CH_EACU);
    } else if (leader_sequence_two_keys(CH_E, CH_E)) {
        tap_code16(CH_EGRV);
    } else if (leader_sequence_one_key(CH_A)) {
        tap_code16(CH_AGRV);
    } else if (leader_sequence_one_key(CH_U)) {
        tap_code16(CH_GRV);
        tap_code16(CH_U);
    } else if (leader_sequence_one_key(CH_C)) {
        tap_code16(CH_CCED);
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case CH_A ... CH_Z:
        case CH_Y:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case CH_1 ... CH_0:
        case KC_BACKSPACE:
        case KC_DELETE:
        case CH_MINS:
        case CH_UNDS:
            return true;

        default:
            return false;
    }
}

#ifdef STATUS_LED_2
layer_state_t layer_state_set_user(layer_state_t state) {
    STATUS_LED_2(get_highest_layer(state) > LAYER_BASE);
    return state;
}
#endif

#ifdef STATUS_LED_4
void caps_word_set_user(bool active) {
    STATUS_LED_4(active);
}
#endif
