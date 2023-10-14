/** @file DFS.h
 *  @brief This is a header file that helps in the implementation of Hw_3
 *        You can see all function implementations in the c file DFS.c
 *       
 *  This file contains the function for the DFS algorithm of Hw_3. 
 *  The file use the stack.h file and board.h .
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see stack.h stack.c board.h board.c
 */

#ifndef __DFS_H__
#define __DFS_H__

//include and define libraries
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "stack.h"
#include <time.h>

/** @brief This is the only function of the file and is being used for implementing 
 *         DFS algorithm.
 *  
 * How the algorithm works : 1. Let a blank stack.
 *                           2. Place the root of the tree in the stack.
 *                           3. As long as the stack is not empty.
 *                             a. You extracted the first element of the stack, let's V.
 *                             b. For each valid next state of Vi of V:
 *                               i. If Vi is a solution
 *                                1. show solution and finish
 *                               ii. otherwise
 *                                1. add Vi to the top of the stack.
 *                            4. there is no solution
 * 
 * @param  N the size of the board and the number of the queens
 * @param  L the maximun running time of the algorithm
 * @return void should return nothing
 */
void dfs_algorithm(int N,int L);

#endif
