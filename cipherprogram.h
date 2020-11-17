#pragma once

#include <unordered_map>
#include <string>

#include "cipher.h"

class CipherProgram{
public:
    void run();

    //add a pointer to a cipher class
    void addCipher(std::string cipherName, Cipher* cipherObject);
private:
    void encodeInCipher(Cipher* cipher);

    void decodeInCipher(Cipher* cipher);

    //list of all the available ciphers
    std::unordered_map<std::string, Cipher*> m_cipherList;

};