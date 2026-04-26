
// 3 - Escreva um programa que receba n valores via teclado e receba tambem a
//     operacao a ser executada. Quando for digitado "=" o programa deve mostrar
//     o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
//     de dados devem ser funcoes que recebe os valores usando ponteiros.  
//     As variaveis sao LOCAIS na funcao main().

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