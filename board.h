/** @file board.h
 *  @brief This is a h file that helps in the implementation of Hw_3
 *        You can find the implementation of the functions in : Board.c
 *       
 *  This file contains different functions for the operations of 
 *  a Board type struct.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 */


#ifndef __BOARD_H__
#define __BOARD_H__


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


 /*
 * The Board structure
 *
 */
 typedef struct Board {
   int N;
   char **board;
 } Board ;

/** @brief This function is being used for creating a new game board.
 *  
 * This function creates a  type Board based on a given size.
 * 
 * @param  b the Board that we are going to create
 * @param  N the size of the board

 * @return b the board that we have create.
 */
 Board create_board(Board board,int N);

/** @brief This function prints a given Board.
 *  
 * @param  b the Board that we are going to create
 * @param  N the size of the board

 * @return the Board with the new queen
 */ 
 void print_board(Board board,int N);

 /** @brief This function adds a Queen(char 'Q') in a given position of the board.
 *  
 * @param  b the Board that we are going to add the queen
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen
 * @return void should return nothing
 */
 Board add_queen(Board b, int x , int y);

 /** @brief This function checks if the new given position of the queen is going 
 *         to make any conflicts.
 *  
 * @param   kid the Board that we check.
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen 
 *
 * @return true if there aren't any conflicts and false if there are
 */
 bool isSafe(const Board kid, int x , int y);

 /** @brief This function checks if all the queens that we want ( n queens) 
 *         are in the board.
 *  
 * @param  b the Board that we want to check.
 *
 * @return true if all the queens are in it , and false if they are not
 */
 bool allqueens(const Board kid);

 /** @brief This function makes a clone of a given Board.
 *  
 * @param  b the Board that we are going to make a clone of it.
 * @param  N the size of the board

 * @return the clone Board
 */
 Board clone(const Board b, int N);

 /** @brief This function checks if the new given position of the queen is going 
 *         to make any conflicts and also count them. It's based in the content of algorithm 2 - hill.
 *  
 * @param   kid the Board that we check.
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen 
 *
 * @return the number of the conflicts.
 */
 int isSafe_hill(const Board kid, int x , int y);

/** @brief This function free the dynamic allocated arrays of a struc Board
 *  
 * @param  b the Board that we want to free.
 *
 * @return void
 */
void free_board(Board b);
 
/** @brief This function give the number of conflicts in a board.
 *  
 * @param  hill the board that we want to check the conflicts
 * @param  N the size of the board
 *
 * @return cnt the number of conflicts
 */
int how_many_blocks(Board hill, int N);

/** @brief This function generate a different board. 
 *  This board has one queen in every line but in a random collumn.
 *  
 * @param  b is the new board tha we want to create.
 * @param  N is the size of the board , and the number of the queens 
 * @param  S the seed for srand(). 
 *
 * @return the new generated board
 */
Board generate_board(Board b , int N ,unsigned S);

/** @brief This function change the position of a queen in a given row 
 * to a different column. 
 *  
 * @param  b the board that we want to change the queen
 * @param  row the i of the queen
 * @param  col the j of the queen
 *
 * @return cnt the number of conflicts
 */
Board change_queen(Board b, int row , int col);
#endif
