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

    // Read the directory of the calculator and print out its entries
    TiDirectory dir = ti.getDirectory();

    Serial.printf("Name     Size Type Archived\n");
    for (TiDirectoryEntry entry : dir.entries) {
        Serial.printf("%-8s %5d %2d %1d\n", entry.name.c_str(), entry.size, entry.type, entry.archived);
    }
    Serial.printf("  Free memory: %d bytes\n", dir.free_memory);
}

void loop() {
}
