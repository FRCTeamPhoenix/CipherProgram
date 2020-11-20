#include <iostream>
#include <string>
#include "beaufort.h"
#include "cipherprogram.h"
#include "caesercipher.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    Beaufort beaufort;

    program.addCipher("caesar", &caesar);
    program.addCipher("beaufort", &beaufort);
    program.run();
    

    return 0;
}