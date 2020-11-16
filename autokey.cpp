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

char Autokey::intToChar(int i) {
    return (char)(i + 97);
}

std::string Autokey::encode(std::string baseText, std::string key) {
    std::string totalKey = key + baseText;
    std::string output = "";

    for (int i = 0; i < baseText.length(); i++) {
        output += m_board[charToInt(totalKey[i])][charToInt(baseText[i])];
    }

    return output;
}

std::string Autokey::decode(std::string cipherText, std::string key) {
    //https://crypto.interactive-maths.com/autokey-cipher.html
    std::string totalKey = key;
    std::string output = "";

    for (int i = 0; i < cipherText.length(); i++) {
        //output += m_board[charToInt(totalKey[i])][charToInt(cipherText[i])];
        for (int j = 0; j < m_board[i].length(); j++) {
            if (m_board[charToInt(totalKey[i])][j] == cipherText[i]) {
                output += intToChar(j);
                totalKey += intToChar(j);
                //std::cout << output << std::endl;
                break;
            }
        }
    }

    std::cout << std::endl;

    return output;
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