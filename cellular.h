#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef __CA_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __CA_HEADER__ // being redefined more than once during the build process

#define GENLENGTH 100 //Length of the array or generation length, 50 is good
                      //enough to see the pattern although not too good.

#define SUCCESS 101   // Value to be returned if a function is completed successfully

/**
 * Typedef for a grid.
 * Contains a parent and a child as its two fields
 */
typedef struct grid
{
    int parent[GENLENGTH];
    int child[GENLENGTH];
}Grid;


/**
 * Typedef for a cell.
 * Contains a reference to the neighbours left, right and current
 */
typedef struct cell
{
    int right;
    int left;
    int me;
}Cell;

int start(int[], int);

void displayGen();

void generate();

int rules();

void UserChoice();

int RandomRule();

void chooseRule();

void UserChoice();

int getInt(char*);

#endif
