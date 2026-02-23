#include <stdio.h>
#include "../lib.h"


int main() {
    
    
    int result = addition(4, 20);
    
    
    printf("ALGUMA COISA RODOU EM MAIN");
    printf("E alguma coisa aqui na lib.h tbm, isso aqui: %d", result);
    
    return 0;
}