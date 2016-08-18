/*
 * =============================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  common include file
 *
 *        Version:  1.0
 *        Created:  08/17/2016 05:14:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#ifndef COMMON_H
#define COMMON_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

typedef enum { FALSE, TRUE } boolen;

struct help {
	char short_opt;
	const char *long_opt;
	const char *description;
};

void err_exit(char *s);
void usage(const struct help *help, const char *format, ...);

#endif
