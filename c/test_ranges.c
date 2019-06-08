#include <stdio.h>
#include <string.h>

void main(){
    int v = 0;
    int i;
    for (i = 0;i < 255;i++){
        if ((i > 80 && i < 130) || i >= 180){
            printf("%03d> Normal ", i);
        }
        if (i <= 80 || (i < 180 && i >= 130)){
            printf("%03d>> Baixo!!! ", i);
        }
        printf("\n");
    }
}

