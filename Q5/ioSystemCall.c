#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 30

int main()
{
        int fd, n;
        char buffer[BUFFER_SIZE];

        // Open file for reading and writing
        fd = open("testFile.txt", O_RDWR);
        printf("File descriptor is %d\n", fd);

        // Check if file opened successfully
        if (fd == -1)
        {
                printf("Failed to open file.\n");
                exit(1);
        }

        // Clear buffer before each operation
        memset(buffer, 0, BUFFER_SIZE);

        printf("\nReading first 10 characters from the file:\n");
        n = read(fd, buffer, 10);
        if (n > 0)
        {
                write(1, buffer, n);
                printf("\n");
        }

        printf("\nSkipping 5 characters from current position in the file:\n");
        lseek(fd, 5, SEEK_CUR);
        memset(buffer, 0, BUFFER_SIZE);
        n = read(fd, buffer, 10);
        if (n > 0)
        {
                write(1, buffer, n);
                printf("\n");
        }

        printf("\nGoing to 5th last character in the file:\n");
        lseek(fd, -5, SEEK_END);
        memset(buffer, 0, BUFFER_SIZE);
        n = read(fd, buffer, 7);
        if (n > 0)
        {
                write(1, buffer, n);
                printf("\n");
        }

        printf("\nGoing to 3rd character in the file:\n");
        lseek(fd, 3, SEEK_SET);
        memset(buffer, 0, BUFFER_SIZE);
        n = read(fd, buffer, 5);
        if (n > 0)
        {
                write(1, buffer, n);
                printf("\n");
        }

        // Close the file
        close(fd);
        printf("\nFile operations completed successfully.\n");

        return 0;
}