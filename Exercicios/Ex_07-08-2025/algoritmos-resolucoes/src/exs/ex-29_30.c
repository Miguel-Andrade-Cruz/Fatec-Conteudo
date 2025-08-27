#include <stdio.h>
#include <string.h>

typedef struct {
    int bigger;
    int side_a;
    int side_b;
    char type[3];
} Triangle;


int validate_triangle(int side1, int side2, int side3, Triangle *triangle) {
    int bigger;
    
    if (side1 == side2 && side2 && side3) {
        triangle->bigger = side1;
        triangle->side_a = side2;
        triangle->side_b = side3;
    }
    
    if (side1 > side2) {
        if (side1 > side3) {
            triangle->bigger = side1;
            triangle->side_a = side2;
            triangle->side_b = side3;
        } else {
            triangle->bigger = side3;
            triangle->side_a = side1;
            triangle->side_b = side2;
        }
    } else {
        if (side2 > side3) {
            triangle->bigger = side2;
            triangle->side_a = side3;
            triangle->side_b = side1;
        } else {
            triangle->bigger = side3;
            triangle->side_a = side1;
            triangle->side_b = side2;        }
    }
    
    if (triangle->bigger > (triangle->side_a + triangle->side_b)) {
        return 0;
    }
    
    if (triangle->bigger == triangle->side_a && triangle->side_a == triangle->side_b) {
        strcpy(triangle->type, "EQI");
    }
    
    if (triangle->bigger != triangle->side_a) {
        if (triangle->bigger == triangle->side_b || triangle->side_a == triangle->side_b) {
            strcpy(triangle->type, "ISO");
        } else {
            strcpy(triangle->type, "ESC");
        }
    }
    
    return 1;
}



int main() {
    int side_one, side_two, side_three;
    int bigger_side;
    
    printf("Primeiro lado:\n");
    scanf("%d", &side_one);
    
    printf("Segundo lado:\n");
    scanf("%d", &side_two);
    
    printf("Terceiro lado:\n");
    scanf("%d", &side_three);
    
    Triangle triangle;
    int valid_triangle = validate_triangle(side_one, side_two, side_three, &triangle);
    
    if (valid_triangle == 0) {
        printf("Esses tamanhos não formam um triângulo");
        return 0;
    }
    
    if (strcmp("EQI", triangle.type) == 0) {
        printf("Esse triângulo é equilátero");
    } else if (strcmp("ISO", triangle.type) == 0) {
        printf("Esse triângulo é isóceles");
    } else if (strcmp("ESC", triangle.type) == 0) {
        printf("Esse triângulo é esacleno");
    }

    return 0;
}