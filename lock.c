#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

int main(int argc, char *argv[])
{
    int fd;

    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("Opening %s\n", argv[1]);

    fd = open(argv[1], O_RDWR | O_CREAT, 0666);

    printf("Acquiring shared lock using flock\n");

    flock(fd, LOCK_SH);

    printf("\nCurrent 'lslocks' output:\n");
    system("lslocks");

    getchar();

    flock(fd, LOCK_UN);

    printf("\nFile unlocked\n");

    close(fd);

    return 0;
}