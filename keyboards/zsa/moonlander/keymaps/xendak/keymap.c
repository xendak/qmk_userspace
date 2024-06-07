#include QMK_KEYBOARD_H
#include "version.h"
#include "quantum.h"
#include "features/achordion.h"

//[DEFAULT] = LAYOUT_moonlander(
//        TO(1),      KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,             KC_NO,       KC_NO,     KC_NO,     KC_NO,      KC_NO,        KC_NO,         KC_NO,
//        KC_NO,      KC_GRAVE,    KC_W,         KC_U,        KC_O,        KC_QUOTE,    KC_TAB,            KC_NO,       KC_X,      KC_L,      KC_H,       KC_V,         KC_Z,          KC_NO,
//        KC_NO,      KC_C,        KC_D,         KC_E,        KC_A,        KC_I,        KC_Y,              KC_F,        KC_S,      KC_R,      KC_N,       KC_T,         KC_K,          KC_NO,
//        KC_NO,      KC_P,        KC_G,         KC_COMMA,    KC_DOT,      KC_SLASH,                                    KC_MINUS,  KC_J,      KC_B,       KC_M,         KC_Q,          KC_NO,
//        KC_SCLN,    KC_SPACE,    KC_NO,        KC_NO,       KC_NO,       KC_NO,                                       KC_NO,     KC_NO,     KC_NO,      KC_NO,        KC_LSFT,       KC_BSPC,
//),

#define ______ KC_TRANSPARENT

// HOME ROW
#define HM_S RSFT_T(KC_S)
#define HM_H LSFT_T(KC_H)
#define HM_E LCTL_T(KC_E)
#define HM_R RCTL_T(KC_R)
#define HM_T RALT_T(KC_T)
#define HM_A LALT_T(KC_A)
#define HM_I LALT_T(KC_I)
#define HM_N RALT_T(KC_N)
#define HM_SCLN LCTL_T(KC_SCLN)

#define MY_LEFT LWIN_T(KC_LEFT)
#define MY_UP LALT_T(KC_UP)
#define MY_DOWN RALT_T(KC_DOWN)
#define MY_RIGHT RWIN_T(KC_RIGHT)


