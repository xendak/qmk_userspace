#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_CHATGPT) || defined(ENABLE_RGB_MATRIX_CHATGPT_MULTICROSS)

#        ifdef ENABLE_RGB_MATRIX_CHATGPT
RGB_MATRIX_EFFECT(CHATGPT)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


typedef HSV (*new_reactive_splash_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, HSV base);

bool effect_runner_reactive_new_splash(uint8_t start, effect_params_t* params, new_reactive_splash_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        HSV base = rgb_matrix_config.hsv;
        // hsv.v   = 120;
        // hsv.h = ((hsv.h + 127) % 255);
        // hsv.s = hsv.s <= 100 ? 255 : hsv.s;

        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = effect_func(hsv, dx, dy, dist, tick, base);
        }
        hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#define RADIUS 2
static HSV CHATGPT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, HSV base) {
    uint16_t effect = tick + dist * RADIUS;
    if (effect > 255) effect = 255;
    if (dist > RADIUS * 16) effect = 255;
    // if ((dx > 4 || dx < -4) && (dy > 4 || dy < -4)) effect = 255;
    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4) + dy / 4;
    // hsv.h = rgb_matrix_config.hsv.h + dy / 4;
    if (effect < 255) hsv.h = ((base.h + 127) % 255);//(255 - effect));
    if (effect < 255) hsv.s = base.s <= 100 ? 255 : base.s;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool CHATGPT(effect_params_t* params) {
    return effect_runner_reactive_new_splash(0, params, &CHATGPT_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_CHATGPT) || defined(ENABLE_RGB_MATRIX_CHATGPT_MULTICROSS)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
