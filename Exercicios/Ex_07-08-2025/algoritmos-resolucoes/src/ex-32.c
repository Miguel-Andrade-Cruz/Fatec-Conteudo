#include <stdio.h>
#include <string.h>

int binary_search_range(float *range, int size, float target) {
    int found = -1;
    int low = 0, high = size -1;
    int idx;
    
    do {
        
        idx = (low + high) / 2;
        if (target >= range[idx] && target < range[idx + 1]) {
            found = idx;
            return found;
        }
        
        else if (target < range[idx]) {
            high = idx - 1;
        } else {
            low = idx + 1;
        }
        
    } while (low <= high);
    
    // in case the target is not on the range:
    return found;
}




int main() {
    char 
        label_1[50] = "Muito abaixo do peso",
        label_2[50] = "Abaixo do peso",
        label_3[50] = "Peso normal",
        label_4[50] = "Acima do peso",
        label_5[50] = "Obsedidade I",
        label_6[50] = "Obesidade II (severa)",
        label_7[50] = "Obesidade III (mórbida)"
    ;
    char *IMC_labels[] = {
        label_1,
        label_2,
        label_3,
        label_4,
        label_5,
        label_6,
        label_7
    };
        
    float IMC_ranges[7] = {
        0.0,
        18.5,
        18.5,
        25.0,
        30,
        35,
        999.0
    };
    
    float weight, height, calculated_imc;
    printf("Qual é o seu peso? \n");
    scanf("%f", &weight);
    
    printf("Qual é a sua altura? \n");
    scanf("%f", &height);
    
    calculated_imc = weight / (height * height);
    
    int category_idx = binary_search_range(IMC_ranges, 7, calculated_imc);
    
    char category_label[50];
    strcpy(category_label, IMC_labels[category_idx]);
    
    printf("Seu IMC é de %f. Sua situação: %s \n", calculated_imc, category_label);
    return 0;
}