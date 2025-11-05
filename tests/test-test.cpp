// Where is the file doing the include?

// Where is the file you want to include relative to it?

// Use ../ to go up, then folder names to go down.

#include "../Class-Project/tests/test.h"
#include "tests/test.h"
#include <iostream>

int main() {
    std::cout << "hello World";
    return 0;
}