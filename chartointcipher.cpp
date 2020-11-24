#include "chartointcipher.h"
#include <vector>
#include <string>
#include <iostream>

Chartointcipher::Chartointcipher() {
    m_keyPrompt = "No key required: ";
}

int Chartointcipher::charToInt(char c) {
    return c - 97;
}

char Chartointcipher::intToChar(int i) {
    return (char)(i + 97);
}

std::string Chartointcipher::encode(std::string baseText, std::string key) {
    std::string output = "";

    for (int i = 0; i < baseText.length(); i++) {
        //output.push_back((int)charToInt(baseText[i]));
        std::cout << (int)charToInt(baseText[i]);
    }

    return output;
}

std::string Chartointcipher::decode(std::string cipherText, std::string key) {
    std::string output = "";

    for (int i = 0; i < cipherText.length(); i++) {
        //output.push_back((char)intToChar((int)cipherText[i]));
        std::cout << intToChar((int)(cipherText[i] - '0'));
    }

    return output;
}

bool Chartointcipher::isValidKey(std::string key) {
    return true;
}