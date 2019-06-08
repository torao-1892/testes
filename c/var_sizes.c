#include <stdio.h>

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef union {
    struct {
        uint8_t redp:1;     // Vermelho pararelo de pedestre
        uint8_t green:1;    // Verde
        uint8_t yellow:1;   // Amarelo
        uint8_t red:1;      // Vermelho
        uint8_t off:1;      // 1 = GS apagado, 0 = GS aceso
        uint8_t mode:1;     // 1 = somente Leds, 0 = lampadas
    };
    struct {
        uint8_t group:4;
    };
    uint8_t value;
} gs_data_t;

void main(void){
    printf("SizeOf char: %lu\n", sizeof(char));
    printf("SizeOf short: %lu\n", sizeof(short));
    printf("SizeOf int: %lu\n", sizeof(int));
    printf("SizeOf long: %lu\n", sizeof(long));
    printf("SizeOf long long: %lu\n", sizeof(long long));
    printf("SizeOf float: %lu\n", sizeof(float));
    printf("SizeOf double: %lu\n", sizeof(double));
    printf("SizeOf long double: %lu\n", sizeof(long double));

    printf("Bin Number: %02X\n", 0b01000001);

    printf("SizeOf gs_data_t: %lu\n", sizeof(gs_data_t));
    gs_data_t gs_data[2];
    gs_data[0].value = 0;
    printf("SizeOf gs_data: %lu\n", sizeof(gs_data));
    printf("Sizeof array: %lu\n", sizeof(char[100]));
}