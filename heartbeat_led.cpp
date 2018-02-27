#include "heartbeat_led.h"

void HeartbeatLed::_init (int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);

    _last_update = 0;
    _sequence_index = 0;
    _state = true;
};

HeartbeatLed::HeartbeatLed (int pin) {
    _sequence = _default_sequence;
    _sequence_length = 4;
    _init(pin);
};

HeartbeatLed::HeartbeatLed (int pin, unsigned long* sequence, byte sequence_length) {
    _sequence = sequence;
    _sequence_length = sequence_length;
    _init(pin);
};

void HeartbeatLed::update () {
    if (millis() - _last_update < _sequence[_sequence_index]) {
        return;
    }

    _sequence_index++;
    if (_sequence_index == _sequence_length) {
        _sequence_index = 0;
    }

    _last_update = millis();

    digitalWrite(_pin, _state ? HIGH : LOW);
    _state = !_state;
};
