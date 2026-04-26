
// 2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
//     armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
//     dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
//     funcao main(). Utilize ponteiros para passar o vetor de estrutura para
//     as funcoes. Sempre que o programa for encerrado, os contatos devem ser
//     escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
//     do arquivo.
//     O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
//     1 - inserir contato
//     2 - listar todos os contatos
//     3 - pesquisar um contato pelo nome completo
//     4 - listar os contatos cujo nome inicia com uma letra digitada
//     5 - imprimir os aniversariantes do m s.
//     6 - altera contato pesquisando pelo nome completo
//     7 - exclui contato pesquisando pelo nome completo
//     8 - saida

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