#include <Arduino.h>
#include "BluetoothSerial.h"

// Function Prototypes
void motor1Fwd();
void motor1Rev();
void motor1Stopped();
void motor2Fwd();
void motor2Rev();
void motor2Stopped();
void motor3Fwd();
void motor3Rev();
void motor3Stopped();
void motor4Fwd();
void motor4Rev();
void motor4Stopped();
void motor5Fwd();
void motor5Rev();
void motor5Stopped();



// ensure Bluetooth is properly enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to enable it
#endif

// Instance for Bluetooth object
BluetoothSerial ESP_BT;

// Pinout Assignments

// Motor 1
int motor1Pin1 = 4;
int motor1Pin2 = 2;

// Motor 2
int motor2Pin1 = 16;
int motor2Pin2 = 12;

// Motor 3
int motor3Pin1 = 18;
int motor3Pin2 = 17;

// Motor 4
int motor4Pin1 = 21;
int motor4Pin2 = 19;

// Motor 5
int motor5Pin1 = 23;
int motor5Pin2 = 22;

// LED Pin
int LEDPin = 33;

// Global Vars
int numRecieved;
int dataCount = 1;
int data;

void setup() {
  // set baud rate for ESP32
  Serial.begin(115200);

  // Setting up Outputs

  // Motor 1
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  // Motor 2
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Motor 3
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);

  // Motor 4
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);

  // Motor 5
  pinMode(motor5Pin1, OUTPUT);
  pinMode(motor5Pin2, OUTPUT);

  // LED
  pinMode(LEDPin, OUTPUT);

  // ESP BT device name
  ESP_BT.begin("ESP32_JandM");

  // Printing to let user know pairing 
  Serial.println("Device started, ok to pair with Bluetooth!");
}

void loop() {

  while (ESP_BT.available()){

    delay(10);
    Serial.println("Reading Data");
    numRecieved = ESP_BT.read();
    
    
    switch (numRecieved) {
      case 1:
        Serial.println("Running Case 1");
        motor2Fwd();
        motor2Stopped();
        break;
      
      case 2:
        Serial.println("Running Case 2");
        motor2Rev();
        motor2Stopped();
        break;

      case 3:
        Serial.println("Running Case 3");
        motor3Rev();
        motor3Stopped();
        break;

      case 4:
        Serial.println("Running Case 4");
        motor3Fwd();
        motor3Stopped();
        break;

      case 5:
        Serial.println("Running Case 5");
        motor4Fwd();
        motor4Stopped();
        break;

      case 6:
        Serial.println("Running Case 6");
        motor4Rev();
        motor4Stopped();
        break;

      case 7:
        Serial.println("Running Case 7");
        motor5Fwd();
        motor5Stopped();
        break;
        
      case 8:
        Serial.println("Running Case 8");
        motor5Rev();
        motor5Stopped();
        break;

      case 9:
        Serial.println("Running Case 9");
        digitalWrite(LEDPin, !(digitalRead(LEDPin)));
        break;

      case 10:
        Serial.println("Running Case 10");
        motor1Fwd();
        motor1Stopped();
        break;

      case 11:
        Serial.println("Running Case 11");
        motor1Rev();
        motor1Stopped();
        break;

      case 12:
        Serial.println("Running Case 12");
        motor1Stopped();
        break;
          
      default:
        Serial.println("Running default Case");
        break;
    }
  }
}



// Function Declerations

// Motor 1 Fwd
void motor1Fwd() {
  Serial.println("Moving M1 Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  delay(800);
}

// Motor 1 Rev
void motor1Rev() {
  Serial.println("Moving M1 Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  delay(800);
}

// Motor 1 Stop
void motor1Stopped() {
  Serial.println("Motor M1 stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(800);
}

// Motor 2 Fwd
void motor2Fwd() {
  Serial.println("Moving M2 Forward");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(1000);
}

// Motor 2 Rev
void motor2Rev() {
  Serial.println("Moving M2 Backwards");
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);
}

// Motor 2 Stop
void motor2Stopped() {
  Serial.println("Motor M2 stopped");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);
}

// Motor 3 Fwd
void motor3Fwd() {
  Serial.println("Moving M3 Forward");
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  delay(1000);
}

// Motor 3 Rev
void motor3Rev() {
  Serial.println("Moving M3 Backwards");
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  delay(1000);
}

// Motor 3 Stop
void motor3Stopped() {
  Serial.println("Motor M3 stopped");
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  delay(1000);
}

// Motor 4 Fwd
void motor4Fwd() {
  Serial.println("Moving M4 Forward");
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
  delay(1000);
}

// Motor 4 Rev
void motor4Rev() {
  Serial.println("Moving M4 Backwards");
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);
}

// Motor 4 Stop
void motor4Stopped() {
  Serial.println("Motor M4 stopped");
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);
}

// Motor 5 Fwd
void motor5Fwd() {
  Serial.println("Moving M5 Forward");
  digitalWrite(motor5Pin1, LOW);
  digitalWrite(motor5Pin2, HIGH);
  delay(1000);
}

// Motor 5 Rev
void motor5Rev() {
  Serial.println("Moving M5 Backwards");
  digitalWrite(motor5Pin1, HIGH);
  digitalWrite(motor5Pin2, LOW);
  delay(1000);
}

// Motor 5 Stop
void motor5Stopped() {
  Serial.println("Motor M5 stopped");
  digitalWrite(motor5Pin1, LOW);
  digitalWrite(motor5Pin2, LOW);
  delay(1000);
}
