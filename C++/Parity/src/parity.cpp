#include <iostream>

#include "config.h"

int main () {
    std::cout << "Version " << Parity_VERSION_MAJOR << "." << Parity_VERSION_MINOR << std::endl;
    std::cout << "Hello World!";
    return 0;
}