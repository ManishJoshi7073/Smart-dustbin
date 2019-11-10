#include <Servo.h>
Servo servo;
#include <LiquidCrystal.h>
const int rs=12,en=7,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal LCD(rs,en,d4,d5,d6,d7);
int echo = 9;
int trig=8;
int buzzerpin=1;
long distance;
long duration;
int servopin=11;
void setup() {
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
pinMode(10,OUTPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
servo.attach(11,600,2300);
  LCD.begin(16,2);
  pinMode(1,OUTPUT);
}

void loop() {

  
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo,HIGH);
  distance=duration*(0.034/2);
  Serial.println("Distance is: ");
  Serial.println(distance);
  if(distance<=9)
  {
    {
    digitalWrite(10,HIGH);
     delay(10);
    }
  servo.write(180);              
  delay(500);
    digitalWrite(10,LOW);
      LCD.print("Object detected");
      Serial.println("Object detected");
      delay(100);
    digitalWrite(10,LOW);
    LCD.clear();
}
  else
  {
    servo.write(0);
    delay(500);
   digitalWrite(13,HIGH);
   LCD.print("use me");
   Serial.println("Use me");
    delay(500);
    digitalWrite(13,LOW);
     noTone(buzzerpin);
      LCD.clear(); 
        servo.write(0);
  delay(100);
  }
   tone(1, distance);
  delay(60);
  noTone(4);
  

}
