#include QMK_KEYBOARD_H

#include "enums.h"
#include "oled.h"
#include "encoders.h"
#include "leds.h"
#include "combos.h"

#define KC_LOWER MO(_LOWER)
#define KC_RAISE MO(_RAISE)
#define KC_ADJUS MO(_ADJUST)
#define KC_CRAD LCTL(LALT(KC_DEL))

#define COLEMAK KC_CLMAK
#define QWERTY  KC_QWERTY

#define CHORD(chord) \
            if (record->event.pressed) SEND_STRING(SS_DOWN(X_LALT) chord SS_UP(X_LALT)); \
            return false;

tap_dance_action_t tap_dance_actions[] = {};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSpc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCtrl|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LALT |SPACE | /LOWER  /       \RAISE \  |ENTER | RALT | RAPP | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS, \
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,     KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,     XXXXXXX,  KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LCTL,  KC_LGUI,   KC_LALT, KC_SPC, KC_LOWER,    KC_RAISE, KC_ENT, KC_RALT, KC_APP, KC_RCTL \
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   D  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LALT |SPACE | /LOWER  /       \RAISE \  |ENTER | RALT | RAPP | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,     KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSLS, \
  KC_LCTL,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,     KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_D,   KC_MUTE,     XXXXXXX,  KC_K,     KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LCTL,  KC_LGUI,   KC_LALT, KC_SPC, KC_LOWER,    KC_RAISE, KC_ENT, KC_RALT, KC_APP, KC_RCTL \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTR | LALT |SPACE | /LOWER  /       \RAISE \  |ENTER | RALT | RCTR | RAPP |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
   KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______,                          KC_INS, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_F12, \
  _______, _______, _______, _______, _______, _______,                          KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, KC_MAG2, \
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
   KC_ESC, _______, _______,   KC_P7,    KC_P8,   KC_P9,                          _______,  _______, _______,  KC_MINS,   KC_EQL, _______, \
  _______, _______, _______,   KC_P4,    KC_P5,   KC_P6,                          _______,  _______,   KC_UP,  KC_LBRC,  KC_RBRC, KC_BSLS, \
  _______, QK_LEAD, _______,   KC_P1,    KC_P2,   KC_P3,                          _______,  KC_LEFT, KC_DOWN,  KC_RIGHT, _______, _______, \
  KC_NUBS, _______, _______,   KC_P0,    KC_P0, KC_PDOT,  _______,       _______, _______,  _______, _______,  _______,  _______, KC_MAG1, \
                    _______, _______,  _______, _______,  _______,       _______, _______,  _______, _______,  _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|      |      |      |      |  (   |                    |  )   |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |CADel |      |      |      |  [   |                    |  ]   |      |      |      |      |COLEMK|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  {   |-------.    ,-------|  }   |      |      |      |      |CAPSLK|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1, DM_REC1,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY, \
  XXXXXXX, KC_CRAD, XXXXXXX, XXXXXXX, DM_PLY2, DM_REC2,                           XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, COLEMAK, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_RSTP,                           XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, \
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MAG3, \
                    _______, _______,  _______, _______,  _______,       _______, _______,  _______, _______,  _______ \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    bool num_lock = host_keyboard_led_state().num_lock;
    bool is_nlck_layer = layer_state_cmp(state, _RAISE);
    if ((is_nlck_layer && !num_lock) || (!is_nlck_layer && num_lock)) tap_code(KC_NUM);
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods)
{
    switch (keycode) {
        case KC_MAG1:
        case KC_MAG2:
        case KC_MAG3:
            return false;
    }

    return true;
}

#define MAGIC(kc, str) case kc: SEND_STRING(str); break;

