/*
* ***************************  
  written : Binuka Dasunpriya
  date : 21st July 2020
  updated : 31st May 2021
  updated By : Binuka Dasunpriya
  Email : binukadasunpriya@gmail.com
  GitHub : https://github.com/BinukaDasunpriya
* ***************************  
* ***************************
we need : a ultrasonic sensor
        : a arduino Uno/nano/mega board
        : 7 jumpers
        : a Servo motor 
        
        
connections : Servo motor 
              :Red wire > 5v 
              :orange wire > Arduino pin 9
              :Brown wire > Gnd
              * ***************************
            : Ultrasonic sensor
              :Echo pin > Arduino pin 4
              :Trigger pin > Arduino pin 2
              * ***************************
* ******************************************************* 
 */


#include <Servo.h>

#define trig 2
#define echo 4
Servo Myservo;

void setup() {
 pinMode(trig,OUTPUT);
 pinMode(echo, INPUT);
 Serial.begin(9600);
 Myservo.attach(9);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  long t = pulseIn(echo,HIGH);

  long cm = t / 29 / 2;

  Serial.print(cm);
  Serial.println("cm");
  delay(100);

  if(cm < 20){
    delay(0);
    Myservo.write(90);
  
   }
    else{
    delay(2000);
    Myservo.write(0);
  }
  


}
