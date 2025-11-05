#include "wrap_function.c"
#include "convert.c"
#include "gui.c"

int main() {

    ConversionPackage conversion_package;
    
    pack_input(&conversion_package);

    
    chunk_conversion(&conversion_package, 4);
    
    printf("%s", conversion_package.target_number);
}
