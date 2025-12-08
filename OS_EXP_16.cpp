#include<stdio.h>
#include<stdlib.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;
    int n, i;

    fp = fopen("employee.dat", "wb+");
    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("\nEnter record number to access: ");
    scanf("%d", &i);

    fseek(fp, (i-1)*sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details:\nID: %d\nName: %s\nSalary: %.2f\n",
            e.id, e.name, e.salary);

    fclose(fp);
    return 0;
}

