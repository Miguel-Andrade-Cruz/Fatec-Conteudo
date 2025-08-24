#include <stdio.h>


int main() {

    int some_num;
    
    printf("Manda um número ai meu bom: \n");
    scanf("%d", &some_num);
    
    if (some_num > 0) {
        printf("Esse aí é maior que zero ein....");
    } else if (some_num < 0) {
        printf("Esse aí é MENOR que zero fio, negativasso.");
    } else {
        printf("Não fede nem cheira, zero");
    }
    
    return 0;
}