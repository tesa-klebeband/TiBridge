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

#ifndef TI_LINK_H
#define TI_LINK_H

#include <Arduino.h>
#include <LittleFS.h>
#include <vector>

#define TIMEOUT_RX_US 500000
#define TIMEOUT_TX_US 500000

typedef enum {
    Success,
    TimeoutRx,
    TimeoutTx,
    InvalidData,
    UnsupportedDevice,
    InvalidFile
} TiStatusCodes;

typedef struct {
    double os_ver;
    double bios_ver;
    uint8_t bat_level;
    uint8_t model;
    uint16_t lang_id;
} TiDeviceInfo;

typedef struct {
    bool pixel_data[96][64];
} TiPicture;

typedef struct {
    String name;
    uint16_t size;
    uint8_t type;
    bool archived;
} TiDirectoryEntry;

typedef struct {
    std::vector<TiDirectoryEntry> entries;
    uint16_t free_memory;
} TiDirectory;

typedef enum {
    Ti82,
    Ti83,
    Ti83P,
    Ti84P
} TiDevice;

typedef enum {
    Var = 0x06,
    CTS = 0x09,
    Data = 0x15,
    Ver = 0x2D,
    Exit = 0x36,
    Ack = 0x56,
    Err = 0x5A,
    Rdy = 0x68,
    Scr = 0x6D,
    Del = 0x88,
    EOT = 0x92,
    Req = 0xA2,
    RTS = 0xC9,
    Key = 0x87
} CommandID;

typedef enum {
    RealNumber = 0x00,
    RealList = 0x01,
    Matrix = 0x02,
    YVar = 0x03,
    StringVar = 0x04,
    Program = 0x05,
    LockedProgram = 0x06,
    Picture = 0x07,
    GDB = 0x08,
    WindowSettings1 = 0x0B,
    ComplexNumber = 0x0C,
    ComplexList = 0x0D,
    WindowSettings2 = 0x0F,
    SavedWindowSettings = 0x10,
    TableSetup = 0x11,
    Backup = 0x13,
    DelFlashApp = 0x14,
    AppVar = 0x15,
    GroupVar = 0x17,
    Directory = 0x19,
    FlashOS = 0x23,
    FlashApp = 0x24,
    IDList = 0x26,
    GetCertificate = 0x27,
    Clock = 0x29
} VariableType;

class TiInterface {
   public:
    /**
     * Constructs a new TiInterface used for communication with a TI calculator.
     * @param tip The GPIO pin connected to the tip of the link cable.
     * @param ring The GPIO pin connected to the ring of the link cable.
     * @param device The model of the calculator, as defined in TiDevice.
     */
    TiInterface(uint8_t tip, uint8_t ring, TiDevice device);

    /**
     * Initializes the interface.
     */
    void begin();

    /**
     * Returns the status of the last operation.
     * A code of 0 indicates success, while a non-zero code indicates an error as defined in TiStatusCodes.
     * @return The status code of the last operation.
     */
    uint8_t getLastStatus();

    /**
     * Returns information about the connected calculator.
     * @return A TiDeviceInfo struct containing the calculator's OS version, BIOS version, battery level, model, and language ID.
     */
    TiDeviceInfo getDeviceInfo();

    /**
     * Takes a screenshot of the calculator's screen.
     * The to be returned TiPicture object contains a 96x64 array of booleans representing the pixels on the screen.
     * @return A TiPicture object containing the screenshot.
     */
    TiPicture takeScreenshot();

    /**
     * Emulates a key press on the calculator.
     * @param scancode The scancode of the key to be pressed. TiKeys.h contains a list of key scancodes.
    */
    void sendKey(uint16_t scancode);

    /**
     * Emulates keys presses of characters in order to remotely print a message on the calculator.
     * @param message The message to be printed.
    */
    void sendMessage(String message);

    /**
     * Sends a variable of type RealNumber to the calculator.
     * @param var_name The name of the variable.
     * @param number The value of the variable.
     * @param archived Whether the variable should be archived.
    */
    void sendRealNumber(String var_name, double number, bool archived = false);

    /**
     * Sends a List to the calculator.
     * @param list_id The ID of the list.
     * @param numbers The numbers to be stored in the list.
     * @param archived Whether the list should be archived.
    */
    void sendRealList(uint8_t list_id, std::vector<double> &numbers, bool archived = false);

    /**
     * Sends a Matrix to the calculator.
     * @param matrix_id The ID of the matrix.
     * @param matrix A 2D vector of doubles containing the matrix data.
     * @param archived Whether the matrix should be archived.
    */
    void sendMatrix(uint8_t matrix_id, std::vector<std::vector<double>> &matrix, bool archived = false);

