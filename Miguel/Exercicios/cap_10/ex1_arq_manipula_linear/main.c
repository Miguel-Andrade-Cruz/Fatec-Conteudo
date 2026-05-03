
// 1 - Escreva um programa para criar e abrir um arquivo. Receba via
//     teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo. 
//     O caracter '0' finaliza a entrada de dados. Abra o arquivo novamente,
//     leia e imprima na tela todos os caracteres armazenados no
//     arquivo (um por vezes).


#include <stdio.h>




int main() {
    
    char again = 'n';
    do {
        
        FILE *fptr;
        fptr = fopen("caracteres.txt", "rw");
        
        if (fptr == NULL) {
            printf("Erro ao abrir o arquivo\n");
            exit(0);
        }
        
        char ipt;
        printf("--->>  ");
        getchar();
        while (ipt != '0') {
            
            fputc(ipt, fptr);
            printf("--->>  ");
            getchar(ipt, fptr);
        }
        fputc('\0', fptr);
        
        
        fseek(fptr, 0, SEEK_SET);
        
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}