# Arduino Heartbeat LED library

This is a small and simple library for adding a heartbead LED to your project. A heartbeat can be used as visual indication that the device is still running.

This library should work on any Arduino-compatible board. Tested on an Arduino Uno clone.

## How to use

Include the header file, create an instance of the `HeartbeatLed` object and call the update method in the `loop()` function. The constructor of the HeartbeatLed requires the pin number to be set.

```
#include <HeartbeatLed.h>

HeartbeatLed heartbeat(13);

void setup () {

}

void loop () {
    heartbeat.update();
}
```

When you want to use your own variation of heartbeat, create an unsigned long array with the on and off times. In addition to the pin number, the sequence and the sequence length should be passed to the constructor.

```
#include <HeartbeatLed.h>

// 200ms off, 100ms on, 200ms off, 500ms on, repeat
unsigned long sequence[] = {200, 100, 200, 500};
HeartbeatLed heartbeat(13, sequence, 4);

void setup () {

}

void loop () {
    heartbeat.update();
}
```

## API

### `HeartbeatLed(byte pin_number)` constructor

Initialises the `HeartbeatLed` object. The pin should be connected to an LED.

```
HeartbeatLed heartbeat_led(13);
```

| Argument | Type | Description |
| -------- | :--: | ----------- |
| pin_number | byte | The number of the pin which is connected to the LED. |

### `HeartbeatLed(byte pin_number, unsigned long* sequence, byte sequence_length)` constructor

Initialises the `HeartbeatLed` object. The pin should be connected to an LED.

Note: Make sure to define the sequence array as a global variable, in other words: outside of the setup() and loop() functions. Failing to do this results in the heartbeat not working due to the array going out of scope.

```
unsigned long sequence[] = {200, 100, 200, 500};
HeartbeatLed heartbeat_led(13, sequence, 4);
```

| Argument | Type | Description |
| -------- | :--: | ----------- |
| pin_number      | byte           | The number of the pin which is connected to the LED. |
| sequence        | unsigned long* | The array which contains the heartbeat sequence. |
| sequence_length | byte           | The length of the sequence array. |

### `.update()` method

Updates the state of the heartbeat. Should be called inside the `loop()` function.

```
heartbeat_led.update();
```
