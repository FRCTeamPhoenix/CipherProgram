#pragma once
#include "cipher.h"
#include <string>

class Beaufort : public Cipher{
    public:

    virtual std::string encode(std::string baseText, std::string key = "") override;
    virtual std::string decode(std::string cipherText, std::string key = "") override;
    virtual bool isValidKey(std::string key) override;
    virtual void start();
}