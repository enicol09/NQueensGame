/** @file check.c
 *  @brief This is a c file that helps in the implementation of Hw_3
 *        and is based on the header file  : check.h , so you can see 
 *        all function drives in the header file check.h
 *       
 *  This file implements different functions that help with the check of different input values in the main function.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 */

//define and include libraries
#include "check.h"
#include <stdbool.h>

/** @brief This function is just prints an error message.
 * 
 * @return void should return nothing
 */
void print_er() {
  printf("\n -- We are expecting different arguments in order to implement the problem -- \n");
}

/** @brief This function is being used for checking if a given string(char *s)
 *  is numeric.
 *  
 * @param  s the given string
 * @return true if it is numeric and false if it's not
 */
bool is_it_number(char * s) {
  int n = strlen(s);
  int i = 0;
  for (i = 0; i < n; i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
      return false;
  }
  return true;
}

/** @brief This function is being used for casting a given string(char *s)
 *  to its numeric value.
 *  
 * @param  s the given string
 * @return numeric value
 */
int cast_number(char * s) {
  int i, n = 0;
  if (strlen(s) == 1) {
    for (i = 0; i < strlen(s); i++) {
      n += (s[i] - '0');
    }
    return n;
  } else {
    char c;
    int digit, number = 0;
    for (i = 0; i < strlen(s); i++) {
      c = s[i];
      digit = c - '0';
      number = number * 10 + digit;
    }
    return number;
  }
}

#ifdef DEBUG5
 int main (int argc, char *argv[]){

   printf("\n Just printing the error message" ); 
   print_er();

   char *a;
   
   a="76";
   
   printf("\n shows if the given char is numeric = > should return true" );
    if(is_it_number(a)){
     printf("true");
   } else {
    printf("\n == false \n "); }
 
   printf("\n shows if the given char is numeric = > should return false" );
   a="elia";
    if(is_it_number(a)){
     printf("true");
   } else {
    printf("\n == false \n "); }

    printf("\n cast a char into a integer / should print 297 \n" );
   
    a="\n 297 \n";
    
    printf("%d",cast_number(a));
   


  return 0;
 }
#endif
