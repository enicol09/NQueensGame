/** @file board.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : board.h , so you can see 
 *        all function drives in the header file board.h
 *       
 *  This file implements different functions for the operations of 
 *  a Board type struct.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 */

//using header file "board.h"
#include "board.h"
#include <time.h>

/** @brief This function is being used for creating a new game board.
 *  
 * This function creates a  type Board based on a given size.
 * 
 * @param  b the Board that we are going to create
 * @param  N the size of the board

 * @return b the board that we have create.
 */
Board create_board(Board b, int N) {

   int i, j;
   b.N = N;

   b.board = (char ** ) malloc(N * sizeof(char * ));
   if(b.board == NULL){ 
      printf("System out of memory! \n");
     exit(-1);}
   for (i = 0; i < N; i++) {
      b.board[i] = malloc(N * sizeof(char * ));
      if(b.board[i] == NULL){ 
         printf("System out of memory! \n");
         exit(-1);
      }
      for (j = 0; j < N; j++) {
         b.board[i][j] = '/';
      }
   }


   return b;
}

/** @brief This function generate a different board. 
 *  This board has one queen in every line but in a random collumn.
 *  
 * @param  b is the new board tha we want to create.
 * @param  N is the size of the board , and the number of the queens 
 * @param  S the seed for srand(). 
 *
 * @return the new generated board
 */
Board generate_board(Board b, int N,unsigned S) {
   int i;
   b = create_board(b, N);
 
   for (i = 0; i < N; i++) {
      int num = (rand() % N);
      b.board[i][num] = 'Q';
      //printf("%d  ", num);
   }
   return b;
}

/** @brief This function give the number of conflicts in a board.
 *  
 * @param  hill the board that we want to check the conflicts
 * @param  N the size of the board
 *
 * @return cnt the number of conflicts
 */
int how_many_blocks(Board hill, int N) {

   int cnt = 0;
   int i, j;

   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
         if (hill.board[i][j] == 'Q') {
            cnt += isSafe_hill(hill, i, j);

         }
      }
   }

   if (cnt == 0)
      return 0;
   else
      return cnt;

}

/** @brief This function change the position of a queen in a given row 
 * to a different column. 
 *  
 * @param  b the board that we want to change the queen
 * @param  row the i of the queen
 * @param  col the j of the queen
 *
 * @return cnt the number of conflicts
 */
Board change_queen(Board b, int row, int col) {
 

   Board temp;
   int j;
   temp = clone(b, b.N);
   //free(b);
   for (j = 0; j < temp.N; j++) {
      if (temp.board[row][j] == 'Q') {
         temp.board[row][j] = '/';
      }
   }

   temp.board[row][col] = 'Q';
   return temp;
}

/** @brief This function prints a given Board.
 *  
 * @param  b the Board that we are going to create
 * @param  N the size of the board

 * @return void should return nothing
 */
void print_board(const Board b, int N) {
  

   int i, j;
   for (i = 0; i < N; i++) {
      for (j = 0; j < 4; j++){
        if(i==0 && j == 0){
         printf("   -"); }
         else{
         printf("-");} }
   }

   for (i = 0; i < N; i++) {
      printf("\n");
      for (j = 0; j < N; j++) {
         if (j == N - 1) {
            printf("| %c |", b.board[i][j]);
         } 
         else if ( j==0 ){
           printf("  | %c ", b.board[i][j]);
          }else {
            printf("| %c ", b.board[i][j]);
         }
      }
   }
   printf("\n");
    for (i = 0; i < N; i++) {
      for (j = 0; j < 4; j++){
        if(i==0 && j == 0){
         printf("   -"); }
         else{
         printf("-");} }
   }

}


/** @brief This function adds a Queen(char 'Q') in a given position of the board.
 *  
 * @param  b the Board that we are going to add the queen
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen
 *
 * @return the Board with the new queen
 */
Board add_queen(const Board b, int x, int y) {
  
   Board temp;
   temp = clone(b,b.N);
   
      temp.board[x][y] = 'Q';
         

   return temp;
}


