/** @file stack.h
 *  @brief This is a header file that helps in the implementation of Hw_3
 *        You can see all function implementations in the c file stack.c
 *       
 *  This file contains the function that help in the implementation of a stack
 *  like push and pop. 
 *
 *  @author Pyrros Bratskas 
 *  edited by Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

/*
 * The stack structure
 *
 */
typedef struct stack {
  Board board;
  struct stack *prev;
} stack ;


/** @brief Push an element to the stack
 *
 * @param stack** the stack
 * @param Board the element we want to push
 * @return void
 */
void push(stack **, Board b);


/** @brief Pop value from the stack
 *
 * @param stack** the stack
 * @return Board the element popped from stack
 */
Board pop(stack **);


/** @brief Clear the stack
 *
 * Deletes the elements of the stack. Free the memory.
 *
 * @param stack** the stack
 * @return void
 */
void clear(stack **);


/** @brief Returns the number of elements in the stack
 *
 * @param stack* the stack
 * @return int number of elements
 */
int length(stack *p);


/** @brief Displays the stack
 *
 * @param stack* the stack
 * @return void
 */
void display(stack *);
           
#endif
