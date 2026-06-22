#include <stdio.h>

#define FNAME "database.dat"
#include "../src/table.h"

table users = {
    .column = {
        (Field) {
          .alias = "name",
          .type = VARCHAR
        },
        (Field) {
            .alias = "birth",
            .type = DATE
        }
    },
    .indexed = "name"
};



int main() {
    printf("ALL FINE 1\n"); //
    
    index_t idx_1 = {
        .indexed = users.indexed,
    };
    index_t idx_2 = {
            .indexed = users.indexed,
    };
    index_t idx_3 = {
        .indexed = users.indexed,
    };
    
    printf("ALL FINE 2\n"); //
    FILE *fp = fopen(FNAME, "wb");
    printf("ALL FINE 3\n"); //
    
    fgetpos(fp, idx_1.entry_ptr);
    printf("ALL FINE 3.1\n"); //
    fwrite("Jhon | 02/01/2001", sizeof(char) * 25, 1, fp);
    printf("ALL FINE 3.2\n"); //
    
    fgetpos(fp, idx_2.entry_ptr);
    fwrite("Cindy | 12/11/2111", sizeof(char) * 25, 1, fp);
    
    fgetpos(fp, idx_3.entry_ptr);
    fwrite("Jhon | 30/12/1987", sizeof(char) * 25, 1, fp);
    
    printf("ALL FINE 4\n"); //
    fclose(fp);
    
    printf("ALL FINE 5\n"); //
    fp = fopen(FNAME, "rb");
    printf("ALL FINE 6\n"); //
    
    char ans[25];
    fread(ans, sizeof(char) * 25, 1, fp);
    printf("1: %s\n", ans);
    printf("ALL FINE 7\n");  //
    
    fread(ans, sizeof(char) * 25, 1, fp);
    printf("2: %s\n", ans);

    fread(ans, sizeof(char) * 25, 1, fp);
    printf("3: %s\n", ans);

    fclose(fp);
    return 0;
}