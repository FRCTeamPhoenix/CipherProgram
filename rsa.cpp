#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include "rsa.h"
#include "cipher.h"

rsa::rsa(){
    m_keyPrompt = "enter key";
};

std::string rsa::encode(std::string baseText, std::string key){
    double p;
    double q;
    std::string message;
    std::cin >> message;
    std::vector<char> split_message;
    std::cin >> p;
    std::cin >> q;
    double n = p*q;
    double phi = (p-1)*(q-1);
    double e;
    std::cin >> e;
    if(1<e<phi) {
        
    }
    else {
        exit(0);
    } 

}

std::string rsa::decode(std::string cipherText, std::string key){

}

bool rsa::isValidKey(std::string key){
    return !key.empty() && std::find_if(key.begin(), key.end(), [](unsigned char c) { return !std::isdigit(c); }) == key.end();
}
int main(){
    return 0;
}
