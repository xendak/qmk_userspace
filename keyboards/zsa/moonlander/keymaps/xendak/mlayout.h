#pragma once

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [SEMIMAK] = LAYOUT_moonlander(
            KC_ESCAPE,    KC_1,          KC_2,            KC_3,           KC_4,           KC_5,           RGB_SAI,            RGB_VAI,          KC_6,       KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
            KC_TAB,       KC_MINUS,      KC_L,            KC_H,           KC_V,           KC_Z,           RGB_HUI,            RGB_HUI,          MY_TILD,    KC_W,           KC_U,           KC_O,           KC_QUOTE,       KC_BSPC,
       LT(F_, KC_F),      KC_S,          KC_R,            KC_N,           KC_T,           KC_K,           KC_EQUAL,           KC_MINUS,         KC_C,       KC_D,           KC_E,           KC_A,           KC_I,          LT(F_, KC_Y),
            KC_LSFT,      KC_P,          KC_J,            KC_B,           KC_M,           KC_Q,                                                 KC_X,       KC_G,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSFT,
            KC_LCTL,      KC_RIGHT,      KC_DOWN,         MY_LEFT,        MY_UP,         LT(F_,KC_ESC),                                   LT(F_,KC_ESC),    MY_DOWN,        MY_RIGHT,       KC_SCLN,        KC_SCLN,        KC_RCTL,
                                                          US_MAG3, LT(S_, KC_SCLN),       KC_ENTER,                                             KC_DEL,     KC_LSFT,       LT(S_, KC_SPACE)
            ),
    [GAMES] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,         ______,         ______,         ______,         ______,         ______,             ______,           ______,     ______, ______, ______, ______, ______,
            KC_TAB,       KC_I,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               ______,           KC_Y,       KC_U,           KC_I,           KC_O,           KC_P,           KC_EXLM,
           LT(F_,KC_Z),   KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,               ______,           KC_H,       KC_J,           KC_K,           KC_L,           KC_QUOTE,       KC_QUES,
            KC_LSFT,      KC_M,           KC_X,           KC_C,           KC_V,           KC_B,                                                 KC_N,       KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
            KC_LCTL,      KC_SLASH,       KC_BSLS,        KC_LGUI,        KC_LALT,        KC_BSPC,                                              ______,     KC_LBRC,        KC_RBRC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                          KC_SPACE,       GAME_2,         KC_DELETE,                                            KC_ENTER,   GAME_2,         KC_SPACE
            ),
    [FUNCTION] = LAYOUT_moonlander(
            KC_GRAVE,     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          TO(SEMIMAK),          TO(BMAGE),      KC_F6,      KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
            ______,       KC_EXLM,        KC_AT,          KEYUP,          KC_RCBR,        KC_PIPE,        TO(GAMES),            TO(MAPLE),      KC_UP,      KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
            ______,       KC_HASH,        KC_LEFT,        KEYDN,          KC_RIGHT,       KC_MINUS,       TO(SEMIMAK),          TO(BLASTER),    KC_DOWN,    KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     ______,
            ______,       KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                              KC_AMPR,    KC_1,           KC_2,           KC_3,           KC_BSLS,        ______,
            SBIT,         KC_COMMA,       KC_VOLD,        KC_VOLU,        KC_AUDIO_MUTE,  ______,                                               ______,     KC_0,           KC_DOT,         KC_COMMA,       KC_MINUS,       QK_BOOT,
                                                          KC_INS,         KC_BSPC,        RGB_SLD,                                              PWM,        PWM2,           KEYUP
            ),
    [MAPLE] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
       LT(F_,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       KC_A,           MP_S,           KC_D,           KC_F,           KC_ENTER,
            KC_B,         KC_M,          KC_COMMA,        KC_K,           KC_N,           KC_G,                                                 KC_H,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_QUOTE,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        ______,                                               ______,     KC_LALT,        ______,         ______,         ______,         ______,
                                                          KC_SPACE,       KC_ENTER,       KC_DEL,                                               ______,     KC_ENTER,       KC_COMMA
            ),
    [BMAGE] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           BLASTER_SGP,    KC_E,           KC_R,           KC_T,
       LT(F_,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       B_A,            KC_S,           B_D,            KC_F,          LT(F_, KC_ENTER),
            KC_B,         KC_M,          KC_COMMA,        KC_K,           B_SMAG,         KC_G,                                                 KC_H,       B_NRL_FARM,     KC_X,           KC_C,           KC_V,           KC_QUOTE,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        ______,                                               ______,     KC_LALT,        ______,         ______,         ______,         ______,
                                                          KC_SPACE,       KC_ENTER,       B_NRL_FARM,                                           ______,     KC_ENTER,       KC_COMMA
            ),
    [BLASTER] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           BLASTER_SGP,    KC_E,           KC_R,           KC_T,
       LT(F_,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       BLASTER_A,      B_SKATE,        BLASTER_D,      KC_F,           KC_ENTER,
            KC_B,         KC_M,          KC_COMMA,        KC_K,           B_SMAG,         KC_N,                                                 KC_Z,       BLASTER_M,      KC_X,           KC_C,           KC_V,           KC_QUOTE,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,       LT(F_,KC_ESCAPE),                                LT(F_,KC_ESCAPE), KC_LALT,        B_SNARL,        ______,         ______,         ______,
                                                          KC_SPACE,       KC_ENTER,       KC_DEL,                                               ______,     KC_ENTER,       KC_COMMA
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
