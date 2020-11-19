#include "cipher.h"
#include "vigenere.h"
#include <iostream>
#include <string>

int main(){
    Vigenere * v = new Vigenere();
    string encoded = v->encode("testingwords", "abcd");
    cout << encoded << endl;
    cout << v->decode(encoded, "abcd") << endl;
    delete v;
    return 0;
}