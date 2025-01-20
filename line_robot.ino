// Define motor pins
#define ENA 5       // Enable pin for left motor (PWM)
#define ENB 6       // Enable pin for right motor (PWM)
#define IN1 7       // Input 1 for left motor
#define IN2 8       // Input 2 for left motor
#define IN3 9       // Input 3 for right motor
#define IN4 10      // Input 4 for right motor

// Define IR sensor pin
#define IR_SENSOR A0

void setup() {
  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set IR sensor pin as input
  pinMode(IR_SENSOR, INPUT);

  // Initialize motors to off
  stopMotors();
}

void loop() {
  int irValue = analogRead(IR_SENSOR); // Read IR sensor value

  // Threshold for detecting the black line
  int thresholdLow = 400;  // Black line detection (lower bound)
  int thresholdHigh = 600; // White surface detection (upper bound)

  if (irValue < thresholdLow) {
    // Black line detected
    turnRight();
  } else if (irValue > thresholdHigh) {
    // No line detected (white surface)
    turnLeft();
  } else {
    // In the middle (gray area or line edge)
    moveForward();
  }
}


// Function to turn the robot right
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100); // Adjust speed
  analogWrite(ENB, 150); // Adjust speed
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150); // Adjust speed
  analogWrite(ENB, 100); // Adjust speed
}


// Function to move the robot forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150); // Adjust speed
  analogWrite(ENB, 150); // Adjust speed
}



// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
