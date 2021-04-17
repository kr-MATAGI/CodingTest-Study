#include <iostream>
#include <vector>

#define MAX_NUM 10000001

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
	int diviedNum = 2;
	while (true)
	{
		if (1 == N)
		{
			break;
		}
		else if (0 == N % diviedNum)
		{
			N /= diviedNum;
			resultList.push_back(diviedNum);
			diviedNum = 2;
		}
		else
		{
			diviedNum++;
		}
	}


	for(int item : resultList)
	{
		printf("%d\n", item);
	}

	return 0;
}