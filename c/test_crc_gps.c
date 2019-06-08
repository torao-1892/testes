#include <stdio.h>

void main (void){
    char string[] = "$GNRMC,215533.00,A,2328.45502,S,04649.76684,W,0.192,,270418,,,A*69";

    int string_size = sizeof (string);

    int i;
    int crc = 0;
    printf("\n%s\n",string);
    for (i = 1; i < string_size - 4;i++){
        crc ^= string[i];
        printf("%c",string[i]);
    }
    
    printf("\nCRC: %02x\n",crc);

}
