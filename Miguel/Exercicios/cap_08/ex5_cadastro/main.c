
// 5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
//     Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
//     recebidos no video numa funcao usando ponteiros. Utilize um comando de loop. 
//     O vetor de estruturas deve ser declarado como variavel global.
//        estrutura: nome, end, cidade, estado, cep

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