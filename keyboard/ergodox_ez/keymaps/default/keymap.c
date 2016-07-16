// modified following file.
// https://github.com/msc654/qmk_firmware/blob/master/keyboard%2Fergodox_ez%2Fkeymaps%2Fdefault%2Fkeymap.c
// test

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define WINDOWS 0  // default layer (for Windows)
#define FN      1  // functions
#define MOUSE   2  // mouse mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 1: Windows layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  | `~   |           |  `~  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  cut | paste| copy | Left | Right|                                       |  Up  | Down |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Space |Delete|------|       |------| Enter  |Space |
 *                                 |      |      | FN   |       | Mouse|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WINDOWS] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,          KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LBRC,
        LCTL(KC_X),     LCTL(KC_V),   LCTL(KC_C),   KC_LEFT,  KC_RGHT,
                                               KC_NO,         KC_NO,
                                                              KC_NO,
                                               KC_SPC,KC_BSPC,LT(2,KC_NO),
        // right hand
             KC_GRV,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_NO,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_RBRC,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_NO,  KC_NO,            KC_NO,
             KC_NO,        KC_NO,
             KC_NO,
             LT(1,KC_NO),KC_ENT , KC_SPC
    ),

/* Keymap 2: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |Enter |------|       |------| Vol- | Vol+ |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Fnctions
[FN] = KEYMAP(
       // left hand
       KC_NO,     KC_F1,    KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
       KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO,
	
                                                              KC_NO, KC_NO,
                                                                     KC_NO,
                                                     KC_SPC, KC_ENT, KC_NO,
       // right hand
       KC_F7, KC_F8,   KC_F9, KC_F10,  KC_F11, KC_F12, RESET,
       KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
              KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
       TG(0),  KC_NO,KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
	                   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
	
       KC_NO, KC_MUTE,
       KC_NO,
       KC_NO, KC_VOLD, KC_VOLU
    ),
    
/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | M-Up |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | LMac |------+------+------+------+------+--------|
 * |        |  M-L | M-Dn | M-R  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | LWin |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | WH-L | WH-R |                                       | Sp+2 | Sp+1 | Sp+0 |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | M2   |MClick|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |Space |Enter |------|       |------|RClick|LClick|
 *                                 |      |      |      |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOUSE] = KEYMAP(
       // left hand
       KC_NO,     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,
       KC_NO,     KC_NO,    KC_MS_U, KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO,     KC_MS_L,  KC_MS_D, KC_MS_R, KC_NO,   KC_NO,
       KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO,     KC_NO,    KC_NO,   KC_WH_L, KC_WH_R,
                                                             KC_NO,  KC_NO,
                                                                     KC_NO,
                                                     KC_SPC, KC_ENT, KC_NO,
       // right hand
       KC_F7,         KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
       KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       TG(0), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_ACL2, KC_ACL1, KC_ACL0, KC_NO,   KC_NO,
       KC_BTN4, KC_BTN3,
       KC_PGUP,
       KC_PGDN, KC_BTN1, KC_BTN2
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();    
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case WINDOWS:
            ergodox_right_led_2_on();
            break;
        case FN:
            ergodox_right_led_3_on();
            break;
        case MOUSE:
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};
