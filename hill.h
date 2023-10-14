/** @file hill.h
 *  @brief This is a header file that helps in the implementation of Hw_3
 *        You can see all function implementations in the c file hill.c
 *       
 *  This file contains the function for the Hill algorithm of Hw_3. 
 *  The file use the board.h .
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see board.h board.c
 */

#ifndef __HILL_H__
#define __HILL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "stack.h"


/** @brief This is the main function of the file and is being used for implementing 
 *        Hill Climbing algorithm.
 *  
 * How the algorithm works : 1. For each queen Qi, i = 1..N, place her in [i, Yi],
 *                           where Yi is selected at random 1..N.
 *                           2. Let T0 be the number of queens couples threatened with each other.
 *                           3. T = T0, x = 0, y = 0
 *                           4. For i = 1 to N // Find motion that minimizes threats
 *                              a. For j = 1 to N, j ≠ Yi
 *                             i. Let K be the number of threats that would exist if
 *                             queen Qi moved to [i, j].
 *                             ii. If K <T then
 *                               1. T = K, x = i, y = j
 *                          5. If T <T0 then // If a move is found that reduces the threats
 *                              a. move queen Qx to [x, y]
 *                              b. If T = 0 then // If the threats are resolved
 *                               i.return the queen's current position as a solution.
 *                              c. otherwise
 *                               i. go to step 4.
 *                           6. otherwise
 *                              a. Go to Step 1 (restart)
 * 
 * @param  N the size of the board and the number of the queens
 * @param  L the maximun running time of the algorithm
 * @param  S the Seed for srand()
 * 
 * @return void should return nothing
 */
void hill_algorithm(int N ,int L , unsigned S);

#endif
