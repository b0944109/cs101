#include <stdio.h>

int main()
{
    int n=9;
    n=n*n+(n*n)/10;
    for(int i =1;i<=n;i++){
        if(i%10==0)printf("\n");
        else printf("%d*%d=%d\t",i/10+1,i%10,(i/10+1)*(i%10));
    }

    return 0;
}
