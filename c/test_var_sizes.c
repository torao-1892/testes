#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main (void){
    char buf[] = "240F000042726173636F6E74726F6C3B425443333031323B302E302E32616C706861007D";
    int chr;
    char string[50];
    int size,type;
    int seq;
    int i;
    int pins[] = {1,2,3,4,5};

    sscanf(buf,"%02x%02x%04x%s",&size,&type,&seq,buf);
    int ssize = strlen(buf);
    for(i = 0; i < (ssize / 2) - 1;i++){
        sscanf(buf,"%02x%s",&chr,buf);
        string[i] = (char)chr;
        string[i+1] = '\0';
    }
    printf("The buffer of size %d(%d) holds %s\n",size - 5,ssize, string);

    printf("Void: %lu\n", sizeof(void) * 8);
    printf("Void *: %lu\n", sizeof(void *) * 8);
    printf("&pins:%lu\n", sizeof(&pins) * 8);
    printf("Char: %lu\n", sizeof(char) * 8);
    //printf("Short Short: %lu\n", sizeof(short short) * 8);
    printf("Short Int: %lu\n", sizeof(short int) * 8);
    printf("Int: %lu\n", sizeof(int) * 8);
    printf("Long int: %lu\n", sizeof(long int) * 8);
    printf("long long: %lu\n", sizeof(long long) * 8);
    printf("Long Double: %lu\n", sizeof(long double) * 8);
    printf("\nSizeof array of int: %lu\n", sizeof(pins) / sizeof(int));
}
