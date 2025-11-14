#include <stdio.h>

#define ex1


// ------------------------------------------------
#ifdef ex1
int A[20];
int B[20];


int Positivos(int input) {
    
    int is_positive = input > 0;
    return is_positive;
}


void Armazena() {
    
    int numbers_qtd; 
    
    printf("Insira quants números deseja inserir: \n");
    scanf("%d", &numbers_qtd);

    while (numbers_qtd > 20 || numbers_qtd < 4) {

        printf("Número de itens não permitido, insira novamente: \n");
        scanf("%d", &numbers_qtd);
    }
    
    for (int i = 0; i < numbers_qtd; i++) {
        int holder;
        
        printf("Insira número na posição %d: \n", i);
        scanf("%d", &holder);
        while (Positivos(holder == 0)) {
            printf("Insira um número positivo. Posição %d: \n", i);
            scanf("%d", &holder);
        }
        
        A[i] = holder;
    }
    
    return;
}


void Inverte() {

    for (int i_A = 19, i_B = 0; i_B < 20; i_A--, i_B++) {
        
        B[i_B] = A[i_A];
    }
}


int main() {
    
    Armazena();
    Inverte();
    printf("Demonstração do vetor A:\n");
    for (int i = 0; i < 20; i++) {
        printf("Posição %d: %d\n", i, A[i]);
    }
    
    printf("\n");
    
    printf("Demonstração do vetor B:\n");
    for (int i = 0; i < 20; i++) {
        printf("Posição %d: %d\n", i, B[i]);
    }
    
    return 0;
}

#endif
// ------------------------------------------------


#ifdef ex2

int Pos[15];


void Armazena() {
    
    int numbers_qtd; 
    
    printf("Insira quants números deseja inserir: \n");
    scanf("%d", &numbers_qtd);

    while (numbers_qtd > 15 || numbers_qtd < 5) {

        printf("Número de itens não permitido, insira novamente: \n");
        scanf("%d", &numbers_qtd);
    }
    
    for (int i = 0; i < numbers_qtd; i++) {
        int holder;
        
        printf("Insira número na posição %d: \n", i);
        scanf("%d", &holder);
        while (Positivos(holder == 0)) {
            printf("Insira um número positivo. Posição %d: \n", i);
            scanf("%d", &holder);
        }
        
        A[i] = holder;
    }
    
    return;
}

int Positivos(int input) {
    
    int is_positive = input >= 0;
    return is_positive;
}




int main() {
    
}

#endif