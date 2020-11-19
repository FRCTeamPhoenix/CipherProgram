#include "vigenere.h"
#include <iostream>
#include <string>
using namespace std;

char LETTER[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int getValue(char c){
    for(int i = 0; i < 26; i++){
        if(LETTER[i] == c){
            return i;
        }
    }
    return -1;
}

string Vigenere::encode(string baseText, string key){
    int keyIterations = baseText.length()/key.length();
    string stackedKey = "";
    for(int i = 0; i < keyIterations; i++){ // places the key above the base text, repeated as necessary
        stackedKey += key;
    }
    stackedKey += key.substr(0, baseText.length() - (key.length() * keyIterations)); // adds remainder onto stackedKey
    
    string result = "";
    for(int i = 0; i < baseText.length(); i++){
        int totalVal = getValue(stackedKey[i]) + getValue(baseText[i]);
        while(totalVal > 25){
            totalVal -= 26;
        }
        result += LETTER[totalVal];
    }
    cout << stackedKey << endl << baseText << endl;
    return result;
}
string Vigenere::decode(string cipherText, string key){
    int keyIterations = cipherText.length()/key.length();
    string stackedKey = "";
    for(int i = 0; i < keyIterations; i++){ // places the key above the base text, repeated as necessary
        stackedKey += key;
    }
    stackedKey += key.substr(0, cipherText.length() - (key.length() * keyIterations)); // adds remainder onto stackedKey
    cout << endl << stackedKey << endl << cipherText << endl;

    string result = "";
    // look under the character from stackedKey to find where it is the correct character from the input string
    // subtract value of given char by value of key char, look in 
    for(int i = 0; i < cipherText.length(); i++){
        int index = getValue(cipherText[i]) - getValue(stackedKey[i]);
        while(index < 0){
            index += 26;
        }
        result += LETTER[index];
    }
    return result;
}
bool Vigenere::isValidKey(string key){
    return true;
}
