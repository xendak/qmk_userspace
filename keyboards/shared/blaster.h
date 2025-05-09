#pragma once

#define NRL_DELAY 313

#define K_JMP KC_LALT
#define X_JMP X_LALT

bool blaster_nrl_weave(keyrecord_t *record) {
    if (record->event.pressed) {
        weave = false;
        unregister_code(K_JMP);
        unregister_code(KC_D);
        unregister_code(KC_A);
        // SEND_STRING( SS_DOWN(X_D) SS_DOWN(X_S) SS_DELAY(NRL_DELAY) SS_UP(X_S) SS_UP(X_D) SS_DELAY(15) );

        SEND_STRING(
            SS_DOWN(X_D) SS_DELAY(5)
            SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(90)
            SS_DOWN(X_J) SS_DELAY(30) SS_UP(X_J) SS_DELAY(146)
            SS_UP(X_D)
            // SS_DELAY(6) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP)
        );

    }
    return false;
}

bool blaster_nrl_bob(keyrecord_t *record) {
    if (record->event.pressed) {
        weave = false;
        unregister_code(K_JMP);
        unregister_code(KC_D);
        unregister_code(KC_A);
        // SEND_STRING( SS_DOWN(X_A) SS_DOWN(X_S) SS_DELAY(NRL_DELAY) SS_UP(X_S) SS_UP(X_A) SS_DELAY(7) );

        SEND_STRING(
            SS_DOWN(X_A) SS_DELAY(5)
            SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(90)
            SS_DOWN(X_J) SS_DELAY(30) SS_UP(X_J) SS_DELAY(146)
            SS_UP(X_A)
            // SS_DELAY(6) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP)
        );

    }
    return false;

}

bool blaster_nrl_bob_short_dash(keyrecord_t *record) {
    if (record->event.pressed)
        SEND_STRING(SS_DOWN(X_A) SS_DOWN(X_S) SS_DELAY(NRL_DELAY) SS_UP(X_S) SS_UP(X_A) SS_DELAY(150) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP) SS_DELAY(40));
    return false;
}
bool blaster_nrl_weave_short_dash(keyrecord_t *record) {
    if (record->event.pressed)
        SEND_STRING(SS_DOWN(X_D) SS_DOWN(X_S) SS_DELAY(NRL_DELAY) SS_UP(X_S) SS_UP(X_D) SS_DELAY(150) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP) SS_DELAY(40));
    return false;
}

bool blaster_bullet_blast(keyrecord_t *record) {
    if (record->event.pressed) {
        weave = false;
        SEND_STRING(SS_DOWN(X_O));
        SEND_STRING(SS_DOWN(X_Q));
    } else {
        SEND_STRING(SS_UP(X_O) SS_UP(X_Q));
    }
    return false;
}

bool blaster_skate(keyrecord_t *record) {
    if (record->event.pressed) {
        weave = false;
        SEND_STRING(SS_DOWN(X_A));
    } else {
        SEND_STRING(SS_UP(X_A) SS_DELAY(240) SS_DOWN(X_JMP) SS_DOWN(X_COMMA) SS_DELAY(40) SS_UP(X_JMP) SS_UP(X_COMMA));
    }
    return false;
}

bool blaster_skate_jump_only(keyrecord_t *record) {
    if (record->event.pressed) {
        weave = false;
        SEND_STRING(SS_DOWN(X_JMP) SS_DELAY(7) SS_DOWN(X_COMMA) SS_DELAY(40) SS_UP(X_JMP) SS_UP(X_COMMA));
    }
    return false;
}

bool blaster_smag(keyrecord_t *record, uint16_t key) {
            // record, KC_A);

    if (record->event.pressed) {
        weave = false;
        wait_ms(5);
        unregister_code(K_JMP);
        register_code(key);
        wait_ms(15);
        register_code(KC_X);
        wait_ms(55);
        register_code(KC_N);
        wait_ms(80);
        unregister_code(KC_N);
        wait_ms(180);
        unregister_code(KC_X);
        wait_ms(150);
        register_code(KC_K);
        wait_ms(90);
        unregister_code(KC_K);
        wait_ms(185);
        unregister_code(key);
        wait_ms(100);
        tap_code(KC_LALT);
    }
    return false;
}

