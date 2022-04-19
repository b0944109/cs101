#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapArray(int a[],int b[], int size){
    int(*temp)[size];
    for(int i = 0; i< size; i++){
        swap(&a[i], &b[i]);
    }
}
void printArray(int a[], int size){
    for(int i = 0; i <size; i++){
        if(i == size-1) printf("%d]\n", a[i]);
        else printf("%d, ",a[i]);
    }
}
char* copy_string(char* s)
{
    int L = 0;
    for(char* t = s; *t; t++)L++;
    char* r = calloc(L, sizeof(char));
    char* i = r;
    for(int k = 0;k<L;k++)*i++ = *s++;
    return r;
}
int main()
{
    int n, m;
    n = 1;
    m = 2;
    swap(&n, &m);
    printf("No.1 -------------------\n");
    printf("after swap, n = %d, m = %d\n", n, m);
    
    int size= 10;
    int source [10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    swapArray (source, dest, size);
    printf("No.2 -------------------\n");
    printf("after swap array, source array = [");
    printArray (source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("No.3 -------------------\n");
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    return 0;
}
