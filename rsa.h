#pragma once
#include <vector>
#include <string>
#include "cipher.h"


class rsa : public Cipher{
    public:
    rsa();
 
    //returns a string of the encoded text
    virtual std::string encode(std::string baseText, std::string key = "") override;

    //returns a string of the decoded text
    virtual std::string decode(std::string cipherText, std::string key = "") override;

    //returns if give key is valid (used for frontend)
    virtual bool isValidKey(std::string key);
};
