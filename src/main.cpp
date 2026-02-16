#include <Arduino.h>

// Define the number of LEDs
const int ledCount = 6;

// Create an array to store the pin numbers for each LED
int ledPins[] = {2, 3, 4, 5, 6, 7};

// Function prototypes
void allLedsOff();
void allLedsOn(int duration);
void sparkle(int duration);
void chase(int duration);
void wonder(int duration);
void climbUp(int duration);
void shimmer(int duration);

void setup() {
  // Set all the LED pins to OUTPUT mode
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Seed the random number generator
  randomSeed(analogRead(0));
}

void loop() {
  // --- First line: "Twinkle, twinkle, little star" ---
  sparkle(250);
  sparkle(250);
  chase(250);
  allLedsOn(500);
  delay(250); // Pause

  // --- Second line: "How I wonder what you are" ---
  wonder(1000);
  allLedsOn(1000);
  delay(250); // Pause

  // --- Third line: "Up above the world so high" ---
  climbUp(1000);
  delay(1000); // Hold all on
  allLedsOff();
  delay(250); // Pause

  // --- Fourth line: "Like a diamond in the sky" ---
  shimmer(1000);
  allLedsOn(1000);
  delay(250); // Pause

  // --- Repeat first line: "Twinkle, twinkle, little star" ---
  sparkle(250);
  sparkle(250);
  chase(250);
  allLedsOn(500);
  delay(250); // Pause

  // --- Repeat second line: "How I wonder what you are" ---
  wonder(1000);
  allLedsOn(1000);
  delay(1500); // Longer pause before looping
}

// --- Helper Functions ---

void allLedsOff() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void allLedsOn(int duration) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(duration);
  allLedsOff();
}

void sparkle(int duration) {
  allLedsOff();
  digitalWrite(ledPins[random(ledCount)], HIGH);
  digitalWrite(ledPins[random(ledCount)], HIGH);
  delay(duration);
  allLedsOff();
}

void chase(int duration) {
  for (int i = 0; i < ledCount; i++) {
    allLedsOff();
    digitalWrite(ledPins[i], HIGH);
    delay(duration / ledCount);
  }
}

void wonder(int duration) {
  int stepDelay = duration / (ledCount * 2);
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(stepDelay);
  }
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(stepDelay);
  }
}

void climbUp(int duration) {
  allLedsOff();
  int stepDelay = duration / ledCount;
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(stepDelay);
  }
}

void shimmer(int duration) {
  int stepDelay = 50;
  int shimmerCount = duration / stepDelay;
  for (int i = 0; i < shimmerCount; i++) {
    allLedsOff();
    digitalWrite(ledPins[random(ledCount)], HIGH);
    delay(stepDelay);
  }
}
