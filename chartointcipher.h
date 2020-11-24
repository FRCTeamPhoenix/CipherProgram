#pragma once
#include <string>
#include "cipher.h"

class Chartointcipher: public Cipher {
    private:
        int charToInt(char c);
        char intToChar(int i);
    public:
        Chartointcipher();
        //returns a string of the encoded text
        virtual std::string encode(std::string baseText, std::string key = "") override;

        //returns a string of the decoded text
        virtual std::string decode(std::string cipherText, std::string key = "") override;

        //returns if give key is valid (used for frontend)
        virtual bool isValidKey(std::string key) override;
};