#pragma once

#define rot8(x, k) (((x) << (k)) | ((x) >> (8 - (k))))
uint8_t jsf8(void) {
    static uint8_t a = 0xf1;
    static uint8_t b = 0xee, c = 0xee, d = 0xee;

    uint8_t e = a - rot8(b, 1);
    a = b ^ rot8(c, 4);
    b = c + d;
    c = d + e;
    return d = e + a;
}

void random_time(float base_time_seconds) {
    // Convert base time to milliseconds, rounded
    uint16_t base_ms = (uint16_t)(base_time_seconds * 1000.0f + 0.5f);
    // Generate jitter (-127 to +127 ms) using jsf8()
    uint8_t r = jsf8();
    int16_t jitter = (r & 0x80) ? -(r & 0x7F) : (r & 0x7F);
    // Calculate total delay, ensuring non-negative
    int32_t total_ms = (int32_t)base_ms + jitter;
    if (total_ms < 0) total_ms = 0;
    // Wait for the computed time
    wait_ms((uint16_t)total_ms);
}
