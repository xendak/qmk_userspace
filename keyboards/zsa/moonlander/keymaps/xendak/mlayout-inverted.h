#pragma once

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [RAIN] = LAYOUT_moonlander(
        RGB_VAI,      KC_6,          KC_7,            KC_8,           KC_9,           KC_0,           KC_BSPC,            KC_ESCAPE,        KC_1,       KC_2,           KC_3,           KC_4,           KC_5,           RGB_SAI,
        RGB_HUI,      MY_TILD,       KC_W,            KC_O,           KC_U,           KC_DOT,         KC_BSPC,            KC_TAB,           KC_P,       KC_F,           KC_L,           KC_K,           KC_V,           RGB_HUI,
        KC_MINUS,     KC_C,          KC_D,            KC_A,           KC_E,           KC_I,      LT(F_, KC_SLASH),    LT(F_, KC_COMMA),     KC_N,       KC_S,           KC_H,           KC_T,           KC_M,           KC_EQUAL,
        KC_QUOT,      KC_G,          KC_SCLN,         KC_UNDS,        KC_Z,           KC_RSFT,                                              KC_LSFT,    KC_B,           KC_X,           KC_J,           KC_Y,           KC_Q,
        KC_LSFT, LT(S_, KC_SPACE),   KC_DEL,          LT(F_,KC_ESC),  KC_NO,          KC_NO,                                                KC_NO,      KC_NO,          LT(F_,KC_ESC),  KC_ENTER,       KC_R,           LT(S_, KC_SCLN),
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),

    [GAMES] = LAYOUT_moonlander(
        _______,      _______,       _______,         _______,        _______,        _______,        _______,            KC_ESCAPE,        _______,    _______,        _______,        _______,        _______,        _______,
        _______,      KC_Y,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_EXLM,            KC_TAB,           KC_I,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
        _______,      KC_H,          KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_QUOTE,       KC_QUES,            LT(F_,KC_Z),      KC_LSFT,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_N,         KC_M,          KC_COMMA,        KC_DOT,         KC_UP,          KC_SLASH,                                             KC_LSFT,    KC_M,           KC_X,           KC_C,           KC_V,           KC_B,
        KC_SPACE,     GAME_2,        KC_ENTER,        LT(F_,KC_ESC),  KC_NO,          KC_NO,                                                KC_NO,      KC_NO,          LT(F_,KC_ESC),  KC_DELETE,      GAME_2,         KC_SPACE,
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),

    [FUNCTION] = LAYOUT_moonlander(
        TO(RAIN),     KC_F6,         KC_F7,           KC_F8,          KC_F9,          KC_F10,         KC_F11,             KC_GRAVE,         KC_F1,      KC_F2,          KC_F3,          KC_F4,          KC_F5,          TO(RAIN),
        TO(MAPLE),    KC_UP,         KC_P7,           KC_P8,          KC_P9,          KC_ASTR,        KC_F12,             _______,          KC_EXLM,    KC_AT,          KEYUP,          KC_RCBR,        KC_PIPE,        TO(GAMES),
        TO(BLASTER),  KC_DOWN,       KC_P4,           KC_P5,          KC_P6,          KC_KP_PLUS,     _______,            _______,          KC_HASH,    KC_LEFT,        KEYDN,          KC_RIGHT,       KC_MINUS,       TO(BLASTER),
        KC_AMPR,      KC_P1,         KC_P2,           KC_P3,          KC_BSLS,        _______,                                              _______,    KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,
        KEYUP,        PWM2,          PWM,             KC_NO,          KC_NO,          KC_NO,                                                KC_NO,      KC_NO,          KC_NO,          RGB_SLD,        KC_BSPC,        KC_INS,
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),

    [MAPLE] = LAYOUT_moonlander(
        _______,      _______,       _______,         _______,        _______,        _______,        _______,            KC_ESCAPE,        _______,    _______,        _______,        _______,        _______,       _______,
        _______,      KC_LCTL,       KC_Q,            KC_W,           KC_E,           KC_R,           KC_T,               KC_TAB,           KC_I,       KC_U,           KC_UP,          KC_O,           KC_P,          KC_T,
        _______,      KC_J,          KC_A,            MP_S,           KC_D,           KC_F,           KC_ENTER,         LT(F_,KC_DOT),      KC_LSFT,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_L,          KC_H,
        KC_H,         KC_Z,          KC_X,            KC_C,           KC_V,           KC_QUOTE,                                             KC_B,       KC_M,           KC_COMMA,       KC_K,           KC_N,          KC_G,
        KC_DEL,       KC_COMMA,      KC_LALT,         LT(F_,KC_ESC),  KC_NO,          KC_NO,                                                KC_NO,      KC_NO,          LT(F_,KC_ESC),  KC_Y,           KC_LALT,       KC_SPACE,
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),
    [BLASTER] = LAYOUT_moonlander(
        _______,      _______,       _______,         _______,        _______,        _______,        _______,             KC_ESCAPE,       _______,    _______,        _______,        _______,        _______,       _______,
        _______,      KC_LCTL,       KC_A,            BLASTER_SGP,    KC_D,           KC_E,           KC_R,                KC_TAB,          KC_I,       KC_U,           KC_UP,          BLASTER_O,      KC_P,          KC_T,
        _______,      KC_J,          BLASTER_A,       B_SKATE,        BLASTER_D,      KC_F,           KC_ENTER,            LT(F_,KC_DOT),   KC_LSFT,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_L,          KC_H,
        KC_Z,         BLASTER_M,     KC_X,            KC_C,           KC_V,           KC_QUOTE,                                             KC_B,       KC_M,           KC_E,           KC_R,           B_SMAG,        B_FSMAG,
        KC_DEL,       KC_COMMA,      KC_LALT,         LT(F_,KC_ESC),  KC_NO,          KC_NO,                                                KC_NO,      KC_NO,          LT(F_,KC_ESC),  KC_Y,           KC_LALT,       KC_SPACE,
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),

    [SYMBOLS] = LAYOUT_moonlander(
        KC_MINUS,     KC_KP_6,       KC_KP_7,         KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_ESCAPE,           KC_GRAVE,        KC_KP_1,    KC_KP_2,       KC_KP_3,         KC_KP_4,        KC_KP_5,       KC_EQUAL,
        _______,      KC_UNDS,       KC_PIPE,         KC_MINUS,       KC_AMPR,        KC_ASTR,        KC_F12,              _______,         KC_BSLS,    KC_LBRC,       KC_RBRC,         KC_AT,          KC_PIPE,       _______,
        _______,      KC_ASTR,       KC_UNDS,         KC_SCLN,        KC_DOT,         KC_KP_PLUS,     _______,             KC_SCLN,         KC_MINUS,   KC_LPRN,       KC_RPRN,         KC_HASH,        KC_ASTR,       _______,
        KC_AMPR,      KC_EQUAL,      KC_LT,           KC_GT,          KC_EXLM,        _______,                                              _______,    KC_PERC,       KC_LCBR,         KC_RCBR,        KC_DQUO,       KC_GRAVE,
        KC_RSFT,      _______,       _______,         KC_NO,          KC_NO,          KC_NO,                                                KC_NO,      KC_NO,         KC_NO,           _______,        _______,       KC_LSFT,
        KC_NO,        KC_NO,         KC_NO,           KC_NO,          KC_NO,          KC_NO
    ),

};
