
// 3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
//     funcao para compara-las usando ponteiros e retorne como resultado se 
//     sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main(). 
//     Imprima o resultado na funcao main(). Declare os vetores como variavel global

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