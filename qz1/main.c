#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main()
{ 
    FILE* counterbin;
    int read_temp[5];
    int write_temp[1] = {1};
    if(!(counterbin = fopen("counter.bin", "rb+"))){
        counterbin = fopen("counter.bin", "wb+");
        fwrite(write_temp, sizeof(int), 1, counterbin);
    }else{
        fseek(counterbin, 0, SEEK_SET);
        fread(read_temp, sizeof(int), 1, counterbin);
        write_temp[0] = read_temp[0] + 1;
        fseek(counterbin, 0, SEEK_SET);
        fwrite(write_temp, sizeof(int), 1, counterbin);
    }
    fseek(counterbin, 0, SEEK_SET);
    fread(read_temp, sizeof(int), 1, counterbin);
    fclose(counterbin);
    
    int n;
    printf("請輸入N(1 <= N <= 5)");
    scanf("%d", &n);
    while(n > 5 || n < 1){
        printf("格式不符，請重新輸入N(1 <= N <= 5)");
        scanf("%d", &n);
    }
    FILE* lotto;
    FILE* counter;
    char No[50];
    No[0]= read_temp[0]+'0';
    char FH[50]="lotto[";
    sprintf(No, "%.5d", read_temp[0]);
    strcat(FH, No);
    strcat(FH, "].txt");
    lotto = fopen(FH ,"w+");
    time_t cur;
    time(&cur);
    srand((unsigned)time(NULL));
    fprintf(lotto, "========= %s =========\n", "lotto649");
    fprintf(lotto, "========+ No.%.5d +========\n", read_temp[0]);
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
    
    FILE* testbin;
    testbin = fopen("test.bin", "wb+");
    int write[5] = {1, 2, 3, 4, 5};
    int read[5];
    fwrite(write, sizeof(int), 5, testbin);
    fseek(testbin, 0, SEEK_SET);
    fread(read, sizeof(int), 5, testbin);
    fclose(testbin);
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
