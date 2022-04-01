#include <Arduino.h>
#include <setup.h>

#define TEST1
// #define TEST2
// #define TEST3
// #define TEST4
// #define TEST5
int i = 0;

void setup() {
    Serial.begin(1000000);
    Serial.println("hello world");
}

void loop() {
// 50で回転
#ifdef TEST1
    MD.run(50, 50, 50, 50);
    Serial.println("+50");
    delay(1000);
    //-50で回転
    MD.run(-50, -50, -50, -50);
    Serial.println("-50");
    delay(1000);
    MD.run(0, 0, 0, 0);
    Serial.println("Stop");
    delay(1000);
#elif defined(TEST2)
    i++;
    MD.drive(i, 100, 0);
    delay(100);
#elif defined(TEST3)
    MD.driveVector(60, 0, 0); // X60,Y00 ベクトルに動く
#elif defined(TEST4)
    MD.driveVector(0, 60, 0); // X00,Y60 ベクトルに動く
#elif defined(TEST5)
    MD.driveVector(50, 50, 0); // X50,Y50 ベクトルに動く
#endif
}