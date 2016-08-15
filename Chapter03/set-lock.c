/*
 * =============================================================================
 *
 *       Filename:  set-lock.c
 *
 *    Description:  set write lock
 *
 *        Version:  1.0
 *        Created:  08/15/2016 03:39:46 PM
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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    struct flock fl;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s file [option]\n", argv[0]);
        fprintf(stderr, "       -w    lock write\n");
        fprintf(stderr, "       -r    lock read\n");
        fprintf(stderr, "       -u    unlock\n");
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    switch (argv[2][1]) {
    case 'w':
        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        break;
    case 'r':
        fl.l_type = F_RDLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        break;
    case 'u':
        fl.l_type = F_RDLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        break;
    }

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl set lock");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
