/*
 * =============================================================================
 *
 *       Filename:  open-file.c
 *
 *    Description:  open a file using open()
 *
 *        Version:  1.0
 *        Created:  08/13/2016 01:13:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    int fd;

    fd = open("file", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
