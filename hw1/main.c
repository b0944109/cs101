/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{ 
    int n;
    printf("請輸入N(1 <= N <= 5)");
    scanf("%d", &n);
    while(n > 5 || n < 1){
        printf("格式不符，請重新輸入N(1 <= N <= 5)");
        scanf("%d", &n);
    }
    FILE* lotto;
    FILE* counter;
    lotto = fopen("lotto.txt","w+");
    time_t cur;
    time(&cur);
    srand((unsigned)time(NULL));
    fprintf(lotto, "========= %s =========\n", "lotto649");
    fprintf(lotto, "= %.24s =\n", ctime(&cur));
    for(int t = 1; t <= n; t++){
        
        int LN[7];
        for(int i = 0; i < 6; i++){
            int temp = rand() % 70;
            while(findA(LN, temp) != -1){
                temp = rand() % 70;
            }
            LN[i] = temp;
        }
        int temp;
        temp = rand() % 10 +1;
        while(findA(LN, temp) != -1)
            temp = rand() % 10 +1;
        LN[6] = temp;
        fprintf(lotto, " [%d]: ", t);
        for(int i = 0; i < 7; i++)
            fprintf(lotto, "%.2d ", LN[i]);
        fprintf(lotto, " \n");
        if(t == n){
            for(int ii = t+1; ii <=5; ii++){
                fprintf(lotto, " [%d]: ", ii);
                fprintf(lotto, "-- -- -- -- -- -- --  \n");
            }
        }
    }
    fprintf(lotto, "==========%s==========", "csie@CGU");
    fclose(lotto);
    
    return 0;
}
int findA(int arr[], int tar){
    int len = 7;
    int index = -1;
    for(int i = 0; i < len; i++){
        if(arr[i] == tar){
            index = i;
            break;
        }
    }
    return index;
    
}
