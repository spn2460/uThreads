/* 
 * File:   main.c
 * Author: jonas
 *
 * Created on April 13, 2013, 7:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../lib/uthreads.h"
#include "../lib/queue.h"

int main(int argc, char** argv) {
    printf("lib uthread inicializada com retorno %d\n", libuthread_init());
    return (EXIT_SUCCESS);
}

