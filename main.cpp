#include <iostream>
#include <string>

#include "cipher.h"
#include "autokey.h"

int main(){
    Autokey a = Autokey();
    std::cout << "Encode text: ";
    std::string encode;
    std::cin >> encode;

    std::string key;
    while(true) {
        std::cout << "Key: ";
        std::cin >> key;

        if (a.isValidKey(key)) {
            break;
        }
        std::cout << "Key is broken" << std::endl;
    }

    std::cout << a.encode(encode, key) << std::endl << std::endl;

    std::cout << "Decode text: ";
    std::string decode;
    std::cin >> decode;

    key = "";
    while(true) {
        std::cout << "Key: ";
        std::cin >> key;

        if (a.isValidKey(key)) {
            break;
        }
        std::cout << "Key is broken" << std::endl;
    }

    std::cout << a.decode(decode, key) << std::endl << std::endl;

    std::string h;
    std::cin >> h;
    return 0;
}