#include <stdio.h>

int isArmstrong(int number) {
  
  int lastDigit = 0;
  int power = 0;
  int sum = 0;
  int n = number;

  while(n!=0) {


     lastDigit = n % 10;

     power = lastDigit*lastDigit*lastDigit;
     sum += power;

     n /= 10;
  }

  if(sum == number) return 0;
  else return 1;
}

int isPalindrome(int number){

  int temp, remainder, rev=0;

  temp = number;

  while( number!=0 ) {
 
     remainder = number % 10;

     rev = rev*10 + remainder;

     number /= 10;
  }

  if ( rev == temp ) return 0;
  else return 1;
}