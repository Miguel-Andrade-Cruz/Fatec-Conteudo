#include "middleware.h"


void clean_buffer() {

    while (getchar() != '\n');
    return;
}

int ask_for_number(); // TODO Declarar função

int sum_number_algarisms(int num); // TODO Declarar função

void show_sum_of_algarisms(int sum_of_algarisms); // TODO Declarar função