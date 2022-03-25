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
int main(){
   
    time_t cur;
    time(&cur);
    
    FILE* RB;
    RB = fopen("records.bin", "rb+");
    lotto_record_t NM;
    fseek(RB, 0-(int)sizeof(lotto_record_t), SEEK_END);
    fread(&NM, sizeof(lotto_record_t), 1, RB);
    lotto_record_t RT[NM.lotto_no];
    fseek(RB, 0, SEEK_SET);
    fread(RT, sizeof(lotto_record_t), NM.lotto_no, RB);
    fclose(RB);
    
    
    
    FILE* RP;
    RP = fopen("report.txt", "w+");
    fprintf(RP, "========= lotto649 Report =========\n");
    fprintf(RP, "- Date ------ Num. ------ Receipt -\n");

    
    
    
    char a[32];
    int S = 0, B = 0, R = 0, SS = 0, BS = 0, RS = 0, DS = 0;
    
    for(int n = 0; n<NM.lotto_no; n++){
        
        if(n == 0){
            strcpy(a, RT[n].lotto_date);
            fprintf(RP, "%s ", a);
            S++;
            B += RT[n].lotto_recelpt / 55;
            R += RT[n].lotto_recelpt;
            DS = 1;
        }else if(!strcmp(a, RT[n].lotto_date)){
            S++;
            B += RT[n].lotto_recelpt / 55;
            R += RT[n].lotto_recelpt;
        }else{
            fprintf(RP, "   %3d/%-3d       %7d\n", S, B, R);
            SS += S;
            BS += B;
            RS += R;
            strcpy(a, RT[n].lotto_date);
            fprintf(RP, "%s ", a);
            S = 1;
            B = RT[n].lotto_recelpt / 55;
            R = RT[n].lotto_recelpt;
            DS++;
        }
        if(n == NM.lotto_no - 1){
            fprintf(RP, "   %3d/%-3d       %7d\n", S, B, R);
            SS += S;
            BS += B;
            RS += R;
        }
        //printf("%s\n", RT[0].lotto_date);
        //fprintf(RP, "   % .3d/%- .3d       % .7d\n", S, B, R);
    }
    char T[20];
    strftime(T, 100,  "%Y%m%d", localtime(&cur));
    fprintf(RP, "-----------------------------------\n");
    fprintf(RP, "%8d  %5d/%-6d  %9d\n", DS, SS, BS, RS);
    fprintf(RP, "========= %s Printed ========\n", T);
    fclose(RP);
    
    return 0;
    
}