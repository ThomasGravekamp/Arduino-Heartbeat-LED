# Arduino Heartbeat LED library

This is a small and simple library for having an LED pulse out a heartbeat. A heartbeat can be used as visual indication that the device is still running.

This library should work on any Arduino-compatible board. Tested on an Arduino Uno clone.

## How to use

Include the header file, create an instance of the HeartbeatLed object and call the update method in the `loop()` function. The constructor of the HeartbeatLed requires the pin number to be set.

```
#include <heartbeat_led.h>

HeartbeatLed heartbeat(13);

void setup () {

}

void loop () {
    heartbeat.update();
}
```

When you want to use your own variation of heartbeat, create an unsigned long array with the on and off times. In addition to the pin number, the sequence and the sequence length should be passed to the constructor.

```
#include <heartbeat_led.h>

// 200ms off, 100ms on, 200ms off, 500ms on, repeat
unsigned long sequence[] = {200, 100, 200, 500};
HeartbeatLed heartbeat(13, sequence, 4);

void setup () {

}

void loop () {
    heartbeat.update();
}
```
