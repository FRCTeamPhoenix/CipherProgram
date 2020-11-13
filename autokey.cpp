#include "autokey.h"
#include <vector>
#include <string>
#include <iostream>

Autokey::Autokey() {
    std::string currLine = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < currLine.length(); i++) {
        m_board.push_back(currLine);
        currLine = currLine.substr(1, currLine.length() - 1) + currLine[0];
    }
    /*
    for (int i = 0; i < currLine.length(); i++) {
        std::cout << m_board[i] << std::endl;
    }
    int h;
    std::cin >> h;
    */
}

int Autokey::charToInt(char c) {
    return c - 97;
}

std::string Autokey::encode(std::string baseText, std::string key) {
    std::string totalKey = key + baseText;
    std::string output = "";

    for (int i = 0; i < baseText.length(); i++) {
        output += m_board[i][charToInt(totalKey[i])];
    }

    return output;
}

std::string Autokey::decode(std::string cipherText, std::string key) {
    return "";
}

bool Autokey::isValidKey(std::string key) {
    for (int i = 0; i < key.length(); i++) {
        if (!isValidChar(key[i])) {
            return false;
        }
    }
    return true;
}

bool Autokey::isValidChar(char c) {
    if ((c >= 97) && (c <= 122)) {
        return true;
    }
    return false;
}