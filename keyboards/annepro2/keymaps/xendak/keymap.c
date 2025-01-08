#include QMK_KEYBOARD_H

#include "annepro2.h"
#include "config.h"
#include "../../../shared/blaster.h"
#include "../../../shared/pwm.h"


static uint16_t key_trigger = 0;
static bool     key_held    = false;
static uint16_t key_timer   = 0;
static bool     weave       = false;

enum anne_pro_layers {
    BASE,
    GAME,
    MAPLE,
    FN1,
    FN2,
};

enum custom_keycodes {
    KEY_HOLD_MACRO = SAFE_RANGE,
    BLASTER_A,
    BLASTER_D,
    BLASTER_W,
    BLASTER_M,
    B_SKATE,
    B_BUNKER,
    B_JUMP,
    B_SMAG,
    KC_PWM,
    KC_PWM2,
    RGB_SLD
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    ESC_TPD,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_60_ansi(
          QK_GESC,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,            KC_EQL,             KC_BSPC,
          KC_TAB,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,            KC_RBRC,            KC_BSLS,
      LT(FN1, KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                                KC_ENT,
          KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                                                RSFT_T(KC_UP),
          KC_LCTL,      KC_LGUI,        KC_LALT,                        KC_SPACE,                                                                                       KC_RALT,        LT(FN1, KC_LEFT),   LT(FN2, KC_DOWN),   RCTL_T(KC_RGHT)
    ),

    [GAME] = LAYOUT_60_ansi(
          KC_ESC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,            KC_EQL,             KC_BSPC,
          KC_TAB,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,            KC_RBRC,            TO(0),
      LT(FN1, KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                                KC_ENT,
          KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                                                KC_UP,
          KC_LCTL,      KC_LGUI,        KC_LALT,                        KC_SPACE,                                                                                       KC_LALT,        KC_LEFT,            KC_DOWN,            KC_RGHT
    ),

    [MAPLE] = LAYOUT_60_ansi(
          KC_ESC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,            KC_EQL,             KC_BSPC,
          KC_TAB,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_LCTL,        KC_Q,           BLASTER_W,      KC_E,           KC_R,               KC_RBRC,            TO(0),
      LT(FN1, KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_Z,           B_SKATE,        BLASTER_A,      BLASTER_D,      KC_F,                                   KC_ENT,
          KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           BLASTER_M,      KC_LALT,        KC_C,           KC_X,                                                   KC_V,
          KC_LCTL,      KC_LGUI,        KC_LALT,                        B_JUMP,                                                                                         KC_LALT,        KC_LEFT,            KC_DOWN,            KC_RGHT
    ),

    /*[BLASTER] = LAYOUT_60_ansi(*/
    /*      KC_ESC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,            KC_EQL,             KC_BSPC,*/
    /*      KC_TAB,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,            KC_RBRC,            TO(0),*/
    /*  LT(FN1, KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                                KC_ENT,*/
    /*      KC_LSFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                                                KC_UP,*/
    /*      KC_LCTL,      KC_LGUI,        KC_LALT,                        KC_SPACE,                                                                                       KC_LALT,        KC_LEFT,            KC_DOWN,            KC_RGHT*/
    /*),*/

    /*[MAPLE] = LAYOUT_60_ansi(*/
    /*      KC_ESC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,            KC_EQL,             KC_BSPC,*/
    /*      KC_TAB,       KC_U,           KC_UP,          KC_O,           KC_R,           KC_T,           KC_Y,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_LBRC,            KC_RBRC,            TO(0),*/
    /*      TD(ESC_TPD),  KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_F,           KC_G,           KC_H,           KC_A,           KC_S,           KC_D,           KC_F,           KC_QUOT,                                KC_ENT,*/
    /*      KC_LSFT,      KC_M,           KC_I,           KC_N,           KC_V,           KC_B,           KC_N,           KC_Z,           KC_X,           KC_C,           KC_V,                                                   KC_UP,*/
    /*      KC_Y,         KC_LGUI,        KC_LALT,                        KEY_HOLD_MACRO,                                                                                        KC_RALT,        KC_LEFT,            KC_DOWN,            KC_RGHT*/
    /*),*/

    [FN1] = LAYOUT_60_ansi( /* FN1 */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_PWM2, KC_PWM,  KC_INS,  KC_DEL,  _______,
        _______, _______, _______,                            _______,                   _______, _______, MO(FN2), _______
    ),

    [FN2] = LAYOUT_60_ansi( /* FN2 */
        TO(1),   TO(2),      TO(1),      TO(0),      KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, RGB_SLD,
        _______, _______,    KC_UP,      _______,    _______,    _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
        _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
        _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
        QK_BOOT, _______,    _______,                                     _______,                   _______, MO(FN1), MO(FN2), _______
     ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(ESC_TPD):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_SINGLE_HOLD: layer_on(FN1); break;
        case TD_DOUBLE_TAP:
            if(layer_state_is(GAME))
                layer_off(GAME);
            else
                layer_on(GAME);
            break;
        case TD_DOUBLE_HOLD:
            if(layer_state_is(MAPLE))
                layer_off(MAPLE);
            else
                layer_on(MAPLE);
            break;

        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_ESC); register_code(KC_ESC); break;
        default: break;
    }
}

void x_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: layer_off(FN1); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ESC); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ESC_TPD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uint8_t mod_state = get_mods();
    switch (keycode) {
        case KC_PWM:
            return pwm_1(record);
        case KC_PWM2:
            return pwm_2(record);
        case KEY_HOLD_MACRO:
            if (record->event.pressed)
                key_held = !key_held;
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                if ((get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT))
                    rgblight_decrease_speed();
                else
                    rgblight_increase_speed();
            }
            return false;
        case B_JUMP:
            return blaster_skate_jump_only(record);
        case BLASTER_A:
            return blaster_nrl_bob(record);
        case BLASTER_D:
            return blaster_nrl_weave(record);
        case B_SKATE:
            return blaster_skate(record);
        case BLASTER_W:
            if (record->event.pressed)
                key_trigger = 2;
            else
                key_trigger = 0;
            return false;
        case BLASTER_M:
            if (record->event.pressed)
                key_trigger = 1;
            else
                key_trigger = 0;
            return false;
        case B_SMAG:
            return blaster_smag(record);
    }
    return true;
}

