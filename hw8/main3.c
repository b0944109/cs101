#include <stdio.h>
void get_binary(int n){
    for(int i =31;i>=0;i--){
        printf("%d",(n&1<<i)>>i);
        if(i%4==0)
            printf(" ");
    }
}

int main()
{
    get_binary(16);

    return 0;
}
