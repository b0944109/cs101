#include <stdio.h>

int main()
{
    int row=10;
    for(int i =1,j=1;i<=row;j++){
        if(j<=row-i)
            printf("  ");
        else if(j<row+i)
            printf("* ");
        else{
            printf("\n");
            j=0;
            i++;
        }
            
    }
    return 0;
}
