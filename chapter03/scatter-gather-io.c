/*
 * =============================================================================
 *
 *       Filename:  scatter-gather-io.c
 *
 *    Description:  a demonstrate of scatter-gathert I/O 
 *
 *        Version:  1.0
 *        Created:  08/18/2016 03:55:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include "common.h"

#include <sys/uio.h>
#include <fcntl.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int opt;
	int fd_read;
	int fd_write = STDOUT_FILENO;
	ssize_t num_read;
	static char buf0[10];
	static char buf1[20];
	static char buf2[30];
	
	int iovcnt;
	struct iovec iov[3];

	static struct option long_option[] = {
		{"help", 	no_argument,		0, 'h'},
		{"read",	required_argument,	0, 'r'},
		{"write",	required_argument,	0, 'w'},
		{0, 0, 0, 0}
	};

	const struct help help[] = {
		{'h', "help", "show the usage and exit"},
		{'r', "readv", "readv file"},
		{'w', "writev", "writev file"},
		{0, 0, 0},
	};

	while ((opt = getopt_long(argc, argv, "hr:w:", long_option, NULL)) != -1) {
		switch (opt) {
			case 'r':
				if ((fd_read = open(optarg, O_RDONLY)) == -1)
					err_exit("open file for reading");
				break;
			case 'w':
				if ((fd_write = open(optarg, O_RDWR)) == -1)
					err_exit("open file for writing");
				break;
			case 'h':
				/* break through */
			default:
				usage(help, "Usage: %s -r[file] -w[file]\n", argv[0]);
		}
	}

	iov[0].iov_base = buf0;
	iov[0].iov_len = sizeof(buf0);
	iov[1].iov_base = buf1;
	iov[1].iov_len = sizeof(buf1);
	iov[2].iov_base = buf2;
	iov[2].iov_len = sizeof(buf2);

	iovcnt = sizeof(iov) / sizeof(struct iovec);

	if ((num_read = readv(fd_read, iov, iovcnt)) == -1)
		err_exit("readv");

	if ((num_read = writev(fd_write, iov, iovcnt)) == -1)
		err_exit("writev");

	exit(EXIT_SUCCESS);
}

