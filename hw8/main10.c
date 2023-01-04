#include <stdio.h>
int get_digit(int n){
    return n%10;
}

int main()
{
    int n = 1234;
    int sum = 0;
    int l=1;
    while(n/l!=0){
        l*=10;
    }
    for(l/=10;l>0;l/=10){
        sum+=get_digit(n)*l;
        n/=10;
    }
    
    printf("sum = %d\n", sum);

    return 0;
}
