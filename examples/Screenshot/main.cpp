/*
 * This file is part of TiBridge (https://github.com/tesa-klebeband/TiBridge).
 * Copyright (c) 2024 tesa-klebeband.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>
#include <TiBridge.h>

// Create a TiInterface object with the pins for the link cable and the calculator model
TiInterface ti(23, 22, Ti83P);

void setup() {
    Serial.begin(115200);

    // Start the interface
    ti.begin();

    // Take a screenshot of the calculator's screen
    TiPicture screen = ti.takeScreenshot();

    // Print the screenshot to the serial monitor
    for (int row = 0; row < 64; row++) {
        for (int col = 0; col < 96; col++) {
            Serial.print(screen.pixel_data[col][row] ? "█" : " ");
        }
        Serial.println();
    }
}

void loop() {
}
