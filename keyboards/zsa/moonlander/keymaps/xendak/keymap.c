#include QMK_KEYBOARD_H
#include "version.h"
#include "quantum.h"

// #include "achordion/achordion.h"

#define ______ KC_TRANSPARENT

#define HM_S RSFT_T(KC_S)
#define HM_H LSFT_T(KC_H)
#define HM_E LCTL_T(KC_E)
#define HM_R RCTL_T(KC_R)
#define HM_T RALT_T(KC_T)
#define HM_A LALT_T(KC_A)

#define HM_I RSFT_T(KC_I)
#define HM_N LSFT_T(KC_N)
//#define THUMBR2 LCTL_T(KC_SCLN)
#define THUMBR2 US_MAG2

#define MY_LEFT LWIN_T(KC_LEFT)
#define MY_UP LALT_T(KC_UP)
#define MY_DOWN RALT_T(KC_DOWN)
#define MY_RIGHT RWIN_T(KC_RIGHT)

#define MY_LEFTP LT(F_, KC_QUOTE)
#define MY_RIGHP LT(F_, KC_COMMA)

#define F_ FUNCTION
#define S_ SYMBOLS
#define GAME_1 MT(MOD_LCTL, KC_ENTER)
#define GAME_2 MT(MOD_RSFT, KC_ENTER)


enum layers {
    RAIN,
    GAMES,
    MAPLE,
    BLASTER,
    FUNCTION,
    SYMBOLS,
};

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    US_MAG1,
    US_MAG2,
    US_MAG3,
    US_MAG4,
    PWM,
    PWM2,
    KEYUP,
    KEYDN,
    SBIT,
    MY_LGUI,
    MY_LALT,
    MY_RALT,
    MY_LCTL,
    MY_LSFT,
    BM_S,
    MP_S,
    BLASTER_M,
    B_M_SLOW,
    B_SNARL,
    BLASTER_A,
    BLASTER_O,
    BLASTER_D,
    BLASTER_F,
    BLASTER_AS,
    BLASTER_DS,
    BMACRO_DS,
    BMACRO_AS,
    M_HELPER,
    B_JUMP_FARM,
    B_NRL_FARM,
    B_A,
    B_D,
    BLASTER_DOUBLE_JUMP,
    BLASTER_SGP,
    B_SMAG,
    B_FSMAG,
    B_BUNKER,
    B_SKSSP,
    B_SKATE,
    MY_SHIFT,
    MY_MAGIC,
    MY_BSPC,
    MY_TILD
};

static uint16_t key_trigger = 0;
static bool     key_held    = false;
static uint16_t key_timer   = 0;
static bool     weave       = false;

#define BSPC_MAX_LENGTH 30

static bool key_pressed = false;
struct key_list {
    uint8_t key_count;
    uint8_t last_key_count;
    uint8_t key_list[BSPC_MAX_LENGTH];
};
struct key_list kk;

#include "tt/sequence_transform.h"

#include "../../../../shared/blaster.h"
#include "../../../../shared/pwm.h"
#include "g/keymap_combo.h"
#include "../../../../shared/rand.h"
#include "helper_maplestory.c"

#include "mlayout.h"

bool get_hold_on_other_key_press_per_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_S:
        case HM_H:
        case HM_N:
        case HM_I:
        case HM_R:
        case HM_E:
        case HM_A:
        case HM_T:
        case LT(S_, KC_SPACE):
        case LT(S_, MY_MAGIC):
        case MY_LEFT:
        case MY_UP:
        case MY_DOWN:
        case MY_RIGHT:
            return true;
        default:
            return false;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case SEMI50: case SEMI51: case SEMI52: case SEMI53: case SEMI54:// case SEMI55: case SEMI56: case SEMI57: case SEMI58: case SEMI59: case SEMI60:
            return 30;
        case BLASTER1:
        case BLASTER2:
        case MAPLE1:
        case MAPLE2:
        case ALL_MAPLE1:
            return 110;
    }
    if (combo->keys[0] == LT(S_, KC_SPACE) || combo->keys[0] == US_MAG3 || combo->keys[0] == LT(S_, KC_NO)) { // if first key in the array is Enter
        return 30;
    }

    return COMBO_TERM;
}

// uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//     switch (tap_hold_keycode) {
//         case MY_LEFT:
//         case MY_UP:
//         case MY_DOWN:
//         case MY_RIGHT:
//         case MY_RIGHP:
//         case LT(F_, KC_SCLN):
//         case LT(F_, KC_DOT):
//         case LT(F_, KC_ENTER):
//         case LT(F_, KC_ESCAPE):
//         case LT(F_, KC_LCTL):
//         case LT(F_, KC_MINUS):
//         case MY_LEFTP:
//         case LT(F_, KC_Z):
//         case LT(F_, KC_Y):
//         case LT(F_, KC_F):
//             // case LT(S_, KC_SPACE):
//             // case LT(S_, KC_BSPC):
//             return 0; // Bypass Achordion for these keys.
//     }

