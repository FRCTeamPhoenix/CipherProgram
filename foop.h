#pragma once

#include "cipher.h"
using namespace std;

class Foop : public Cipher{
public:
    Foop();

    //returns a string of the encoded text
    virtual string encode(string baseText, string key = "") override;

    //returns a string of the decoded text
    virtual string decode(string cipherText, string key = "") override;

    //returns if give key is valid (used for frontend)
    virtual bool isValidKey(string key) override;
};