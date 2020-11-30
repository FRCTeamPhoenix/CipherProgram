#include <iostream>
#include <ctype.h>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include "rsa.h"

rsa::rsa(){
    m_keyPrompt = "enter values for p and q separated by a comma. e.g. 12,12:";
};

std::string rsa::encode(std::string baseText, std::string key){
    
    std::string delimiter = ",";
    std::string pparse = key.substr(0, key.find(delimiter));
    std::string qparse= key.substr(key.find(delimiter)+1, -1); 
    int p = stoi(pparse);
    int q = stoi(qparse);
    std::cout << p << " " << q << '\n';
    double n = p*q;
    double phi = (p-1)*(q-1);
    double e;
    std::cout << "enter value for e" << '\n';
    std::cin >> e;
    char cic;
    for (char c : baseText){
        double ic = (double)c;
        double enc = pow(ic,e);
        std::cout << enc << '\n';
        cic = (char)enc;
    }
    std::cout << cic << '\n';
    //double d1 = 1/e;
    //double d=fmod(d1,phi);
return "done";
}

std::string rsa::decode(std::string cipherText, std::string key){
    return "bob";
}

bool rsa::isValidKey(std::string key){
    return true;
}

int main(){
    rsa text;
    text.encode("asdlkfjaflkds", "14,15");
    return 0;
}
