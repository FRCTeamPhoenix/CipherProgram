#include "cipher.h"
#include "vigenere.h"
#include <iostream>
#include <string>

int main(){
    Vigenere * v = new Vigenere();
    string encoded = v->encode("testingwords", "ab cd");
    cout << encoded << endl;
    cout << v->decode("foop", "ab2cd") << endl;
    delete v;
    return 0;
}