/*
 * =============================================================================
 *
 *       Filename:  common.c
 *
 *    Description:  some common function
 *
 *        Version:  1.0
 *        Created:  08/17/2016 07:13:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include "common.h"

void err_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void usage(const struct help *help, const char *format, ...)
{
	int j;
	va_list ap;

	fflush(stdout);
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);

	if (help[0].long_opt == NULL) {
		for (j = 0; help[j].short_opt != 0; j++) {
			fprintf(stderr, " -%c\t%s\n", help[j].short_opt, 
					help[j].description);
		}
	}
	else {	
		for (j = 0; help[j].short_opt != 0; j++) {
			fprintf(stderr, " -%c, --%s\t%s\n", help[j].short_opt, 
					help[j].long_opt, help[j].description);
		}
	}

	fflush(stderr);

	exit(EXIT_FAILURE);
}
