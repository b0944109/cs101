#include <stdio.h>
int* get_int_array(int n){return calloc(n, sizeof(int));}
void set_value(int* p, int v){*p = v;}
void print_array(int* p, int n){
    printf("[");
    for(int i= 0;i<n;i++){
        if(i == n-1)
            printf("%d]\n", p[i]);
        else
            printf("%d, ", p[i]);
    }
}
typedef struct array_list{
    int n;
    int* (*getArray)(int);
    void (*setValue)(int*, int);
    void (*printArray)(int*, int);
}array_list_t;

int func(char* a, char* b){
    int sum = 0;
    while(*a++)sum++;
    while(*b++)sum++;
    return sum;
}
char* add_str_func(char a[], char b[], int (*func)(char*, char*)){
    char* r = calloc(func(&a, &b),sizeof(char));
    char* t = r;
    char* aa = &a;
    char* bb = &b;
    while(*aa++)*t++ = *aa;
    while(*bb++)*t++ = *bb;
    return r;
}

int main()
{
    printf("No.1 -------------------\n");
    int n = 10; 

    int* ip = get_int_array(n); 

    for (int i=0; i<n;i++) { set_value(ip+i, i+1); 

    } 
    print_array(ip, n); 
    
    
    printf("No.2 -------------------\n");
    array_list_t new;
    new.getArray = get_int_array;
    new.setValue = set_value;
    new.printArray = print_array;
    new.n = 20;
    
    int* ip2 = new.getArray(new.n);
    for (int i=0; i<new.n;i++) { new.setValue(ip2+i, i+1);
    }
    new.printArray(ip2, new.n);
    free(ip);
    printf("No.3 -------------------\n");
    char a[] = "IU!IU!";
    char b[] = "@CGU";
    //printf("%d", func(&a, &b));
    
    printf ("add_func = %s\n", add_str_func(1, 2, func)); 
    return 0;
}
