# TiBridge
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/tesa-klebeband/library/TiBridge.svg)](https://registry.platformio.org/libraries/tesa-klebeband/TiBridge)
![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/tesa-klebeband/TiBridge)
![GitHub License](https://img.shields.io/github/license/tesa-klebeband/TiBridge)
![GitHub Repo stars](https://img.shields.io/github/stars/tesa-klebeband/TiBridge?style=flat)
![GitHub forks](https://img.shields.io/github/forks/tesa-klebeband/TiBridge?style=flat)
TiBridge is an easy-to-use library that allows for communication between a Microcontroller like the ESP32 and TI Graphing Calculator

## Features
- Send Vars, Apps and Programs with ease to your TI calculator
- Take Screenshots
- Remotely control your calc
- Many more...

## Installation
Create a new PlatformIO project and add the following to your `platformio.ini` file (append to the existing `lib_deps` if it already exists by creating a new line with the same indentation):
```ini
lib_deps =
    https://github.com/tesa-klebeband/TiBridge
```

## Using TiBridge
Examples are provided in the `examples` folder. To use TiBridge in your project, include the library and create an instance of the `TiInterface` class. The following example demonstrates how to remotely print "Hello World!" to a connected TI calculator:
```cpp
#include <Arduino.h>
#include <TiBridge.h>

TiInterface ti(23, 22, Ti83P);

void setup() {
    ti.begin();
    ti.sendMessage("Hello World!");
}

void loop() {
}
```

## License
All files within this repo are released under the GNU GPL V3 License as per the LICENSE file stored in the root of this repo.