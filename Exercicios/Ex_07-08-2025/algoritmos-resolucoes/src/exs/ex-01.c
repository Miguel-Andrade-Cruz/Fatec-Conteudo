#include <stdio.h>

int main() {

    // Receba via teclado um número qualquer e exiba o seu sucessor e seu antecessor

    int number_choosed;
    int antecessor;
    int sucessor;
    
    printf("Digite o número escolhido: \n");
    scanf("%d", &number_choosed);
    
    antecessor = number_choosed - 1;
    sucessor = number_choosed + 1;
    
    printf("Antecessor: %d | Sucessor: %d    ", antecessor, sucessor);
    
    return 0;
}