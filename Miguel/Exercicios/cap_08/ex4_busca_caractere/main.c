
// 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
//     uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros. 
//     Imprima o resultado da pesquisa no video na funcao main(). Passe como 
//     informacao para a funcao a letra digitada. (utilize o comando return). 
//     O vetor deve ser declarado como variavel global.

//     vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE

#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

char list[] = {
    'b','d','f',
    'h','j','k',
    'm','o','q',
    's','u','w',
    'y'
};

int search_for_char( char *ipt) {
    
    int i = 0;
    while ( i < 12 ) {
        
        if ( list[i] == *ipt ) {
            return 1;
        }
        i++;
    }
    
    return 0; //
}


int main() {
    
    char again = 'n';
    do {
        
        char ipt, *pIpt;
        printf("Digite um caractere:  ");
        scanf("%c", pIpt);
        clear_buffer();
        
        int exists = search_for_char(pIpt);
        if (exists) {
            printf("Esse caractere existe na lista\n");
        } else {
            printf("Esse caractere não está presente na lista\n");
        }
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