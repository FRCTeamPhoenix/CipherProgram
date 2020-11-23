#include <iostream>
#include <string>
#include "beaufort.h"
#include "cipher.h"
#include "autokey.h"
#include "cipherprogram.h"
#include "caesercipher.h"
#include "vigenere.h"
#include "rehpic.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    Beaufort beaufort;
    Vigenere vigenere;
    Autokey autokey;
    Rehpic rehpic;

    program.addCipher("caesar", &caesar);
    program.addCipher("vigenere", &vigenere);
    program.addCipher("autokey", &autokey);
    program.addCipher("beaufort", &beaufort);
    program.addCipher("rehpic", &rehpic);
    program.run();
    

    return 0;
}