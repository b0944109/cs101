#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct record_t{
    int lotto_no;
    int lotto_recelpt;
    int emp_id;
    char lotto_date[20];
    char lotto_time[20];
}lotto_record_t;

typedef struct opraterT{
    int emp_id;
    int emp_salary;
    char emp_name[20];
}emp_record_t;


int main()
{ 
    lotto_record_t thisrecord;
    
    
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
    
    
    printf("歡迎光臨長庚樂透彩購機台");
    printf("請輸入操作人員ID:(1~5)");
    int op;
    scanf("%d", &op);
    while(op < 0 || op > 5){
        printf("請重新輸入操作人員(1~5)");
        scanf("%d", &op);
    }
    
    if(op == 0){
        emp_record_t Nemp;
        int ID, Salary;
        char Name[50];
        printf("請輸入要新增操作人員 ID (1 ~ 99) :");
        scanf("%d", &ID);
        while(ID<1 || ID >99){
            printf("請重新輸入要新增操作人員 ID (1 ~ 99) :");
            scanf("%d", &ID);
        }
        Nemp.emp_id = ID;
        printf("請輸入要新增操作人員 Name: ");
        scanf("%s", Name);
        strcpy(Nemp.emp_name, Name);
        printf("請輸入要新增操作人員 Salary: ");
        scanf("%d", &Salary);
        Nemp.emp_salary = Salary;
        addEmployee(Nemp);
    }else{
        
    thisrecord.emp_id = op;
    
    
    FILE* operatorbin;
    int opread[1];
    int opwrite[1];
    
    opwrite[0] = op;
    if(!(operatorbin = fopen("operator_id.bin", "ab+"))){
        operatorbin = fopen("operator_id.bin", "wb+");
        fwrite(opwrite, sizeof(int), 1, operatorbin);
    }else{
        fwrite(opwrite, sizeof(int), 1, operatorbin);
        fseek(operatorbin, (read_temp[0]-1)*4, SEEK_SET);
        fread( opread, sizeof(int), 1, operatorbin);
    }
    fclose(operatorbin);
    
    
    int n;
    printf("請問您要購買幾組樂透彩(1~5)");
    scanf("%d", &n);
    while(n > 5 || n < 1){
        printf("格式不符，請重新輸入(1 <= N <= 5)");
        scanf("%d", &n);
    }
    thisrecord.lotto_recelpt = n * 50 * 1.1;
    
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
    thisrecord.lotto_no = read_temp[0];
    
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
    fprintf(lotto, "========* Op.%.5d *========\n", opread[0]);
    fprintf(lotto, "========= %s =========", "csie@CGU");
    fclose(lotto);
    
    FILE* testbin;
    testbin = fopen("test.bin", "wb+");
    int write[5] = {1, 2, 3, 4, 5};
    int read[5];
    fwrite(write, sizeof(int), 5, testbin);
    fseek(testbin, 0, SEEK_SET);
    fread(read, sizeof(int), 5, testbin);
    fclose(testbin);
    printf("已為您購買的 %d 組樂透組合輸出至 %s", n, FH);
    
    char date[50];
    char ttime[50];
    strftime(date, 100, "%Y %m %d", localtime(&cur));
    strftime(ttime, 100, "%H:%M:%S", localtime(&cur));
    strcpy(thisrecord.lotto_date, date);
    strcpy(thisrecord.lotto_time, ttime);
    addRecord(thisrecord);
    }
    
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
void addRecord( lotto_record_t data ){
    FILE* record;
    lotto_record_t write_temp[1];
    write_temp[0] = data;
    if(!(record = fopen("records.bin", "ab+"))){
        record = fopen("records.bin", "wb+");
        fwrite(write_temp, sizeof(lotto_record_t), 1, record);
    }else{
        fwrite(write_temp, sizeof(lotto_record_t), 1, record);
    }
    fclose(record);
}
void addEmployee(emp_record_t emp){
    FILE* empre;
    emp_record_t write[1];
    write[0] = emp;
    empre = fopen("operator_id.bin", "ab+");
    fwrite(write, sizeof(emp_record_t), 1, empre);
    fclose(empre);
}