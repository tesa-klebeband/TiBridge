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

#include <TiBridge.h>
#include <TiKeys.h>

const uint16_t keymap[] = {
    KEY_SPACE,
    KEY_EXCLAM_DOWN,
    KEY_QUOTE,
    KEY_POUND,
    KEY_DOLLAR,
    KEY_PERCENT,
    KEY_AMPERSAND,
    KEY_QUOTE,
    KEY_L_PAREN,
    KEY_R_PAREN,
    KEY_MUL,
    KEY_ADD,
    KEY_COMMA,
    KEY_SUB,
    KEY_DEC_PNT,
    KEY_DIV,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_COLON,
    KEY_SEMICOLON,
    KEY_TLT,
    KEY_TEQ,
    KEY_TGT,
    KEY_QUEST,
    KEY_AT_SIGN,
    KEY_CAP_A,
    KEY_CAP_B,
    KEY_CAP_C,
    KEY_CAP_D,
    KEY_CAP_E,
    KEY_CAP_F,
    KEY_CAP_G,
    KEY_CAP_H,
    KEY_CAP_I,
    KEY_CAP_J,
    KEY_CAP_K,
    KEY_CAP_L,
    KEY_CAP_M,
    KEY_CAP_N,
    KEY_CAP_O,
    KEY_CAP_P,
    KEY_CAP_Q,
    KEY_CAP_R,
    KEY_CAP_S,
    KEY_CAP_T,
    KEY_CAP_U,
    KEY_CAP_V,
    KEY_CAP_W,
    KEY_CAP_X,
    KEY_CAP_Y,
    KEY_CAP_Z,
    KEY_L_BRACK,
    KEY_BACK_SLASH,
    KEY_R_BRACK,
    KEY_CAP_A_CARET,
    KEY_UNDERSCORE,
    KEY_GRAVE,
    KEY_LA,
    KEY_LB,
    KEY_LC,
    KEY_LD,
    KEY_LE,
    KEY_LF,
    KEY_LG,
    KEY_LH,
    KEY_LI,
    KEY_LJ,
    KEY_LK,
    KEY_LL,
    KEY_LM,
    KEY_LSMALLN,
    KEY_LO,
    KEY_LP,
    KEY_LQ,
    KEY_LSMALLR,
    KEY_LS,
    KEY_LT,
    KEY_LU,
    KEY_LV,
    KEY_LW,
    KEY_LX,
    KEY_LY,
    KEY_LZ,
    KEY_L_BRACE,
    KEY_VERT_SLASH,
    KEY_R_BRACE,
    KEY_TILDE};

TiInterface::TiInterface(uint8_t tip, uint8_t ring, TiDevice device) {
    this->tip = tip;
    this->ring = ring;
    switch (device) {
        case Ti82:
            tx_id = 0x02;
            rx_id = 0x82;
            break;
        case Ti83:
            tx_id = 0x03;
            rx_id = 0x83;
            break;
        case Ti83P:
        case Ti84P:
            tx_id = 0x23;
            rx_id = 0x73;
            break;
    }
}

void TiInterface::begin() {
    pinMode(tip, INPUT_PULLUP);
    pinMode(ring, INPUT_PULLUP);
}

uint8_t TiInterface::getLastStatus() {
    return status;
}

TiDeviceInfo TiInterface::getDeviceInfo() {
    TiDeviceInfo info;
    if (!transmit(Ver)) return info;
    if (!getResponse(Ack, 4)) return info;
    if (!transmit(CTS)) return info;
    if (!getResponse(Ack, 4)) return info;
    std::vector<uint8_t> data = getDataResponse(Data, 11);
    if (data.size() != 11) return info;
    if (!transmit(Ack)) return info;

    info.os_ver = data[0] + (data[1] / 100.0);
    info.bios_ver = data[2] + (data[3] / 100.0);
    info.bat_level = data[4];
    info.model = data[5];
    info.lang_id = (data[6] << 8) + data[7];

    return info;
}

