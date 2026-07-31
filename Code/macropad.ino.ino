#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Buttons
const int BTN1 = 1;
const int BTN2 = 2;
const int BTN3 = 3;
const int BTN4 = 4;

// Timing
unsigned long holdTime = 500;
unsigned long doubleWindow = 250;

// Pet system
String petType = "blob";
int petHungerRate = 5;
int petSleepTime = 20;
bool petEnabled = false;
unsigned long lastFed = 0;

// Button state struct
struct KeyState {
  bool pressed = false;
  unsigned long pressTime = 0;
  unsigned long lastPress = 0;
};
KeyState keys[4];

// Draw simple pet
void drawPet(bool happy) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  if (petType == "blob") {
    display.fillRect(40, 32, 48, 24, SSD1306_WHITE);
    if (happy) display.fillRect(52, 48, 16, 2, SSD1306_BLACK);
  }

  if (petType == "cat") {
    display.fillRect(40, 36, 48, 20, SSD1306_WHITE);
    display.fillRect(42, 28, 10, 10, SSD1306_WHITE);
    display.fillRect(68, 28, 10, 10, SSD1306_WHITE);
    if (happy) display.fillRect(52, 48, 16, 2, SSD1306_BLACK);
  }

  if (petType == "ghost") {
    display.fillRect(40, 28, 48, 28, SSD1306_WHITE);
    if (happy) display.fillRect(52, 48, 16, 2, SSD1306_BLACK);
  }

  display.display();
}

// Handle serial commands
void handleCommand(String cmd) {
  cmd.trim();

  if (cmd.startsWith("SET")) {
    // Example: SET 1 SINGLE CTRL+T
    Serial.println("OK");
  }

  if (cmd.startsWith("SCREEN TEXT")) {
    String text = cmd.substring(cmd.indexOf("\"") + 1, cmd.lastIndexOf("\""));
    display.clearDisplay();
    display.setCursor(0, 32);
    display.setTextSize(1);
    display.print(text);
    display.display();
    Serial.println("OK");
  }

  if (cmd.startsWith("SCREEN IMG")) {
    // Expect 8192 bits
    Serial.println("OK");
  }

  if (cmd.startsWith("SCREEN PET ENABLE")) {
    petEnabled = true;
    drawPet(false);
    Serial.println("OK");
  }

  if (cmd.startsWith("PET FEED")) {
    lastFed = millis();
    drawPet(true);
    delay(600);
    drawPet(false);
    Serial.println("OK");
  }

  if (cmd.startsWith("PET TYPE")) {
    petType = cmd.substring(9);
    drawPet(false);
    Serial.println("OK");
  }

  if (cmd.startsWith("PET HUNGER_RATE")) {
    petHungerRate = cmd.substring(16).toInt();
    Serial.println("OK");
  }

  if (cmd.startsWith("PET SLEEP_TIME")) {
    petSleepTime = cmd.substring(15).toInt();
    Serial.println("OK");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  // Read serial
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    handleCommand(cmd);
  }

  // Pet idle refresh
  if (petEnabled) {
    if (millis() - lastFed > petHungerRate * 10000) {
      drawPet(false);
    }
  }
}