void matrix_scan_user(void) {
    if (key_held && timer_elapsed(key_timer) > 900) {
        register_code(KC_X);
        wait_ms(500);
        unregister_code(KC_X);

        key_timer = timer_read32();
    }

    switch (key_trigger) {
        case 1: {
            if (timer_elapsed(key_timer) > 60) {
                blaster_nrl_macro(weave);
                weave     = !weave;
                key_timer = timer_read32();
            }
        } break;
        case 2: {
            if (timer_elapsed(key_timer) > 50) {
                blaster_sgp();
                key_timer = timer_read32();
            }
        } break;
        default:
            break;
    }
}


void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_foreground_color(0x00, 0x00, 0x00);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FN1:
            // Set the leds to green
            ap2_led_set_foreground_color(0x00, 0xFF, 0x00);
            break;
        case FN2:
            // Set the leds to blue
            ap2_led_set_foreground_color(0x00, 0xF0, 0xFF);
            break;
        case BASE:
            ap2_led_reset_foreground_color();
            ap2_led_set_foreground_color(0x00, 0x00, 0x00);
            /*HSV mayargb = rgblight_get_hsv();*/
            /*rgb_matrix_sethsv_noeeprom(mayargb.h, 0, mayargb.v); // turn off color by setting saturation to 0*/
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            break;
        case GAME:
            ap2_led_reset_foreground_color();
            ap2_led_set_foreground_color(0x20, 0xA0, 0x50);
            ap2_led_set_foreground_color(0x00, 0xF0, 0xFF);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
            break;
        case MAPLE:
            ap2_led_reset_foreground_color();
            ap2_led_set_foreground_color(0xA0, 0xC0, 0x00);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_FLOW);
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_sticky_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_mask_set_mono */
    } else {
        // Reset the capslock if there is no layer active
        ap2_led_unset_sticky_key(2, 0);
    }

    return true;
}


