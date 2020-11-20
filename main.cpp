#include <iostream>
#include <string>

#include "cipherprogram.h"
#include "caesercipher.h"
#include "vigenere.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    Vigenere vigenere;

    program.addCipher("caesar", &caesar);
    program.addCipher("vigenere", &vigenere);
    program.run();
    
    return 0;
}