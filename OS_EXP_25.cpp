#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("sample.txt", O_CREAT | O_RDWR, 0777);
    write(fd, "Operating Systems\n", 18);

    lseek(fd, 0, SEEK_SET);
    char buf[20];
    read(fd, buf, 18);
    printf("File content: %s\n", buf);

    struct stat st;
    stat("sample.txt", &st);
    printf("File size: %ld bytes\n", st.st_size);

    DIR *d = opendir(".");
    struct dirent *dir;
    printf("\nDirectory listing:\n");
    while((dir = readdir(d)) != NULL)
        printf("%s\n", dir->d_name);

    closedir(d);
    close(fd);

    return 0;
}