//     return TAPPING_TERM * 2 + 150; // Otherwise use a timeout of 800 ms.
// }

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_E:
        case HM_A:
            return QUICK_TAP_TERM;
        default:
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_RIGHP:
        case MY_LEFTP:
        case LT(F_, KC_F):
        case LT(F_, KC_Y):
        case LT(F_, KC_SCLN): // case LT(S_, KC_SPACE): case LT(S_, KC_BSPC):
            return TAPPING_TERM + 40;
        case MY_LEFT:
        case MY_UP:
        case MY_DOWN:
        case MY_RIGHT:
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case SEMI01: case SEMI02: case SEMI03: case SEMI04: case SEMI05: case SEMI06: case SEMI07: case SEMI08: case SEMI09: case SEMI10:
        case SEMI11: case SEMI12: case SEMI13: case SEMI14: case SEMI15: case SEMI16: case SEMI17: case SEMI18: case SEMI19: case SEMI20:
        case SEMI21: case SEMI22: case SEMI23: case SEMI24: case SEMI25: case SEMI26: case SEMI27: case SEMI28: case SEMI29: case SEMI30:
        case SEMI31: case SEMI32: case SEMI33: case SEMI34: case SEMI35: case SEMI36: case SEMI37: case SEMI38: case SEMI39: case SEMI40:
        case SEMI41: case SEMI42: case SEMI43: case SEMI44: case SEMI45: case SEMI46: case SEMI47: case SEMI48: case SEMI49: case SEMI50:
        case SEMI51: case SEMI52: case SEMI53: case SEMI54:// case SEMI55: case SEMI56: case SEMI57: case SEMI58: case SEMI59: case SEMI60:
            if (get_highest_layer(layer_state) == RAIN) return true;
            else { break; }
        // MAPLE_COMBOS
        // case ALL_MAPLE1:
        // case ALL_MAPLE2:
        //     if (get_highest_layer(layer_state) == BLASTER ||
        //         get_highest_layer(layer_state) == MAPLE)
        //         return true;
        //     else { break; }
        case MAPLE1: case MAPLE2:
            if (get_highest_layer(layer_state) == MAPLE) return true;
            else { break; }
        // case BLASTER1: case BLASTER2:
        //     if (get_highest_layer(layer_state) == BLASTER) return true;
        //     else { break; }
    }
    return false;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Dvorak.
    switch (tap_hold_keycode) {
        case MY_UP:
        case MY_RIGHT:
            switch (other_keycode) {
                case KC_TAB:
                case KC_1 ... KC_5:
                    return true;
            }
    }

    // Also allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    // if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

    // Otherwise, follow the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool process_magic_key(uint16_t prev_keycode, uint8_t prev_mods) {
    uint16_t kc = prev_keycode = QK_MODS_GET_BASIC_KEYCODE(prev_keycode);
    switch (kc) {
        case KC_E:
        case HM_E:
            SEND_STRING("u");
            return false;
        case KC_K:
            SEND_STRING("i");
            return false;
        case KC_U:
            SEND_STRING("e");
            return false;
        case KC_O:
            SEND_STRING("a");
            return false;
        case KC_A:
        case HM_A:
            SEND_STRING("o");
            return false;
        case KC_Y:
            SEND_STRING("p");
            return false;
        case KC_P:
        case KC_H:
        case HM_H:
            SEND_STRING("y");
            return false;
        case KC_SPACE:
        case LT(S_, KC_SPACE):
            SEND_STRING("I");
            return false;
        case KC_W:
        case KC_V:
        case KC_Z:
            SEND_STRING("s");
            return false;
        case KC_LPRN:
            SEND_STRING("\"");
            return false;
        case KC_QUOTE:
            SEND_STRING(")");
            return false;
        case KC_MINUS:
            tap_code16(KC_GT);
            return false;
        case KC_Q:
        case KC_J:
            SEND_STRING("u");
            prev_keycode = KC_Q;
            return false;
        case KC_C:
            SEND_STRING("k");
            return false;
        case KC_B:
            SEND_STRING("l");
            return false;
        case KC_L:
            SEND_STRING("r");
            return false;
        case KC_R:
        case HM_R:
            SEND_STRING("l");
            return false;
        case KC_S:
        case HM_S:
            SEND_STRING("w");
            return false;
        case KC_X:
            SEND_STRING("p");
            return false;
        case KC_I:
        case HM_I:
            SEND_STRING("'");
            return false;
        case KC_T:
        case KC_N:
        case HM_N:
            SEND_STRING("'");
            return false;
        case MY_BSPC:
            for (int i = 0; i < kk.last_key_count; i++) {
                tap_code(kk.key_list[i]);
            }
            kk.key_count      = 0;
            kk.last_key_count = 0;
            return false;

        // REMOVE HOLDS AND NON-CHARACTER INPUTS
        case KC_ENTER:
        case KC_TAB:
        case KC_ESC:
        case KC_LSFT:
        case KC_LCTL:
        case KC_RCTL:
        case KC_LALT:
        case KC_RALT:
        case KC_LWIN:
        case KC_RWIN:
        case KC_DEL:
            return false;

        // Exclusive for portuguese
        case MY_TILD:
        case KC_TILD:
        case QK_GESC:
        case KC_GRAVE:
            tap_code(KC_A);
            return false;

        default:
            tap_code(prev_keycode);
            return false;
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case MY_MAGIC:
        case QK_REP:
        case KC_BSPC:
        case LT(S_, KC_BSPC):
        case LT(S_, MY_MAGIC):
            return false; // Ignore ALTREP keys.
    }

    return true; // Other keys can be repeated.
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (get_highest_layer(layer_state) == RAIN) {
        if (!process_sequence_transform(keycode, record, US_MAG1)) return false;
        // if (!process_achordion(keycode, record)) return false;
        if (keycode == LT(S_, KC_NO) && record->event.pressed && record->tap.count)
            keycode = US_MAG1;
        if (keycode == LT(S_, KC_OUT) && record->event.pressed && record->tap.count)
            keycode = US_MAG3;
    }

    // int rep_count = get_repeat_key_count();
    // TODO: make use of this function
    if (record->event.pressed) key_pressed = true;

    uint8_t mod_state = get_mods();
    if (record->event.pressed) switch (keycode) {
            case MY_BSPC:
                if ((mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
                    kk.last_key_count = kk.key_count;
                    kk.key_count      = 0;
                    clear_mods();
                    add_mods(MOD_BIT(KC_LCTL));
                    tap_code(KC_BSPC);
                    add_mods(mod_state);
                } else {
                    if (kk.key_count >= 0)
                        register_code(KC_BACKSPACE);
                    else {
                        for (int i = 0; i < kk.key_count; i++)
                            tap_code(KC_BSPC);
                        kk.last_key_count = kk.key_count;
                        kk.key_count      = 0;
                    }
                }
                break;
            case MY_LGUI:
                add_oneshot_mods(MOD_BIT(KC_LGUI));
                add_mods(MOD_BIT(KC_LGUI));
                break;
            case MY_LALT:
                add_oneshot_mods(MOD_BIT(KC_LALT));
                add_mods(MOD_BIT(KC_LALT));
                break;
            case MY_RALT:
                add_oneshot_mods(MOD_BIT(KC_RALT));
                add_mods(MOD_BIT(KC_RALT));
                break;
            case MY_LCTL:
                add_oneshot_mods(MOD_BIT(KC_LCTL));
                add_mods(MOD_BIT(KC_LCTL));
                break;
            case MY_LSFT:
                add_oneshot_mods(MOD_BIT(KC_LSFT));
                add_mods(MOD_BIT(KC_LSFT));
                break;
        }
    else
        switch (keycode) {
            case MY_LGUI:
            case MY_RALT:
            case MY_LALT:
            case MY_LCTL:
            case MY_LSFT:   clear_mods(); break;
            case MY_BSPC:   unregister_code(KC_BSPC); break;
        }

    switch (keycode) {
        case KC_BSPC:
            static bool delete_key;
            if (record->event.pressed) {
                if ((mod_state & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DELETE);
                    delete_key = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delete_key) {
                    unregister_code(KC_DELETE);
                    delete_key = false;
                    return false;
                }
            }
            return true;
        case LT(S_, MY_MAGIC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(US_MAG1);
                return false;
                // return process_magic_key(get_last_keycode(), get_last_mods());
            }
            return true;

        case SBIT:
            if (record->event.pressed) send_byte(get_highest_layer(layer_state));
            return false;
        case PWM:
            return pwm_1(record);
        case PWM2:
            return pwm_2(record);
        case KEYUP:
            if (record->event.pressed) {
                if ((mod_state & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_PGUP);
                    set_mods(mod_state);
                } else
                    register_code(KC_UP);
            } else {
                unregister_code(KC_UP);
            }
            return false;
        case MP_S:
            if (record->event.pressed)
                register_code(KC_S);
            else
                unregister_code(KC_S);
            return false;
        case BM_S:
            if (record->event.pressed)
                register_code(KC_S);
            else
                unregister_code(KC_S);
            return false;

        case BLASTER_AS:
            if (record->event.pressed) {
                register_code(KC_A);
                register_code(KC_S);
            } else {
                unregister_code(KC_S);
                unregister_code(KC_A);
            }
            return false;
        case BLASTER_DS:
            if (record->event.pressed) {
                register_code(KC_D);
                register_code(KC_S);
            } else {
                unregister_code(KC_D);
                unregister_code(KC_S);
            }
            return false;
        case BLASTER_DOUBLE_JUMP  :
            return blaster_skate_jump_only(record);
        case B_A:
            return blaster_nrl_bob_short_dash(record);
        case B_D:
            return blaster_nrl_weave_short_dash(record);

        case BLASTER_A:
            return blaster_nrl_bob(record);
        case BLASTER_D:
            return blaster_nrl_weave(record);
        case B_SKATE:
            return blaster_skate(record);
        case BLASTER_O:
            return blaster_bullet_blast(record);
        case B_SKSSP:
            if (record->event.pressed)
                key_trigger = 2;
            else
                key_trigger = 0;
            return false;
        case B_M_SLOW:
            if (record->event.pressed)
                key_trigger = 4;
            else
                key_trigger = 0;
            return false;
        case BLASTER_M:
            if (record->event.pressed)
                key_trigger = 1;
            else
                key_trigger = 0;
            return false;
        case B_SNARL:
            if (record->event.pressed)
                key_trigger = 4;
            else
                key_trigger = 0;
            return false;
        case M_HELPER:
            if (record->event.pressed)
                key_held = !key_held;
            return false;
        case B_FSMAG:
            return blaster_smag_gms(record, KC_D);
        case B_SMAG:
            return blaster_smag(record, KC_D);
        case BLASTER_SGP:
            if (record->event.pressed)
                key_trigger = 3;
            else
                key_trigger = 0;
            return false;
        case KEYDN:
            if (record->event.pressed) {
                if ((mod_state & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_PGDN);
                    set_mods(mod_state);
                } else
                    register_code(KC_DOWN);
            } else {
                unregister_code(KC_DOWN);
            }
            return false;

        case MY_TILD:
            if (record->event.pressed) {
                if ((get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT) || (get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    mod_state = get_mods();
                    clear_mods();
                    tap_code16(KC_GRAVE);
                    set_mods(mod_state);
                }
                else
                    register_code16(KC_TILD);
            } else {
                unregister_code16(KC_TILD);
                unregister_code16(KC_GRAVE);
            }
            return false;

        case RGB_SLD:
            if (record->event.pressed) {
                if ((get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT) || (get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT))
                    rgblight_decrease_speed();
                else
                    rgblight_increase_speed();
            }
            return false;
    }

    return true;
}

void matrix_scan_user(void) {
    sequence_transform_task();  // Add this line
    // achordion_task();
    if (key_held && timer_elapsed(key_timer) > 60) {
        helper_maplestory();
        key_timer = timer_read32();
    }
    switch (key_trigger) {
        // NRL_BOB
        case 1: {
            if (timer_elapsed(key_timer) > 60) {
                blaster_nrl_macro();
                weave     = !weave;
                key_timer = timer_read32();
            }
        } break;
            // double sgp skate
        case 2: {
            if (timer_elapsed(key_timer) > 60) {
                blaster_double_sgp_skate();
                key_timer = timer_read32();
            }
        } break;
            // SGP + BOB/WEAVE
        case 3: {
            if (timer_elapsed(key_timer) > 50) {
                blaster_sgp();
                key_timer = timer_read32();
            }
        } break;
        case 4: {
            // SNARL
            if (timer_elapsed(key_timer) > 60) {
                blaster_snarl();
                key_timer = timer_read32();
            }

        } break;
        default:
            break;
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_sequence_transform();  // Add this line
}

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
    //HSV final = rgblight_get_hsv();
    //rgb_matrix_sethsv_noeeprom(final.h, 0, 255); // turn off color by setting saturation to 0
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CHATGPT);
    kk.key_count      = 0;
    kk.last_key_count = 0;
}

void matrix_init_user() {}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    rgblight_set_speed(225);
    switch (layer) {
        case FUNCTION:
        case SYMBOLS:
            rgblight_set_speed(120);
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DUAL_BEACON);
            break;
        case GAMES:
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
        case MAPLE:
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            HSV cyanrgb = rgblight_get_hsv();
            rgb_matrix_sethsv_noeeprom(cyanrgb.h, cyanrgb.s, 255);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
        case BLASTER:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
        case RAIN:
            rgb_matrix_sethsv_noeeprom(99, 255, 255);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
    }
    return state;
}
