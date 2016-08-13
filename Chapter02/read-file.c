/*
 * =============================================================================
 *
 *       Filename:  read-file.c
 *
 *    Description:  read from a file using read()
 *
 *        Version:  1.0
 *        Created:  08/13/2016 01:14:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#define MAX_READ 4096

int main(int argc, char *argv[])
{
    // variable for read()
    char buffer[MAX_READ+1];
    ssize_t num_read;
    
    // variable for open()
    int fd;
    
    fd = open("open-file.c", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    num_read = read(fd, buffer, MAX_READ);
    if (num_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[num_read] = '\0';
    printf("\n%s\n", buffer);

    exit(EXIT_SUCCESS);
}
