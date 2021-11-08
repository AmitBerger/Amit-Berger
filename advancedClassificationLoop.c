#include <stdio.h>
#include <math.h>
 
int isArmstrong(int num) {
   int originalNum, remainder, n = 0, flag;
   double result = 0.0;

   for (originalNum = num; originalNum != 0; ++n) {
      originalNum /= 10;
   }

   for (originalNum = num; originalNum != 0; originalNum /= 10) {
      remainder = originalNum % 10;

   
      result += pow(remainder, n);
   }

   if (round(result) == num)
      flag = 1;
   else
      flag = 0;
   return flag;
}

int isPalindrome(int number){

  int temp, remainder, rev=0;

  temp = number;

  while( number!=0 ) {
 
     remainder = number % 10;

     rev = rev*10 + remainder;

     number /= 10;
  }

  if ( rev == temp ) return 1;
  else return 0;
}
