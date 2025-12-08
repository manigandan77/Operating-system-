#include <stdio.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_NAME 100

struct SingleDirectory {
    char dirname[MAX_NAME];
    char files[MAX_FILES][MAX_NAME];
    int fileCount;
};

int main() {
    struct SingleDirectory dir;
    int i;

    printf("Enter directory name: ");
    scanf("%s", dir.dirname);

    printf("Enter number of files: ");
    scanf("%d", &dir.fileCount);

    for (i = 0; i < dir.fileCount; i++) {
        printf("Enter file name %d: ", i + 1);
        scanf("%s", dir.files[i]);
    }

    // Output
    printf("\n----- Directory Structure -----\n");
    printf("Directory Name: %s\n", dir.dirname);
    printf("Files inside directory:\n");

    for (i = 0; i < dir.fileCount; i++) {
        printf("%d. %s\n", i + 1, dir.files[i]);
    }

    return 0;
}

