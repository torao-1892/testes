#include <stdio.h>

void main(){
    float a;
    float b;
    float c;
    float test1;
    float test2;

    a = (float)1/(float)3;
    test1 = a + a + a;
    test2 = 0.1 + 0.7;

    printf("3 vezes %0.02f = %0.04f\n", a, test1);
    printf("0.1 + 0.7 = %0.04f\n", test2);

    if (0.7 > 0.7){
        printf("0.7 maior que 0.7");
    } else {
        printf("0.7 menor ou igual a 0.7");
    }
}
