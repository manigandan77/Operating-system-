#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[50];

    fd = open("testfile.txt", O_CREAT | O_RDWR, 0777);
    if(fd < 0) {
        printf("File not created!\n");
        return 0;
    }

    write(fd, "Hello OS Lab!\n", 14);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 14);

    printf("Data read: %s\n", buffer);

    close(fd);
    return 0;
}

