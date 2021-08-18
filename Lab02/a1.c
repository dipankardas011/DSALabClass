/*WAP to store n employee’s data such as employee name, gender, designation, department, basic pay. Calculate the gross pay of each employees as follows:
Gross pay = basic pay + HR + DA
HR=25% of basic and DA=75% of basic.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 30

typedef struct Employee{
    char name[MAX_CHAR];
    char gender;
    char desig[MAX_CHAR];
    char depart[MAX_CHAR];
    int salary;
}Employee;


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    Employee *ee=(Employee*)malloc(n*sizeof(Employee));

    for(int i=0;i<n;i++)
    {
        printf("Enter the name, gender, designation, department, base_salary\n");
        scanf(" %[^\n]s ",ee[i].name);
        scanf(" %c",&ee[i].gender);
        scanf(" %s",ee[i].desig);
        scanf(" %s",ee[i].depart);
        scanf("%d",&ee[i].salary);
    }

    for(int i=0;i<n;i++)
    {
        printf("Employee %d\n",i+1);
        printf("\tName: %s\n",ee[i].name);
        printf("\tGender: %c\n",ee[i].gender);
        printf("\tDesignation: %s\n",ee[i].desig);
        printf("\tDepartment: %s\n",ee[i].depart);
        printf("\tBase salary: %d\n",ee[i].salary);
        double gross = (1+0.25+0.75)*ee[i].salary;
        printf("\tGross salary: %.2lf\n",gross);
        printf("------------------------------\n");
    }

    free(ee);
    remove(argv[0]);
    return 0;
}
