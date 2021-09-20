#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// define
#define MAX_SIZE 100000
#define COL_MAX 4

// global
int dpArray[MAX_SIZE][COL_MAX] = { 0, };

// solution
int solution(vector<vector<int>> land)
{
	int retValue = 0;

	// init
	for (int cIdx = 0; cIdx < COL_MAX; cIdx++)
		dpArray[0][cIdx] = land[0][cIdx];
	
	for (int rIdx = 1; rIdx < land.size(); rIdx++)
	{
		for (int cIdx = 0; cIdx < COL_MAX; cIdx++)
		{
			for (int nextIdx = 0; nextIdx < COL_MAX; nextIdx++)
			{
				if (cIdx == nextIdx)
					continue;
				
				const int calculateVal = dpArray[rIdx - 1][nextIdx] + land[rIdx][cIdx];
				dpArray[rIdx][cIdx] = dpArray[rIdx][cIdx] < calculateVal ? calculateVal : dpArray[rIdx][cIdx];
			}
		}
	}

	// Get Max value
	for (int idx = 0; idx < 4; idx++)
		retValue = retValue < dpArray[land.size() - 1][idx] ?
		dpArray[land.size() - 1][idx] : retValue;

	return retValue;
}


// main
int main() 
{
	vector<vector<int>> land = { {1,2,3,5}, {5,6,7,8}, {4,3,2,1} };
	const int answer = solution(land);

	printf("answer : %d\n", answer);
}