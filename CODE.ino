// QTR-8A sensor pins
const int sensorPins[8] = {
  32, 33, 34, 35, 36, 39, 25, 26
};

// TB6612FNG motor driver pins
const int PWMA = 14;
const int AIN1 = 27;
const int AIN2 = 13;

const int PWMB = 4;
const int BIN1 = 18;
const int BIN2 = 19;

const int STBY = 23;

// PID values
float Kp = 0.12;
float Ki = 0.0;
float Kd = 0.5;

int baseSpeed = 130;
int maxSpeed = 220;

float error = 0;
float previousError = 0;
float integral = 0;

int sensorValues[8];

void setup() {

  Serial.begin(115200);

  // Configure sensors
  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  // Configure motor driver
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  // ESP32 ADC resolution
  analogReadResolution(12);

  stopMotors();

  delay(1000);
}

void loop() {

  int position = readLine();

  // Calculate error from center
  error = position - 3500;

  // PID calculations
  integral += error;

  float derivative = error - previousError;

  float correction =
      Kp * error +
      Ki * integral +
      Kd * derivative;

  previousError = error;

  // Calculate motor speeds
  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
  rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);

  // Move robot
  setMotor(leftSpeed, rightSpeed);

  // Debugging
  Serial.print("Position: ");
  Serial.print(position);

  Serial.print(" Error: ");
  Serial.print(error);

  Serial.print(" Left: ");
  Serial.print(leftSpeed);

  Serial.print(" Right: ");
  Serial.println(rightSpeed);

  delay(5);
}

// Read sensor array and calculate line position
int readLine() {

  long weightedSum = 0;
  long total = 0;

  for (int i = 0; i < 8; i++) {

    int rawValue = analogRead(sensorPins[i]);

    // QTR-8A usually gives lower readings on black
    int value = 4095 - rawValue;

    sensorValues[i] = value;

    weightedSum += (long)value * i * 1000;
    total += value;
  }

  // If line is not detected
  if (total < 800) {
    return 3500;
  }

  return weightedSum / total;
}

// Control both motors
void setMotor(int left, int right) {

  // Left motor
  if (left >= 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }

  // Right motor
  if (right >= 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  analogWrite(PWMA, abs(left));
  analogWrite(PWMB, abs(right));
}

// Stop both motors
void stopMotors() {

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
