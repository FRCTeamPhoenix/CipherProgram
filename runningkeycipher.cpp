#include "runningkeycipher.h"

#include <iostream>
#include <algorithm>
#include <ctype.h>

RunningKeyCipher::RunningKeyCipher(){
    m_keyPrompt = "Enter text with no numbers. Equal to or greater than message.";
}

const char LETTER[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int getValue(char c){
    for(int i = 0; i < 26; i++){
        if(LETTER[i] == c){
            return i;
        }
    }
    return -1;
}

std::string RunningKeyCipher::encode(std::string baseText, std::string key){

}

std::string RunningKeyCipher::decode(std::string cipherText, std::string key){

}
bool RunningKeyCipher::isValidKey(std::string key){
    for (int i = 0; i < key.length(); i++){
        if (!isalpha(key[i])){
            return false;
        }
        key[i] = tolower(key[i]);
    }
    return true;
}