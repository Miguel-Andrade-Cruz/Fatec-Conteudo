#include <stdio.h>


int main() {
    
    float step_height, wanted_height;
    int steps;
    
    printf("Qual é o tamanho do degrau?\n");
    scanf("%f", &step_height);
    
    printf("Quanto você quer subir?\n");
    scanf("%f", &wanted_height);
    
    steps = wanted_height / step_height;
    if (wanted_height % step_height == 0) {
        steps++;
    }
    
    printf("Você precisa subir %d degraus", steps);
    
    return 0;
}