#include <stdio.h>
#include <stdlib.h>

void write_shared_memory() {
    FILE *fp;
    char data[100];

    fp = fopen("shared_memory.txt", "w");   // create a shared memory file
    if (!fp) {
        printf("Error creating shared memory file!\n");
        return;
    }

    printf("Enter data to write into shared memory: ");
    fflush(stdin);
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);

    printf("Data written successfully.\n");
}

void read_shared_memory() {
    FILE *fp;
    char buffer[100];

    fp = fopen("shared_memory.txt", "r");
    if (!fp) {
        printf("Shared memory not found! Please write first.\n");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    printf("Data read from shared memory: %s\n", buffer);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== SHARED MEMORY IPC SIMULATION ===\n");
        printf("1. Write to Shared Memory\n");
        printf("2. Read from Shared Memory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear newline

        if (choice == 1) {
            write_shared_memory();
        }
        else if (choice == 2) {
            read_shared_memory();
        }
        else if (choice == 3) {
            exit(0);
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
