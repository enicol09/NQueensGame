/** @file nQueens.c
 *  @brief This is the main .c file , that implements 
 *  homework_3. 
 * 
 *  The program is based on the nqueens problem.The program can call and perform the following functions / different algorithms in order to 
 *  try  solve the n-queens problem
 *  Algorithm 1: Unsupervised Depth Search Algorithm (DFS)
 *  Algorithm 2: Stochastic Hill Climbing Algorithm with Reboots (HILL)
 *  Algorithm 3: Stochastic Simulated Annealing Algorithm (SIMULATE)
 *  It use the functions of 4 different other header files. 
 *   
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see DFS.c hill.c simulate.c check.c
 *  @see DFS.h hill.h simulate.h check.h
 */

//define and include libraries
#include "board.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"
#include "hill.h"
#include "simulate.h"
#include "check.h"
#include <time.h>

//Main function of the program
int main (int argc, char *argv[]) {

char *algorithm; //name of the algorithm
char *N; //board size
char *L; //maxtime
char *S; //seed
int n,l,s;
unsigned s1;

 if(argc < 5) { //if the given arguments are less than the ones we want print error
  print_er();
   return 0;
    }
 else if(argc == 6 ){
   print_er();
   return 0;
    }
 else if(argc > 7 ) { //if the given arguments are more than the ones we want print error
   print_er(); 
   return 0;
   }

 else if(argc == 5 ) { //if the given arguments are the ones we want

  //checking things (using check.h)
  if(strcmp(argv[1],"maxtime")==0){
      algorithm = argv[3];
      N = argv[4];
      L = argv[2];
  } 
  else if ( (strcmp(argv[1],"dfs")==0) || (strcmp(argv[1],"hill")==0) || (strcmp(argv[1],"ann")==0)){
  algorithm = argv[1];
  N = argv[2];
  L = argv[4];
  
  }
  else{
   print_er();
   return 0;
    }

  s1 = time(NULL);
 // printf("%d" ,s1);
  printf("\n Algorithm = %s , N = %s , Maxtime = %s \n " , algorithm, N , L);

   if(is_it_number(N)==false || is_it_number(L)==false){
   print_er();
   return 0;
 } 
  
  n = cast_number(N);
  l = cast_number(L);

  //check for dfs algorithm 



  if(strcmp(algorithm,"dfs")==0){
    if( n <= 3 && n!=1){
   printf( "\n -- There is not any solution :( -- \n" );
     return 0;
  }
 
   
   dfs_algorithm(n,l);
  
} 

 //check for hill algorithm
 else if(strcmp(algorithm,"hill")==0){
   if( n <= 3 && n!=1){
   printf( "\n -- There is not any solution :( -- \n" );
     return 0;
  }
    hill_algorithm(n,l,s1);
  } 

 //check for ann algorithm
 else if ((strcmp(algorithm,"ann")==0)){
     if( n <= 3 && n!=1){
      printf( "\n -- There is not any solution :( -- \n" );
        return 0;
      }
     simulate_algorithm(n,l,s1);
   }

 //if the algorithm name is not valid print error
 else{ 
     print_er(); }
   return 0;
  }

 else if(argc == 7 ) { //only for ann and hill algorithm ( case for given seed )
 

 if(strcmp(argv[1],"maxtime")==0){
      L = argv[2];
      if(strcmp(argv[3],"seed")==0){
         S = argv[4];
         algorithm = argv[5];
         N = argv[6];

       if ( (strcmp(argv[5],"dfs")==0) || (strcmp(argv[5],"hill")==0) || (strcmp(argv[5],"ann")==0)){
         algorithm = argv[5];
         N = argv[6];
         }
      else{
         print_er();
         return 0;
       }
     }
     else if ( (strcmp(argv[3],"dfs")==0) || (strcmp(argv[3],"hill")==0) || (strcmp(argv[3],"ann")==0)){
       algorithm = argv[3];
       N = argv[4];
       
       if((strcmp(argv[5],"seed")==0)){
       S = argv[5]; }
       else{
        print_er();
        return 0;
      }
    }
    else{
     print_er();
     return 0;
    }
  }
     
      else if ( (strcmp(argv[1],"dfs")==0) || (strcmp(argv[1],"hill")==0) || (strcmp(argv[1],"ann")==0)){
        algorithm = argv[1];
        N = argv[2];
        
        if(strcmp(argv[3],"seed")==0){
         S = argv[4];
         if(strcmp(argv[5],"maxtime")==0){
           L = argv[6];}
         else{
            print_er();
         return 0; }
       }
     
      else if(strcmp(argv[3],"maxtime")==0){
         L=argv[4];
          if(strcmp(argv[5],"seed")==0){
           S = argv[6];}
         else{
            print_er();
         return 0; }
       }
        else{
         print_er();
         return 0; }
     }

      else if(strcmp(argv[1],"seed")==0){
      S = argv[2];
      if(strcmp(argv[3],"maxtime")==0){
         L = argv[4];
         algorithm = argv[5];
         N = argv[6];

       if ( (strcmp(argv[5],"dfs")==0) || (strcmp(argv[5],"hill")==0) || (strcmp(argv[5],"ann")==0)){
         algorithm = argv[5];
         N = argv[6];
         }
       else{
         print_er();
         return 0;
       }
     }
     else if ( (strcmp(argv[3],"dfs")==0) || (strcmp(argv[3],"hill")==0) || (strcmp(argv[3],"ann")==0)){
       algorithm = argv[3];
       N = argv[4];
       
       if((strcmp(argv[5],"maxtime")==0)){
       L = argv[5]; }
       else{
        print_er();
        return 0;
      }
    }
    else{
     print_er();
     return 0;
    }
  }
    else{
     print_er();
     return 0;
    }

 
  
  //checking things
  if(is_it_number(N)==false || is_it_number(L)==false || is_it_number(S)==false){
   print_er();
   return 0;
 } 

  n = cast_number(N);
  l = cast_number(L);
  s = cast_number(S);
  
  s1 = (unsigned)s;
  //printf("%d" ,s1);

   printf("\n Algorithm = %s , N = %s , Maxtime = %s , Seed = %s \n" , algorithm, N , L , S);
 //hill algorithm 
 
 if(strcmp(algorithm,"hill")==0){
    if( n <= 3 && n!=1){
   printf( "\n -- There is not any solution :( -- \n" );
     return 0;
      }
    hill_algorithm(n,l,s1);
  }
 
 //simulate algorithm
 else if ((strcmp(algorithm,"ann")==0)){
      if( n <= 3 && n!=1){
   printf( "\n -- There is not any solution :( -- \n" );
      return 0;
  }
     simulate_algorithm(n,l,s1);
   }

 //print error for not valid algorithm
 else{
   print_er(); }
   return 0;
  }
 return 0;
}
