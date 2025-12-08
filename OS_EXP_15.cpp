#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10

struct Directory {
    char userName[50];          // User directory name
    int fileCount;              // Number of files
    char files[MAX_FILES][50];  // File names
};

int main() {
    struct Directory dir[MAX_USERS];
    int userCount;

    printf("Enter number of user directories: ");
    scanf("%d", &userCount);

    // Input section
    for (int i = 0; i < userCount; i++) {
        printf("\nEnter user directory name: ");
        scanf("%s", dir[i].userName);

        printf("Enter number of files for %s: ", dir[i].userName);
        scanf("%d", &dir[i].fileCount);

        for (int j = 0; j < dir[i].fileCount; j++) {
            printf("Enter file %d name: ", j + 1);
            scanf("%s", dir[i].files[j]);
        }
    }

    // Output section
    printf("\n\n----- TWO LEVEL DIRECTORY STRUCTURE -----\n");
    for (int i = 0; i < userCount; i++) {
        printf("\nUser Directory: %s\n", dir[i].userName);
        printf("Files:\n");

        for (int j = 0; j < dir[i].fileCount; j++) {
            printf("  %d. %s\n", j + 1, dir[i].files[j]);
        }
    }

    return 0;
}

