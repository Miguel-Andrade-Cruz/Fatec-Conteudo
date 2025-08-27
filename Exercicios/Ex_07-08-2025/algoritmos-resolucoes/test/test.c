#include <stdlib.h>

#include "../src/lib/inputer/inputer.h"
#include "../src/lib/validator/validator.h"

// Mônadas precisam de:
// 
// - Um tipo monádico
// - Wrapper
// - Runner
// 
// 
// No nosso contexto, precisamos:
// - pegar entrada de usuário, que pode ser de três tipos de dados diferentes.
// - aplicar funções de validação em cima desse input
// - passar para o







int main() {
    
    Inputer price_of_pizza = {.msg = "Qual é o preço da piza? \n", .type = T_FLOAT};
    
    Validator *less_than_100 = less_than(100);
    Validator *greater_than_50 = greater_than(50);
    Validator *checks[] = {less_than_100, greater_than_50};
    
    int lenght = sizeof(checks) / sizeof(checks[0]);
    pull(&price_of_pizza, checks, lenght);
    
    free(less_than_100);
    return 0;
}




// Example of API usage

// Inputer i_price = {.msg = "Insira o preço:", .type = IPT_TYPE.T_FLOAT};
// Validator *price_requisites = {non_negative, less_than_100};


// check(&i_price, price_requisites);
// float price = getinput(i_price);
