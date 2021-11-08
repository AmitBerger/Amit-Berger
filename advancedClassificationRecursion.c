#include <stdio.h>


int reverse(int num)
{
    /* Find number of digits in num */
    int digit = (int)log10(num);
    
    /* Recursion base condition */
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}
int isPalindrome(int num){
    
    if(num == reverse(num))
    {
        return 1;
    }
    
    return 0;
}




int power(int base, int exp){
	int result=base;
for(int i=0; i<exp-1;i++){
	result=result*base;
	}
return result;
}
int  isArmstrongRec(int n, int ans, int temp,int times,int Digits){
	int k =0;
	if(times==Digits){
		if(ans==n){
			return 1;
		}
		else {return 0;}
	}
		else{
			times=times+1;
			k=temp%10;
			temp=temp/10;
			ans=ans+power(k,Digits);
			return isArmstrongRec(n, ans,temp, times,Digits);
	}
}


int isArmstrong(int n) {
	int Digits =0;
	int temp =n;
	int answer =0;
	while (temp>=1){
		temp=temp/10;
		Digits=Digits+1;
	}
	temp =n;
	return isArmstrongRec(n, answer, temp,0,Digits);
	
}
