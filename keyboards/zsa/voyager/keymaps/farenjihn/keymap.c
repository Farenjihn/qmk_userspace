// Copyright 2024 Valentin Finini
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_swiss_fr.h"
#include "sendstring_swiss_fr.h"

#define KC_TRACK_PREV KC_MEDIA_PREV_TRACK
#define KC_TRACK_NEXT KC_MEDIA_NEXT_TRACK
#define KC_TRACK_PLAY KC_MEDIA_PLAY_PAUSE
#define KC_TRACK_STOP KC_MEDIA_STOP

#define KC_VOL_DOWN KC_AUDIO_VOL_DOWN
#define KC_VOL_UP KC_AUDIO_VOL_UP
#define KC_VOL_MUTE KC_AUDIO_MUTE

#define QK_TT_DOWN QK_DYNAMIC_TAPPING_TERM_DOWN
#define QK_TT_UP QK_DYNAMIC_TAPPING_TERM_UP
#define QK_TT_RPT QK_DYNAMIC_TAPPING_TERM_PRINT

#define KC_PREV_TAB LCTL(LSFT(KC_TAB))
#define KC_NEXT_TAB LCTL(KC_TAB)

#define LTHUMB_INNER LT(L_NAV, KC_SPC)
#define LTHUMB_OUTER LT(L_FN_NUM, KC_TAB)

#define RTHUMB_INNER LT(L_SYM, KC_ENT)
#define RTHUMB_OUTER LT(L_MEDIA, KC_BSPC)

#define HS_COLD 130, 86
#define HS_WARM 198, 128

enum layer {
    L_BASE = 0,
    L_NAV,
    L_SYM,
    L_FN_NUM,
    L_MEDIA,
    L_GAME,
};

enum custom_keycode {
    KC_VSPLIT = SAFE_RANGE,
    KC_HSPLIT,
    KC_PARENT_PATH,
    KC_NAMESPACE,
    KC_LED_DOWN,
    KC_LED_UP,
    KC_LED_TOGG,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT(
        TO(L_GAME),     CH_1,           CH_2,           CH_3,           CH_4,           CH_5,                           CH_6,           CH_7,           CH_8,           CH_9,           CH_0,           KC_DELETE,
        OSM(MOD_LALT),  CH_B,           CH_L,           CH_D,           CH_W,           CH_Z,                           CH_QUOT,        CH_F,           CH_O,           CH_U,           CH_J,           CH_SLSH,
        KC_ESC,         CH_N,           CH_R,           CH_T,           CH_S,           CH_G,                           CH_Y,           CH_H,           CH_A,           CH_E,           CH_I,           CW_TOGG,
        KC_LCTL,        CH_Q,           CH_X,           CH_M,           CH_C,           CH_V,                           CH_K,           CH_P,           CH_DOT,         CH_COMM,        CH_MINS,        LCTL(KC_LSFT),
                                                                        LTHUMB_INNER,   LTHUMB_OUTER,                   RTHUMB_OUTER,   RTHUMB_INNER
    ),
    [L_NAV] = LAYOUT(
        KC_NO,          _______,        _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______,        _______,        KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_PREV_TAB,    KC_NEXT_TAB,    KC_NO,          KC_NO,          KC_NO,
        KC_NO,          OSM(MOD_LCTL),  KC_LEFT_GUI,    OSM(MOD_LSFT),  OSM(MOD_LALT),  KC_NO,                          KC_VSPLIT,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_HSPLIT,      KC_END,         KC_PGDN,        KC_PAGE_UP,     KC_HOME,        KC_NO,
                                                                        _______,        _______,                        _______,        _______
    ),
    [L_SYM] = LAYOUT(
        KC_NO,          KC_NO,          CH_ACUT,        CH_GRV,         CH_DIAE,        KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          CH_CIRC,        CH_LABK,        CH_RABK,        CH_DQUO,        CH_AT,                          CH_AMPR,        CH_PIPE,        CH_LBRC,        CH_RBRC,        CH_TILD,        KC_NO,
        KC_NO,          CH_EXLM,        CH_MINS,        CH_PLUS,        CH_EQL,         KC_PARENT_PATH,                 KC_NAMESPACE,   CH_COLN,        CH_LPRN,        CH_RPRN,        CH_QUES,        KC_NO,
        KC_NO,          CH_PERC,        CH_SLSH,        CH_ASTR,        CH_HASH,        CH_0,                           CH_DLR,         CH_SCLN,        CH_LCBR,        CH_RCBR,        CH_BSLS,        KC_NO,
                                                                        _______,        _______,                        _______,        _______
    ),
    [L_FN_NUM] = LAYOUT(
        KC_NO,          KC_NO,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_NO,                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_NO,                          KC_NO,          KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_NO,                          KC_0,           KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,
                                                                        _______,        _______,                        _______,        _______
    ),
    [L_MEDIA] = LAYOUT(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_NO,          QK_TT_DOWN,     QK_TT_UP,       QK_TT_RPT,      CM_TOGG,        KC_NO,
        KC_NO,          KC_NO,          KC_VOL_MUTE,    KC_VOL_DOWN,    KC_VOL_UP,      KC_NO,                          KC_NO,          AS_DOWN,        AS_UP,          AS_RPT,         KC_NO,          KC_NO,
        KC_NO,          KC_TRACK_STOP,  KC_TRACK_PLAY,  KC_TRACK_PREV,  KC_TRACK_NEXT,  KC_NO,                          KC_NO,          KC_LED_DOWN,    KC_LED_UP,      KC_LED_TOGG,    KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                        _______,        _______,                        _______,        _______
    ),
    [L_GAME] = LAYOUT(
        TO(L_BASE),     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TAB,         CH_Q,           CH_W,           CH_E,           CH_R,           CH_T,                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_LEFT_SHIFT,  CH_A,           CH_S,           CH_D,           CH_F,           CH_G,                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_LCTL,        CH_Y,           CH_X,           CH_C,           CH_V,           CH_B,                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                        _______,        KC_NO,                          KC_NO,          KC_NO
    ),
};
// clang-format on

