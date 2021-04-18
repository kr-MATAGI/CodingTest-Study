#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX_NUM 10000001

void calcSqrtN(const int N, std::vector<int>& dest)
{
	int sqrtN = sqrt(N);
	if (1 == sqrtN)
	{
		if(1 != N)
			dest.push_back(N);

		return;
	}
	else
	{
		int diviedN = N / (int)sqrtN;
		while (true)
		{
			if (N == sqrtN * diviedN)
			{
				if (1 == sqrtN)
				{
					dest.push_back(N);
				}
				break;
			}
			else
			{
				sqrtN--;
				diviedN = N / (int)sqrtN;
			}
		}

		calcSqrtN(sqrtN, dest);
		if(N != diviedN)
			calcSqrtN(diviedN, dest);
	}
}

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	int N = 0;
	(void)scanf("%d", &N);
	
	// calc
	if (1 == N)
		return 0;
	
	std::vector<int> resultList;
	calcSqrtN(N, resultList);

	// print
	std::sort(resultList.begin(), resultList.end());
	for(int item : resultList)
	{
		printf("%d\n", item);
	}

	return 0;
}