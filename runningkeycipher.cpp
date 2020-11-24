#include "runningkeycipher.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>

RunningKeyCipher::RunningKeyCipher(){
    m_keyPrompt = "Enter text with no numbers. Equal to the message. (Case senseitive)";
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
    std::string result = "";
     for(int i = 0; i < baseText.length(); i++){
            int totalVal = getValue(key[i]) + getValue(baseText[i]);
            while(totalVal > 25){
                totalVal -= 26;
            }
            result += LETTER[totalVal];
        }
        //cout << stackedKey << endl << baseText << endl;
        return result;
    }


std::string RunningKeyCipher::decode(std::string cipherText, std::string key){
   std::string result = "";
         for(int i = 0; i < cipherText.length(); i++){
            int index = getValue(cipherText[i]) - getValue(key[i]);
            while(index < 0){
                index += 26;
            }
            result += LETTER[index];
        }
        return result;
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