TiPicture TiInterface::takeScreenshot() {
    TiPicture screen;
    if (!transmit(Scr)) return screen;
    if (!getResponse(Ack, 4)) return screen;
    std::vector<uint8_t> data = getDataResponse(Data, 768);
    if (data.size() != 768) return screen;
    if (!transmit(Ack)) return screen;

    for (int row = 0; row < 64; row++) {
        for (int col = 0; col < 12; col++) {
            for (int bit = 0; bit < 8; bit++) {
                screen.pixel_data[col * 8 + bit][row] = (data[row * 12 + col] >> (7 - bit)) & 1;
            }
        }
    }

    return screen;
}

void TiInterface::sendKey(uint16_t scancode) {
    if (!transmit(Key, {}, scancode)) return;
    if (!getResponse(Ack, 4)) return;
    getResponse(Ack, 4);
}

void TiInterface::sendMessage(String message) {
    for (char &c : message) {
        if (c >= 32 && c <= 126) {
            sendKey(keymap[c - 32]);
        } else {
            if (c == '\n') {
                sendKey(KEY_ENTER);
            } else {
                sendKey(KEY_QUEST);
            }
        }
    }
}

void TiInterface::sendRealNumber(String var_name, double number, bool archived) {
    std::vector<uint8_t> header = makeVarHeader(var_name, RealNumber, 9, archived);
    std::vector<uint8_t> data = makeRealData(number);

    transmitVar(header, data);
}

void TiInterface::sendRealList(uint8_t list_id, std::vector<double> &numbers, bool archived) {
    const char var_name[] = {0x5D, list_id, 0x00};
    std::vector<uint8_t> header = makeVarHeader(String(var_name), RealList, numbers.size() * 9 + 2, archived);
    std::vector<uint8_t> data = {(uint8_t)(numbers.size() & 0xFF), (uint8_t)(numbers.size() >> 8)};
    for (int i = 0; i < numbers.size(); i++) {
        std::vector<uint8_t> real_data = makeRealData(numbers[i]);
        data.insert(data.end(), real_data.begin(), real_data.end());
    }

    transmitVar(header, data);
}

void TiInterface::sendYVar(uint8_t yvar_id, std::vector<uint8_t> &tokens) {
    const char var_name[] = {0x5E, (char)(0x10 + yvar_id), 0x00};
    std::vector<uint8_t> header = makeVarHeader(String(var_name), YVar, tokens.size() + 2, false);
    std::vector<uint8_t> data = {(uint8_t)(tokens.size() & 0xFF), (uint8_t)(tokens.size() >> 8)};
    data.insert(data.end(), tokens.begin(), tokens.end());

    transmitVar(header, data);
}

void TiInterface::sendStringVar(String var_name, std::vector<uint8_t> &tokens, bool archived) {
    std::vector<uint8_t> header = makeVarHeader(var_name, StringVar, tokens.size() + 2, archived);
    std::vector<uint8_t> data = {(uint8_t)(tokens.size() & 0xFF), (uint8_t)(tokens.size() >> 8)};
    data.insert(data.end(), tokens.begin(), tokens.end());

    transmitVar(header, data);
}

void TiInterface::sendMatrix(uint8_t matrix_id, std::vector<std::vector<double>> &matrix, bool archived) {
    const char var_name[] = {0x5C, matrix_id, 0x00};
    std::vector<uint8_t> header = makeVarHeader(String(var_name), Matrix, matrix.size() * matrix[0].size() * 9 + 2, archived);
    std::vector<uint8_t> data = {(uint8_t)matrix[0].size(), (uint8_t)matrix.size()};
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            std::vector<uint8_t> real_data = makeRealData(matrix[i][j]);
            data.insert(data.end(), real_data.begin(), real_data.end());
        }
    }

    transmitVar(header, data);
}

