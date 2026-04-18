#include "helps.c"



int main() {
    
    
    char again = 'n';
    do {
        
        
        
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente?  ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
