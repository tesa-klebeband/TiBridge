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
#include <LittleFS.h>

// Create a TiInterface object with the pins for the link cable and the calculator model
TiInterface ti(23, 22, Ti83P);

void setup() {
    Serial.begin(115200);

    // Start the interface
    ti.begin();

    // Initialize LittleFS
    if (!LittleFS.begin()) {
        Serial.println("Failed to initialize LittleFS.");
        return;
    }

    // Open an App file
    File app_file = LittleFS.open("/App.8xk", "r");
    if (!app_file) {
        Serial.println("Failed to open App file.");
        return;
    }

    // Send the App file to the calculator
    ti.sendFlashAppFile(app_file);

    // Print status of Operation
    Serial.printf("Sent App file with status %d\n", ti.getLastStatus());

    // Close the App file
    app_file.close();
}

void loop() {
}
