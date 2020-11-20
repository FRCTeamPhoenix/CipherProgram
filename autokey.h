#pragma once
#include <string>
#include <vector>
#include "cipher.h"

class Autokey: public Cipher {
    private:
        std::vector<std::string> m_board;
        int charToInt(char c);
        char intToChar(int i);
        bool isValidChar(char c);
    public:
        Autokey();
        //returns a string of the encoded text
        virtual std::string encode(std::string baseText, std::string key = "") override;

        //returns a string of the decoded text
        virtual std::string decode(std::string cipherText, std::string key = "") override;

        //returns if give key is valid (used for frontend)
        virtual bool isValidKey(std::string key) override;
};