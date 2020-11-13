#pragma once

#include <unordered_map>
#include <string>

#include "cipher.h"

class CipherProgram{
public:
    void Run();

private:
    void encodeInCipher(std::string cipher);

    //list of all the available ciphers
    std::unordered_map<std::string, Cipher*> m_cipherList;

};