/** @brief This function makes a clone of a given Board.
 *  
 * @param  b the Board that we are going to make a clone of it.
 * @param  N the size of the board
 *
 * @return the clone Board
 */
Board clone(const Board b, int N) {
 
   Board temp;
   int i, j;
   temp = create_board(temp, b.N);
   for (i = 0; i < b.N; i++) {
      for (j = 0; j < b.N; j++) {
         if (temp.board[i][j] != b.board[i][j]) {
            temp.board[i][j] = 'Q';
         }
      }
   }

   return temp;

}

/** @brief This function checks if the new given position of the queen is going 
 *         to make any conflicts.
 *  
 * @param   kid the Board that we check.
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen 
 *
 * @return true if there aren't any conflicts and false if there are
 */
bool isSafe(const Board kid, int x, int y) {

   int i, j;

   for (i = 0; i < kid.N; i++) {
      for (j = 0; j < kid.N; j++) {
         if (i != x || j != y) {
            if (kid.board[i][j] == 'Q') {
               if (i == x) {
                  return false;
               }
               if (j == y) {
                  return false;
               }
               if (abs((i - x)) == abs((j - y))) {
                  return false;
               }

            }
         }
      }
   }
   return true;

}
/** @brief This function checks if the new given position of the queen is going 
 *         to make any conflicts and also count them. It's based in the content of algorithm 2 - hill.
 *  
 * @param   kid the Board that we check.
 * @param  x the i position of the queen
 * @param  y the j postion of  the queen 
 *
 * @return the number of the conflicts.
 */
 int isSafe_hill(const Board kid, int x, int y) {

   int i, j;
   int cnt = 0;
   for (i = 0; i < kid.N; i++) {
      for (j = 0; j < kid.N; j++) {
         if (i != x || j != y) {
            if (kid.board[i][j] == 'Q') {
               if (i == x) {
                  cnt++;
               }
               if (j == y) {
                  cnt++;
               }
               if (abs((i - x)) == abs((j - y))) {
                  cnt++;
               }

            }
         }
      }
   }
   return cnt;

}

/** @brief This function free the dynamic allocated arrays of a struc Board
 *  
 * @param  b the Board that we want to free.
 *
 * @return void
 */
void free_board(Board b){
 
  int i;
  for(i=0;i< b.N ; i++){
     free((b.board[i]));
  }
  
  free(b.board);
 }

/** @brief This function checks if all the queens that we want ( n queens) 
 *         are in the board.
 *  
 * @param  b the Board that we want to check.
 *
 * @return true if all the queens are in it , and false if they are not
 */
bool allqueens(const Board kid) {

   int cnt = 0;
   int i, j;

   for (i = 0; i < kid.N; i++) {
      for (j = 0; j < kid.N; j++) {
         if (kid.board[i][j] == 'Q') {
            cnt++;
         }
      }
   }

   if (cnt == kid.N)
      return true;
   return false;

}

 #ifdef DEBUG
 int main (int argc, char *argv[]){
    //creation of board
   //example 1
   Board c;
   
   //N=10 for checking reasons
   printf("\n creating a board of size 10 and print it \n" ); 

   c = create_board(c,10);

  print_board(c,10); 
   
   printf("\n adding a queen in position 0,1 \n" ); 

   c = add_queen(c,0,1);

   print_board(c,10); 

   printf("\n changing the position of the queen in position 1,2 \n" );  

   c=change_queen(c,0,2);

   print_board(c,10);   
  
   printf("\n make a clone of the board c \n" );  
  
   Board b;
   
   b = clone(c,10);

   print_board(b,10); 
   
   printf("\n checking if adding a queen in a position can create any conflicts - should return false \n" ); 

   if(isSafe(b,0,1)){
     printf("true");
   } else {
    printf("\n == false \n "); }
   
     printf("\n checking how many conflicts there are  - should return 0\n" );

     printf(" == %d " , isSafe_hill(b,1,0)); 
     
     printf("\n free board b and c\n" );
     free_board(c);
     free_board(b);

    return 0;
 }
  #endif

