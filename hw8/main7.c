#include <stdio.h>
int plus(int k){
    int t1=k/100;
    k%=100;
    k*=(t1>=0)?1:-1;
    int t2=k/10;
    k%=10;
    k*=(t2>=0)?1:-1;
    int t3=k;
    k%=10;
    k*=(t3>=0)?1:-1;
    int sum=t1+t2+t3;
}

int main()
{
    int a=-999;
    int b=999;
    
    
    
    
    printf("a= %d\n",plus(a));
    printf("b= %d\n",plus(b));

    return 0;
}
