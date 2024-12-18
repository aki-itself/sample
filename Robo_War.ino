// BTS7960 Left Motor
#define L_R_EN 7
#define L_L_EN 8
#define L_RPWM 5
#define L_LPWM 6

// Weapon Command
#define WP 3

// BTS7960 Right Motor
#define R_R_EN 11
#define R_L_EN 12
#define R_RPWM 9
#define R_LPWM 10

// Bluetooth commands
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'
#define FOR_RIG 'I'
#define FOR_LEF 'G'
#define BAC_LEF 'H'
#define BAC_RIG 'J'
#define HOR_ON 'V'
#define HOR_OFF 'v'

void setup() {
  // Output pins for both motors
  // left motor
  pinMode(L_R_EN, OUTPUT);
  pinMode(L_L_EN, OUTPUT);
  pinMode(L_RPWM, OUTPUT);
  pinMode(L_LPWM, OUTPUT);

  // Right Motors
  pinMode(R_R_EN, OUTPUT);
  pinMode(R_L_EN, OUTPUT);
  pinMode(R_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);

  pinMode(WP, OUTPUT);
  
  Serial.begin(9600);

  stopMotors();

}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read Bluetooth command

    switch (command) {
      case FORWARD:
        moveForward();
        break;
      case BACKWARD:
        moveBackward();
        break;
      case LEFT:
        turnLeft();
        break;
      case RIGHT:
        turnRight();
        break;
      case FOR_RIG:
        forRig();
        break;
      case FOR_LEF:
        forLef();
        break;
      case BAC_RIG:
        bacRig();
        break;
      case BAC_LEF:
        bacLef();
        break;
      case HOR_ON:
        WP_ON();
        break;
      case HOR_OFF:
        WP_OFF();
        break;
      case STOP:
        stopMotors();
        break;
      default:
        // Unknown command - Do Nothing
        break;
    }
  }
}

void moveForward()
{
  // Left motor forward
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 255);
  analogWrite(L_LPWM, 0);

  // Right motor forward
  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 255);
  analogWrite(R_LPWM, 0);
}

void moveBackward()
{
  // Left motor backward
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 255);

  // Right motor backward
  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 255);
}

void turnLeft()
{

  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 255);

  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 255);
  analogWrite(R_LPWM, 0);
}

void turnRight()
{
  
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 255);
  analogWrite(L_LPWM, 0);

  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 255);
}

void stopMotors()
{
  // Stop both motors
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 0);
}

void forRig()
{
 
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 255);
  analogWrite(L_LPWM, 0);

 
  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 0);
}

void forLef()
{
  
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 0);

  // Right motor forward
  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 255);
  analogWrite(R_LPWM, 0);
}

void bacRig()
{
  
  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 255);

  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 0);
}

void bacLef()
{

  digitalWrite(L_R_EN, HIGH);
  digitalWrite(L_L_EN, HIGH);
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 0);

  digitalWrite(R_R_EN, HIGH);
  digitalWrite(R_L_EN, HIGH);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 255);
}


// Weapon Motor High and Low Command

// High Command
void WP_ON()
{
  digitalWrite(WP, HIGH);
}

// Low Command
void WP_OFF()
{
  digitalWrite(WP, LOW);
}