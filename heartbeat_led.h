#ifndef heartbeat_led
#define heartbeat_led

#include "Arduino.h"

// Define the default sequence here to prevent it from going out of scope.
const unsigned long _default_sequence[] = {200, 125, 200, 600};

class HeartbeatLed {
    public:
        HeartbeatLed(int pin);
        HeartbeatLed(int pin, unsigned long* sequence, byte sequence_length);
        void update();

    private:
        int _pin;
        byte _sequence_length;
        unsigned long* _sequence;

        unsigned long _last_update;
        byte _sequence_index;
        boolean _state;

        void _init(int pin);
};

#endif
