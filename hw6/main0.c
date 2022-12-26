#include <stdio.h>

int main()
{
    int i = 10;
    if(i&(i-1)){
        printf("%d is %s",i,"false");
    }else{
        printf("%d is %s",i,"true");
    }
    return 0;
}
