#ifndef NHCSR04
#define NHCSR04

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define MICROS_OFFSET 3198
#define SENSOR_TRIGGER_TIME 10

class SR04
{
public:
    static uint16_t microsecondsTimeoutOffset;

    SR04(byte trigger, byte echo, uint16_t maxCentimeters = 100);

    uint64_t ping();

    double centimeters(bool doPing = true);

    double inches(bool doPing = true);

    uint16_t maxCentimeters;
    float sensorFactor;
    float cmOffset;
private:
    const byte trigger, echo;
    uint64_t pulseTime;
};

#endif