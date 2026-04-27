
// 2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
//     ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
//     a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
//     feitos usando ponteiro.
// OBS.: As variaveis sao locais na funcao main().


#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE

#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int main() {
    
    char again = 'n';
    do {
        
        int num, *pNum = &num;
        int count = 0, *pCount = &count;
        int sum = 0, *pSum = &sum;
        
        printf("-->>  ");
        scanf("%d", pNum);
        clear_buffer();
        
        int done = 0;
        while (*pNum >= 0) {
            
            *pSum += *pNum;
            *pCount = *pCount + 1;
            
            printf("-->>  ");
            scanf("%d", pNum);
            clear_buffer();
        }
        
        float median, *pMedian = &median;
        
        *pMedian = (float) *pSum / *pCount;
        printf("A média dos valores é igual a %f\n", *pMedian);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE



#ifdef OUTER_MODE

int main() {
    
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE