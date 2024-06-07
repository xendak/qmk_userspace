#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(UNDERGLOW_SPIRAL)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CUSTOM_REACTIVE_SPIRAL_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
  uint16_t effect = tick - dist;
  if (effect > 255)
  {
      hsv.v = 205;
      return hsv;
  }
  hsv.h += effect;
  if (dist >= 40) {
      hsv.v = 205;
      return hsv;
  }
  hsv.v = qadd8(hsv.v, 255 - effect);
  return hsv;
}
bool UNDERGLOW_SPIRAL(effect_params_t* params) {
  return effect_runner_reactive_splash(0, params, &CUSTOM_REACTIVE_SPIRAL_math);
}
#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
