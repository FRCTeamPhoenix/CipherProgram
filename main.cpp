#include <iostream>
#include <string>

#include "cipherprogram.h"
#include "caesercipher.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;

    program.addCipher("caesar", &caesar);
    program.run();
    
    return 0;
}