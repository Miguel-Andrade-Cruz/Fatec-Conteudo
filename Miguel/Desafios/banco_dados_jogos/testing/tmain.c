#include <stdio.h>
#include <string.h>

int main() {
    
    char str[10] = "Caraio";
    
    FILE *fptr;
    fptr = fopen("some.txt", "w");
    fwrite(str, strlen(str), 1, fptr);
    fclose(fptr);
    return 0;
}