#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n);
int isArmstrong(int n);

int nth(int x)
{
    int n = 0;
    while (x != 0)
    {
        n++;
        x = x / 10;
    }
    return n;
}

double isArmstrongRec(int n, int len)
{
    if (n == 0)
    {
        return 0;
    }
    double curr = pow(n % 10, len);
    return curr + isArmstrongRec(n / 10, len);
}

int isArmstrong(int n)
{
    int len = nth(n);
    if (isArmstrongRec(n, len) == n)
    {
        return TRUE;
    }
    return FALSE;
}

int isPalindrome(int num)
{
    
    if (num == reverse(num))
    {
        return TRUE;
    }

    return FALSE;
}


int reverse(int num)
{
    int digit = (int)log10(num);

    if (num == 0)
        return 0;

    return ((num % 10 * pow(10, digit)) + reverse(num / 10));
}