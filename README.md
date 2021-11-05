
[![Arduino CI](https://github.com/RobTillaart/IEEE754tools/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/IEEE754tools/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/IEEE754tools/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/IEEE754tools/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/IEEE754tools/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/IEEE754tools/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/IEEE754tools.svg?maxAge=3600)](https://github.com/RobTillaart/IEEE754tools/releases)


# IEEE754tools

Arduino library to manipulate IEEE754 float numbers fast.


## Description

IEEE754tools.h contains a collection of bit-hacks to speed up a number of operations
 on floating point numbers on the Arduino. 
These bit-hacks started in 2010 (oldest code found), maybe even earlier.

http://en.wikipedia.org/wiki/Double_precision

http://en.wikipedia.org/wiki/Single-precision_floating-point_format


## WARNING

- If you don't need micro-second speed ups **do not use** these code snippets.
- code is experimental, so use with care - after testing 


## Test results examples 

updated for 0.2.2

| example      |  UNO   |  ESP32  |
|:-------------|:------:|:-------:|
| fastnegate   |   Y    |    Y    |
| float2Double |   Y    |    N    | 


## Future

- test with double
- test on ESP23
- investigate other speed ups
- write more examples
- example binary transfer over Serial
- example binary transfer over Ethernet
- 


## Operations

See examples

