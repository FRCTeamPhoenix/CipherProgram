#include "cipher.h"
#include "vigenere.h"
#include <iostream>
#include <string>

int main(){
    Vigenere * v = new Vigenere();
    cout << v->encode("testingwords", "abc") << endl;
    // cout << v->decode("tfutjpgxqreu", "abc") << endl;
    delete v;
    return 0;
}