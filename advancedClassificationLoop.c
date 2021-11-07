#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n);
int isArmstrong(int n);

int nth(int x) {
    int n = 0;
    while(x != 0){
        n++;
        x = x / 10;
    }
    return n;
}

int isArmstrong(int n) {
    int temp = n;
    int sum = 0;
    int len = nth(n);
    while (temp != 0) {
        int s = temp % 10;
        sum += pow(s, len);
        temp = temp / 10;
    }
    if(sum == n) {
        return 1;
    }
    return 0;
 }

int isPalindrome(int n) {
    int r,temp;
    int sum = 0;
    temp=n;    
    while(n>0)    
    {    
        r=n%10;    
        sum=(sum*10)+r;    
        n=n/10;    
    }    
    if(temp==sum)    
        return 1;    
    else     
        return 0;  
}