#include "HeartbeatLed.h"

void HeartbeatLed::_init (byte pin_number) {
    _pin_number = pin_number;
    pinMode(_pin_number, OUTPUT);

    _last_update = 0;
    _sequence_index = 0;
    _state = true;
};

HeartbeatLed::HeartbeatLed (byte pin_number) {
    _sequence = _default_sequence;
    _sequence_length = 4;
    _init(pin_number);
};

HeartbeatLed::HeartbeatLed (byte pin_number, unsigned long* sequence, byte sequence_length) {
    _sequence = sequence;
    _sequence_length = sequence_length;
    _init(pin_number);
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

    digitalWrite(_pin_number, _state ? HIGH : LOW);
    _state = !_state;
};
