[![Build Status](https://travis-ci.org/jipp/eBot.svg?branch=master)](https://travis-ci.org/jipp/eBot)

# eBot library
Library for the Elegoo Smart Robot Car V2.0. It is meant to include all functions from the different Lessons delivered with the car.

## IDE
* PlatformIO IDE: store the unzipped eBot folder including content into the lib folder of the project lib -> eBot -> examples, src, ...
* Arduino IDE: import the eBot.zip using the Library import function

## Needed Libraries
* servo.h (standard Library)

## The following features are implemented - prefix new_ is used to differentiate between original and modified examples
* Lesson 1 - pure car movement
* Lesson 2 - bluetooth
* Lesson 3 - infrared -> not yet working
* Lesson 4 - ultrasonic
* Lesson 5 - line tracking -> not yet implemented

## The following features are in progress
* line tracking
* IR support

## Info
* The IRremote.h is not working as is. Modifications are needed (timer needs to be changed)
* In case the IRremote.h is changed, the servo.h will not work as timers will collide

## IRremote.h
For IRremore some modifications are needed from the original library:
* for Library version 2.3.3:
```
diff boarddefs.h boarddefs.h.orig
144,145c144,145
< 	#define IR_USE_TIMER1   // tx = pin 9
< 	//#define IR_USE_TIMER2     // tx = pin 3
---
> 	//#define IR_USE_TIMER1   // tx = pin 9
> 	#define IR_USE_TIMER2     // tx = pin 3
```
* for Library version 2.0.1:
```
diff IRremoteInt.h IRremoteInt.h.orig
206,207c206,207
< 	#define IR_USE_TIMER1   // tx = pin 9
< 	//#define IR_USE_TIMER2     // tx = pin 3
---
> 	//#define IR_USE_TIMER1   // tx = pin 9
> 	#define IR_USE_TIMER2     // tx = pin 3
```

### Used Pins
The pins are used based on the naming of the Arduino UNO
* LS1 2
*	ServoPin	3
* LS2 4
* ENA	5
* IN1	6
* IN2	7
* IN3	8
* IN4	9
* LS3 10
* ENB	11
* receiverpin	12
* Echo	A4
* Trig	A5

## Tested hardware
### Boards
* Elegoo Smart Robot Car V2.0
