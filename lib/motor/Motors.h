#ifndef _MOTORS_
#define _MOTORS_

#include "Arduino.h"

#define MOTOR_F45 6
#define MOTOR_B45 10
#define MOTOR_F135 7
#define MOTOR_B135 18
#define MOTOR_F225 3
#define MOTOR_B225 4
#define MOTOR_F315 5
#define MOTOR_B315 2

class Motors {
  public:
    Motors();
    void turn(int8_t channel, int16_t power);
    void run(int16_t p1, int16_t p2, int16_t p3, int16_t p4);
    void drive(int16_t deg, int16_t Speed, int16_t spin);
    void driveVector(int16_t vecX, int16_t vecY, int16_t spin);

  private:
    uint8_t channelF;
    uint8_t channelB;
};
#endif