    /**
     * Sends a Y-Variable to the calculator.
     * @param yvar_id The ID of the Y-Variable.
     * @param tokens The tokens to be stored in the Y-Variable. Include TiTokens.h for a list of tokens.
    */
    void sendYVar(uint8_t yvar_id, std::vector<uint8_t> &tokens);

    /**
     * Sends a String Variable to the calculator.
     * String variables are essentially the same as Y-Variables, but cannot be evaluated.
     * @param var_name The name of the variable.
     * @param tokens The tokens to be stored in the variable. Include TiTokens.h for a list of tokens.
     * @param archived Whether the variable should be archived.
    */
    void sendStringVar(String var_name, std::vector<uint8_t> &tokens, bool archived = false);

    /**
     * Sends a picture to the calculator.
     * @param pic_id The ID of the picture.
     * @param picture A TiPicture object containing the picture data in pixel_data[][].
     * @param archived Whether the picture should be archived.
    */
    void sendPicture(uint8_t pic_id, TiPicture &picture, bool archived = false);

    /**
     * Sends a program to the calculator. This function should be used for BASIC programs. For sending raw program files, use sendProgramFile.
     * @param program_name The name of the program.
     * @param tokens The tokens to be stored in the program. Include TiTokens.h for a list of tokens.
     * @param edit_locked Whether the program should be edit-locked.
     * @param archived Whether the program should be archived.
    */
    void sendProgram(String program_name, std::vector<uint8_t> &tokens, bool edit_locked = false, bool archived = false);

    /**
     * Sends a program file to the calculator.
     * @param program_file A File object containing the program file data. The file should be in the .8xp format and opened in read mode without any errors.
     * @param archived Whether the program should be archived.
    */
    void sendProgramFile(File &program_file, bool archived = false);

    /**
     * Sends an already buffered program file to the calculator.
     * @param program_file_data A vector of bytes containing the program file data. The file should be in the .8xp format.
     * @param archived Whether the program should be archived.
    */
    void sendProgramFile(std::vector<uint8_t> &program_file_data, bool archived = false);

    /**
     * Sends a Flash Application file to the calculator. Sending buffered data is not supported.
     * @param app_file A File object containing the Flash Application file data. The file should be in the .8xu format and opened in read mode without any errors.
    */
    void sendFlashAppFile(File &app_file);

    /**
     * Send a stream of bytes to the calculator.
     * @param data A vector of bytes to be sent.
    */
    void sendBytes(std::vector<uint8_t> data);

    /**
     * Receives a stream of bytes from the calculator.
     * @param max_len The maximum number of bytes to be received. Default is INT_MAX.
     * @return A vector of bytes received from the calculator.
    */
    std::vector<uint8_t> getAvailableBytes(int max_len = INT_MAX);

    /**
     * Returns the directory of the calculator in form of a TiDirectory object.
     * Each entry in the directory contains the name, size, type, and archived status of the variable.
     * @return A TiDirectory object containing the directory entries and free memory.
    */
    TiDirectory getDirectory();

    /**
     * Checks if the calculator is ready to receive data.
     * @return True if the calculator is ready, false otherwise.
    */
    bool checkReady();

    /**
     * Deletes a variable from the calculator. Deleting Flash Apps and Vars doesn't work currently.
     * @param var_name The name of the variable to be deleted.
     * @param var_type The type of the variable to be deleted.
     * @param archived Whether the variable is archived.
    */
    void deleteVar(String var_name, VariableType var_type, bool archived = false);

   private:
    uint8_t tip, ring;
    uint8_t tx_id;
    uint8_t rx_id;
    uint8_t status;
    int timeout_rx = TIMEOUT_RX_US;
    int timeout_tx = TIMEOUT_TX_US;
    uint8_t getByte();
    void sendByte(uint8_t data);
    std::vector<uint8_t> makePacket(uint8_t cmd, std::vector<uint8_t> data = {});
    uint16_t calculateChecksum(std::vector<uint8_t> data);
    bool transmit(uint8_t cmd, std::vector<uint8_t> data = {}, int len_field = INT_MAX);
    bool getResponse(uint8_t expected_cmd, int expected_packet_len);
    std::vector<uint8_t> getDataResponse(uint8_t expected_cmd, int expected_data_len);
    std::vector<uint8_t> makeVarHeader(String var_name, VariableType var_type, uint16_t var_size, bool archived);
    std::vector<uint8_t> makeRealData(double number);
    bool transmitVar(std::vector<uint8_t> header, std::vector<uint8_t> data);
    bool transmitFlashPage(std::vector<uint8_t> header, std::vector<uint8_t> data);
    std::vector<uint8_t> makeFlashAppHeader(uint32_t data_size, uint16_t flash_page, uint16_t flash_offset);
};

#endif