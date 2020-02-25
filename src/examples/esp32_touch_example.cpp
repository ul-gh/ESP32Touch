/** @file esp32_touch_example.cpp
 * ********************** ESP32Touch basic example ****************************
 * 
 * This registers three touch button inputs switching on/off and toggling
 * an LED connected to GPIO 2 (on-board blue LED on many popular boards).
 * 
 * All of the operation takes place asynchronously via user-defined
 * callback functions, which can be any type compatible with a C++
 * std::function object, i.e. plain global functions, static an non-static
 * class or instance members or C++11 lambda expressions.
 * The callbacks must have a signature of void(void).
 * 
 * 
 * For the sensor input pins, please again note that the touch API uses
 * a different numbering scheme than the standard GPIO numbers.
 * E.g. touch button no. 0 is GPIO 4.
 * 
 * I can also recommend the ESP32 pinout reference and reserved pins info from:
 * https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
 * 
 * GPIOs used in this example: <p>
 *    GPIO2:   LED output, tied to GND via 220...470 Ohms <br>
 *    GPIO12:  Touch sensor input for OFF <br>
 *    GPIO13:  Touch sensor input for ON <br>
 *    GPIO15:  Touch sensor input for toggling </p>
 * 
 * Repository at: https://github.com/ul-gh/ESP32Touch
 * 2020-02-25 Ulrich Lukas
 */

#include <Arduino.h>
// Omit this line to disable debug print output
#define ENABLE_DEBUG_PRINT 1
#include <esp32_touch.hpp>

// LED pin
constexpr uint8_t led_pin = 2;     // GPIO 2

// Touch button GPIO pins
constexpr int touch_io_off = 5;    // GPIO 12
constexpr int touch_io_on = 4;     // GPIO 13
constexpr int touch_io_toggle = 3; // GPIO 15

// Touch button touch detection threshold in percent of the
// calibration-time (i.e. idle-state) sensor readout value.
constexpr uint8_t touch_threshold = 92;

// Standard serial port setup
constexpr unsigned long serial_baudrate = 115200;

// Instantiate touch button driver
ESP32Touch buttons{};

// Define callback functions
void enable_led() {
  Serial.println("Switching ON the LED!");
  digitalWrite(led_pin, HIGH);
}
void disable_led() {
  Serial.println("Switching the LED off!");
  digitalWrite(led_pin, LOW);
}

void setup() {
  // Enable serial output
  Serial.begin(serial_baudrate);
  // Setup LED GPIO pin
  pinMode(led_pin, OUTPUT);
  // Register above callback functions with the touch button driver
  buttons.configure_input(touch_io_on, touch_threshold, enable_led);
  buttons.configure_input(touch_io_off, touch_threshold, disable_led);
  // You can also directly register a lambda:
  buttons.configure_input(touch_io_toggle, touch_threshold, []() {
      bool current_led_state = (bool)digitalRead(led_pin);
      digitalWrite(led_pin, ~current_led_state);
  });
  // Call this once and you are done..
  buttons.begin();
}

void loop() {
  // All touch button code runs asynchronously, you can do anything here.
}