
// 2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
//     ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
//     a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
//     feitos usando ponteiro.
// OBS.: As variaveis sao locais na funcao main().

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