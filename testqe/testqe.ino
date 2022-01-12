/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/



#include "Keyboard.h"
// the setup routine runs once when you press reset:
int qs_status=0,es_status=0;
int qs_temp=0,es_temp=0;
int qs=45,es=43;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(qs,INPUT_PULLUP);
  pinMode(es,INPUT_PULLUP);
  Keyboard.releaseAll();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  //int sensorValue = analogRead(A0);
  //tn = digitalRead(45);
  qs_temp = analogRead(qs);
  es_temp = analogRead(es);
  //int ss = analogRead(45);
  //loge(es_temp);
 Serial.println(90000+es_temp);
  Serial.println(80000+qs_temp);
  //logq(qs_temp);
  //log(qs);
 //Serial.println(ss);
  // print out the value you read:
 //Serial.println(tn);
         // delay in between reads for stability
  //Serial.println("start");
  if (qs_temp<100&&qs_status==0){
  Serial.println("QKeyPress");
  Keyboard.press(KEY_Q);
  qs_status=1;
}
  else if (qs_status==1&&qs_temp>100){
    Serial.println("QKeyUP");
    Keyboard.release(KEY_Q);
    qs_status=0;
  }
   if(es_status==0&&es_temp<100){
   Serial.println("EKeyPress");
   Keyboard.press(KEY_E);
   es_status=1;
   }
   else if(es_status==1&&es_temp>100){
   Serial.println("EKeyUP");
   Keyboard.release(KEY_E);
   es_status=0;
  }
   delay(19);
   return;
}
