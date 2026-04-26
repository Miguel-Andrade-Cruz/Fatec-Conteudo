
// 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
//     uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros. 
//     Imprima o resultado da pesquisa no video na funcao main(). Passe como 
//     informacao para a funcao a letra digitada. (utilize o comando return). 
//     O vetor deve ser declarado como variavel global.

//     vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

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