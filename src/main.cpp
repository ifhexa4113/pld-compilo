#include <iostream>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << test() << std::endl;
    std::cout << test2() << std::endl;
    return 0;
}