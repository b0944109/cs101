#include <stdio.h>

int main()
{
    int i = 12345;
    int t = i%10000/1000;
    int d = i%10;
    i-=t*1000;
    i-=d;
    i+=t;
    i+=d*1000;
    printf("i = %d",i);
    return 0;
}