enum layers {
    GRAPHITE,
    GAMES,
    MAPLE,
    BLASTER,
    BMAGE,
    SEMIMAK,
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
    BLASTER_A,
    BLASTER_D,
    BLASTER_F,
    BLASTER_AS,
    BLASTER_DS,
    BMACRO_DS,
    BMACRO_AS,
    BLASTER_DOUBLE_JUMP,
    BLASTER_SGP,
    B_HAMMER,
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

// TRY AT RNG
uint8_t prng8(void) {
    static uint8_t s = 0xAA, a = 0;
    s ^= s << 3;
    s ^= s >> 5;
    s ^= a++ >> 2;
    return s;
}
uint16_t prng16(void) {
    return prng8() | (((uint16_t)prng8()) << 8);
}
uint32_t prng32(void) {
    return prng16() | (((uint32_t)prng16()) << 16);
}

uint32_t prng(uint32_t min, uint32_t max) {
    if (min > max) {
        uint32_t tmp = min;
        min          = max;
        max          = tmp;
    }
    uint32_t range = max - min;
    if (range == 0) {
        return min;
    }
    return min + (prng32() % range);
}

#include "g/keymap_combo.h"
#include "sequence_transform/sequence_transform.h"
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
        case LT(7, KC_SPACE):
        case LT(7, MY_MAGIC):
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
        case UTIL1:
        case UTIL2:
        case UTIL4:
        case UTIL5:
            return 30;
        case UTIL3:
            return 50;
        case BLASTER1:
        case BLASTER2:
        case BMAGE1:
        case BMAGE2:
        case MAPLE1:
        case MAPLE2:
        case ALL_MAPLE1:
            return 80;
    }
    if (combo->keys[0] == LT(7, KC_SPACE) || combo->keys[0] == LT(7, MY_MAGIC)) { // if first key in the array is Enter
        return 30;
    }

    return COMBO_TERM;
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case MY_LEFT:
        case MY_UP:
        case MY_DOWN:
        case MY_RIGHT:
        case LT(6, KC_COMMA):
        case LT(6, KC_SCLN):
        case LT(6, KC_DOT):
        case LT(6, KC_ENTER):
        case LT(6, KC_ESCAPE):
        case LT(6, KC_LCTL):
        case LT(6, KC_MINUS):
        case LT(6, KC_QUOTE):
        case LT(6, KC_Z):
        case LT(6, KC_Y):
        case LT(6, KC_F):
            // case LT(7, KC_SPACE):
            // case LT(7, KC_BSPC):
            return 0; // Bypass Achordion for these keys.
    }

    return TAPPING_TERM * 2; // Otherwise use a timeout of 800 ms.
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(6, KC_COMMA):
        case LT(6, KC_SCLN): // case LT(7, KC_SPACE): case LT(7, KC_BSPC):
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
        // case TAI1:  case TAI2:  case TAI3:  case TAI4:  case TAI5:  case TAI6:  case TAI7:  case TAI8:  case TAI9:  case TAI10:
        // case TAI11: case TAI12: case TAI13: case TAI14: case TAI15: case TAI16: case TAI17: case TAI18: case TAI19: case TAI20:
        // case TAI21: case TAI22: case TAI23: case TAI24: case TAI25: case TAI26: case TAI27: case TAI28: case TAI29: case TAI30:
        // case TAI31: case TAI32: case TAI33: case TAI34: case TAI35: case TAI36: case TAI37: case TAI38: case TAI39: case TAI40:
        // case TAI41: case TAI42: case TAI43: case TAI44: case TAI45: case TAI46: case TAI47: case TAI48: case TAI49: case TAI50:
        // case TAI51: case TAI52: case TAI53: case TAI54: case TAI55: case TAI56: case TAI57: case TAI58: case TAI59: case TAI60:
        // case TAI61: case TAI62: case TAI63: case TAI64: case TAI65: case TAI66: case TAI67: case TAI68: case TAI69: case TAI70:
        // case TAI71: case TAI72: case TAI73: case TAI74: case TAI75: case TAI76: case TAI77: case TAI78: case TAI79: case TAI80:
        // case TAI81: case TAI82: case TAI83: case TAI84: case TAI85: case TAI86: case TAI87: case TAI88: case TAI89: case TAI90:
        // case TAI91: case TAI92: case TAI93: case TAI94: case TAI95: case TAI96: case TAI97: case TAI98: case TAI99: case TAI100:
        // case TAI101: case TAI102: case TAI103: case TAI104: case TAI105: case TAI106:
        case GRAL01: case GRAL02: case GRAL03: case GRAL04: case GRAL05: case GRAL06: case GRAL07: case GRAL08: case GRAL09:
        case GRAL10: case GRAL11: case GRAL12: case GRAL13: case GRAL14: case GRAL15: case GRAL16: case GRAL17: case GRAL18:
        case GRAR01: case GRAR02: case GRAR03: case GRAR04: case GRAR05: case GRAR06: case GRAR07: case GRAR08: case GRAR09:
        case GRAR10: case GRAR11: case GRAR12: case GRAR13: case GRAR14: case GRAR15: case GRAR16: case GRAR17: case GRAR18:
        case GRALR01: case GRALR02: case GRALR03: case GRALR04: case GRALR05: case GRALR06: case GRALR07: case GRALR08: case GRALR09:
        case GRALR10: case GRALR11: case GRALR12: case GRALR13: case GRALR14: case GRALR15:
        case GRARL01: case GRARL02: case GRARL03: case GRARL04: case GRARL05: case GRARL06: case GRARL07: case GRARL08: case GRARL09:
        case GRARL10: case GRARL11: case GRARL12: case GRARL13: case GRARL14: case GRARL15:
        case UTIL1: case UTIL2: case UTIL3: case UTIL4: case UTIL5:
            if (get_highest_layer(layer_state) == GRAPHITE) return true;

        // MAPLE_COMBOS
        case ALL_MAPLE1:
            if (get_highest_layer(layer_state) == BLASTER ||
                get_highest_layer(layer_state) == MAPLE   ||
                get_highest_layer(layer_state) == BMAGE )
                return true;
        case MAPLE1: case MAPLE2:
            if (get_highest_layer(layer_state) == MAPLE) return true;
        case BLASTER1: case BLASTER2:
            if (get_highest_layer(layer_state) == BLASTER) return true;
        case BMAGE1: case BMAGE2:
            if (get_highest_layer(layer_state) == BMAGE) return true;

        case SEMIL1: case SEMIL2: case SEMIR1: case SEMIB1:
            if (get_highest_layer(layer_state) == SEMIMAK) return true;
    }
    return false;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
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
    return achordion_opposite_hands(tap_hold_record, other_record);
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
        case LT(7, KC_SPACE):
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
        case LT(7, KC_BSPC):
        case LT(7, MY_MAGIC):
            return false; // Ignore ALTREP keys.
    }

    return true; // Other keys can be repeated.
}

