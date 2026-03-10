// Motor driver pins
#define ENA 5
#define IN1 6
#define IN2 7
#define ENB 9
#define IN3 10
#define IN4 11

// Ultrasonic sensor
#define TRIG 3
#define ECHO 4

// Line sensors
#define LEFT_SENSOR 2
#define RIGHT_SENSOR 8

long duration;
int distance;

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  Serial.begin(9600);
}

void loop()
{
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  // If obstacle very close -> stop (parking)
  if(distance < 15)
  {
    stopCar();
    Serial.println("Vehicle Parked");
  }
  else
  {
    lineFollow();
  }

  delay(50);
}

int getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  return duration * 0.034 / 2;
}

void lineFollow()
{
  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  if(left == LOW && right == LOW)
  {
    moveForward();
  }
  else if(left == HIGH && right == LOW)
  {
    turnLeft();
  }
  else if(left == LOW && right == HIGH)
  {
    turnRight();
  }
  else
  {
    stopCar();
  }
}

void moveForward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void turnLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void turnRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void stopCar()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}