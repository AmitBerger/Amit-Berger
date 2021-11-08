#include <stdio.h>  
int fact(int  n){
    if (n==0){
        return 1;
    }
    else if (n==1){
        return 1;
    }
    else{
        return n*factorial( n-1);
    }
}
int isStrong(int n)     {  
  
    int sum=0;  
    int k=n;  
    int r;  
    while(k!=0)  {  
        r=k%10;  
        int f=fact(r);  
        k=k/10;  
        sum=sum+f;  
    }  
    if(sum==n)   {  
        return 1; 
    }  
    else  {  
        return 0; 
    }  
    return 0;  
}  


int isPrime(int n){
	int flag =1;
	for (int i = 1; i <= n-1; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
 
    if (n <= 1)
        flag = 0;
 
    if (flag == 1) {
        return 1;
    }
    else {
        return 0;
    }
 
    return 0;
	}
