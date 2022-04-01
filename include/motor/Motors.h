#ifndef _MOTORS_
#define _MOTORS_

#include "Arduino.h"

#define F45 6
#define B45 10
#define F135 7
#define B135 18
#define F225 3
#define B225 4
#define F315 5
#define B315 2

class Motors {
    Motors();
    void turn(int8_t channel, int16_t power);
    void run(int16_t p1, int16_t p2, int16_t p3, int16_t p4);
    void drive(int16_t deg, int16_t Speed, int16_t spin);
    void driveVector(int16_t vecX, int16_t vecY, int16_t spin);
  private:
};
#endif
