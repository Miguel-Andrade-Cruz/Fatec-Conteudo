#include "bassie.c"

int main() {
    
    ConversionPackage conversion_package;

    pack_input(&conversion_package);
    convert(&conversion_package);
    
    show_output(&conversion_package);
    
    return 0;
}
