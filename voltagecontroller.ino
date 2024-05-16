int led = 13;
int sol = 3;
#define but 5
bool buttonState = false; // Variable to store button state
bool lastButtonState = false; // Variable to store last button state
unsigned long lastDebounceTime = 0; // Variable to store last debounce time
unsigned long debounceDelay = 50; // Debounce delay in milliseconds
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sol, OUTPUT);
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  // Read the button state with debounce
  int reading = digitalRead(but);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        // Button is pressed
        digitalWrite(sol, LOW);
        digitalWrite(led, HIGH);
      } else {
      digitalWrite(sol, HIGH);
      digitalWrite(led, LOW);
      }
    }
  }
  lastButtonState = reading;
}






