#include <iostream>
#include <deque>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 11

int N;
int operatorArr[4]; // +, -, *, /
int maxValue;
int minValue;

// method
void Calc(std::deque<int>& src, int operCnt, int value)
{
	if (N - 1 == operCnt)
	{
		maxValue = maxValue < value ? value : maxValue;
		minValue = minValue > value ? value : minValue;

		return;
	}
		
	// +
	if (0 != operatorArr[0])
	{
		operatorArr[0]--;

		int num = src.front();
		src.pop_front();
		value += num;

		int plusCnt = operCnt + 1;
		Calc(src, plusCnt, value);

		value -= num;
		src.push_front(num);

		operatorArr[0]++;
	}

	// -
	if (0 != operatorArr[1])
	{
		operatorArr[1]--;

		int num = src.front();
		src.pop_front();
		value -= num;

		int plusCnt = operCnt + 1;
		Calc(src, plusCnt, value);

		value += num;
		src.push_front(num);

		operatorArr[1]++;
	}

	// *
	if (0 != operatorArr[2])
	{
		operatorArr[2]--;

		int num = src.front();
		src.pop_front();
		value *= num;

		int plusCnt = operCnt + 1;
		Calc(src, plusCnt, value);

		value /= num;
		src.push_front(num);

		operatorArr[2]++;
	}

	// /
	if (0 != operatorArr[3])
	{
		operatorArr[3]--;

		int num = src.front();
		src.pop_front();
		value /= num;

		int plusCnt = operCnt + 1;
		Calc(src, plusCnt, value);

		value *= num;
		src.push_front(num);

		operatorArr[3]++;
	}	
}

int main()
{
	// init
	std::ios::sync_with_stdio(false);
	memset(operatorArr, 0, sizeof(4));
	maxValue = INT_MIN;
	minValue = INT_MAX;

	// input
	N = 0;
	(void)scanf("%d", &N);

	std::deque<int> numList;
	for (int n = 0; n < N; n++)
	{
		int input = 0;
		(void)scanf("%d", &input);
		numList.push_back(input);
	}

	for (int idx = 0; idx < 4; idx++)
	{
		int input = 0;
		(void)scanf("%d", &input);
		operatorArr[idx] = input;
	}

	// Calc
	int startNum = numList.front();
	numList.pop_front();
	Calc(numList, 0, startNum);

	// print
	printf("%d\n%d", maxValue, minValue);

	return 0;
}