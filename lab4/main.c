#include <stdio.h>
int i, s = -1;
int* getN(int n[], int size, int find){
    for(i= 0; i < size; i++){
        if(n[i] == find) return &n[i];
    }
}
int* row(int n[], int size){
    int t = 999999;
    for(int z = 0; z<size;z++){
        if(n[z]<t && n[z]>s){
            t = n[z];
            i = z;
        }
    }
    return &n[i];
}
int main()
{   
    printf("No.1 ---------------\n");
    int n[]={8,2,0,1,5,3,9,6,4,7};
    int* p = getN(n, 10, 9);
    printf("&n[%i]->%p, n[%i]=%d; p->%p, *p=%d\n", i, p, i, *p, &p, *p);
    
    
    printf("No.2 ---------------\n");
    int* ap[10];
    for(int k = 0;k < 10; k++){
        ap[k] = row(n, 10);
        //printf("%d", *ap[k]);
        s = *ap[k];
        printf("&n[%i]->%p, n[%i]=%i; ap[%i]->%p, *ap[%i]=%i\n", i, ap[k], i, *ap[k], k, ap[k], k, *ap[k]);
    }
    
    
    return 0;
}
