/*
 * =============================================================================
 *
 *       Filename:  stat.c
 *
 *    Description:  a demostration of stat() 
 *
 *        Version:  1.0
 *        Created:  08/24/2016 01:41:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */
#define _DEFAULT_SOURCE

#include "common.h"
#include <time.h>

static void show_stat( const struct stat *sp );

int main(int argc, char *argv[])
{
	struct stat status;

	if (argc != 2 || strcmp(argv[1], "--help") == 0) {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (stat(argv[1], &status) == -1) {
		err_exit("stat\n");
	}

	show_stat(&status);

	exit(EXIT_SUCCESS);
}

static void show_stat( const struct stat *sp )
{
	fprintf(stdout, "File Type:\t\t");

	switch (sp->st_mode & S_IFMT) {
	case S_IFREG: 
		fprintf(stdout, "regular file\n");
		break;
	case S_IFDIR:
		fprintf(stdout, "directory\n");
		break;
	case S_IFCHR: 
		fprintf(stdout, "character device\n");
		break;
	case S_IFBLK: 
		fprintf(stdout, "block device\n");
		break;
	case S_IFLNK: 
		fprintf(stdout, "symbolic link\n");
		break;
	case S_IFIFO: 
		fprintf(stdout, "FIFO or pipe\n");
		break;
	case S_IFSOCK: 
		fprintf(stdout, "socket\n");
		break;
	default:
		fprintf(stdout, "unknown file type\n");
		break;
	}

	fprintf(stdout, "I-node Number:\t\t%ld\n", (long) sp->st_ino);
	fprintf(stdout, "Mode:\t\t\t%lo\n", (unsigned long)sp->st_mode);
	fprintf(stdout, "Number of link:\t\t%ld\n", (long) sp->st_nlink);
	fprintf(stdout, "Oweership:\t\tUID=%ld GID=%ld\n", 
			(long) sp->st_uid, (long) sp->st_gid);
	fprintf(stdout, "File size:\t\t%lld Byte\n", (long long)sp->st_size);
	fprintf(stdout, "Optimal IO block size:\t%ld Byte\n", 
			(long)sp->st_blksize);
	fprintf(stdout, "number of block:\t%ld\n", (long) sp->st_blocks);
	fprintf(stdout, "Last time access:\t%s", ctime(&sp->st_atime));
	fprintf(stdout, "Last time modify:\t%s", ctime(&sp->st_mtime));
	fprintf(stdout, "Last time chage:\t%s", ctime(&sp->st_ctime));
}
