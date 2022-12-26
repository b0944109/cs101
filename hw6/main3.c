#include <stdio.h>

int main()
{
    int i=2022;
    if(i%4==0){
        if(i%100!=0){
            printf("閏年");
        }else if(i%400==0){
            printf("閏年");
        }else{
            printf("平年");
        }
    }else{
        printf("平年");
    }
    return 0;
}
