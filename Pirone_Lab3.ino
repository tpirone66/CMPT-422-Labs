const int sensorPin = A0;
const float baselineTemp = 23.0;
const float maxTemp = 28.0;
const int greenLEDPin = 10;
const int blueLEDPin = 11;
const int redLEDPin = 9;
const int numReadings = 10;
float prevTemp = 0;
int blueValue = 255;
int redValue = 0;
int redBright = 255;
int blueBright = 255;
int redSensorValue = 0;
int blueSensorValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(sensorPin);
  delay(5);
  blueSensorValue = analogRead(sensorPin);
  int sensorVal = analogRead(sensorPin);
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float average = 0.0;
  Serial.print(", Normalized Sensor Value: ");
  for (int i = 0; i < numReadings; i++) {
    average = average + (analogRead(sensorPin) - average);
  }
  Serial.print(average);
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  prevTemp = temperature;
  Serial.println(temperature);
  if (temperature <= baselineTemp) {
    blueBright = 255;
    redBright = 0;
    analogWrite(redLEDPin, redBright);
    analogWrite(blueLEDPin, blueBright);
    prevTemp = temperature;
    return;
  }
  if (temperature >= maxTemp) {
    blueBright = 0;
    redBright = 255;
    analogWrite(redLEDPin, redBright);
    analogWrite(blueLEDPin, blueBright);
    prevTemp = temperature;
    return;
  }
  if (temperature > baselineTemp and temperature <= baselineTemp + .5) {
    analogWrite(redLEDPin, 25.5);
    analogWrite(blueLEDPin, 229.5);
    return;
  }
  if (temperature > baselineTemp + .5 and temperature <= baselineTemp + 1) {
    analogWrite(redLEDPin, 51);
    analogWrite(blueLEDPin, 204);
    return;
  }
  if (temperature > baselineTemp + 1 and temperature <= baselineTemp + 1.5) {
    analogWrite(redLEDPin, 76.5);
    analogWrite(blueLEDPin, 178.5);
    return;
  }
  if (temperature > baselineTemp + 1.5 and temperature <= baselineTemp + 2) {
    analogWrite(redLEDPin, 102);
    analogWrite(blueLEDPin, 153);
    return;
  }
  if (temperature > baselineTemp + 2 and temperature <= baselineTemp + 2.5) {
    analogWrite(redLEDPin, 127.5);
    analogWrite(blueLEDPin, 127.5);
    return;
  }
  if (temperature > baselineTemp + 2.5 and temperature <= baselineTemp + 3) {
    analogWrite(redLEDPin, 127.5);
    analogWrite(blueLEDPin, 127.5);
    return;
  }
  if (temperature > baselineTemp + 3 and temperature <= baselineTemp + 3.5) {
    analogWrite(redLEDPin, 153);
    analogWrite(blueLEDPin, 102);
    return;
  }
  if (temperature > baselineTemp + 3.5 and temperature <= baselineTemp + 4) {
    analogWrite(redLEDPin, 178.5);
    analogWrite(blueLEDPin, 76.5);
    return;
  }
  if (temperature > baselineTemp + 4 and temperature <= baselineTemp + 4.5) {
    analogWrite(redLEDPin, 204);
    analogWrite(blueLEDPin, 51);
    return;
  }
  if (temperature > baselineTemp + 4.5 and temperature < baselineTemp + 5) {
    analogWrite(redLEDPin, 229.5);
    analogWrite(blueLEDPin, 25.5);
    return;
  }
  analogWrite(redLEDPin, redBright);
  analogWrite(blueLEDPin, blueBright);
}
