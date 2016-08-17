/*
 * =============================================================================
 *
 *       Filename:  read-stdin.c
 *
 *    Description:  read from standard input using read()
 *
 *        Version:  1.0
 *        Created:  08/13/2016 01:13:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wyatt Jee (WJ), bluesorrow221@gmail.com
 *   Organization:  JianYuChuPing
 *
 * =============================================================================
 */

#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#define MAX_READ 4096

int main(int argc, char *argv[])
{
    char buffer[MAX_READ+1]; 
    ssize_t num_read;

    num_read = read(STDIN_FILENO, buffer, MAX_READ);
    if (num_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[num_read] = '\0';
    
    printf("The data you input: %s\n", buffer);

    exit(EXIT_SUCCESS);
}
