
// 4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
//     estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
//     A estrutura e' uma variavel global.
//     Faca um menu com as seguintes opcoes:
//     1 - receber todos os dados
//     2 - imprime todos os dados 
//     3 - calcula o IMC de todas as pessoas. 
//     4 - sair
//         Calculo do IMC = peso/(altura*altura).
//         estrutura: nome, peso, altura

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