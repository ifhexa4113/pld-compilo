#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "../parser-lib/calc.tab.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << test() << std::endl;
    std::cout << test2() << std::endl;
    int res = 0;
    yyparse(&res);
    printf("Résutlat : %d\n",res);
    return 0;
}