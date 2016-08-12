#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#define MAX_READ 4096

int main(int argc, char *argv[])
{
    char buffer[MAX_READ+1]; 
    ssize_t num_read;

    num_read = read(STDIN_FILENO, buffer, MAX_READ);
    if (num_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[num_read] = '\0';
    
    printf("The data you input: %s\n", buffer);

    exit(EXIT_SUCCESS);
}
