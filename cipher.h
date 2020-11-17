#pragma once

#include <string>

class Cipher{
public:
    //returns a string of the encoded text
    virtual std::string encode(std::string baseText, std::string key = "") = 0;

    //returns a string of the decoded text
    virtual std::string decode(std::string cipherText, std::string key = "") = 0;

    //returns if give key is valid (used for frontend)
    virtual bool isValidKey(std::string key) = 0;

    std::string getKeyPrompt()  { return m_keyPrompt; }

protected:
    std::string m_keyPrompt = "Key: ";

};