bool process_my_bspc(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (keycode == MY_BSPC) return true;
    if (keycode == LT(7, KC_SPACE)) {
        kk.key_count = 0;
    }

#ifndef NO_ACTION_ONESHOT
    const uint8_t mods = get_mods() | get_oneshot_mods();
#else
    const uint8_t mods = get_mods();
#endif // NO_ACTION_ONESHOT
       // Disable autocorrection while a mod other than shift is active.
    if ((mods & ~MOD_MASK_SHIFT) != 0) {
        kk.key_count = 0;
        return true;
    }
    switch (keycode) {
#ifndef NO_ACTION_TAPPING
        case QK_MOD_TAP ... QK_MOD_TAP_MAX: // Tap-hold keys.
#    ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#    endif // NO_ACTION_LAYER
           // Ignore when tap-hold keys are held.
            if (record->tap.count == 0) {
                return true;
            }
            // Otherwise when tapped, get the basic keycode.
            // Fallthrough intended.
#endif // NO_ACTION_TAPPING

        // Handle shifted keys, e.g. symbols like KC_EXLM = S(KC_1).
        case QK_LSFT ... QK_LSFT + 255:
        case QK_RSFT ... QK_RSFT + 255:
            keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
            if (keycode == KC_QUOTE || keycode == KC_LPRN) return true;
            break;
    }
    switch (keycode) {
        // Ignore shifts, Caps Lock, one-shot mods, and layer switch keys.
        case KC_NO:
        case KC_LSFT:
        case KC_RSFT:
        case KC_CAPS:
        case KC_LCTL:
        case KC_RCTL:
        case KC_LALT:
        case KC_RALT:
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
        case QK_TO ... QK_TO_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            return true; // Ignore these keys.
    }
    if (!(KC_A <= keycode && keycode <= KC_Z)) {
        if (keycode == KC_BSPC) {
            if (kk.key_count > 0 && kk.last_key_count == 0) kk.key_count -= 1;
            return true;
        } else if (KC_TAB == keycode || KC_ENTER == keycode || keycode == KC_SPACE || keycode == KC_ESC) {
            kk.key_count = 0;
            return true;
        }
    }
    if (kk.key_count >= BSPC_MAX_LENGTH) kk.key_count = 0;
    if (keycode == KC_SPC) return true;

    kk.key_list[kk.key_count] = (uint8_t)keycode;
    kk.key_count += 1;
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (get_highest_layer(layer_state) == GRAPHITE) {
        if (!process_sequence_transform(keycode, record, US_MAG1))
        if (!process_achordion(keycode, record)) return false;
        if (!process_my_bspc(keycode, record)) return false;
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
        case LT(7, MY_MAGIC):
            if (record->tap.count && record->event.pressed) {
                return process_magic_key(get_last_keycode(), get_last_mods());
            }
            return true;
        case MY_MAGIC:
            if (record->event.pressed) return process_magic_key(get_last_keycode(), get_last_mods());
            return false;
        // oneshot shift if pressed, toggle layer if held:
        case MY_SHIFT:
            static uint8_t custom_key_tapping = 0;
            if (record->event.pressed) {
                mod_state          = get_mods();
                custom_key_tapping = timer_read32();
                add_oneshot_mods(MOD_BIT(KC_LSFT));
                add_mods(MOD_BIT(KC_LSFT));

                key_pressed = false;
                if (!key_pressed && timer_elapsed(custom_key_tapping) > TAPPING_TERM + 40) {
                    clear_mods();
                    set_mods(mod_state);
                    layer_on(7);
                }
            } else {
                if (timer_elapsed(custom_key_tapping) > TAPPING_TERM + 40) clear_mods();
                if (get_highest_layer(layer_state) == 7) layer_off(7);
            }

            return false;

        case SBIT:
            if (record->event.pressed) send_byte(get_highest_layer(layer_state));
            return false;
        case PWM:
            if (record->event.pressed) SEND_STRING("#PWM#");
            return false;
        case PWM2:
            if (record->event.pressed) SEND_STRING("#PWM2#");
            return false;
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
        case BLASTER_DOUBLE_JUMP:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(7);
                register_code(KC_COMMA);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_COMMA);
            }
            return false;
        case BMACRO_DS:
            if (record->event.pressed) {
                register_code(KC_D);
                register_code(KC_S);
                wait_ms(prng(344, 370)); // 370
            } else {
                unregister_code(KC_D);
                unregister_code(KC_S);
            }
            return false;
        case BMACRO_AS:
            if (record->event.pressed) {
                register_code(KC_A);
                register_code(KC_S);
                // wait_ms(343.33); // 370
                wait_ms(prng(344, 370)); // 370
            } else {
                unregister_code(KC_A);
                unregister_code(KC_S);
            }
            return false;
        case BLASTER_F:
            if (record->event.pressed) {
                register_code(KC_D);
                register_code(KC_F);
                wait_ms(60);
            } else {
                unregister_code(KC_D);
                unregister_code(KC_F);
            }
            return false;
        // GOHERE
        case BLASTER_A:
            if (record->event.pressed) {
                unregister_code(KC_LALT);
                unregister_code(KC_D);
                unregister_code(KC_A);
                register_code(KC_A);
                // wait_ms(20.83);
                register_code(KC_S);
                wait_ms(333.33); // 370
                unregister_code(KC_S);
                unregister_code(KC_A);
            } else {
                unregister_code(KC_A);
            }
            return false;
        case BLASTER_D:
            if (record->event.pressed) {
                unregister_code(KC_LALT);
                unregister_code(KC_D);
                unregister_code(KC_A);
                register_code(KC_D);
                // wait_ms(20.83);
                // tap_code16(KC_S);
                register_code(KC_S);
                wait_ms(333.33);
                unregister_code(KC_S);
                unregister_code(KC_D);
            } else {
                unregister_code(KC_D);
            }
            return false;
        case B_SKATE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_A));
            } else {
                SEND_STRING(SS_UP(X_A) SS_DELAY(240) SS_DOWN(X_LALT) SS_DOWN(X_COMMA) SS_DELAY(40) SS_UP(X_LALT) SS_UP(X_COMMA));
            }
            return false;
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
        case B_HAMMER:
            if (record->event.pressed) {
                weave = false;
                unregister_code(KC_LALT);
                unregister_code(KC_A);
                unregister_code(KC_D);
                register_code(KC_D);
                wait_ms(20.33);
                register_code(KC_X);
                // wait_ms(65);
                wait_ms(83.34);
                register_code(KC_N);
                // wait_ms(250);
                wait_ms(213.34);
                unregister_code(KC_X);
                wait_ms(20.33);
                unregister_code(KC_N);
                wait_ms(240.33);
                register_code(KC_S);
                wait_ms(30);
                unregister_code(KC_S);
                wait_ms(170);
                unregister_code(KC_D);
                wait_ms(117);
                register_code(KC_LALT);
                wait_ms(20);
                unregister_code(KC_LALT);
                wait_ms(40);

                // SEND_STRING(
                //     SS_DOWN(X_X)
                //     SS_DOWN(X_D)
                //     SS_DELAY(70)
                //     SS_TAP(X_N)
                //     SS_DELAY(250) //260
                //     SS_UP(X_X)
                //     SS_DELAY(170) //200
                //     SS_TAP(X_S)
                //     SS_DELAY(300) //350?
                //     SS_UP(X_D)
                //     SS_DELAY(130) // 5 / 110 - back dash
                //     SS_TAP(X_LALT)
                //     SS_DELAY(60)
                //   );
            }
            return false;
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
    achordion_task();
    if (key_held && timer_elapsed(key_timer) > 60) {
        key_timer = timer_read32();
    }
    switch (key_trigger) {
        // NRL_BOB
        case 1: {
            if (timer_elapsed(key_timer) > 60) {
                unregister_code(KC_LALT);
                unregister_code(KC_D);
                unregister_code(KC_A);
                // old 283
                if (weave) {
                    SEND_STRING(SS_DOWN(X_D) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(293) SS_UP(X_S) SS_UP(X_D) SS_DELAY(7) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
                } else {
                    SEND_STRING(SS_DOWN(X_A) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(293) SS_UP(X_S) SS_UP(X_A) SS_DELAY(7) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
                }
                weave     = !weave;
                key_timer = timer_read32();
            }
        } break;
            // double sgp skate
        case 2: {
            if (timer_elapsed(key_timer) > 60) {
                register_code(KC_W);
                wait_ms(7);
                register_code(KC_A);
                unregister_code(KC_W);
                wait_ms(7);
                unregister_code(KC_A);
                wait_ms(240);
                tap_code(KC_LALT);
                wait_ms(7);
                tap_code(KC_COMMA);
                wait_ms(60);
                register_code(KC_W);
                wait_ms(7);
                register_code(KC_A);
                unregister_code(KC_W);
                wait_ms(7);
                unregister_code(KC_A);
                wait_ms(60);

                key_timer = timer_read32();
            }
        } break;
            // SGP + BOB/WEAVE
        case 3: {
            if (timer_elapsed(key_timer) > 50) {
                SEND_STRING(SS_DOWN(X_W) SS_DOWN(X_A) SS_DELAY(200) SS_UP(X_W) SS_UP(X_A) SS_DELAY(5) SS_TAP(X_LALT) SS_DELAY(100) // 140
                );
                key_timer = timer_read32();
            }
        } break;
        case 4: {
            if (timer_elapsed(key_timer) > 60) {
                unregister_code(KC_D);
                unregister_code(KC_A);
                if (weave) {
                    SEND_STRING(SS_DOWN(X_D) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(333) SS_UP(X_S) SS_UP(X_D) SS_DELAY(7) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
                } else {
                    SEND_STRING(SS_DOWN(X_A) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(333) SS_UP(X_S) SS_UP(X_A) SS_DELAY(7) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
                }
                weave     = !weave;
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
    HSV final = rgblight_get_hsv();
    rgb_matrix_sethsv_noeeprom(final.h, 0, 255); // turn off color by setting saturation to 0
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CHATGPT);
    kk.key_count      = 0;
    kk.last_key_count = 0;
}

// LEADER_START
// void leader_start_user(void) {
//     // Do something when the leader key is pressed
//     // TODO: change rgb when using leader function ? based on layer probably?
//     rgb_matrix_sethsv_noeeprom(HSV_GREEN);
// }
//
// void leader_end_user(void) {
//     if (leader_sequence_one_key(KC_1))
//         tap_code16(KC_F1);
//     else if (leader_sequence_one_key(KC_2))
//         tap_code16(KC_F2);
//     else if (leader_sequence_one_key(KC_3))
//         tap_code16(KC_F3);
//     else if (leader_sequence_one_key(KC_4))
//         tap_code16(KC_F4);
//     else if (leader_sequence_one_key(KC_5))
//         tap_code16(KC_F5);
//     else if (leader_sequence_one_key(KC_6))
//         tap_code16(KC_F6);
//     else if (leader_sequence_one_key(KC_7))
//         tap_code16(KC_F7);
//     else if (leader_sequence_one_key(KC_8))
//         tap_code16(KC_F8);
//     else if (leader_sequence_one_key(KC_9))
//         tap_code16(KC_F9);
//
//     else if (leader_sequence_two_keys(KC_0, KC_0))
//         tap_code16(KC_F10);
//     else if (leader_sequence_two_keys(KC_0, KC_1))
//         tap_code16(KC_F11);
//     else if (leader_sequence_two_keys(KC_0, KC_2))
//         tap_code16(KC_F12);
//     else if (leader_sequence_two_keys(KC_0, KC_3))
//         tap_code16(KC_F13);
//     else if (leader_sequence_two_keys(KC_0, KC_4))
//         tap_code16(KC_F14);
//     else if (leader_sequence_two_keys(KC_0, KC_5))
//         tap_code16(KC_F15);
//     else if (leader_sequence_two_keys(KC_0, KC_6))
//         tap_code16(KC_F16);
//     else if (leader_sequence_two_keys(KC_0, KC_7))
//         tap_code16(KC_F17);
//     else if (leader_sequence_two_keys(KC_0, KC_8))
//         tap_code16(KC_F18);
//     else if (leader_sequence_two_keys(KC_0, KC_9))
//         tap_code16(KC_F19);
//
//     rgb_matrix_sethsv_noeeprom(HSV_RED);
// }
//
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
        case GRAPHITE:
            // rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            // rgblight_set_speed(50);
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            HSV mayargb = rgblight_get_hsv();
            rgb_matrix_sethsv_noeeprom(mayargb.h, 0, mayargb.v); // turn off color by setting saturation to 0
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
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
        case BMAGE:
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            HSV bmagergb = rgblight_get_hsv();
            rgb_matrix_sethsv_noeeprom(bmagergb.h, bmagergb.s, 255);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
        case BLASTER:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            // HSV gamergb = rgblight_get_hsv();
            // rgb_matrix_sethsv_noeeprom(gamergb.h, 0, gamergb.s); // turn off color by setting saturation to 0
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
        case SEMIMAK:
            rgb_matrix_sethsv_noeeprom(99, 255, 255);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_CHATGPT);
            break;
    }
    return state;
}