const uint16_t PROGMEM combo_b_ts[] = {CH_T, CH_S, COMBO_END};
const uint16_t PROGMEM combo_j_ha[] = {CH_H, CH_A, COMBO_END};

const uint16_t PROGMEM combo_leader[] = {CH_S, CH_H, COMBO_END};

const uint16_t PROGMEM combo_thumb_inner[] = {LTHUMB_INNER, RTHUMB_INNER, COMBO_END};
const uint16_t PROGMEM combo_thumb_outer[] = {LTHUMB_OUTER, RTHUMB_OUTER, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_b_ts, CH_B),      //
    COMBO(combo_j_ha, CH_J),      //
    COMBO(combo_leader, QK_LEAD), //
    COMBO(combo_thumb_inner, OSM(MOD_LALT)),
    COMBO(combo_thumb_outer, OSM(MOD_LALT | MOD_LSFT)),
};

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HS_COLD, rgb_matrix_get_val());
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case L_GAME:
            rgblight_sethsv_noeeprom(HS_WARM, rgb_matrix_get_val());
            autoshift_disable();
            break;
        default:
            rgblight_sethsv_noeeprom(HS_COLD, rgb_matrix_get_val());
            autoshift_enable();
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_VSPLIT:
            if (record->event.pressed) SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(25) SS_TAP(X_V));
            break;
        case KC_HSPLIT:
            if (record->event.pressed) SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(25) SS_TAP(X_S));
            break;
        case KC_PARENT_PATH:
            if (record->event.pressed) SEND_STRING("../");
            break;
        case KC_NAMESPACE:
            if (record->event.pressed) SEND_STRING("::");
            break;
        case KC_LED_DOWN:
            if (record->event.pressed) rgb_matrix_decrease_val_noeeprom();
            break;
        case KC_LED_UP:
            if (record->event.pressed) rgb_matrix_increase_val_noeeprom();
            break;
        case KC_LED_TOGG:
            if (record->event.pressed) rgb_matrix_toggle_noeeprom();
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
        case CH_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
        case CH_1 ... CH_0:
        case KC_BSPC:
        case KC_DEL:
        case CH_UNDS:
            return true;
        default:
            return false;
    }
}
