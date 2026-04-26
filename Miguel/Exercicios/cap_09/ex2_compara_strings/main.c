
// 2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
//     passando como parametro ponteiros.
//     Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
//     Escreva uma funcao para comparar as 2 strings. Passe como parametros para 
//     a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1 
//     ou se DIFERENTES 0. Mostre o resultado no video na funcao main().

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