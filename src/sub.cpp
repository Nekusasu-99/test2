#include<def.h>
void IR() {
    ir1 = 0;
    ir2 = 0;
    ir3 = 0;
    ir4 = 0;
    ir5 = 0;
    ir6 = 0;
    ir7 = 0;
    ir8 = 0;
  for (int i = 0; i < 3000; i++) {
      ir1 += digitalRead(pin1);
      ir2 += digitalRead(pin2);
      ir3 += digitalRead(pin3);
      ir4 += digitalRead(pin4);//irの値を格納する変数にIRのセンサー値を足していく
      ir5 += digitalRead(pin5);
      ir6 += digitalRead(pin6);
      ir7 += digitalRead(pin7);
      ir8 += digitalRead(pin8);//irの値を格納する変数にIRのセンサー値を足していく
    }
    ball0   =  (lastball1 * 0.1 + 0.9 * (3000 - ir1))*0.9907;
    ball45  =  (lastball2 * 0.1 + 0.9 * (3000 - ir2))*0.9795;
    ball90  =  (lastball3 * 0.1 + 0.9 * (3000 - ir3))*0.9795;
    ball135 =  (lastball4 * 0.1 + 0.9 * (3000 - ir4))*0.9325;
    ball180 =  (lastball5 * 0.1 + 0.9 * (3000 - ir5))*0.9125;
    ball225 =  (lastball6 * 0.1 + 0.9 * (3000 - ir6))*0.8919;
    ball270 =  (lastball7 * 0.1 + 0.9 * (3000 - ir7))*0.9675;
    ball315 =  (lastball8 * 0.1 + 0.9 * (3000 - ir8))*0.9672;
    ball0d    = 0.00009*ball0*ball0     - 2.04969*ball0   + 488.14251;
    ball45d   = 0.00009*ball45*ball45   - 2.04969*ball45  + 488.14251;
    ball90d   = 0.00009*ball90*ball90   - 2.04969*ball90  + 488.14251;
    ball135d  = 0.00009*ball135*ball135 - 2.04969*ball135 + 488.14251;
    ball180d  = 0.00009*ball180*ball180 - 2.04969*ball180 + 488.14251;
    ball225d  = 0.00009*ball225*ball225 - 2.04969*ball225 + 488.14251;
    ball270d  = 0.00009*ball270*ball270 - 2.04969*ball270 + 488.14251;
    ball315d  = 0.00009*ball315*ball315 - 2.04969*ball315 + 488.14251;
    y = (ball0 + ball45*root2 + ball315*root2 - ball180 - ball135*root2 - ball225*root2) / 3000*(-1);
    x = (ball90+ ball45*root2 + ball135*root2 - ball270 - ball315*root2 - ball225*root2) / 3000;
    /*y = (ball0 - ball180)/3000 *(-1);
    x = (ball90 - ball270)/3000;*/
    balldir0 = round(atan2(y, x) * 180 / 3.141592653589793238462643)*(-1);
    if (balldir0 < 0) {
      balldir1 = balldir0 + 360;
    }
    if ( 0 == balldir0) {
      balldir1 = balldir0;
    } else if (0 < balldir0 && balldir0 <= 90) {
      balldir1 = 90 - balldir0;
    } else if (90 < balldir0 && balldir0 <= 180) {
      balldir1 = (balldir0 - 90) * (-1);
    } else if (-180 < balldir0  && balldir0  <= -90) {
      balldir1 =  (270 + balldir0) * (-1);
    } else if (-90 < balldir0  && balldir0  < 0) {
      balldir1 = balldir0 * (-1) + 90 ;
    } 
    lastball1 = ball0;
    lastball2 = ball45;
    lastball3 = ball90;
    lastball4 = ball135;
    lastball5 = ball180;
    lastball6 = ball225;
    lastball7 = ball270;
    lastball8 = ball315;
}
void motor() {
    motor1 = round(sin((movedir - 45)  * 3.141592 / 180 ) * -1 * Speed);
    motor2 = round(sin((movedir - 135) * 3.141592 / 180 ) * -1 * Speed);
    motor3 = round(sin((movedir - 225) * 3.141592 / 180 ) * Speed);
    motor4 = round(sin((movedir - 315) * 3.141592 / 180 ) * Speed);
    ////////////////////////////////////////////////////////////////////////
    /*linemotor1 = round(sin((linedir - 45)  * 3.141592 / 180 ) * -1 * linespeed);
    linemotor2 = round(sin((linedir - 135) * 3.141592 / 180 ) * -1 * linespeed);
    linemotor3 = round(sin((linedir - 225) * 3.141592 / 180 ) * linespeed);
    linemotor4 = round(sin((linedir - 315) * 3.141592 / 180 ) * linespeed);*/
    ////////////////////////////////////////////////////////////////////////
    /*totalpower1 =  (Power0 + motor1 + linemotor1)*0.88;
    totalpower2 =  (Power*0 + motor2 + linemotor2)*0.88;
    totalpower3 =  (-1 * Power0 + motor3 + linemotor3)*0.93;
    totalpower4 =  (-1 * Power0 + motor4 + linemotor4);*/
    totalpower1 =  (Power0 + motor1 + linemotor1)*1.05;
    totalpower2 =  (Power0 + motor2 + linemotor2);
    totalpower3 =  (-1 * Power0 + motor3 + linemotor3)*1.07;
    totalpower4 =  (-1 * Power0 + motor4 + linemotor4)*1.07;
    if (totalpower1 > 255) {
      totalpower1 = 255;
      totalpower2 = 255;
      totalpower3 = 255;
      totalpower4 = 255;
    }
     if (totalpower1 > 0) {
      motor1f = totalpower1;
      analogWrite(f45, motor1f);
      analogWrite(b45, 0);
    } else if (totalpower1 < 0) {
      motor1b = totalpower1 * -1;
      analogWrite(b45, motor1b);
      analogWrite(f45, 0);
    }
    if (totalpower2 > 0) {
      motor2f = totalpower2;
      analogWrite(f135, motor2f);
      analogWrite(b135, 0);
    } else if (totalpower2 < 0) {
      motor2b = totalpower2 * -1;
      analogWrite(b135, motor2b);
      analogWrite(f135, 0);
    }
    if (totalpower3 > 0) {
      motor3f = totalpower3;
      analogWrite(f225, motor3f);
      analogWrite(b225, 0);
    } else if (totalpower3 < 0) {
      motor3b = totalpower3 * -1;
      analogWrite(b225, motor3b);
      analogWrite(f225, 0);
    }
    if (totalpower4 > 0) {
      motor4f = totalpower4;
      analogWrite(f315, motor4f);
      analogWrite(b315, 0);
    } else if (totalpower4 < 0) {
      motor4b = totalpower4 * -1;
      analogWrite(b315, motor4b);
      analogWrite(f315, 0);
    }
}