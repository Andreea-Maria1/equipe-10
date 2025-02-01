#include <Servo.h>

Servo myservo; 

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const   int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
int pos = 0;


void setup()   {
  myservo.attach(10); 
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3,   OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB,   OUTPUT);
  for (pos = 110; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15 ms for the servo to reach the position
  }
  delay(10000);
  for (pos = 60; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15 ms for the servo to reach the position
  }
  delay(5000);

}

void loop() {
  myservo.write(75); 
  MoveForward(100);
  delay(500);
  Movebackward(100);
  delay(500);
  TurnRight(70);
  delay(2000);
  MoveForward(70);
  delay(500);
  Movebackward(100);
  delay(500);
  

}


void MoveForward(int speed){
  analogWrite(ENA,   speed);
  analogWrite(ENB, 172); 
  digitalWrite(IN1,   HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4,   LOW);
}

void Movebackward(int speed){
  analogWrite(ENA,   speed);
  analogWrite(ENB, speed); 
  digitalWrite(IN1,   LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,   HIGH);
}



void TurnRight(int speed){
  analogWrite(ENA,   speed);
  analogWrite(ENB, speed+90); 
  digitalWrite(IN1,   LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4,   LOW);
}

void TurnLeft(int speed){
  analogWrite(ENA,   speed);
  analogWrite(ENB, speed); 
  digitalWrite(IN1,   HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,   HIGH);
}