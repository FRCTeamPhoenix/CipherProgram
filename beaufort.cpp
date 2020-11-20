#include<iostream>
#include<string>
#include "beaufort.h"
using namespace std;

Beaufort::Beaufort() {
    m_keyPrompt = "Enter Key(all lowercase letters): ";
}

string Beaufort::encode(string baseText, string key) {
    string output;
    string table = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<baseText.size(); i++) {
        char charText = baseText[i];
        char charKey = key[i % key.size()];
        int tempInt = 0;
        for (int j=0; j<26; j++) {

            if(table[j] == charText) {
                tempInt = j;
                break;
            }
        }
        int shift = 0;
        for(int k=tempInt; k<tempInt+26; k++) {
                int letter = k % 26;
                if (table[letter] == charKey) {
                    break;
                }
                shift++;
        }
         output += table[shift];

    }
    cout << output << endl;
    return output;
}

string Beaufort::decode(string cipherText, string key) {
    string output;
    string table = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<cipherText.size(); i++) {
        char charText = cipherText[i];
        char charKey = key[i % key.size()];
        int tempInt = 0;
        for (int j=0; j<26; j++) {

            if(table[j] == charText) {
                tempInt = j;
                break;
            }
        }
        int shift = 0;
            for(int k=tempInt; k<tempInt+26; k++) {
                int letter = k % 26;
                if (table[letter] == charKey) {
                    break;
                }
                shift++;
            }
            output += table[shift];

    }
    cout << output << endl;
    return output;
}

bool Beaufort::isValidKey(string key) {
    for (int i = 0; i<key.length(); i++) {
            if (isdigit(key[i]) == false) {
                if(key.length()>3)
                    return true;
                else
                    return false;
            }
            else
                return false;
    }
    
    return false;
}

void Beaufort::start() {
    while(true) {
        string method = "";
        string key = "";
        cout << "Encode, Decode, or Quit" << endl;

        while(method != "encode" && method != "decode" && method != "quit") {
            if(method != "")
            cout << "You need to type either 'Encode', 'Decode' or 'Quit'." << endl;  
            else
            getline(cin, method);
        }

        if(method == "quit") {
            return;
        }
        
        if(method == "encode") {
            string baseText;
            cout << "Give word you want to encode: " << endl;
            getline(cin, baseText);
            cout << "Give a key: " << endl;
            getline(cin, key);
            while(isValidKey(key) == false) {
                cout << "Give a valid key. It needs to be a word over 3 letters " << endl;
                getline(cin, key);
            }


            encode(baseText, key);
        }

        if(method == "decode") {
            string cipherText;
            cout << "Give word you want to decode: " << endl;
            getline(cin, cipherText);
            cout << "Give a key: " << endl;
            getline(cin, key);
            while(isValidKey(key) == false) {
                cout << "Give a valid key. It needs to be a word over 3 letters " << endl;
                getline(cin, key);
            }


            decode(cipherText, key);
        }
    }
}