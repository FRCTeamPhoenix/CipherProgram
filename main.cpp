#include <iostream>
#include <string>

#include "cipherprogram.h"
#include "rsa.h"

int main(){
    CipherProgram program;
    rsa rsa;

    program.addCipher("rsa", &rsa);
    program.run();
    
    return 0;
}