/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
typedef struct employee{
    int em_id;
    char em_name[64];
    int em_age;
    char em_phone[12];
    int em_salary;
}employee_t;
int main()
{
    employee_t a, b, c, d;
    a.em_salary = 10;
    b.em_salary = 20;
    c.em_salary = 30;
    d.em_salary = 40;
    
    printf("%d", c.em_salary);
    return 0;
}
employee_t Vssalary(employee_t a[]){
    return a[0];
}
