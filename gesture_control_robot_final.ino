int xPin = A0;  // Analog input pin for x-axis gesture control
int yPin = A1;  // Analog input pin for y-axis gesture control

int out1 = 8;   // Output pins for controlling the robot motors
int out2 = 9;
int out3 = 10;
int out4 = 11;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
}
void loop() {
  int xval = analogRead(xPin);  // Read the analog value from the x-axis sensor
  int yval = analogRead(yPin);  // Read the analog value from the y-axis sensor

  if ((xval > 294 && xval < 340) && (yval > 294 && yval < 340)) {
    // If x and y values fall within a certain range, stop the robot
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
  } else {
    // Otherwise, check other conditions to determine robot movement
    if ((xval > 340 && xval < 380) && (yval > 294 && yval < 340)) {
      // Forward
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      digitalWrite(out3, HIGH);
      digitalWrite(out4, LOW);
    }
    if ((xval > 345 && xval < 294) && (yval > 294 && yval < 340)) {
      // Backward
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      digitalWrite(out3, LOW);
      digitalWrite(out4, HIGH);
    }
    if ((xval > 294 && xval < 340) && (yval > 340 && yval < 380)) {
      // Left
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      digitalWrite(out3, LOW);
      digitalWrite(out4, LOW);
    }
    if ((xval > 294 && xval < 340) && (yval > 340 && yval < 294)) {
      // Right
      digitalWrite(out1, LOW);
      digitalWrite(out2, LOW);
      digitalWrite(out3, HIGH);
      digitalWrite(out4, LOW);
    }
  }
}
