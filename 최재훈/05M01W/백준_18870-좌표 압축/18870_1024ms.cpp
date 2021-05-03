#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define N_MAX 1000000
#define X_MIN -1000000000
#define X_MAX 1000000000

// compress pair
int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// 
	int N = 0;
	(void)scanf("%d", &N);

	std::vector<int> inputList;
	std::unordered_map<int, int> compPairList;
	inputList.resize(N);
	for (int idx = 0; idx < N; idx++)
	{
		int x = 0;
		(void)scanf("%d", &x);
		inputList[idx] = x;
	}

	// sort and compress
	std::vector<int> copyList = inputList;
	std::sort(copyList.begin(), copyList.end());
	
	int value = 0;
	for (int idx = 0; idx < copyList.size(); idx++)
	{
		if (compPairList.end() == compPairList.find(copyList[idx]))
		{
			compPairList.insert(std::pair<int, int>(copyList[idx], value));
			value++;
		}
	}

	// update
	for (int idx = 0; idx < N; idx++)
	{
		inputList[idx] = compPairList[inputList[idx]];
		printf("%d ", inputList[idx]);
	}
	printf("\n");

	return 0;
}