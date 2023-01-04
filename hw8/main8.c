#include <stdio.h>

int main()
{
    int i=4;
    
    for(int k=1,j=1;j<=i*2-1;k++){
        if(k<j)
            if(j>i&&k>i*2-j-1){
                printf("*");
            }else{
                printf(" ");
            }
            
        else if(k>=j&&k<=i*2-j)
            printf("*");
        else if(k>i*2-j){
            if(j>i)
                printf("*");
            k=0;
            j++;
            printf("\n");
        }
    }

    return 0;
}
 