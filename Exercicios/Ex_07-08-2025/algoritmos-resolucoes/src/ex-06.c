#include <stdio.h>

float value_by_percentage(float reference_value, float percentage) {
    
    float correspondent_value = reference_value * percentage;

    return correspondent_value;
}


int main() {
    
    // O custo ao consumidor de um carro novo é a soma do
    // preço da fábrica com o percentual de lucro do distribuidor
    // e dos impostos aplicados ao preço de fábrica.
    // Faça um programa que receba via teclado:
    // O preço de fábrica de um veículo, o percentual de lucro do
    // distribuidor e o percentual de impostos. Calcule e mostre:
    
    // a. O valor correspondente ao lucro do distribuidor
    
    // b. O valor correspondente aos impostos
    
    // c. O preço final do veículo
    
    
    
    float industry_price;
    float distributor_percentage, fees_percentage;
    
    printf("Qual é o preço de fábrica do automóvel?");
    scanf("%f", &industry_price);
    
    printf("Qual é a porcentagem de lucro do distribuidor?");
    scanf("%f", &distributor_percentage);
    
    printf("Qual é a porcentagem de impostos?");
    scanf("%f", &fees_percentage);    
   
    float distributor_value = value_by_percentage(industry_price, distributor_percentage);
    float fees_value = value_by_percentage(industry_price, fees_percentage);
    float final_price = industry_price + distributor_value + fees_value;
   
    printf("Valor do distribuidor: %f \n Valor de imposto: %f \n Valor final: %f", distributor_value, fees_value, final_price);
    return 0;
}