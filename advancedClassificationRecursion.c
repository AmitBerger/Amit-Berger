#include <stdio.h>

int  isPalindrome(int n){
    static int sum = 0;
    if(n != 0)
    {
        sum = sum *10 + n%10;
         isPalindrome(n/10);   
    }
    else if(sum == n)
        return 1;
    else
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
