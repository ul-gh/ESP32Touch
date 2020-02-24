#include <Arduino.h>
#include <esp32_touch.hpp>


// Touch button touch detection threshold in percent of the
// calibration-time idle-state sensor readout value
constexpr uint8_t touch_threshold = 92;
// Touch button GPIO pins
constexpr int touch_io_left = 4; // GPIO 13
constexpr int touch_io_right = 5; // GPIO 12
// LED pin
constexpr uint8_t led_pin = 2; // Onboard-LED on the NodeMCU32s and similar boards
// Standard serial port setup
constexpr unsigned long serial_baudrate = 115200;

// Instanciate touch button driver
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
  Serial.begin(serial_baudrate);
  pinMode(led_pin, OUTPUT);
  buttons.configure_input(touch_io_left, touch_threshold, enable_led);
  buttons.configure_input(touch_io_right, touch_threshold, disable_led);
  buttons.begin();
}

void loop() {
  // All touch button code runs asynchronously, you can do anything here
}