bool blaster_smag_gms(keyrecord_t *record, uint16_t key) {
            // record, KC_A);

    if (record->event.pressed) {
        weave = false;
        wait_ms(5);
        unregister_code(K_JMP);
        register_code(key);
        wait_ms(55);
        register_code(KC_X);
        wait_ms(55);
        register_code(KC_N);
        wait_ms(80);
        unregister_code(KC_N);
        wait_ms(180);
        unregister_code(KC_X);
        wait_ms(150);
        register_code(KC_K);
        wait_ms(90);
        unregister_code(KC_K);
        wait_ms(185);
        unregister_code(key);
        wait_ms(100);
        tap_code(KC_LALT);
        wait_ms(25);
    }
    return false;
}


// ON MATRIX
void blaster_nrl_macro(void) {
    unregister_code(K_JMP);
    unregister_code(KC_D);
    unregister_code(KC_A);

    if (weave) {
        SEND_STRING(
            SS_DOWN(X_D) SS_DELAY(5)
            SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(90)
            SS_DOWN(X_J) SS_DELAY(30) SS_UP(X_J) SS_DELAY(146)
            // SS_DOWN(X_S) SS_DELAY(330) SS_UP(X_S) SS_DELAY(7)
            SS_UP(X_D) SS_DELAY(6) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP)
            SS_DELAY(32));
    } else {
        SEND_STRING(
            SS_DOWN(X_A) SS_DELAY(5)
            SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(90)
            SS_DOWN(X_J) SS_DELAY(30) SS_UP(X_J) SS_DELAY(146)
            // SS_DOWN(X_S) SS_DELAY(330) SS_UP(X_S) SS_DELAY(7)
            SS_UP(X_A) SS_DELAY(6) SS_DOWN(X_JMP) SS_DELAY(20) SS_UP(X_JMP)
            SS_DELAY(32));
    }
}

void blaster_sgp(void) {
    SEND_STRING(SS_DOWN(X_W) SS_DOWN(X_A) SS_DELAY(200) SS_UP(X_W) SS_UP(X_A) SS_DELAY(5) SS_TAP(X_JMP) SS_DELAY(120));
}

void blaster_double_sgp_skate(void) {
    register_code(KC_W);
    wait_ms(7);
    register_code(KC_A);
    unregister_code(KC_W);
    wait_ms(7);
    unregister_code(KC_A);
    wait_ms(240);
    tap_code(K_JMP);
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

// void blaster_snarl(void) {
//     SEND_STRING(
//         SS_DOWN(X_A)
//         SS_DOWN(X_X)
//         // SS_DELAY(179)
//         SS_DOWN(X_K) SS_DELAY(90) SS_UP(X_K) SS_DELAY(60)
//         SS_DOWN(X_J) SS_DELAY(60) SS_UP(X_J) SS_DELAY(146)
//         SS_UP(X_X)
//         SS_DELAY(150)
//         SS_UP(X_A)
//         SS_DELAY(10)
//         SS_DOWN(X_JMP)
//         SS_DELAY(25)
//         SS_UP(X_JMP)
//         SS_DELAY(15)
//     );
// }


void blaster_snarl(void) {
    SEND_STRING(
        SS_DOWN(X_X)
        SS_DELAY(100)
        SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(90)
        SS_DOWN(X_J) SS_DELAY(30) SS_UP(X_J) SS_DELAY(186)
        SS_UP(X_X)
        SS_DELAY(32)
    );
}

// void blaster_snarl(void) {
//     SEND_STRING(
//         SS_DOWN(X_X)
//         SS_DELAY(99)
//         SS_DOWN(X_K) SS_DELAY(90) SS_UP(X_K) SS_DELAY(60)
//         SS_DOWN(X_J) SS_DELAY(60) SS_UP(X_J) SS_DELAY(186)
//         SS_UP(X_X)
//         SS_DELAY(10)
//     );
// }

void gms_blaster_snarl(void) {
    SEND_STRING(
        SS_DOWN(X_X)
        SS_DELAY(169)
        SS_DOWN(X_K) SS_DELAY(90) SS_UP(X_K) SS_DELAY(60)
        SS_DOWN(X_J) SS_DELAY(60) SS_UP(X_J) SS_DELAY(156)
        // SS_DOWN(X_K) SS_DELAY(60) SS_UP(X_K) SS_DELAY(136)
        SS_UP(X_X)
        SS_DELAY(10)
    );
}
