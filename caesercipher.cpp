#include "caesercipher.h"

#include <algorithm>

CaeserCipher::CaeserCipher(){
    //set the proper prompt
    m_keyPrompt = "Enter shift: ";
}

std::string CaeserCipher::encode(std::string baseText, std::string key){
    //by this point, assume key and text are valid

    //figure out shift
    int shift = std::stoi(key);

    std::string out = "";

    for (char c : baseText){
        out += ((c - 'a') + shift) % 26 + 'a';
    }

    return out;
}

std::string CaeserCipher::decode(std::string cipherText, std::string key){
    //by this point, assume key and text are valid

    //figure out shift
    int shift = std::stoi(key);

    std::string out = "";

    for (char c : cipherText){
        char newCharShift =  ((c - 'a') - shift) % 26;

        //ensure that the chars remain in bounds
        if(newCharShift >= 0)
            out += newCharShift + 'a';
        else
            out += newCharShift + 'z' + 1;
    }

    return out;
}

bool CaeserCipher::isValidKey(std::string key){
    //code copied from stack overflow to determine if something is a number
    return !key.empty() && std::find_if(key.begin(), key.end(), [](unsigned char c) { return !std::isdigit(c); }) == key.end();
}