# eBot library
Library for the Elegoo Smart Robot Car V2.0. It is meant to include all functions from the different Lessons delivered with the car.

## IDE
* PlatformIO IDE: store the unzipped eBot folder including content into the lib folder of the project lib -> eBot -> examples, src, ...
* Arduino IDE: import the eBot.zip using the Library import function

## Needed Libraries
the following library is needed by the eBot library - in case the lib is not installed the older Robot IRRemote lib will be used which will cause link problems!
* [  4  ] IRremote -> collides with wheel stearing (ongoing troubleshooting)

## The following features are implemented - prefix new_ is used to differentiate between original and modified examples
* Lesson 1 - pure car movement
* Lesson 2 - bluetooth
* Lesson 4 - ultrasonic
* Lesson 5 - line tracking

## The following features are in progress
* correction factor for straight movement
* combination of different features like used in mBot
* including more sensors
* more advanced ultrasonic usage

## Info
So far no debug function included.

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
