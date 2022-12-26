#include <stdio.h>
#include <math.h>
int main()
{

    double pi=0;
    int i=-1;
    while(fabs(pi-3.14159)>=0.0000049){
        i+=2;
        pi+=(i/2%2==1)?-4.0/i:4.0/i;
        printf("差距=%.7f   X=%d\n",fabs(pi- 3.14159),i);
    }
    printf("PI計算結果=%.5f 於最小X=%d",pi,i);//the minimum x is 264775
    
    //test  264773 ,the result is 3.14160(wrong)
    /**
    int x =264773;
    double pi=0;
    for(int i=1;i<=x;i+=2){
        pi+=(i/2%2==1)?-4.0/i:4.0/i;
    }
    
    printf("\n%.5f",pi);
    **/
    
    
    return 0;
}