void TiInterface::sendPicture(uint8_t pic_id, TiPicture &picture, bool archived) {
    const char var_name[] = {0x60, pic_id, 0x00};
    std::vector<uint8_t> header = makeVarHeader(String(var_name), Picture, 0x300 + 2, archived);
    std::vector<uint8_t> data = {0x0, 0x3};
    for (int row = 0; row < 64; row++) {
        for (int col = 0; col < 12; col++) {
            uint8_t byte = 0;
            for (int bit = 0; bit < 8; bit++) {
                byte |= picture.pixel_data[col * 8 + bit][row] << (7 - bit);
            }
            data.push_back(byte);
        }
    }
    transmitVar(header, data);
}

void TiInterface::sendProgram(String program_name, std::vector<uint8_t> &tokens, bool edit_locked, bool archived) {
    std::vector<uint8_t> header = makeVarHeader(program_name, edit_locked ? LockedProgram : Program, tokens.size() + 2, archived);
    std::vector<uint8_t> data = {(uint8_t)(tokens.size() & 0xFF), (uint8_t)(tokens.size() >> 8)};
    data.insert(data.end(), tokens.begin(), tokens.end());

    transmitVar(header, data);
}

void TiInterface::sendProgramFile(File &program_file, bool archived) {
    program_file.seek(0x48);
    uint16_t data_size = program_file.read() | (program_file.read() << 8);
    program_file.seek(0x3B);
    bool edit_locked = false;
    if (program_file.read() == 0x06) edit_locked = true;
    String program_name;
    for (int i = 0; i < 8; i++) {
        char c = program_file.read();
        if (c == 0) break;
        program_name += c;
    }
    program_file.seek(0x4A);
    std::vector<uint8_t> tokens;
    for (int i = 0; i < data_size; i++) {
        tokens.push_back(program_file.read());
    }
    sendProgram(program_name, tokens, edit_locked, archived);
}

void TiInterface::sendProgramFile(std::vector<uint8_t> &program_file_data, bool archived) {
    uint16_t data_size = program_file_data[0x48] | (program_file_data[0x49] << 8);
    bool edit_locked = false;
    if (program_file_data[0x3B] == 0x06) edit_locked = true;
    String program_name;
    for (int i = 0; i < 8; i++) {
        char c = program_file_data[0x3C + i];
        if (c == 0) break;
        program_name += c;
    }
    std::vector<uint8_t> tokens;
    for (int i = 0; i < data_size; i++) {
        tokens.push_back(program_file_data[0x4A + i]);
    }
    sendProgram(program_name, tokens, edit_locked, archived);
}

void TiInterface::sendFlashAppFile(File &app_file) {
    app_file.seek(0);
    String file_identifier;
    for (int i = 0; i < 8; i++) {
        file_identifier += (char)app_file.read();
    }
    if (file_identifier != "**TIFL**") {
        status = InvalidFile;
        return;
    }
    app_file.seek(0x30);
    if (rx_id != app_file.read()) {
        status = UnsupportedDevice;
        return;
    }
    if (app_file.read() != 0x24) {
        status = InvalidFile;
        return;
    }

    app_file.seek(0x4A);
    uint32_t data_size = app_file.read() | (app_file.read() << 8) | (app_file.read() << 16) | (app_file.read() << 24);

    uint16_t page_num = 0;
    uint16_t page_address = 0;
    std::vector<uint8_t> data;
    bool success = false;

    while (app_file.available()) {
        String line = app_file.readStringUntil(0x0D);
        if (app_file.peek() == 0x0A) app_file.read();

        if (line[0] != ':') {
            status = InvalidFile;
            return;
        }

        if (line.substring(0, 3) == ":02") {
            page_num = strtol(line.substring(11, 13).c_str(), NULL, 16);
            continue;
        } else if (line == ":00000001FF") {
            if (data.size() != 0) {
                while (data.size() < 0x80) {
                    data.push_back(0);
                }
                std::vector<uint8_t> header = makeFlashAppHeader(data.size(), page_num, page_address);
                if (!transmitFlashPage(header, data)) return;
                success = true;
                break;
            }
        }

        if (data.size() == 0) {
            page_address = strtol(line.substring(3, 7).c_str(), NULL, 16);
        }
        uint8_t num_bytes = strtol(line.substring(1, 3).c_str(), NULL, 16);
        for (int i = 0; i < num_bytes; i++) {
            data.push_back(strtol(line.substring(9 + i * 2, 11 + i * 2).c_str(), NULL, 16));
        }
        if (data.size() >= 0x80) {
            std::vector<uint8_t> header = makeFlashAppHeader(data.size(), page_num, page_address);
            if (!transmitFlashPage(header, data)) return;
            data.clear();
        }
    }
    if (success) {
        int old_timeout_rx = timeout_rx;
        int old_timeout_tx = timeout_tx;
        timeout_rx = 1000000;
        timeout_tx = 1000000;
        if (!transmit(EOT)) goto error;
        if (!getResponse(Ack, 4)) goto error;

    error:
        timeout_rx = old_timeout_rx;
        timeout_tx = old_timeout_tx;
    }
}

