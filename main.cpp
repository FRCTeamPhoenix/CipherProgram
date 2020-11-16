#include <iostream>
#include <string>

#include "cipher.h"
#include "autokey.h"

int main(){
    Autokey a = Autokey();
    std::cout << "Encode text: ";
    std::string encode;
    std::cin >> encode;

    std::cout << "Key: ";
    std::string key;
    std::cin >> key;

    std::cout << a.encode(encode, key) << std::endl << std::endl;

    std::cout << "Decode text: ";
    std::string decode;
    std::cin >> decode;

    std::cout << "Key: ";
    key = "";
    std::cin >> key;

    std::cout << a.decode(decode, key) << std::endl << std::endl;

    std::string h;
    std::cin >> h;
    return 0;
}