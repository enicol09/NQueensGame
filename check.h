/** @file check.h
 *  @brief This is a h file that helps in the implementation of Hw_3
 *        You can find the implementation of the functions in : check.c
 *       
 *  This file contains different functions for checking the inputs in the main.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 */

#ifndef __CHECK_H__
#define __CHECK_H__



//include and define libraries
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "stack.h"
#include <stdbool.h>
#define A 0.001

/** @brief This function is being used for checking if a given string(char *s)
 *  is numeric.
 *  
 * @param  s the given string
 * @return true if it is numeric and false if it's not
 */
bool is_it_number(char *s);

/** @brief This function is being used for casting a given string(char *s)
 *  to its numeric value.
 *  
 * @param  s the given string
 * @return numeric value
 */
int cast_number(char *s);

/** @brief This function is just prints an error message.
  * 
  * @return void should return nothing
  */
void print_er();

#endif
