#include "middleware.h"

#define DEBUG


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}