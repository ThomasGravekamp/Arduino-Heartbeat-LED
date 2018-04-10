#ifndef __ARDUINO_HARTBEAT_LED
#define __ARDUINO_HARTBEAT_LED

#include "Arduino.h"

// Define the default sequence here to prevent it from going out of scope.
const unsigned long _default_sequence[] = {200, 125, 200, 600};

class HeartbeatLed {
    public:
        HeartbeatLed(byte pin_number);
        HeartbeatLed(byte pin_number, unsigned long* sequence, byte sequence_length);
        void update();

    private:
        byte _pin_number;
        byte _sequence_length;
        unsigned long* _sequence;

        unsigned long _last_update;
        byte _sequence_index;
        bool _state;

        void _init(byte pin_number);
};

#endif
