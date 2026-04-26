
// 4 - Escreva um programa para o controle de mercadorias em uma dispensa
//     domestica. Para cada produto sera' armazenado um codigo numerico, nome
//     do produto e quantidade atual numa estrutura de dados. A unica estrutura
//     de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
//     os registros das mercadorias direto no arquivo. (utilize a funcao fseek quando
//     necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
//     O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
//     1 - inclui produtos
//     2 - listar todos os produtos
//     3 - pesquisar uma mercadoria pela descricao
//     4 - listar os produtos nao disponiveis.
//     5 - alterar a quantidade atual
//     6 - altera produtos
//     7 - exclui produtos
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