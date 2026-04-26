
// 2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
//    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao 
//    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
//    A estrutura e' uma variavel global.
//    Faca um menu com uma opcao para saida do programa. 
//    estrutura: nome, end, cidade, estado, cep

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