/*
 * =============================================================================
 *
 *       Filename:  basic-io.c
 *
 *    Description:  basic io using open() close() write() read() lseek()
 *    
 *          Usage:  ./basic-io [optrion] file
 *                      -h, --help        display this help and exit
 *                      -o, --offset      set offset
 *                      -r, --read        read part of file
 *                      -w, --write       write data to file
 *
 *        Version:  1.0
 *        Created:  08/13/2016 01:10:38 PM
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <ctype.h>

static void usage_error(char *progname, char *msg, int opt);

int main(int argc, char *argv[])
{
    int fd, opt, j;
    off_t offset = 0;
    char *buf;
    ssize_t num_read, num_write;
    size_t opt_read;
    int flag_lseek = 0;
    int flag_read = 0;
    int flag_write = 0;
    const char shortopts[] = "ho:r:w:";
    const struct option longopts[] = {
        {"help",    no_argument,       0, 'h'},
        {"offset",  required_argument, 0, 'o'},
        {"read",    required_argument, 0, 'r'},
        {"write",   required_argument, 0, 'w'},
        {0, 0, 0, 0},
    };

        
    if (argc < 2) {
        usage_error(argv[0], NULL, 0);
    }

    while ((opt = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
        switch (opt) {
        case 'h':
            usage_error(argv[0], NULL, 0);
        case 'o':
            flag_lseek = 1;
            offset = (off_t) strtol(optarg, NULL, 10);
            break;
        case 'r':
            flag_read = 1;
            opt_read = (ssize_t) strtol(optarg, NULL, 10);
            break;
        case 'w':
            flag_write = 1;
            buf = optarg;
            break;

        case '?':
            break;

        default:
            fprintf(stderr, "Unexpected error\n");
            exit(EXIT_FAILURE);
        }
    }
    
    if ( flag_write && flag_read) {
        fprintf(stderr, "don't using read and write at same time\n");
        usage_error(argv[0], NULL, 0);
    }

    if (argv[optind] == NULL) {
        printf("Choose a file to open\n\n");
        usage_error(argv[0], NULL, 0);
    }

    fd = open(argv[optind], O_RDWR | O_CREAT, 
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    /* rw-rw-rw- */
    
    if (flag_lseek && lseek(fd, offset, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    if (flag_write == 1) {
        if ((num_write = write(fd, buf, strlen(buf))) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("write succeeded\n");
        
    }

    if (flag_read == 1) {
        if ((buf = malloc(opt_read)) == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        if ((num_read = read(fd, buf, opt_read)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("[file]: %s [start position]: %ld\n", argv[optind], offset);
        for (j = 0; j < num_read; j++) {
            printf("%c", isprint(buf[j]) ? buf[j] : '~');
        }
        printf("\n");

        free(buf);
    }

    close(fd);
    exit(EXIT_SUCCESS);
}


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  usage_error
 *  Description:  print usage and exit
 * =============================================================================
 */

static void usage_error(char *progname, char *msg, int opt)
{
    if (msg != NULL && opt != 0)
        fprintf(stderr, "%s (-%c)\n", msg, (char)opt);
    fprintf(stderr, "Usage: %s [optrion] file\n", progname);
    fprintf(stderr, "  -h, --help        display this help and exit\n");
    fprintf(stderr, "  -o, --offset      set offset\n");
    fprintf(stderr, "  -r, --read        read part of file\n");
    fprintf(stderr, "  -w, --write       write data to file\n");

    exit(EXIT_FAILURE);
}
