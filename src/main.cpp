#include <stdio.h>
#include <def.h>
void IR();
void motor();
void setup() {
Serial.begin(9600);
pinMode(pin4, INPUT);
pinMode(pin3, INPUT);
pinMode(pin2, INPUT);
pinMode(pin1, INPUT);
pinMode(pin5, INPUT);
pinMode(pin6, INPUT);
pinMode(pin7, INPUT);
pinMode(pin8, INPUT);
pinMode(line1,INPUT);
pinMode(line2,INPUT);
pinMode(line3,INPUT);
pinMode(line4,INPUT);
pinMode( pin, INPUT_PULLUP );
pinMode(f45,OUTPUT);
pinMode(b45,OUTPUT);
pinMode(f135,OUTPUT);
pinMode(b135,OUTPUT);
pinMode(f225,OUTPUT);
pinMode(b225,OUTPUT);
pinMode(f315,OUTPUT);
pinMode(b315,OUTPUT);
 if(!bno.begin())
  {
    Serial.print("I2C is broken");
    while(1);
  }
  bno.setExtCrystalUse(true); 
}

void loop() {
int value;
value = digitalRead( pin );
if ( value == 1) {
sensors_event_t event; 
bno.getEvent(&event);
   if (event.orientation.x > 180){
  nowdir = event.orientation.x - 360;
} else {
  nowdir = event.orientation.x;
}
      static float last_dir = 0;
      float P = 2.3 * nowdir;                       
      unsigned long nowtime = millis();
      float dt = ((float)(nowtime - lasttime));
      float diff = (nowdir - last_dir) / dt;    
      float D =  0.125*diff * 4300;
      Power0 = P + D; 
      lasttime = nowtime;
      last_dir = nowdir;
    if (Power0 > 120 ) {
      Power0 = 120;
    } else if (Power0 < -120) {
      Power0 = -120;
    }
    if (-1 < nowdir && nowdir < 1) {
      Power0 = 0;
    }
  IR();
    ////////////////////////////////////////////////////////////////////////
   /* line1 = analogRead(A0);//back
    line2 = analogRead(A2);//left
    line3 = analogRead(A4);//right
    line4 = analogRead(A6);//front
 if (balldir1 > -7 && balldir1 < 7){
    Speed = 90;
    movedir = 0;
}else if (line1 > 40){
      linedir = 0;
      linespeed = 90;
      } else  {
      linedir = 180;
      linespeed = 90;
      } 
      if (line4 > 50){
        linedir = 0;
        linespeed = 90;
      } else if ( line3  > 961){
        linedir = 45; 
        linespeed = 90;
      } else if (line2 > 30){
        linedir = 315;
        linespeed = 90;
      }
    if( ball0 == 0 && ball90 == 0 && ball180 == 0 && ball270 ==  0){
      movedir = 180;
      Speed = 100;
    } else if ( balldir1 > 160){
      movedir = balldir1 - 30;
      Speed = 100;
    } else if ( balldir1 < -160){
      movedir = balldir1 + 30;
      Speed = 100;
    } else 
       if (balldir1 > 0){
      movedir = 100;
      Speed = 100;
    } else if (balldir1 < 0){
      movedir = -100;
      Speed = 100;
    }*/
    /*if ( line3  > 960){
        movedir = 270; 
      } else if (line2 > 23){
        movedir = 90;
      } else if (line4 > 48){
        movedir = 180; 
      } else if (line1 > 30){
       movedir = 0;
      } else*/
      /*if (balldir1 > 130){
      movedir = balldir1 - 40;
    } else if  (balldir1 < -130){
      movedir = balldir1 + 40;
    } else {}
    if (ball0||ball45||ball90||ball135||ball180||ball225||ball270||ball315 < 1750){
      Speed = 130;
      movedir = balldir1;
    } else{*/
    movedir = 0;
    Speed = 100;
    //}
    //////////////////////////////////////////////////////////////////////
    motor();   
    /*Serial.print(line1);
    Serial.print("/");
    Serial.print(line2);
    Serial.print("/");
    Serial.print(line3);
    Serial.print("/");
    Serial.println(line4);*/
    Serial.println(balldir1);
 } else {
  Serial.println("nowstop");
  analogWrite(6, 0);
  analogWrite(7, 0);
  analogWrite(8, 0);
  analogWrite(9, 0);
  
  analogWrite(10, 0);
  analogWrite(11, 0);
  analogWrite(12, 0);
  analogWrite(13, 0);
 }
}