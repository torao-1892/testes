#include <stdio.h>
#include <string.h>

void main(){
    char string[] = "<I>e60200091002010007d0000bb80003e80027100102001770000000"
                    "0000000027100203000bb8000bb800000000271001040017700000000"
                    "0000000271002050007d0000bb80003e8002710010600177000000000"
                    "00000027100207000bb8000bb80000000027100108001770000000000"
                    "00000271002090003e8000bb80007d0002710010a0017700000000000"
                    "00002710020b000bb8000bb8000000002710010c00177000000000000"
                    "0002710020d000000000bb8000bb8002710010e001770000000000000"
                    "002710020f000bb8000bb800000000271001100017700000000000000"
                    "0271062<F>";
    char header[4];
    int size = 0;
    sscanf(string, "%3c%2x%s",header,&size,string);
    int i;
    char lrc = (0xFF & size);
    int value = 0;
    char data;
    for (i = 1; i < (size - 1); i++){
        data = ((string[0] - 0x30) << 4) + (string[1] - 0x30);
        sscanf(string,"%2x%s",&value,string);
        lrc = (0x00FF & value) ^ lrc;
        printf("Value: %02x, Data: %02x\n",value,data);
    }
    int lrc_rec = 0;
    sscanf(string,"%2x%s",&lrc_rec,string);
    printf("\nLRC Calc: %u\nLRC Rec: %u\n",(0xFF & lrc), lrc_rec);
}

