#include<iostream>
#include<string>
#include "rehpic.h"
using namespace std;

Rehpic::Rehpic() {
    m_keyPrompt = "No key needed. Press enter.";
}

string Rehpic::encode(string baseText, string key) {
    string output;
    int n = baseText.length();

    for(int i=0; i < n/2; i++) {
        swap(baseText[i], baseText[n-i-1]);
    }
    output = baseText;

    return output;
}

string Rehpic::decode(string cipherText, string key) {
    return encode(cipherText, "");
}

bool Rehpic::isValidKey(string key) {
    return true;
}