TiDirectory TiInterface::getDirectory() {
    TiDirectory dir;
    std::vector<uint8_t> header = {0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    if (!transmit(Req, header)) return dir;
    if (!getResponse(Ack, 4)) return dir;
    std::vector<uint8_t> data = getDataResponse(Data, 2);
    if (data.size() != 2) return dir;
    dir.free_memory = data[0] | (data[1] << 8);
    if (!transmit(Ack)) return dir;

    while (1) {
        data.clear();
        data = getDataResponse(Var, 13);
        if (data.size() != 13) break;

        TiDirectoryEntry entry;
        for (int i = 0; i < 8; i++) {
            if (data[i + 3] == 0) break;
            entry.name += (char)data[i + 3];
        }
        entry.size = data[0] | (data[1] << 8);
        entry.type = data[2];
        entry.archived = data[12] >> 7;

        if (!transmit(Ack)) break;

        dir.entries.push_back(entry);
    }
    if (status == InvalidData) status = Success;
    transmit(EOT);
    return dir;
}

bool TiInterface::checkReady() {
    if (!transmit(Rdy)) return false;
    std::vector<uint8_t> data = getAvailableBytes(4);
    if (status) return false;
    if ((data.size() != 4) || (data[0] != rx_id) || (data[1] != Ack)) {
        status = InvalidData;
        return false;
    }
    return !(data[2] & 1);
}

void TiInterface::deleteVar(String var_name, VariableType var_type, bool archived) {
    std::vector<uint8_t> header = makeVarHeader(var_name, var_type, 0, archived);
    if (!transmit(Del, header)) return;
    if (!getResponse(Ack, 4)) return;
    getResponse(Ack, 4);
}

uint8_t TiInterface::getByte() {
    uint8_t data = 0;
    status = Success;
    int time_us = 0;
    for (int i = 0; i < 8; i++) {
        time_us = 0;
        while (digitalRead(tip) & digitalRead(ring)) {
            if (time_us > timeout_rx) {
                status = TimeoutRx;
                return 0;
            }
            delayMicroseconds(1);
            time_us++;
        }
        time_us = 0;
        if (digitalRead(ring) == 0) {
            data |= 1 << i;
            pinMode(tip, OUTPUT);
            digitalWrite(tip, LOW);
            while (!digitalRead(ring)) {
                if (time_us > timeout_rx) {
                    status = TimeoutRx;
                    return 0;
                }
                delayMicroseconds(1);
                time_us++;
            }
            digitalWrite(tip, HIGH);
            pinMode(tip, INPUT_PULLUP);
        } else {
            pinMode(ring, OUTPUT);
            digitalWrite(ring, LOW);
            while (!digitalRead(tip)) {
                if (time_us > timeout_rx) {
                    status = TimeoutRx;
                    return 0;
                }
                delayMicroseconds(1);
                time_us++;
            }
            digitalWrite(ring, HIGH);
            pinMode(ring, INPUT_PULLUP);
        }
    }
    return data;
}

void TiInterface::sendByte(uint8_t data) {
    int time_us;
    status = Success;
    for (int i = 0; i < 8; i++) {
        time_us = 0;
        while (!digitalRead(tip) || !digitalRead(ring)) {
            if (time_us > timeout_tx) {
                status = TimeoutTx;
                return;
            }
            delayMicroseconds(1);
            time_us++;
        }
        time_us = 0;
        if ((data >> i) & 1) {
            pinMode(ring, OUTPUT);
            digitalWrite(ring, LOW);
            while (digitalRead(tip)) {
                if (time_us > timeout_tx) {
                    status = TimeoutTx;
                    return;
                }
                delayMicroseconds(1);
                time_us++;
            }
            pinMode(ring, INPUT_PULLUP);
            time_us = 0;
            while (!digitalRead(tip)) {
                if (time_us > timeout_tx) {
                    status = TimeoutTx;
                    return;
                }
                delayMicroseconds(1);
                time_us++;
            }
        } else {
            pinMode(tip, OUTPUT);
            digitalWrite(tip, LOW);
            while (digitalRead(ring)) {
                if (time_us > timeout_tx) {
                    status = TimeoutTx;
                    return;
                }
                delayMicroseconds(1);
                time_us++;
            }
            pinMode(tip, INPUT_PULLUP);
            time_us = 0;
            while (!digitalRead(ring)) {
                if (time_us > timeout_tx) {
                    status = TimeoutTx;
                    return;
                }
                delayMicroseconds(1);
                time_us++;
            }
        }
    }
}

void TiInterface::sendBytes(std::vector<uint8_t> data) {
    for (int i = 0; i < data.size(); i++) {
        sendByte(data[i]);
        if (status) return;
    }
}

std::vector<uint8_t> TiInterface::getAvailableBytes(int max_len) {
    std::vector<uint8_t> data;

    for (int i = 0; i < max_len; i++) {
        uint8_t b = getByte();
        if (status == TimeoutTx) return data;
        if (status == TimeoutRx) {
            status = Success;
            return data;
        }
        data.push_back(b);
    }
    return data;
}

std::vector<uint8_t> TiInterface::makePacket(uint8_t cmd, std::vector<uint8_t> data) {
    std::vector<uint8_t> packet;
    packet.push_back(tx_id);
    packet.push_back(cmd);
    uint16_t len = data.size();
    packet.push_back(len & 0xFF);
    packet.push_back(len >> 8);
    for (int i = 0; i < data.size(); i++) {
        packet.push_back(data[i]);
    }
    if (len) {
        uint16_t checksum = calculateChecksum(data);
        packet.push_back(checksum & 0xFF);
        packet.push_back(checksum >> 8);
    }
    return packet;
}

uint16_t TiInterface::calculateChecksum(std::vector<uint8_t> data) {
    uint16_t checksum = 0;
    for (int i = 0; i < data.size(); i++) {
        checksum += data[i];
    }
    return checksum;
}

bool TiInterface::transmit(uint8_t cmd, std::vector<uint8_t> data, int len_field) {
    std::vector<uint8_t> tx_data = makePacket(cmd, data);
    if (len_field != INT_MAX) {
        tx_data[2] = len_field & 0xFF;
        tx_data[3] = (len_field >> 8) & 0xFF;
    }
    sendBytes(tx_data);
    if (status) return false;
    return true;
}

bool TiInterface::getResponse(uint8_t expected_cmd, int expected_packet_len) {
    std::vector<uint8_t> data = getAvailableBytes(expected_packet_len);
    if (status) return false;
    if ((data.size() != expected_packet_len) || (data[0] != rx_id) || (data[1] != expected_cmd)) {
        status = InvalidData;
        return false;
    }
    return true;
}

std::vector<uint8_t> TiInterface::getDataResponse(uint8_t expected_cmd, int expected_data_len) {
    int expected_packet_len = expected_data_len + 4 + 2;
    std::vector<uint8_t> data = getAvailableBytes(expected_packet_len);
    std::vector<uint8_t> stripped_data;
    if (status) return stripped_data;
    if ((data.size() != expected_packet_len) || (data[0] != rx_id) || (data[1] != expected_cmd)) {
        status = InvalidData;
        return stripped_data;
    }

    for (int i = 0; i < expected_data_len; i++) {
        stripped_data.push_back(data[i + 4]);
    }

    return stripped_data;
}

std::vector<uint8_t> TiInterface::makeVarHeader(String var_name, VariableType var_type, uint16_t var_size, bool archived) {
    std::vector<uint8_t> header;
    header.push_back(var_size & 0xFF);
    header.push_back(var_size >> 8);
    header.push_back(var_type);
    for (int i = 0; i < 8; i++) {
        if (i < var_name.length()) {
            header.push_back(var_name[i]);
        } else {
            header.push_back(0);
        }
    }
    header.push_back(0);
    header.push_back(archived << 7);
    return header;
}

std::vector<uint8_t> TiInterface::makeRealData(double number) {
    std::vector<uint8_t> data;
    data.push_back((number < 0) << 7);
    if (number < 0) number = -number;
    uint8_t exponent = 0x80;

    while (number < 1) {
        number *= 10;
        exponent--;
    }
    while (number >= 10) {
        number /= 10;
        exponent++;
    }

    data.push_back(exponent);
    for (int i = 0; i < 7; i++) {
        uint8_t digit = ((int)number % 10);
        uint8_t mantissa = digit << 4;
        number -= digit;
        number *= 10;
        digit = ((int)number % 10);
        mantissa |= digit;
        number -= digit;
        number *= 10;
        data.push_back(mantissa);
    }

    return data;
}

bool TiInterface::transmitVar(std::vector<uint8_t> header, std::vector<uint8_t> data) {
    if (!transmit(RTS, header)) return false;
    if (!getResponse(Ack, 4)) return false;
    if (!getResponse(CTS, 4)) return false;
    if (!transmit(Ack)) return false;
    if (!transmit(Data, data)) return false;
    if (!getResponse(Ack, 4)) return false;
    if (!transmit(EOT)) return false;
    return true;
}

bool TiInterface::transmitFlashPage(std::vector<uint8_t> header, std::vector<uint8_t> data) {
    int old_timeout_rx = timeout_rx;
    int old_timeout_tx = timeout_tx;
    if (!transmit(Var, header)) goto error;
    if (!getResponse(Ack, 4)) goto error;
    timeout_rx = 10000000;
    timeout_tx = 10000000;
    if (!getResponse(CTS, 4)) goto error;
    if (!transmit(Ack)) goto error;
    if (!transmit(Data, data)) goto error;
    if (!getResponse(Ack, 4)) goto error;

    timeout_rx = old_timeout_rx;
    timeout_tx = old_timeout_tx;
    return true;

error:
    timeout_rx = old_timeout_rx;
    timeout_tx = old_timeout_tx;
    return false;
}

std::vector<uint8_t> TiInterface::makeFlashAppHeader(uint32_t data_size, uint16_t flash_page, uint16_t flash_offset) {
    std::vector<uint8_t> header;
    header.push_back(data_size & 0xFF);
    header.push_back((data_size >> 8) & 0xFF);
    header.push_back(FlashApp);
    header.push_back((data_size >> 16) & 0xFF);
    header.push_back((data_size >> 24) & 0xFF);
    header.push_back(0x00);
    header.push_back(flash_offset & 0xFF);
    header.push_back(flash_offset >> 8);
    header.push_back(flash_page & 0xFF);
    header.push_back(flash_page >> 8);
    return header;
}