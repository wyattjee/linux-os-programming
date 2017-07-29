/*
 * =====================================================================================
 *
 *       Filename:  segments_address.c
 *
 *    Description:  demonstrate the symbol: etext, edata, end
 *
 *        Version:  1.0
 *        Created:  07/29/2017 09:46:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

extern char etext, edata, end;

int main(int argc, char *argv[])
{
    fprintf(stdout, "First address past:\n");
    fprintf(stdout, "    program text (stdout, etext)   %10p\n", &etext);
    fprintf(stdout, "    initialized data (edata)       %10p\n", &edata);
    fprintf(stdout, "    uninitialized data (end)       %10p\n", &end);

    exit(EXIT_SUCCESS);
}
