#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <unistd.h>

int main() {
    int src, dest;
    char buffer[100];
    int bytesRead;

    src = open("source.txt", O_RDONLY);
    if (src < 0) {
        perror("Source file error");
        return 1;
    }

    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Destination file error");
        close(src);
        return 1;
    }

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }

    close(src);
    close(dest);

    printf("File copied successfully!\n");
    return 0;
}

