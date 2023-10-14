/** @file simulate.h
 *  @brief This is a header file that helps in the implementation of Hw_3
 *        You can see all function implementations in the c file simulate.c
 *       
 *  This file contains the function for the simulate algorithm of Hw_3. 
 *  The file use the board.h .
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see board.h board.c
 */

#ifndef __SIMULATE_H__
#define __SIMULATE_H__

//include-define libraries
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "stack.h"
#define A 0.001

/** @brief This is the only function of the file and is being used for implementing 
 *         simulate algorithm.
 *  
 * How the algorithm works :
 * 1. For each queen Qi, i = 1..N, position her
 *    [i, Yi], where Yi is randomly selected in the interval 1N.
 * 2. Let T0 be the number of queens couples threatened in between
 *   their.
 * 3. Randomly chose a queen Qx, x∈1..N. Randomly selected one
 * column y∈1..N.
 * 4. Calculate the number of threats, even T, if Queen Qx
 *  move to [x, y] (don't move it yet).
 * 5. If TT0 then // if the traffic presents less threats
 * a. move queen Qx to [x, y]
 * b. If T = 0 then
 * i. He returned to the queen's current position as a solution.
 * 6. otherwise
 *  a. Let ΔT = T0-T, ΔT <0. Let p = α · eΔT, where 0 <α≤1 parameter
 *  defined as fixed in the program. Choose one
 * random real number r∈ [0,1]. If r≤p, then
 * move the queen Qx to [x, y].
 * 7. Go to Step 2.
 * 
 * @param  N the size of the board and the number of the queens
 * @param  L the maximun running time of the algorithm
 * @param  S the seed for srand()
 * @return void should return nothing
 */
void simulate_algorithm(int N,int L,unsigned S);


#endif
