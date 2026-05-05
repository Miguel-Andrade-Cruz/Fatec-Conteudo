
#define EX_0

#ifdef EX_1

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
#endif // EX_1
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_2
#endif // EX_2
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_3
#endif // EX_3
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_4
#endif // EX_4
// ------------------------------------------------