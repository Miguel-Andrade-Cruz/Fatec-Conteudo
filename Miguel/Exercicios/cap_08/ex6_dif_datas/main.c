
// 6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
//     usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
//     usando ponteiros. Utilize um vetor de estruturas declarado como variavel 
//     global.
//     	estrutura: dia, mes e ano

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