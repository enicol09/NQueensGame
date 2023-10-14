/** @file stack.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : stack.h , so you can see 
 *        all function drives in the header file stack.h
 *       
 *  This file has the functions of the implementation of a stack.
 *  The file use the board.h file.
 *
 *  @author Pyrros Bratskas 
 *  edited by Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see board.h board.c
 */


#include "stack.h"

void push(stack **p, Board b) {
  stack *element = (stack *)malloc(sizeof(stack));
  if(element == NULL){ 
     printf("System out of memory! \n");
     exit(-1);
  }  
  element->board = b;
  element->prev = *p;
  *p = element;       
}


Board pop(stack **p) {
  Board b;
  stack *tmp;
  if(!*p){
  printf("System error");
  exit(-1); }  
                     /* Retourne -1 si la stack est vide. */
  tmp = (*p)->prev;

  b = clone((*p)->board ,((*p)->board).N);
  free_board((*p)->board);
  free(*p);
  *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
  return b;     /* Retourne la value soutirée de la stack. */
}


void clear(stack **p) {
  stack *tmp;
  while(*p) {
    tmp = (*p)->prev;
    free_board((*p)->board);
    free(*p);
    *p = tmp;
  }
}


int length(stack *p) {
  int n=0;
  while(p) {
    n++;
    p = p->prev;
  }
  return n;
}


void display(stack *p) {
  while(p) {
    print_board(p->board,4);
    printf("\n");
    p = p->prev;
  }
}

 #ifdef DEBUG4
 int main (int argc, char *argv[]){
  stack *bfs_tree;
  bfs_tree = NULL;
  Board b ;
  b = create_board(b,4);
  push(&bfs_tree,b);

  display(bfs_tree);

  Board c;

  c = pop(&bfs_tree);
 
  print_board(c,4);

  clear(&bfs_tree);

 }
#endif
