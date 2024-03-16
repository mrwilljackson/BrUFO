#include "Pushbutton.h"

Pushbutton::Pushbutton(byte pin) : pin(pin), state(HIGH), lastState(HIGH), lastReading(HIGH), buttonPressed(false), debounceDelay(50) {
  // Constructor initializes the pin and debounce parameters
}

void Pushbutton::init() {
  pinMode(pin, INPUT_PULLUP); // Initialize the button pin as input with pull-up
  lastReading = digitalRead(pin); // Initial read of the button state
}

void Pushbutton::update() {
  byte newReading = digitalRead(pin);

  // Check for a change in the reading
  if (newReading != lastReading) {
    lastDebounceTime = millis(); // Reset the debounce timer
  }

  // Check if the button state has been stable for longer than the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Update the stable state if it has changed
    if (newReading != state) {
      state = newReading;
      // If the button was pressed (considering active low), mark the event
      if (state == LOW) {
        buttonPressed = true;
      }
    }
  }

  lastReading = newReading; // Save the current reading as the last reading
}

bool Pushbutton::wasPressed() {
  // Check if a button press was recorded
  if (buttonPressed) {
    buttonPressed = false; // Reset the flag
    return true;
  }
  return false;
}