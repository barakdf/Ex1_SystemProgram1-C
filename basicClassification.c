#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int x);
int isStrong(int x);

int isPrime(int x)
{
	if (x == 1)
	{
		return TRUE;
	}

	if (x <= 0)
	{
		return FALSE;
	}

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

unsigned long long fact(int n)
{

	unsigned long long dfact = 1;

	for (int i = 2; i <= n; i++)
	{
		dfact *= i;
	}
	return dfact;
}

int isStrong(int x)
{
	if (x <= 0)
	{
		return FALSE;
	}
	int temp = x;
	int sum = 0;
	while (temp != 0)
	{
		int curr = temp % 10;
		sum += fact(curr);
		temp = temp / 10;
	}
	if (sum == x)
	{
		return TRUE;
	}
	return FALSE;
}