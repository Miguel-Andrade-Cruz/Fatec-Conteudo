
// 5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
//     de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
//     sequencialmente pelo teclado numa funcao e imprima todos os registros no
//     video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
//     Coloque no menu a opcao de sair tambem. Utilize o comando switch.
//     (vetor de estruturas)
//      estutura: nome, end, cidade, estado, cep

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