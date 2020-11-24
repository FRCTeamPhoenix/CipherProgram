#include "foop.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

Foop::Foop(){
    m_keyPrompt = "Please enter an integer >= 0 and < the length of the text: ";
}

string Foop::encode(string baseText, string key){
    int n = stoi(key);
    string result = baseText;
    int len = baseText.length();
    bool hasTouched[len];
    fill_n(hasTouched, len, false);
    for(int i = 0; i + n < len; i++){
        if(!hasTouched[i] && !hasTouched[i+n]){
            result[i] = baseText[i+n];
            result[i+n] = baseText[i];
            hasTouched[i] = true;
            hasTouched[i+n] = true;
        }
    }
    return result;
}

string Foop::decode(string cipherText, string key){
    return encode(cipherText, key);
}

bool Foop::isValidKey(string key){
    /*for(char c : key){
        if(!isdigit(c)){
            return false;
        }
    }
    return stoi(key) >= 0 && stoi(key) < key.length();*/
    return true;
}