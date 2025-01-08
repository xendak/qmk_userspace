#pragma once

bool blaster_nrl_weave(keyrecord_t *record) {
    if (record->event.pressed) {
        unregister_code(KC_LALT);
        unregister_code(KC_D);
        unregister_code(KC_A);
        SEND_STRING(SS_DOWN(X_D));
    } else {
        SEND_STRING( SS_DOWN(X_S) SS_DELAY(303) SS_UP(X_S) SS_DELAY(7) SS_UP(X_D) SS_DELAY(1) );
    }
    return false;
}

bool blaster_nrl_bob(keyrecord_t *record) {
    if (record->event.pressed) {
        unregister_code(KC_LALT);
        unregister_code(KC_D);
        unregister_code(KC_A);
        SEND_STRING(SS_DOWN(X_A));
    } else {
        SEND_STRING( SS_DOWN(X_S) SS_DELAY(303) SS_UP(X_S) SS_DELAY(7) SS_UP(X_A) SS_DELAY(1) );
    }
    return false;

}

bool blaster_nrl_bob_short_dash(keyrecord_t *record) {
    if (record->event.pressed)
        SEND_STRING(SS_DOWN(X_A) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(333) SS_UP(X_S) SS_UP(X_A) SS_DELAY(150) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
    return false;
}
bool blaster_nrl_weave_short_dash(keyrecord_t *record) {
    if (record->event.pressed)
        SEND_STRING(SS_DOWN(X_D) SS_DOWN(X_S) SS_DELAY(30) SS_DELAY(333) SS_UP(X_S) SS_UP(X_D) SS_DELAY(150) SS_DOWN(X_LALT) SS_DELAY(20) SS_UP(X_LALT) SS_DELAY(40));
    return false;
}

bool blaster_skate(keyrecord_t *record) {
    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_A));
    } else {
        SEND_STRING(SS_UP(X_A) SS_DELAY(240) SS_DOWN(X_LALT) SS_DOWN(X_COMMA) SS_DELAY(40) SS_UP(X_LALT) SS_UP(X_COMMA));
    }
    return false;
}

bool blaster_skate_jump_only(keyrecord_t *record) {
    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(7) SS_DOWN(X_COMMA) SS_DELAY(40) SS_UP(X_LALT) SS_UP(X_COMMA));
    }
    return false;
}

bool blaster_smag(keyrecord_t *record) {
    if (record->event.pressed) {
        SEND_STRING(
                SS_DOWN(X_X)
                SS_DOWN(X_D)
                SS_DELAY(105)
                SS_DOWN(X_N)
                SS_DELAY(35)
                SS_UP(X_N)
                SS_DELAY(200)
                SS_UP(X_X)
                SS_DELAY(250)
                SS_TAP(X_K)
                SS_TAP(X_K)
                SS_DOWN(X_K)
                SS_DELAY(20)
                SS_UP(X_K)
                SS_DELAY(100)
                SS_UP(X_D)
                SS_DELAY(110)
                SS_DOWN(X_LALT)
                SS_DELAY(50)
                SS_UP(X_LALT)
                SS_DELAY(10)
                );
    }
    return false;
}

// ON MATRIX
void blaster_nrl_macro(bool weave) {
    unregister_code(KC_LALT);
    unregister_code(KC_D);
    unregister_code(KC_A);

    if (weave) {
        SEND_STRING(SS_DOWN(X_D) SS_DELAY(7) SS_DOWN(X_S) SS_DELAY(303) SS_UP(X_S) SS_DELAY(7) SS_UP(X_D) SS_DELAY(6) SS_DOWN(X_LALT) SS_DELAY(80) SS_UP(X_LALT) SS_DELAY(1));
    } else {
        SEND_STRING(SS_DOWN(X_A) SS_DELAY(7) SS_DOWN(X_S) SS_DELAY(303) SS_UP(X_S) SS_DELAY(7) SS_UP(X_A) SS_DELAY(6) SS_DOWN(X_LALT) SS_DELAY(80) SS_UP(X_LALT) SS_DELAY(1));
    }
}

void blaster_sgp(void) {
    SEND_STRING(SS_DOWN(X_W) SS_DOWN(X_A) SS_DELAY(200) SS_UP(X_W) SS_UP(X_A) SS_DELAY(5) SS_TAP(X_LALT) SS_DELAY(100));
}

void blaster_double_sgp_skate(void) {
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
}

void blaster_snarl(void) {
    SEND_STRING(
            SS_DOWN(X_X)
            SS_DELAY(60)
            SS_DOWN(X_S)
            SS_DELAY(350)
            SS_UP(X_S)
            SS_DELAY(70)
            SS_UP(X_X)
            SS_DELAY(15)
            );
}
