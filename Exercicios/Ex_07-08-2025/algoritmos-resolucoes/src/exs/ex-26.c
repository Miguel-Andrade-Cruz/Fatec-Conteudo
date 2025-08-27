#include <stdio.h>


int main() {
    
    int num1, num2;
    
    printf("Apoi coloque um número aí meu fi:\n");
    scanf("%d", &num1);
    
    printf("Agora outro, por obséquio: \n");
    scanf("%d", &num2);
    
    if ( num1 == num2) {
        printf("Ô fio, os dois são iguais ôme, te ajeita!");
    } else if (num1 > num2) {
        printf("O primeiro que tu mandou é maior, visse?");
    } else {
        printf("Esse último aí é maior que o primeiro, oia");
    }
    
    return 0;
}