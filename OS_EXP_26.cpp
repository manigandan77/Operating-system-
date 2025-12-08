#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int choice;
    char fname[50], data[200];

    printf("1.Create\n2.Read\n3.Append\n4.Delete\nChoice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter filename: ");
    gets(fname);

    switch(choice) {
        case 1:
            fp = fopen(fname, "w");
            printf("Enter data: ");
            gets(data);
            fprintf(fp, "%s", data);
            fclose(fp);
            break;

        case 2:
            fp = fopen(fname, "r");
            if(!fp){printf("File not found"); return 0;}
            while(fgets(data,200,fp)) printf("%s", data);
            fclose(fp);
            break;

        case 3:
            fp = fopen(fname, "a");
            printf("Enter data: ");
            gets(data);
            fprintf(fp, "%s", data);
            fclose(fp);
            break;

        case 4:
            remove(fname);
            printf("Deleted.\n");
            break;
    }
    return 0;
}

