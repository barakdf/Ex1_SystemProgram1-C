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



double isArmstrongRec(int n, int len){
    if (n == 0) {
        return 0;
    }
    double curr = pow(n%10, len);
    return curr + isArmstrongRec(n/10,len);
}

int isArmstrong(int n) {
    int len = nth(n);
    if(isArmstrongRec(n,len) == n) {
        return 1;
    }
    return 0;
}

int isPalindrome(int n) {
    if (n < 10) {
        return 1;
    }
    int len = 0;
    int temp = n;
    while(temp != 0) {
        len++;
        temp = temp/10;
    }
    if ((int) (n/pow(10,len-1)) != (n%10)) {
        return 0;
    }
    return isPalindrome((n%(int)pow(10,len-1))/10);
}