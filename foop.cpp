#include "foop.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

Foop::Foop(){
    m_keyPrompt = "No key required";
}

string Foop::encode(string baseText, string key){
    string result = baseText;
    for(int i = 0; i < baseText.length()/2; i++){
        result[2*i] = baseText[2*i+1];
        result[2*i+1] = baseText[2*i];
    }
    return result;
}

string Foop::decode(string cipherText, string key){
    return encode(cipherText, "");
}

bool Foop::isValidKey(string key){
    return true;
}