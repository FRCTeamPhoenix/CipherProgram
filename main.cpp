#include <iostream>
#include <string>

#include "cipher.h"
#include "autokey.h"
#include "cipherprogram.h"
#include "caesercipher.h"
#include "vigenere.h"
#include "foop.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    Vigenere vigenere;
    Autokey autokey;
    Foop foop;

    program.addCipher("caesar", &caesar);
    program.addCipher("vigenere", &vigenere);
    program.addCipher("autokey", &autokey);
    program.addCipher("foop", &foop);
    program.run();
    
    return 0;
}