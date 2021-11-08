# include <stdio.h>
int isPrime(int n){

    int flag=1;
        if (n<1){
            flag =0;
        }
        else if( n==1){
            flag=1;
        }
        else{
            for (int i=2; i<=n/2 && flag!=0; i++ ){
                if (n%i==0){
                    flag=0 ;
                }
            }
        }
        if (flag==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    

int isStrong(int num)
{
    int originalNum, lastDigit, sum;

    originalNum = num;

    sum = 0;

    while(num > 0)
    {

       
        lastDigit = num % 10;

        /* Find factorial of last digit */
        int fact = 1;
        for(int i=1; i<=lastDigit; i++)
        {
            fact = fact * i;
        }

        /* Add factorial to sum */
        sum = sum + fact;

        num = num / 10;
    }

    /* Check Strong number condition */
    if(sum == originalNum)
    {
       return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}

