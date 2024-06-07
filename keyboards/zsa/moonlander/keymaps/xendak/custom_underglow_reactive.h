#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(UNDERGLOW_REACTIVE)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// typedef HSV (*runner_custom_splash_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick);
// bool effect_runner_custom_reactive_splash(uint8_t start, effect_params_t* params, reactive_splash_f effect_func) {
//   RGB_MATRIX_USE_LIMITS(led_min, led_max);
//   uint8_t count = g_last_hit_tracker.count;
//   // uint8_t first_sat = rgb_matrix_config.hsv.s;
//   for (uint8_t i = led_min; i < led_max; i++) {
//     bool override_base_led = false;
//     RGB_MATRIX_TEST_LED_FLAGS();
//     HSV hsv = rgb_matrix_config.hsv;
//     // hsv.v   = 0;
//     for (uint8_t j = start; j < count; j++) {
//       int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
//       int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
//       uint8_t  dist = sqrt16(dx * dx + dy * dy);
//       uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
//       hsv           = effect_func(hsv, dx, dy, dist, tick);
//       override_base_led = true;
//     }
//     hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
//     //RGB old_rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv.v)
//     RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
//     //rgb_matrix_set_color(i, 0x30, 0x30, 0x90);
//     if (override_base_led)
//       rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//     // rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//   }
//   return rgb_matrix_check_finished_leds(led_max);
// }
//
static HSV CUSTOM_REACTIVE_NEXUS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
  uint16_t effect = tick - dist;
  if (effect > 255)
    //effect = 0;
  {
    hsv.v = 205;
    hsv.h = (rgb_matrix_config.hsv.h + 90) % 360;
    // hsv.h = 50;
    // hsv.s = 0;
    return hsv;
  }
  if (dist > 72)
    // effect = 255;
  {
    hsv.v = 205;
    hsv.h = (rgb_matrix_config.hsv.h + 90) % 360;
    // hsv.h = 50;
    // hsv.s = 0;
    return hsv;
  }

  if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8))
    // effect = 255;
  {
    hsv.v = 205;
    hsv.h = (rgb_matrix_config.hsv.h + 90) % 360;
    // hsv.h = 50;
    // hsv.s = 0;
    return hsv;
  }

  hsv.v = qadd8(hsv.v, 255 - effect);
  hsv.h = rgb_matrix_config.hsv.h + dy / 4;
  // hsv.h = scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed, 1) >> 6);
  hsv.s = qadd8(hsv.s, 255 - effect);
  return hsv;
}

bool UNDERGLOW_REACTIVE(effect_params_t* params) {
  return effect_runner_reactive_splash(0, params, &CUSTOM_REACTIVE_NEXUS_math);
}
#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
