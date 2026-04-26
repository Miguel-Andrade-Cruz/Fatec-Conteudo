
// 3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
//     teclado na funcao main(). Faca uma funcao que calcule o numero de dias 
//     entre elas e mostre o resultado no video na funcao main(). A estrutura e' 
//     uma variavel global. 
//     Utilize vetor de estruturas.
//                 estrutura: dia, mes, ano

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