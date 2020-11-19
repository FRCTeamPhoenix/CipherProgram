#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include "cipher.h"

using namespace std;

class rsa{
    public:
        virtual void decode(string message);
        virtual void encode(string message);
    
};

void rsa::encode(string message){
    double p;
    double q;
    string message;
    cin >> message;
    vector<char> split_message;
     for (char ch : message)
    {
        // Copy only alphabetical characters and numeric digits
        if (isalnum(ch))
        {
            split_message.push_back(ch);
        }
    }

    cin >> p;
    cin >> q;
    double n = p*q;
    double phi = (p-1)*(q-1);
    double e;
    cin >> e;
    if(1<e<phi) {
        
    }
    else {
        exit(0);
    } 

}

void rsa::decode(string message){

}

int main(){
    rsa msg;


    new rsa();


    rsa::encode();
    return 0;
}
