#pragma once
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GRAPHITE] = LAYOUT_moonlander(
            QK_GESC,      KC_1,          KC_2,            KC_3,           KC_4,           KC_5,           KC_EQUAL,           KC_MINUS,         KC_6,       KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
            KC_TAB,       KC_SLASH,      KC_U,            KC_O,           KC_F,           KC_X,           ______,             ______,           KC_Z,       KC_W,           KC_D,           KC_L,           KC_Q,           KC_DEL,
            MY_LEFTP,     HM_I,          HM_E,            KC_A,           HM_H,           KC_Y,           ______,             ______,           KC_G,       HM_S,           KC_T,           HM_R,           HM_N,           MY_RIGHP,
            KC_LSFT,      MY_TILD,       KC_MINUS,        KC_DOT,         KC_P,           KC_K,                                                 KC_V,       KC_C,           KC_M,           KC_J,           KC_B,           KC_RSFT,
            KC_LCTL,      KC_RIGHT,      KC_DOWN,         MY_LEFT,        MY_UP,          LT(6,KC_ESC),                                  LT(6,KC_ESCAPE),   MY_DOWN,        MY_RIGHT,       KC_SCLN,        KC_SCLN,        KC_RCTL,
                                                          LT(7, KC_NO),   KC_BSPC,        KC_ENTER,                                             KC_DEL,     THUMBR2,        LT(7, KC_SPACE)
            ), // MY_TILD
    [GAMES] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,         ______,         ______,         ______,         ______,         ______,             ______,           ______,     ______, ______, ______, ______, ______,
            KC_TAB,       KC_I,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               ______,           KC_Y,       KC_U,           KC_I,           KC_O,           KC_P,           KC_EXLM,
            LT(6,KC_Z),   KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,               ______,           KC_H,       KC_J,           KC_K,           KC_L,           KC_QUOTE,       KC_QUES,
            KC_LSFT,      KC_M,           KC_X,           KC_C,           KC_V,           KC_B,                                                 KC_N,       KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
            KC_LCTL,      KC_SLASH,       KC_BSLS,        KC_LGUI,        KC_LALT,        KC_BSPC,                                              ______,     KC_LBRC,        KC_RBRC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                    KC_SPACE,   MT(MOD_LCTL, KC_ENTER)   ,KC_DELETE,                                    KC_ENTER,   MT(MOD_RSFT, KC_ENTER),KC_SPACE
            ),
    [FUNCTION] = LAYOUT_moonlander(
            KC_GRAVE,     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          TO(0),              TO(4),            KC_F6,      KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
            ______,       KC_EXLM,        KC_AT,          KEYUP,          KC_RCBR,        KC_PIPE,        TO(1),              TO(2),            KC_UP,      KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
            ______,       KC_HASH,        KC_LEFT,        KEYDN,          KC_RIGHT,       KC_MINUS,       TO(5),              TO(3),            KC_DOWN,    KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     ______,
            ______,       KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                              KC_AMPR,    KC_1,           KC_2,           KC_3,           KC_BSLS,        ______,
            SBIT,         KC_COMMA,       KC_VOLD,        KC_VOLU,        KC_AUDIO_MUTE,  ______,                                               ______,     KC_0,           KC_DOT,         KC_COMMA,       KC_MINUS,       QK_BOOT,
                                                          KC_INS,         KC_BSPC,        RGB_SLD,                                              PWM,        PWM2,           KEYUP
            ),
    [MAPLE] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
        LT(6,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       KC_A,           MP_S,           KC_D,           KC_F,           LT(6, KC_ENTER),
            ______,       KC_M,          KC_COMMA,        KC_K,           KC_N,           KC_G,                                                 KC_H,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        ______,                                               ______,     KC_LALT,        ______,         ______,         ______,         ______,
            KC_SPACE,       KC_ENTER,       ______,                                               ______,     KC_ENTER,       KC_COMMA
            ),
    [BMAGE] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
        LT(6,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       KC_A,           KC_S,           KC_D,           KC_F,           LT(6, KC_ENTER),
            ______,       KC_M,          KC_COMMA,        KC_K,           B_HAMMER,       KC_G,                                                 KC_H,       BLASTER_M,      KC_X,           KC_C,           KC_V,           KC_B,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        ______,                                               ______,     KC_LALT,        ______,         ______,         ______,         ______,
            KC_SPACE,       KC_ENTER,       ______,                                               ______,     KC_ENTER,       KC_COMMA
            ),
    [BLASTER] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           BLASTER_SGP,    KC_E,           KC_R,           KC_T,
        LT(6,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       BLASTER_A,      B_SKATE,        BLASTER_D,      KC_F,           LT(6, KC_ENTER),
            ______,       KC_M,          KC_COMMA,        KC_K,           B_HAMMER,       KC_N,                                                 KC_Z,       BLASTER_M,      KC_X,           KC_C,           KC_V,           KC_B,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,         LT(6,KC_ESCAPE),                                 LT(6,KC_ESCAPE), KC_LALT,        B_M_SLOW,         ______,         ______,         ______,
                                                          KC_SPACE,       KC_ENTER,       KC_DEL,                                               ______,     KC_ENTER,       KC_COMMA
            ),
    [SEMIMAK] = LAYOUT_moonlander(
            KC_ESCAPE,    KC_1,          KC_2,            KC_3,           KC_4,           KC_5,           RGB_SAI,            RGB_VAI,          KC_6,       KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
            KC_TAB,       KC_MINUS,      KC_L,            KC_H,           KC_V,           KC_Z,           RGB_HUI,            RGB_HUI,          KC_GRAVE,   KC_W,           KC_U,           KC_O,           KC_QUOTE,       KC_TAB,
        LT(6, KC_F),      KC_S,          KC_R,            KC_N,           KC_T,           KC_K,           ______,             ______,           KC_C,       KC_D,           KC_E,           KC_A,           KC_I,           LT(6, KC_Y),
            KC_LSFT,      KC_P,          KC_J,            KC_B,           KC_M,           KC_Q,                                                 KC_X,       KC_G,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSFT,
            KC_LCTL,      ______,        ______,          ______,         ______,         LT(6,KC_ESCAPE),                                LT(6,KC_ESCAPE),  ______,         ______,         ______,         ______,         KC_RCTL,
                                                          US_MAG3,   KC_LSFT,        KC_ENTER,                                             KC_DEL,     THUMBR2,        LT(7, KC_SPACE)
            ),
    [SYMBOLS] = LAYOUT_moonlander(
            KC_GRAVE,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        KC_EQUAL,            KC_MINUS,          KC_KP_6,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_ESCAPE,
            ______,       KC_BSLS,        KC_LBRC,        KC_RBRC,        KC_AT,          KC_PIPE,        ______,              ______,            KC_UNDS,    KC_PIPE,        KC_MINUS,       KC_AMPR,        KC_ASTR,        KC_F12,
            KC_SCLN,      KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_HASH,        KC_ASTR,        ______,              ______,            KC_ASTR,    KC_UNDS,        KC_SCLN,        KC_DOT,         KC_KP_PLUS,     ______,
            ______,       KC_PERC,        KC_LCBR,        KC_RCBR,        KC_DQUO,        KC_GRAVE,                                               KC_AMPR,    KC_EQUAL,       KC_LT,          KC_GT,          KC_EXLM,        ______,
            ______,       ______,         ______,         ______,         ______,         ______,                                                 ______,     ______,         KC_DOT,         KC_0,           ______,         ______,
                                                          KC_LSFT,        ______,         ______,                                                 ______,     ______,         KC_RSFT
            ),

};
