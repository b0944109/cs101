#include <stdio.h>

int main()
{
    int i=15;
    int count=0;
    int ii=i;
    for(int k =128,c=1;k>0;k/=2,c++){
        printf("%d",ii/k);
        if(ii/k)
            count++;
        ii%=k;
        if(!(c%4))
            printf(" ");
    }
    printf(" (%d)有%d個 1" ,i,count);
    
    

    return 0;
}
