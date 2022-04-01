#include <Motors.h>

Motors::Motors() {
    pinMode(F45, OUTPUT);
    pinMode(B45, OUTPUT);
    pinMode(F135, OUTPUT);
    pinMode(B135, OUTPUT);
    pinMode(F225, OUTPUT);
    pinMode(B225, OUTPUT);
    pinMode(F315, OUTPUT);
    pinMode(B315, OUTPUT);
}
void Motors::turn(int8_t channel, int16_t power) {
    //チャンネル選択
    switch (channel) {
    case 1:
        channelMOTOR_F = MOTOR_F45;
        channelMOTOR_B = MOTOR_B45;
        break;
    case 2:
        channelMOTOR_F = MOTOR_F135;
        channelMOTOR_B = MOTOR_B135;
        break;
    case 3:
        channelMOTOR_F = MOTOR_F255;
        channelMOTOR_B = MOTOR_B255;
        break;
    case 4:
        channelMOTOR_F = MOTOR_F315;
        channelMOTOR_B = MOTOR_B315;
        break;
    }
    //最大値設定
    constrain(power, -255, 255);
    if (power > 0) {
        analogWrite(channelF, abs(power));
        analogWrite(channelB, 0);
    } else {
        analogWrite(channelF, 0);
        analogWrite(channelB, abs(power));
    }
}

void Motors::run(int16_t p1, int16_t p2, int16_t p3, int16_t p4) {
    turn(1, p1);
    turn(2, p2);
    turn(3, p3);
    turn(4, p4);
}

void Motors::drive(int16_t deg, int16_t Speed, int16_t spin) {
    int16_t p1, p2, p3, p4;
    p1 = round(sin((movedir - 45) * 3.141592 / 180) * -1 * Speed) + spin;
    p2 = round(sin((movedir - 135) * 3.141592 / 180) * -1 * Speed) + spin;
    p3 = round(sin((movedir - 225) * 3.141592 / 180) * Speed) + spin;
    p4 = round(sin((movedir - 315) * 3.141592 / 180) * Speed) + spin;
    run(p1, p2, p3, p4);
}

void Motors::driveVector(int16_t vecX, int16_t vecY, int16_t spin) {
    int16_t p1 = vecX * -0.7071 + vecY * -0.7071 + spin;
    int16_t p2 = vecX * 0.7071 + vecY * -0.7071 + spin;
    int16_t p3 = vecX * 0.7071 + vecY * 0.7071 + spin;
    int16_t p4 = vecX * -0.7071 + vecY * 0.7071 + spin;
    run(p1, p2, p3, p4);
}