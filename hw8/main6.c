#include <stdio.h>

int main()
{
    int n=4;
    for(int i =1,j=1;i<=n;j++){
        if(j<=n-i)
            printf(" ");
        else if(j<n+i)
            printf("*");
        else{
            printf("\n");
            j=0;
            i++;
        }
        
    }
    for(int i =1;i<=n+2;i++){
        for(int ii=0;ii<=n+2;ii++){
            if(i!=1&&i!=n+2){
                if(ii==0||ii==n+2)
                    printf("*");
                else
                    printf(" ");
            }else{
                printf("*");
            }
        }
        printf("\n");
        
    }
    return 0;
}
