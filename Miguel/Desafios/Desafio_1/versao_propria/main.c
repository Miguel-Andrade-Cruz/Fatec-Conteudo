#include "actions/actions.c"


int main() {
    
    display_greetings();
    
    do {
        
        display_menu();
        
        int option = ask_action();
        call_action(option);
    } while (AGAIN == 's');
    return 0;
}
