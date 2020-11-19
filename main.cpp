#include <iostream>
#include <string>

#include "cipher.h"
#include "autokey.h"
#include "cipherprogram.h"
#include "caesercipher.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    Autokey autokey;

    program.addCipher("caesar", &caesar);
    program.addCipher("autokey", &autokey);
    program.run();
    
    return 0;
}