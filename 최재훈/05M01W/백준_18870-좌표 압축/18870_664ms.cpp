#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// init
	std::ios::sync_with_stdio(false);
	

	int N = 0;
	(void)scanf("%d", &N);

	// input
	std::vector<int> inputList;
	for (int idx = 0; idx < N; idx++)
	{
		int num = 0;
		(void)scanf("%d", &num);
		inputList.push_back(num);
	}

	// 중복 제거
	std::vector<int> copyList = inputList;
	std::sort(copyList.begin(), copyList.end());
	copyList.erase(std::unique(copyList.begin(), copyList.end()), copyList.end());

	// printf
	for (int idx = 0; idx < N; idx++)
	{
		int pos = std::lower_bound(copyList.begin(), copyList.end(), inputList[idx]) - copyList.begin();
		printf("%d ", pos);
	}
	printf("\n");

	return 0;
}