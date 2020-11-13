#include<iostream>
#include<string>
#include "beaufort.h"
using namespace std;

string Beaufort::encode(string baseText, string key = "") {
    string output = "";
    string table = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<baseText.size(); i++) {
        char charText = baseText[i];
        char charKey = key[i % key.size()];
        int tempInt = 0;
        for (int j=0; j<26; j++) {

            if(table[j] == charText) {
                tempInt = j;
            }

            int shift = 0;
            for(int k=0; k<tempInt; k++) {
                int letter = k % 26;
                if (table[letter] == charKey) {
                    break;
                }
                shift++;
            }
            output += table[shift];
        }

    }
    return output;
}