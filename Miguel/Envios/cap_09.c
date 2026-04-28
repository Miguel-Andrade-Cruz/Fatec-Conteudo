
// EX 1 -- NO
// EX 2 -- OK
// EX 3 -- NO
// EX 4 -- NO
// EX 5 -- NO
// EX 6 -- NO

#define EX_0

#ifdef EX_1
#endif // EX_1
// -----------------------------------------------


// -----------------------------------------------
#ifdef EX_2
void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_strs(char *str1, char *str2) {
    
    printf("Digite a primeira string (máx. 10 caract) -->>  ");
    scanf("%s", str1);
    clear_buffer();
    
    printf("Digite a segunda string (máx. 10 caract) -->>  ");
    scanf("%s", str2);
    clear_buffer();
    return;
}

int strequal(char *str1, char *str2) {
    
    int i = 0;
    while ( 
        str1[i] == str2[i] &&
        str1[i] != '\0' &&
        str2[i] != '\0'
    ) {
        i++;
    }
    
    if ( (str1[i] == '\0') && (str2[i] == '\0') ) {
        return 1;
    }
    return 0;
}

int main() {
    
    char again = 'n';
    do {
        
        char str1[10];
        char str2[10];
        
        ask_for_strs(str1, str2);
        int is_equal = strequal(str1, str2);
        
        if ( is_equal ) {
            printf("As duas strings são iguais\n");
        } else {
            printf("As duas strings são diferentes\n");
        }
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_2
// -----------------------------------------------


// -----------------------------------------------
#ifdef EX_3
#endif // EX_3
// -----------------------------------------------



// -----------------------------------------------
#ifdef EX_4
#endif // EX_4
// -----------------------------------------------




// -----------------------------------------------
#ifdef EX_5
#endif // EX_5




#ifdef EX_6
#endif // EX_6



