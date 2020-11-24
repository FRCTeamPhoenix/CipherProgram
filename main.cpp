#include <iostream>
#include <string>

#include "cipherprogram.h"
#include "caesercipher.h"
#include "runningkeycipher.h"

int main(){
    CipherProgram program;
    CaeserCipher caesar;
    RunningKeyCipher running;

    program.addCipher("caesar", &caesar);
    program.addCipher("running", &running);
    program.run();
    
    return 0;
}