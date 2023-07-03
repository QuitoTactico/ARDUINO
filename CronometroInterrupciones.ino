/*
 * Esteban Vergara Giraldo
 * Jonathan Betancur Espinoza
 */

#include <TimerOne.h>
float s = 0;

void up(){
  Timer1.initialize(100000);
  s = s + 0.1;
  Serial.println(s);
  Timer1.attachInterrupt(up); 
}

void pausa(){
  Timer1.detachInterrupt();
}

void down(){
  Timer1.initialize(100000);
  s = s - 0.1;
  Serial.println(s);
  Timer1.attachInterrupt(down); 
}

void reset(){
  s = 0;
  Serial.println(s);
}

void setup() {
  attachInterrupt(2,up,RISING);
  attachInterrupt(3,pausa,RISING);
  attachInterrupt(4,down,RISING);
  attachInterrupt(5,reset,RISING);
  Serial.begin(9600);
}

void loop() {
}
