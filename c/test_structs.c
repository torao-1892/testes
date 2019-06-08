#include <stdio.h>
#include <string.h>

#define N_COLORS 4

struct {
    unsigned char valid:1;
    unsigned long int number_lamps;
    unsigned long int current;
    unsigned long int voltage;
} gs_values[2][N_COLORS];

void main(){
    printf("Sizeof char: %lu\n", sizeof(char));
    printf("Sizeof short int: %lu\n", sizeof(short int));
    printf("Sizeof int: %lu\n", sizeof(int));
    printf("Sizeof long int: %lu\n", sizeof(long int));
    printf("Sizeof long long: %lu\n", sizeof(long long));
    printf("Sizeof float: %lu\n", sizeof(float));
    printf("Sizeof double: %lu\n", sizeof(double));
    printf("Sizeof long double: %lu\n", sizeof(long double));
    printf("Sizeof gs_values: %lu\n", sizeof(gs_values));
    printf("Sizeof gs_values[0]: %lu\n", sizeof(gs_values[0]));
    printf("Sizeof gs_values[0][0]: %lu\n", sizeof(gs_values[0][0]));
    int i, ii;
    char *p = (char *)gs_values;
    for (i = 0;i < sizeof(gs_values); i++){
        printf(" %02X", (char)*(p + i));
        *(p + i) = i + 1;
    }    
    printf("\n");
    //gs_values[0][0].valid = 1;
    //gs_values[0][0].number_lamps = 12345;
    //gs_values[0][0].current = 12345;
    for (i = 0;i < sizeof(gs_values); i++){
        printf(" %02X", (char)*(p + i));
    }    
    printf("\n");
    for (i = 0; i < 2;i++){
        for (ii = 0; ii < N_COLORS; ii++){
            printf("gs_values[%d][%d].valid: %u\n", i, ii, gs_values[i][ii].valid);
            printf("gs_values[%d][%d].number_lamps: %d\n", i, ii, gs_values[i][ii].number_lamps);
            printf("gs_values[%d][%d].current: %d\n", i, ii, gs_values[i][ii].current);
            printf("gs_values[%d][%d].voltage: %d\n", i, ii, gs_values[i][ii].voltage);
        }
    }
    memset(gs_values,0,sizeof(gs_values));
    for (i = 0;i < sizeof(gs_values); i++){
        printf(" %02X", (char)*(p + i));
    }    
    printf("\n");
    for (i = 0; i < 2;i++){
        for (ii = 0; ii < N_COLORS; ii++){
            printf("gs_values[%d][%d].valid: %u\n", i, ii, gs_values[i][ii].valid);
            printf("gs_values[%d][%d].number_lamps: %d\n", i, ii, gs_values[i][ii].number_lamps);
            printf("gs_values[%d][%d].current: %d\n", i, ii, gs_values[i][ii].current);
            printf("gs_values[%d][%d].voltage: %d\n", i, ii, gs_values[i][ii].voltage);
            gs_values[i][ii].valid = 1;
        }
    }
    for (i = 0;i < sizeof(gs_values); i++){
        printf(" %02X", (char)*(p + i));
    }    
    printf("\n");
}
