/** @file simulate.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : simulate.h , so you can see 
 *        all function drives in the header file simulate.h
 *       
 *  This file implements the 3rd algorithm - simulate algorithm of Hw_3. 
 *  The file use the board.h file.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug The debug name has one problem with the pow.
 *  @see board.h board.c
 */

//include - define libraries
#include <time.h>
#include "simulate.h"
#include "hill.h"
#include <math.h>
#define A 0.001
#define M_E 2.71828

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
void simulate_algorithm(int N , int L, unsigned S) {

   srand(S);

   Board sim;
   Board sim_temp;

   int tzero = 0;
   int col, row;
   int t;
   int dt;
   double p;
   double randomValue;
   clock_t time1,time2;
   float time_all = 0;
   int restarts = 0; 
   int steps = 0;

   time1=clock();

   sim = generate_board(sim, N,S);
   //print_board(sim, N);

   while (time_all < L) {
    
      tzero = how_many_blocks(sim, N);
      //printf("\n number of conficts = %d \n", tzero);

      row = (rand() % N);
      col = (rand() % N);

     // printf(" row = %d , col = %d \n", row, col);

      sim_temp = change_queen(sim, row, col);
      //print_board(sim_temp, N);

      t = how_many_blocks(sim_temp, N);
      free_board(sim_temp); 
      //free_board(sim_temp);
      //printf("\n number of conficts = %d \n", t);

      if (t <= tzero) {
         if (t == 0) {
            sim_temp = change_queen(sim, row, col);
            free_board(sim);
            sim = clone(sim_temp, N);
            printf("\n --- There is a solution --- \n");
           
            time2=clock();
            print_board(sim, N);

            free_board(sim);
            free_board(sim_temp);

            printf("\n *-- Time spent: %f secs --*\n",((float) time2-time1)/CLOCKS_PER_SEC);
            printf("\n *-- This took %d restarts , and %d steps --*\n" ,restarts,steps);
            printf("\n");
            return;
         }
         time2 = clock();
            time_all = ((float) time2-time1)/CLOCKS_PER_SEC;
            if(time_all > L ) {
                 printf("\n--- There is no solution for this time limit :( --- \n");
                  free_board(sim);
                  //free_board(sim_temp);
                return;  }

         sim_temp = change_queen(sim, row, col);
         free_board(sim);
         sim = clone(sim_temp, N);
         free_board(sim_temp);
         steps++;

      } else {
         dt = tzero - t;
         p = A * (pow(M_E, dt));
           
        // printf(" p = %f \n" , p);
         randomValue = rand();
         randomValue = randomValue / RAND_MAX;
          
          //printf(" randomvalue = %f \n" , randomValue);
         

         if (randomValue <= p) {
            sim_temp = change_queen(sim, row, col);
            free_board(sim);
            sim = clone(sim_temp, N);
            free_board(sim_temp);
            steps++;
            time2 = clock();
            time_all = ((float) time2-time1)/CLOCKS_PER_SEC;

            if(time_all > L ) {
                 printf("\n--- There is no solution for this time limit :( --- \n");
                  free_board(sim);
                  free_board(sim_temp);
                return;  }
         } 
          
       
          
      }
            
   }
  printf("\n--- There is no solution for this time limit :( --- \n");
  //free_board(sim);
 // free_board(sim_temp);
}

 #ifdef DEBUG3
 int main (int argc, char *argv[]){
   
  printf("\n calculating ann algorithm for N = 4 and time limit 10 and s = 15 \n" );
  simulate_algorithm(4,10,15);
   
  printf("\n calculating ann algorithm for N = 6 and time limit 10 and s=15 \n" );
   simulate_algorithm(6,10,15);

  printf("\n calculating ann algorithm for N = 8 and time limit 10 and s=15\n" );
  simulate_algorithm(8,10,15);
 }
#endif
