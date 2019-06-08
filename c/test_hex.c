#include <stdio.h>
#include <string.h>

void main(){
    int i;
    char chrs[3];
    char data;
    char d1,d2;
    for (i = 0; i < 256; i++){
        sprintf(chrs,"%02x",i);
        if(('0' <= chrs[0]) && (chrs[0] <= '9')){
            d1 = chrs[0] - '0';
        } else {
            if (('a' <= chrs[0]) && (chrs[0] <= 'f')){
                d1 = (chrs[0] - 'a') + 10;
            } else {
                d1 = (chrs[0] - 'A') + 10;
            }
        }
        if(('0' <= chrs[1]) && (chrs[1] <= '9')){
            d2 = chrs[1] - '0';
        } else {
            if (('a' <= chrs[1]) && (chrs[1] <= 'f')){
                d2 = (chrs[1] - 'a') + 10;
            } else {
                d2 = (chrs[1] - 'A') + 10;
            }
        }

        data = (d1 << 4) + (d2);
        printf("%02x: %x - %x -> %02x\n", i, d1, d2,(data & 0x00FF));
    }
}
