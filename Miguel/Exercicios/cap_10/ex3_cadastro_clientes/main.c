
// 3 - Escreva um programa para controlar de um cadastro de clientes. Para cada
//     registro sera' armazenado nome, email e celular numa estrutura de dados. 
//     A unica estrutura de dados e' uma variavel LOCAL na funcao main().
//     Escreva os registros direto no arquivo. (utilize a funcao fseek quando
//     necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
//     passar parametros para as funcoes.
//     O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
//     1 - inclui registros
//     2 - listar todos os registros
//     3 - pesquisar registro pelo nome
//     4 - altera registro
//     5 - exclui registro
//     6 - saida

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