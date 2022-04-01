#include <Arduino.h>
#include <math.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_EEPROM_I2C.h>
#include <DueTimer.h>
#include <Wire.h>
#define DATA 8
#define root2  0.70710678
unsigned long balltimer;
const int f45  = 6; 
const int b45  = 10;
const int f135 = 7;
const int b135 = 8;
const int f225 = 3;
const int b225 = 4;
const int f315 = 5;
const int b315 = 2;
const int pin = 11;
int pin4 = 24;//135
int pin3 = 22;//90
int pin1 = 26;//0
int pin2 = 28;//45
int pin8 = 30;//315
int pin7 = 32;//270
int pin5 = 36;//180
int pin6 = 34;//225
double line1,line2,line3,line4;
double ball0,ball45,ball90,ball135,ball180,ball225,ball270,ball315;
double ball0d,ball45d,ball90d,ball135d,ball180d,ball225d,ball270d,ball315d;
double lastball1, lastball2, lastball3, lastball4,lastball5, lastball6, lastball7, lastball8;
double x, y, balldir0, balldir1;
int m1Power, m2Power, m3Power, m4Power, movedir,timer, last_timer, Speed, linedir, linespeed;
int totalpower1, totalpower2, totalpower3, totalpower4;
int motor1f, motor1b , motor2f , motor2b , motor3f , motor3b , motor4f , motor4b;
double motor1, motor2, motor3, motor4, linemotor1, linemotor2, linemotor3, linemotor4;
int ir1, ir2, ir3, ir4,ir5,ir6,ir7,ir8;
float P, I, D;
unsigned long lasttime;
double setdir, PIDPower, lastdir,nowdir0,nowdir,Power0;
Adafruit_BNO055 bno = Adafruit_BNO055(55);