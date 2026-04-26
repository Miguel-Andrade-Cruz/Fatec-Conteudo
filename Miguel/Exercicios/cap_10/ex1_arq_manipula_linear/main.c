
// 1 - Escreva um programa para criar e abrir um arquivo. Receba via
//     teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo. 
//     O caracter '0' finaliza a entrada de dados. Abra o arquivo novamente,
//     leia e imprima na tela todos os caracteres armazenados no
//     arquivo (um por vezes).

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