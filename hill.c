/** @file hill.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : hill.h , so you can see 
 *        all function drives in the header file hill.h
 *       
 *  This file implements the DFS algorithm of Hw_3. 
 *  The file use the board.h file.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see board.h board.c
 */

#include "hill.h"
#include "board.h"
#include "time.h"


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
void hill_algorithm(int N , int L ,unsigned int S) {
   Board hill;
   int tzero;
   Board hill_temp;
   int x = 0, y = 0, row, col;
   int k;
   int t;
   bool change = false ;
   clock_t time1,time2;
   float time_all= 0;
   int restarts = 0; 
   int steps = 0;

   srand(S);
  
   time1=clock();
   while (time_all < L) {

      hill = generate_board(hill, N , S);

      tzero = how_many_blocks(hill, N);
  
      t = tzero;

      for (row = 0; row < N; row++) {
         for (col = 0; col < N; col++) {
            
            hill_temp = change_queen(hill, row, col);

            k = how_many_blocks(hill_temp, N);

            if (k < t) {
               change = true;
               t = k;
               x = row;
               y = col;
            }
 
           free_board(hill_temp);
         }

         if (t == 0) {
            if(change) {
            
            hill_temp = change_queen(hill, x, y);
            free_board(hill);
            hill = clone(hill_temp, N); }
            
            printf("\n --- There is a solution --- \n");

            time2=clock();
            print_board(hill, N);

            free_board(hill_temp);
            free_board(hill);

            printf("\n *-- Time spent: %f secs --*\n",((float) time2-time1)/CLOCKS_PER_SEC);
            printf("\n *-- This took %d restarts , and %d steps --*\n" ,restarts,steps);
            printf("\n");   
            return;
         }

         if (t < tzero) {
            tzero = t;
           
            time2 = clock();
            time_all = ((float) time2-time1)/CLOCKS_PER_SEC;
            if(time_all > L ) {
                printf("\n--- There is no solution for this time limit :( --- \n");

                 //free_board(hill_temp);
                 free_board(hill);
                return;  }

            hill_temp = change_queen(hill, x, y);
            free_board(hill);

            hill = clone(hill_temp, N);

            free_board(hill_temp);
            // printf("change has been made");
            steps++;

            //print_board(hill, N);
         }
      
           
          
      }

     free_board(hill);
    
     restarts++;
     time2 = clock();
     time_all = ((float) time2-time1)/CLOCKS_PER_SEC;
   }
   
    //free_board(hill_temp);
    //free_board(hill);

   printf("\n--- There is no solution for this time limit :( --- \n");
}

 #ifdef DEBUG2
 int main (int argc, char *argv[]){
   
  printf("\n calculating hill algorithm for N = 4 and time limit 10 and s = 15 \n" );
  hill_algorithm(4,10,15);
   
  printf("\n calculating hill algorithm for N = 6 and time limit 10 and s = 15 \n" );
  hill_algorithm(6,10,15);

  printf("\n calculating dfs algorithm for N = 8 and time limit 10 and s=15\n" );
  hill_algorithm(8,10,15);
 }
#endif
