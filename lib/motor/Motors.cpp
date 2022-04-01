#include <Motors.h>

Motors::Motors() {
    pinMode(MOTOR_F45, OUTPUT);
    pinMode(MOTOR_B45, OUTPUT);
    pinMode(MOTOR_F135, OUTPUT);
    pinMode(MOTOR_B135, OUTPUT);
    pinMode(MOTOR_F225, OUTPUT);
    pinMode(MOTOR_B225, OUTPUT);
    pinMode(MOTOR_F315, OUTPUT);
    pinMode(MOTOR_B315, OUTPUT);
}
void Motors::turn(int8_t channel, int16_t power) {
    //チャンネル選択
    switch (channel) {
    case 1:
        channelF = MOTOR_F45;
        channelB = MOTOR_B45;
        break;
    case 2:
        channelF = MOTOR_F135;
        channelB = MOTOR_B135;
        break;
    case 3:
        channelF = MOTOR_F225;
        channelB = MOTOR_B225;
        break;
    case 4:
        channelF = MOTOR_F315;
        channelB = MOTOR_B315;
        break;
    }
    //最大値設定
    power = max(power, 255);
    power = min(power, -255);
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
    p1 = round(sin((deg - 45) * 3.141592 / 180) * -1 * Speed) + spin;
    p2 = round(sin((deg - 135) * 3.141592 / 180) * -1 * Speed) + spin;
    p3 = round(sin((deg - 225) * 3.141592 / 180) * Speed) + spin;
    p4 = round(sin((deg - 315) * 3.141592 / 180) * Speed) + spin;
    run(p1, p2, p3, p4);
}

void Motors::driveVector(int16_t vecX, int16_t vecY, int16_t spin) {
    int16_t p1 = vecX * -0.7071 + vecY * -0.7071 + spin;
    int16_t p2 = vecX * 0.7071 + vecY * -0.7071 + spin;
    int16_t p3 = vecX * 0.7071 + vecY * 0.7071 + spin;
    int16_t p4 = vecX * -0.7071 + vecY * 0.7071 + spin;
    run(p1, p2, p3, p4);
}