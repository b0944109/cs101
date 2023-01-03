#include <stdio.h>
int round_func(float f){
    
    printf("%d",(int)(f*10+5)/10);
    return (int)(f*10+5)/10;
}
int main()
{
    round_func(1.4);

    return 0;
}
