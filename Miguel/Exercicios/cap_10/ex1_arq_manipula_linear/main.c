
// 1 - Escreva um programa para criar e abrir um arquivo. Receba via
//     teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo. 
//     O caracter '0' finaliza a entrada de dados. Abra o arquivo novamente,
//     leia e imprima na tela todos os caracteres armazenados no
//     arquivo (um por vezes).



#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE

#include <stdlib.h>
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int main() {
    
    char again = 'n';
    do {
        
        FILE *fptr;
        fptr = fopen("../txts/ex1.txt", "w+");
        
        if (fptr == NULL) {
            printf("Erro ao abrir o arquivo\n");
            exit(0);
        }
        
        
        // write chars to file ------ <
        char ipt;
        printf("--->>  ");
        ipt = getchar();
        while (ipt != '0') {
            
            fputc(ipt, fptr);
            ipt = getchar();
        }
        fputc('\0', fptr);
        fseek(fptr, 0, SEEK_SET);
        // ------------ >
        
        // read chars from file ------ <
        char buff;
        buff = fgetc(fptr);
        while ( buff != '\0' ) {
            putchar(' ');
            putchar(buff);
            buff = fgetc(fptr);
        }
        // ------------ >
        fclose(fptr);
        
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