/*
 * =============================================================================
 *
 *       Filename:  set-flags.c
 *
 *    Description:  setting the close-on-exec flag
 *
 *        Version:  1.0
 *        Created:  08/15/2016 03:01:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    int flags;

    if (open("testfile", O_RDWR) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        perror("fcntl get flags");
        exit(EXIT_FAILURE);
    }

    flags |= FD_CLOEXEC;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl set flags");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
