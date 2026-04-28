
// 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
//     uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
//     Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
//     para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa 
//     usando ponteiros.(utilize o comando return). 
//     O vetor deve ser declarado como variavel LOCAL na funcao main().

//     vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y


#define INNER_MODE
// #define OUTER_MODE


#ifdef INNER_MODE

void clear_buffer() {
    
    while ( getchar() != '\n' );
    return;
}



int search_for_char(char *ipt, char *list) {
    
    int i = 0;
    while ( i <= 10 ) {
        
        if ( *ipt == list[i] ) {
            return 1;
        }
        i++;
    }
    return 0;
}



int main() {
    
    char again = 'n';
    do {
        
        char list[10];
        char ipt, *pIpt;
        
        printf("Insira um caractere: ");
        scanf("%c", pIpt);
        clear_buffer();
        
        int found = search_for_char(pIpt, list);
        
        if (found) {
            printf("Essa letra existe na lista\n");
        } else {
            printf("Essa letra não está na lista\n");
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