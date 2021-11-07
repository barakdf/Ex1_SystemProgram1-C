#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int main() {
    int a, b;
    printf("please enter the First and the Second numbers: ");
    scanf("%d %d", &a, &b);
	if (b < a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
    printf("The Armstrong numbers are:");
	for(int i = a; i <= b ; i++){
	    if (isArmstrong(i) == 1)
	    	{
		    	printf(" %d", i);
		    }
	}
	printf("\n");
    printf("The Palindromes are:");
	for(int i = a; i <= b ; i++){
	    if (isPalindrome(i) == 1)
	    	{
		    	printf(" %d", i);
		    }
	}
	printf("\n");
    printf("The Prime numbers are:");
	for(int i = a; i <= b ; i++){
	    if (isPrime(i) == TRUE)
	    	{
	    		printf(" %d", i);
		    }
	}
	printf("\n");
    printf("The Strong numbers are:");
	for(int i = a; i <= b ; i++){
	    if (isStrong(i) == TRUE)
	    	{
		    	printf(" %d", i);
		    }
	}
	printf("\n");
	return 0;
}
