# ESP32Touch
ESP32 touch button driver for the Arduino framwork using async callback interface

## Example usage
File: [src/examples/esp32_touch_example.cpp](https://github.com/ul-gh/ESP32Touch/blob/master/src/examples/esp32_touch_example.cpp)

## HTML class documentation
File: [doc/html/class_e_s_p32_touch.html](https://htmlpreview.github.io/?https://github.com/ul-gh/ESP32Touch/blob/master/doc/html/class_e_s_p32_touch.html)

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`ESP32Touch`](#class_e_s_p32_touch) | ESP32 touch button driver with async callback interface.

# class `ESP32Touch` 

ESP32 touch button driver with async callback interface.

This configures the hardware capacitive touch input pins on the Espressif ESP32 platform for up to ten non-multiplexed buttons.

All of the operation takes place asynchronously via user-defined callback functions, which can be any type compatible with a C++ std::function object, i.e. plain global functions, static an non-static class or instance members or C++11 lambda expressions.

In contrast to the original Arduino touchRead() function, this implementation works reliably with stable, filtered sensor readout and without false triggers by random spikes/zeros from some hardware or API failure (See: [https://forum.arduino.cc/index.php?topic=629955.0](https://forum.arduino.cc/index.php?topic=629955.0))

This API uses the ESP-IDF touch sensor interface, but does not register with the touch hardware ISR interface. Instead, this uses the continuous output from the ESP-IDF touch IIR filter using the filter_read_cb() hook from touch_pad.h. A freeRTOS timer (via Ticker.h) is then set up periodicly calling an event loop handler checking if any button threshold level is reached. If this is the case, it then calls the respective user callback. This has the advantage of not blocking the filter ISR for extended time.

The cycle time for the event checking loop can be configured in the header via dispatch_cycle_time_ms setting, the default is 100 milliseconds.

For the sensor input pins, please again note that the touch API uses a different numbering scheme than the standard GPIO numbers. E.g. touch button no. 0 is GPIO 4.

Repository at: [https://github.com/ul-gh/ESP32Touch](https://github.com/ul-gh/ESP32Touch) 2020-02-25 Ulrich Lukas

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ESP32Touch`](#class_e_s_p32_touch_1a7074c8f7d36dbc91ac5547326abac55a)`()` | 
`public virtual  `[`~ESP32Touch`](#class_e_s_p32_touch_1aa0a1b61dcde76dfc6ff4f927e95c393c)`()` | 
`public void `[`configure_input`](#class_e_s_p32_touch_1a4d71a331ef00f6853eb2285a0afd9763)`(const int input_number,const uint8_t threshold_percent,`[`CallbackT`](#esp32__touch_8hpp_1a57055132e8b5e6931a9475fa451990ae)` callback)` | Configure input pin as a touch input, set threshold value and register the required user callback called when pin is touched.
`public void `[`calibrate_thresholds`](#class_e_s_p32_touch_1a3d6f0e4afbb6f98f753ec02d71bd4ec4)`()` | Force a sensor re-calibration.
`public void `[`begin`](#class_e_s_p32_touch_1a25a1bb0d553ca66879253f21bc9e402c)`()` | This must be called once after all the user callbacks have been set up.
`public void `[`diagnostics`](#class_e_s_p32_touch_1ad8bad94cf8a6e9b6df5d4e8b07d8f5af)`()` | Call this periodicly to see the raw sensor readout values printed.

## Members

#### `public  `[`ESP32Touch`](#class_e_s_p32_touch_1a7074c8f7d36dbc91ac5547326abac55a)`()` 

#### `public virtual  `[`~ESP32Touch`](#class_e_s_p32_touch_1aa0a1b61dcde76dfc6ff4f927e95c393c)`()` 

#### `public void `[`configure_input`](#class_e_s_p32_touch_1a4d71a331ef00f6853eb2285a0afd9763)`(const int input_number,const uint8_t threshold_percent,`[`CallbackT`](#esp32__touch_8hpp_1a57055132e8b5e6931a9475fa451990ae)` callback)` 

Configure input pin as a touch input, set threshold value and register the required user callback called when pin is touched.

#### Parameters
* `input_number` Touch input pin number (!) different from GPIO numbering (!) 

* `threshold_percent` Touch button touch detection threshold in percent of the calibration-time (i.e. idle-state) sensor readout value. 

* `callback` User callback function, which can be any type compatible with a C++ std::function object, i.e. plain global functions, static an non-static class or instance members or C++11 lambda expressions. The callback must have a signature of void(void).

#### `public void `[`calibrate_thresholds`](#class_e_s_p32_touch_1a3d6f0e4afbb6f98f753ec02d71bd4ec4)`()` 

Force a sensor re-calibration.

This is called implicitly by [ESP32Touch::begin()](#class_e_s_p32_touch_1a25a1bb0d553ca66879253f21bc9e402c), but can be called later at run-time to do a re-calibration.

The touch buttons must not be pressed down while the calibration is running..

#### `public void `[`begin`](#class_e_s_p32_touch_1a25a1bb0d553ca66879253f21bc9e402c)`()` 

This must be called once after all the user callbacks have been set up.

#### `public void `[`diagnostics`](#class_e_s_p32_touch_1ad8bad94cf8a6e9b6df5d4e8b07d8f5af)`()` 

Call this periodicly to see the raw sensor readout values printed.

Generated by [Moxygen](https://sourcey.com/moxygen)
