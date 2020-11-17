#include "cipherprogram.h"

#include <iostream>

using namespace std;

void CipherProgram::run(){
    //execute until the user types quit
    while(true){
        cout << "Would you like to 'decode', 'encode', or 'quit'?" << endl;
        string targetMethod = "";
        //get the method the user would like to do
        while(targetMethod != "decode" && targetMethod != "encode" && targetMethod != "quit"){
            if(targetMethod != "")
                cout <<"You must type 'decode', 'encode', or 'quit'"<<endl;

            getline(cin, targetMethod);
        }

        if(targetMethod == "quit") return;

        //start by printing all the ciphers possible
        cout << "Select one of the following ciphers: " << endl;

        //iterate through the hash map and print the key of each entry
        for(auto it = m_cipherList.begin(); it != m_cipherList.end(); it++){
            cout << it->first << endl;
        }

        string targetCipher = "";
        while(m_cipherList.find(targetCipher) == m_cipherList.end()){
            if(targetCipher != "")
                cout << "Cipher not in list, please try again" << endl;

            getline(cin, targetCipher);
            //continue getting input until the cipher is found in the hashmap
        }

        //encode or decode in target method
        if(targetMethod == "encode"){
            encodeInCipher(m_cipherList.find(targetCipher)->second);
        }else{
            decodeInCipher(m_cipherList.find(targetCipher)->second);
        }
    }
}

void CipherProgram::addCipher(std::string name, Cipher* cipher){
    //check if cipher hasn't been added
    if(m_cipherList.find(name) != m_cipherList.end()) throw "Cipher: " + name + " already exists"; 

    //add it to the list
    m_cipherList.insert(std::make_pair(name, cipher));
}

void CipherProgram::encodeInCipher(Cipher* cipher){
    cout << "Text to encode: ";
    string targetText = "";
    getline(cin, targetText);

    string key = "";
    //keep asking for key until the user types a valid one
    do{
        cout << cipher->getKeyPrompt();
        getline(cin, key);
    }while((!cipher->isValidKey(key)));

    //process the input string to be all lowercase, no spaces, letters only
    string processedString = "";
    for(int i = 0; i < targetText.length(); i++){
        //must be lowercase
        char lowered = tolower(targetText[i]);
        //must be alphabetical
        if(lowered >= 'a' && lowered <= 'z'){
            processedString+=lowered;
        }
    }

    cout << "Encoded result: " << cipher->encode(processedString, key) << endl;
}

void CipherProgram::decodeInCipher(Cipher* cipher){
    cout << "Text to decode: ";
    string targetText = "";
    getline(cin, targetText);

    string key = "";
    //keep asking for key until the user types a valid one
    do{
        cout << cipher->getKeyPrompt();
        getline(cin, key);
    }while((!cipher->isValidKey(key)));

    //actually decode now
    cout << "Decoded result: " << cipher->decode(targetText, key) << endl;
}