void process_magic_key_1(uint16_t prev_keycode, uint8_t prev_mods)
{
    switch (prev_keycode) {
        MAGIC(KC_A, "bout ")
        MAGIC(KC_B, "ecause ")
        MAGIC(KC_C, "ould ")
        MAGIC(KC_D, "evelop ")
        MAGIC(KC_E, "ven ")
        MAGIC(KC_F, "irst ")
        MAGIC(KC_G, "ood ")
        MAGIC(KC_H, "ave ")
        MAGIC(KC_I, "nto ")
        MAGIC(KC_J, "ust ")
        MAGIC(KC_K, "now ")
        MAGIC(KC_L, "eft ")
        MAGIC(KC_M, "ake ")
        MAGIC(KC_N, "ow ")
        MAGIC(KC_O, "ther ")
        MAGIC(KC_P, "lease ")
        MAGIC(KC_Q, "ueue ")
        MAGIC(KC_R, "ight ")
        MAGIC(KC_S, "hould ")
        MAGIC(KC_T, "hat ")
        MAGIC(KC_U, "pgrade ")
        MAGIC(KC_V, "ersion ")
        MAGIC(KC_W, "hat ")

        MAGIC(KC_DOT, "com")
    }
}

void process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods)
{
    switch (prev_keycode) {
        MAGIC(KC_A, "fter ")
        MAGIC(KC_B, "efore ")
        MAGIC(KC_C, "ome ")
        MAGIC(KC_D, "eploy ")
        MAGIC(KC_E, "ver ")
        MAGIC(KC_F, "ollow ")
        MAGIC(KC_G, "eneral ")
        MAGIC(KC_H, "owever ")
        MAGIC(KC_I, "nter ")
        MAGIC(KC_J, "udge ")
        MAGIC(KC_K, "now ")
        MAGIC(KC_L, "ittle ")
        MAGIC(KC_M, "ight ")
        MAGIC(KC_N, "eighbor ")
        MAGIC(KC_O, "ther ")
        MAGIC(KC_P, "rogram ")
        MAGIC(KC_Q, "uant ")
        MAGIC(KC_R, "ight ")
        MAGIC(KC_S, "hould ")
        MAGIC(KC_T, "hough ")
        MAGIC(KC_U, "pgrade ")
        MAGIC(KC_V, "ersion ")
        MAGIC(KC_W, "ould ")

        MAGIC(KC_DOT, "org")
    }
}


void process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods)
{
    switch (prev_keycode) {
        /*
        MAGIC(KC_A, "bsolute ")
        MAGIC(KC_B, "efore ")
        MAGIC(KC_C, "ome ")
        MAGIC(KC_D, "eploy ")
        MAGIC(KC_E, "ver ")
        MAGIC(KC_F, "ollow ")
        MAGIC(KC_G, "eneral ")
        MAGIC(KC_H, "owever ")
        MAGIC(KC_I, "nter ")
        MAGIC(KC_J, "udge ")
        MAGIC(KC_K, "now ")
        MAGIC(KC_L, "ittle ")
        MAGIC(KC_M, "ight ")
        MAGIC(KC_N, "eighbor ")
        MAGIC(KC_O, "ther ")
        MAGIC(KC_P, "rogram ")
        MAGIC(KC_Q, "uant ")
        MAGIC(KC_R, "ight ")
        MAGIC(KC_S, "hould ")
        MAGIC(KC_T, "hough ")
        MAGIC(KC_U, "pgrade ")
        MAGIC(KC_V, "ersion ")
        MAGIC(KC_W, "ould ")

        MAGIC(KC_DOT, "org")
        */
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAG1:
            if (record->event.pressed) {
                process_magic_key_1(get_last_keycode(), get_last_mods());
            }
            return false;
        case KC_MAG2:
            if (record->event.pressed) {
                process_magic_key_2(get_last_keycode(), get_last_mods());
            }
            return false;
        case KC_MAG3:
            if (record->event.pressed) {
                process_magic_key_3(get_last_keycode(), get_last_mods());
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_CLMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LPAREN:
            CHORD(SS_TAP(X_P4) SS_TAP(X_P0))
        case KC_RPAREN:
            CHORD(SS_TAP(X_P4) SS_TAP(X_P1))
        case KC_LABRAC:
            CHORD(SS_TAP(X_P9) SS_TAP(X_P1))
        case KC_RABRAC:
            CHORD(SS_TAP(X_P9) SS_TAP(X_P3))
        case KC_LBRACE:
            CHORD(SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P3))
        case KC_RBRACE:
            CHORD(SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P5))
    }
    return true;
}

void leader_start_user(void) {

}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        SEND_STRING("TEST");
    }
}
