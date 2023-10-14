/** @file DFS.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : DFS.h , so you can see 
 *        all function drives in the header file DFS.h
 *       
 *  This file implements the DFS algorithm of Hw_3. 
 *  The file use the stack.h file.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see stack.h stack.c board.h board.c
 */


//include and define libraries
#include "DFS.h"
#include <time.h>
#include <math.h> 


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
void dfs_algorithm(int N, int L) {

   Board parent;
   Board kid; 
   float time;
   clock_t  time1,time2;

   int row = 0, col = 0;
   stack *bfs_tree; //the new stack
   bfs_tree = NULL;

   Board root; 
   root = create_board(root, N);

   push(&bfs_tree, root);
 
   time1=clock(); 
   
   //algorithm implementation
   while (bfs_tree != NULL) {
      parent = pop(&bfs_tree);
      for (row = 0; row < N; row++) {
         kid = add_queen(parent, col, row );

         if (isSafe(kid, col , row)) {
            if (allqueens(kid)) {

               time2=clock();
               printf("\n There is a solution !! \n");
               print_board(kid, N);
               printf("\n Time spent: %f secs\n",((float) time2-time1)/CLOCKS_PER_SEC);
                clear(&bfs_tree);
                free_board(kid);
                free_board(parent);
               return;
            } else {
               time2= clock();
               time = ((float) time2-time1)/CLOCKS_PER_SEC;

               if(time > L ) {
                printf("\n There is no solution for this time limit \n");
                clear(&bfs_tree);
                free_board(kid);
                free_board(parent);
                return ;  }

                push(&bfs_tree, kid);
              
            }
         }
          else{
            free_board(kid);
          }
    
      }
      free_board(parent);
      col++;
      if (col == N)
         col = 0;

               time2= clock();
               time = ((float) time2-time1)/CLOCKS_PER_SEC;
               //printf("time = %3.f < L = %d " , time ,L);

               if(time > L ) {
                printf("\n There is no solution for this time limit \n");
                clear(&bfs_tree);
                return ;  }
   }

   clear(&bfs_tree);
   printf("I am sorry there is no any solution :( ");

   return;
}

 #ifdef DEBUG1
 int main (int argc, char *argv[]){
   
  printf("\n calculating dfs algorithm for N = 4 and time limit 10 s\n" );
  dfs_algorithm(4,10);
   
  printf("\n calculating dfs algorithm for N = 6 \n" );
  dfs_algorithm(6,10);

  printf("\n calculating dfs algorithm for N = 8 and time limit 10 s\n" );
  dfs_algorithm(8,10);
 }
#endif
