#include <stdio.h>
void print_top(){
    printf("  X'mas tree!\n");
}
void print_trunk(){
    for(int i=0;i<5;i++){
        print_stars(1);
    }
}
void print_spaces(int i){
    for(i;i>0;i--){
        printf(" ");
    }
}
void print_stars(int k){
    int p=9-k,n=k;
    for(k;k>0;k--){
        print_spaces(p+k);
        printf("*");
        for(int i=n;i>k;i--)
            printf("**");
        printf("\n");
    }

}

int main()
{
    print_top();
    print_stars(3);
    print_stars(5);
    print_stars(7);
    print_trunk();


    return 0;
}
