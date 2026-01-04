#pragma once
// left side
// top row X was MINUS
// bottom row F was P
// right side
// P was X
// SLASH was QUOTE
// Y was SLASH

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'R', 'R',           'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',           'R', 'R', 'R'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [RAIN] = LAYOUT_moonlander(
            KC_ESCAPE,    KC_1,          KC_2,            KC_3,           KC_4,           KC_5,           RGB_SAI,            RGB_VAI,          KC_6,       KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
            KC_TAB,       KC_B,          KC_F,            KC_L,           KC_K,           KC_V,           RGB_HUI,            RGB_HUI,          MY_TILD,    KC_W,           KC_O,           KC_U,           KC_DOT,         KC_DEL,
       LT(F_, KC_COMMA),  KC_N,          KC_S,            KC_H,           KC_T,           KC_M,           KC_ENTER,           KC_ENTER,         KC_C,       KC_D,           KC_A,           KC_E,           KC_I,           LT(F_, KC_QUOT),
            KC_LSFT,      KC_P,          KC_X,            KC_J,           HMLS,           KC_Q,                                                 KC_SLASH,   HMRS,           KC_SCLN,        KC_UNDS,        KC_Z,           KC_RSFT,
            KC_LCTL,      KC_RIGHT,      KC_DOWN,         KC_LGUI,        KC_LALT,        OSL(F_),                                              OSL(F_),    KC_RALT,        KC_RGUI,        KC_SCLN,        KC_SCLN,        KC_RCTL,
                                                          KC_R,           OSM(MOD_LSFT),  KC_LCTL,                                              KC_ENTER,   OSM(MOD_RSFT),  KC_SPACE
            ),
    [GAMES] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,         ______,         ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         JS_0,
            KC_TAB,       KC_I,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               ______,           KC_Y,       KC_U,           KC_UP,          KC_O,           KC_P,           JS_1,
           LT(F_,KC_Z),   KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,               ______,           KC_H,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_QUOTE,       KC_K,
            KC_LSFT,      KC_M,           KC_X,           KC_C,           KC_V,           KC_B,                                                 KC_N,       KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          JS_2,
            KC_LCTL,      KC_SLASH,       KC_BSLS,        KC_LGUI,        KC_LALT,        KC_BSPC,                                              ______,     KC_LALT,        KC_RBRC,        KC_LEFT,        KC_DOWN,        JS_3,
                                                          KC_SPACE,       GAME_2,         KC_DELETE,                                            KC_ENTER,   GAME_2,         KC_SPACE
            ),
    [FUNCTION] = LAYOUT_moonlander(
            KC_GRAVE,     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          TO(RAIN),             TO(RAIN),       KC_F6,      KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
            ______,       KC_EXLM,        KC_AT,          KEYUP,          KC_RCBR,        KC_PIPE,        TO(GAMES),            TO(MAPLE),      KC_PGUP,    KC_P7,          KC_P8,          KC_P9,          KC_ASTR,        KC_F12,
            ______,       KC_HASH,        KC_LEFT,        KEYDN,          KC_RIGHT,       KC_MINUS,       TO(BLASTER),          TO(BLASTER),    KC_PGDN,    KC_P4,          KC_P5,          KC_P6,          KC_KP_PLUS,     M_HELPER,
            ______,       KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                              KC_AMPR,    KC_P1,          KC_P2,          KC_P3,          KC_BSLS,        ______,
            ______,       KC_COMMA,       KC_VOLD,        KC_VOLU,        KC_AUDIO_MUTE,  ______,                                               ______,     KC_0,           KC_DOT,         KC_COMMA,       KC_MINUS,       QK_BOOT,
                                                          KC_INS,         KC_BSPC,        RGB_SLD,                                              PWM,        PWM2,           KEYUP
            ),
    [MAPLE] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          KC_O,           KC_P,           KC_T,               ______,           KC_LCTL,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
       LT(F_,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       KC_A,           KC_S,           KC_D,           KC_F,           KC_ENTER,
            KC_B,         KC_M,          KC_COMMA,        KC_K,           KC_N,           KC_G,                                                 KC_H,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_QUOTE,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        ______,                                               ______,     KC_LALT,        ______,         SBIT,           ______,         RBIT,
                                                          KC_SPACE,       KC_ENTER,       KC_DEL,                                               KC_DEL,     KC_ENTER,       KC_COMMA
            ),
    [BLASTER] = LAYOUT_moonlander(
            KC_ESCAPE,    ______,        ______,          ______,         ______,         ______,         ______,             ______,           ______,     ______,         ______,         ______,         ______,         ______,
            KC_TAB,       KC_I,          KC_U,            KC_UP,          BLASTER_O,      KC_P,           KC_T,               ______,           KC_LCTL,    KC_A,           BLASTER_SGP,    KC_D,           KC_E,           KC_R,
       LT(F_,KC_DOT),     KC_LSFT,       KC_LEFT,         KC_DOWN,        KC_RIGHT,       KC_L,           KC_H,               ______,           KC_J,       BLASTER_A,      B_SKATE,        BLASTER_D,      KC_F,           KC_ENTER,
            KC_B,         KC_M,          KC_E,            KC_R,           B_SMAG,         B_FSMAG,                                              KC_Z,       BLASTER_M,      KC_X,           KC_C,           KC_V,           KC_QUOTE,
            KC_Y,         KC_SCLN,       KC_GRAVE,        KC_LGUI,        KC_LALT,        MO(F_),                                               MO(F_),     KC_LALT,        B_SNARL,        ______,         ______,         ______,
                                                          KC_SPACE,       KC_ENTER,       KC_DEL,                                               KC_DEL,     KC_ENTER,       BLASTER_DOUBLE_JUMP
            ),
    [SYMBOLS] = LAYOUT_moonlander(
            KC_GRAVE,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        KC_EQUAL,           KC_MINUS,         KC_KP_6,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_ESCAPE,
            ______,       KC_BSLS,        KC_LBRC,        KC_AT,          KC_RBRC,        KC_PIPE,        ______,             ______,           KC_TILDE,   KC_DQUO,        KC_PIPE,        KC_AMPR,        KC_GRAVE,       KC_F12,
            ______,       KC_PERC,        KC_LPRN,        KC_HASH,        KC_RPRN,        KC_ASTR,        ______,             ______,           KC_QUES,    KC_COLN,        KC_KP_PLUS,     KC_MINUS,       KC_ASTR,        ______,
            ______,       KC_QUOT,        KC_LCBR,        KC_DQUO,        KC_RCBR,        KC_GRAVE,                                             KC_AMPR,    KC_EQUAL,       KC_LT,          KC_GT,          KC_EXLM,        ______,
            ______,       ______,         ______,         ______,         ______,         ______,                                               ______,     ______,         KC_DOT,         KC_0,           ______,         ______,
                                                          KC_LSFT,        ______,         ______,                                               ______,     ______,         KC_RSFT
            ),
};
