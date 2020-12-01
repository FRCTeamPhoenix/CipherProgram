#include <iostream>
#include <ctype.h>
#include <list>
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
    double n = p*q;
    double phi = (p-1)*(q-1);
    double e;
    std::cout << "enter value for e" << '\n';
    std::cin >> e;
    char cic;
    //std::list<double> enclist(baseText.length());
    std::list<double> enclist(0);
    std::list<double>::iterator it = enclist.begin(); 
    for (char c : baseText){
        double ic = (double)c;
        double enc = pow(ic,e);
        enclist.insert(it, enc);
    }

    for (std::list<double>::iterator i = enclist.begin(); i != enclist.end(); i++) 
        std::cout << *i << " "; 
return "";
}

std::string rsa::decode(std::string cipherText, std::string key){
    return "";
}

bool rsa::isValidKey(std::string key){
    return true;
}

int main(){
    rsa text;
    text.encode("asdf", "14,15");
    return 0;
}
