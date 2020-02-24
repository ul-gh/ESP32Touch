#ifndef TOUCH_BUTTONS_HPP__
#define TOUCH_BUTTONS_HPP__

#include <functional>
#include <driver/touch_pad.h>
#include <Ticker.h>

// Set to 1 to enable debug print output
#define ENABLE_DEBUG_PRINT 1
#include "info_debug_error.h"

using CallbackT = std::function<void(void)>;

class ESP32Touch
{
public:
    ESP32Touch();
    virtual ~ESP32Touch();
    void configure_input(const int input_number,
                         const uint8_t threshold_percent,
                         CallbackT callback = nullptr);
    void calibrate_thresholds();
    void begin();
    void diagnostics();

private:
    Ticker event_timer;
    static uint8_t s_pad_threshold_percent[TOUCH_PAD_MAX];
    static bool s_pad_enabled[TOUCH_PAD_MAX];
    static bool s_pad_is_pressed[TOUCH_PAD_MAX];
    static uint16_t s_pad_filtered_value[TOUCH_PAD_MAX];
    static uint16_t s_pad_threshold[TOUCH_PAD_MAX];
    static CallbackT s_pad_callback[TOUCH_PAD_MAX];

    static void filter_read_cb(uint16_t *raw_value, uint16_t *filtered_value);
    static void dispatch_callbacks(ESP32Touch* self);
}; // class ESP32Touch

#endif
