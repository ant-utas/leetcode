#include <math.h>
//2147483647 - max int


int reverse(int x){
    if(x==0)return 0;
    int digits = floor(log10(labs(x)))+1;
    long sum=0;
    int current;
    for(int i=digits-1; i>=0; i--){
        current = x%10;
        printf("%d",current);
        sum = sum+(current*(pow(10,i)));
        if(labs(sum)>pow(2,31)-1)return 0;
        printf("-%ld, \n",sum);

        x=x-current;
        x=x/10;
    }
    return (int)sum;
}
