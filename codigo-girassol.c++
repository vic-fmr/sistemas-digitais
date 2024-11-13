#include "Servo.h"

Servo myservo;

int pos = 0; 
int ldrEsquerda = A0; 
int ldrDireita = A1;
int pinoServoMotor = 9;

int Left = 0; 
int Right = 0; 

void setup()  {
Serial.begin(9600);
pinMode(ldrEsquerda, INPUT);
pinMode(ldrDireita,INPUT);
myservo.attach(pinoServoMotor);
myservo.write(pos);
}

void loop()  {
Left = analogRead(ldrEsquerda);
Right = analogRead(ldrDireita);
Serial.println(Left);
Serial.println(Right);

if (Left > (Right +20))  {
  if (pos < 179){
pos++;
myservo.write(pos);
}
}

if (Right > (Left +20))  {
  if (pos > 1){
pos -= 1;
myservo.write(pos); 
}
}

delay(10);
}
