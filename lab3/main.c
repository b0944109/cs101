#include <stdio.h>
int a = -1;
int k = 0;
int my_strlen(char* s){
    int c = 0;
    while(*s++) c++;
    return c;
}

int rec_strlen(char* s){
    if(*s++) rec_strlen(s);
    a++;
}

/*char* my_sort(char* s){
    while (*(s + k)){
        for(int j = 0; j < k; ++j){
            if(*(s + k) > *(s + j)){
                char temp = *(s + k);
                *(s + k) = *(s + j);
                *(s + j) = temp;
            }
        }
        k++;
    }
    return s;
}*/
int main()
{

    printf("%d\n", my_strlen("IU is a girl!"));
    printf("%d\n", rec_strlen("IU is a girl!"));
    /*char* a = NULL;
    a = my_sort("UI is a girl!");
    printf("%c", *a);*/
    return 0;
}

