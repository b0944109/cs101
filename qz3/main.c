#include <stdio.h>
FILE* out;
void rec_dec(char* s){
    if(*s){
    printf("%c,", *s++);
    rec_dec(s);
    }
}
void haoi_tower(int k){
    out = fopen("hanoi.txt", "w+");
    haoi_tower2(k, 'A', 'B', 'C');
    fclose(out);
    printf("file hanoi.txt output success\n");
}
void haoi_tower2(int k, char A, char B, char C){
    if(k == 1)fprintf(out, "Move disk %d from %c to %c\n", k, A, C);
    else{
    haoi_tower2(k-1, A, C, B);
    fprintf(out, "Move disk %d from %c to %c\n", k, A, C);
    haoi_tower2(k-1, B, A, C);
    }
}
int multiplication(int i, int j){
    printf("%d*%d=%d ", i, j, i * j);
    if(j == 9){
        if(i == 9) return 0;
        printf("\n");
        multiplication(i+1, 1);
    }else multiplication(i, j + 1);
}
int main()
{   
    rec_dec("1234567890");
    printf("\nfunc#1-----------------\n");
    haoi_tower(16);
    printf("\nfunc#2-----------------\n");
    multiplication(1, 1);
    printf("\nfunc#3-----------------\n");
    return 0;
}