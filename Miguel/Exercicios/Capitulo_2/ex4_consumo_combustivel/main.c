// 4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
//    consumidos por um carro em um percurso.
//    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
//    abaixo:
//    CONSUMO (km/l) MENSAGEM
//    menor que 8    Venda o carro!
//    entre 8 e 14   Economico!
//    maior que 14   Super economico

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        int kilometers_traveled = ask_kilometers_traveled();
        int gasoline_liters = ask_gasoline_consumed();
        
        float average_consumption = calculate_consumption(kilometers_traveled, gasoline_liters);
        show_consumption(average_consumption);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}