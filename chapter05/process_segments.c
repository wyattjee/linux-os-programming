/*
 * =====================================================================================
 *
 *       Filename:  process_segments.c
 *
 *    Description:  demonstrate the mapping between C variable 
 *                  and the segment of process. 
 *
 *        Version:  1.0
 *        Created:  07/29/2017 08:28:43 PM
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

char buffer[2048];                  /* Uninitialized data segment */
int position[] = { 3, 4, 5 };       /* Initialized data segment */

static int cube(int num)            /* Allocated in frame for cube() */
{
    int result;                     /* Allocated in frame for cube() */

    result = num * num * num;
    return result;                  /* return value passed via register */
}

static void do_cube(int num)        /* Allocated in frame for do_cube() */
{
    if (num > 10 || num < 1) {
        fprintf(stderr, "ERROR: Out of Range\n");
    }
    else {
        for(; num > 0; num--) {
            fprintf(stdout, "The cube of %2d is %4d\n", num, cube(num));
        }
    }
}

int main(int argc, char *argv[])    /* Allocated in frame for main() */
{
    static int num = 6;             /* Initialized data segment */
    char *ptr;                      /* Allocated in frame for main() */

    ptr = malloc(1024);             /* Points to memory in heap segment */
    
    do_cube(num);

    free(ptr);                      /* Always remember to free */

    exit(EXIT_SUCCESS);
}
