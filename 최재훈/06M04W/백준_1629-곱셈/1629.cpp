#include <iostream>
#include <limits.h>

using namespace std;

// global
#define MAX_INPUT_DATA	2147483657 // =INT_MAX
unsigned long long answer = 1;

// method
unsigned long long  CalcMulti(int A, int B, int C);

int main()
{
	/*
	* 모듈러 성질, 지수의 법칙
	*/
	// init
	std::ios::sync_with_stdio(false);

	// input
	int A = 0;
	int B = 0;
	int C = 0;
	(void)scanf("%d %d %d", &A, &B, &C);

	// calc
	answer = CalcMulti(A, B, C);
	
	// print
	printf("%lld\n", answer);

	return 0;
}

unsigned long long CalcMulti(int A, int B, int C)
{
	if (B == 1)
		return A % C;
	
	unsigned long long value = CalcMulti(A, B / 2, C);
	if (0 != B % 2)
		return (value * value % C) * A % C;
	
	return value * value % C;
}