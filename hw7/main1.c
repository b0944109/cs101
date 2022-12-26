#include <stdio.h>

int main()
{
    int n =7;
    for(int i =1;i<=n;i++){
        printf("% *d",n+2-i,i);
        for(int ii =1;ii<i;ii++){
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
