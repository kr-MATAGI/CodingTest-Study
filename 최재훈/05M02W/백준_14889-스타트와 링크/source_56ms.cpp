#include <iostream>
#include <vector>
#include <limits.h>

#define N_MAX	20

int N;
int minValue;
bool checkArr[N_MAX + 1] = { false, };

std::vector<std::vector<int>> inputList;
std::vector<int> starTeam;
std::vector<int> linkTeam;

void calc(int index, int huCnt)
{
	if (0 == minValue)
		return;

	if (huCnt >= (N / 2))
	{
		for (int idx = 0; idx < N; idx++)
		{
			if (false == checkArr[idx])
				linkTeam.push_back(idx);
		}

		// startTeam Value
		int starTeamValue = 0;
		for (int idx = 0; idx < starTeam.size(); idx++)
		{
			const int lhs = starTeam[idx];
			for (int kdx = 0; kdx < starTeam.size(); kdx++)
			{
				if (idx == kdx)
					continue;
				
				const int rhs = starTeam[kdx];
				starTeamValue += inputList[lhs][rhs];
			}
		}

		// linkTeam Value
		int linkTeamValue = 0;
		for (int idx = 0; idx < linkTeam.size(); idx++)
		{
			const int lhs = linkTeam[idx];
			for (int kdx = 0; kdx < linkTeam.size(); kdx++)
			{
				if (idx == kdx)
					continue;

				const int rhs = linkTeam[kdx];
				linkTeamValue += inputList[lhs][rhs];
			}
		}

		int absValue = starTeamValue - linkTeamValue;
		if (0 > absValue)
			absValue *= -1;
#if 0
		if (minValue > absValue)
		{
			for(auto item : starTeam)
			{
				printf("%d ", item);
			}
			printf("---start\n");
			for (auto item : linkTeam)
			{
				printf("%d ", item);
			}
			printf("---end\n\n");
		}
#endif
		minValue = minValue < absValue ? minValue : absValue;
		linkTeam.clear();

		return;
	}

	for (int idx = index + 1; idx < N; idx++)
	{
		if (false == checkArr[idx])
		{
			checkArr[idx] = true;
			starTeam.push_back(idx);

			calc(idx, huCnt + 1);

			checkArr[idx] = false;
			starTeam.pop_back();
		}
	}
}

int main()
{
	// init
	std::ios::sync_with_stdio(false);
	minValue = INT_MAX;
	int start = 0;
	int link = 0;

	// input
	N = 0;
	(void)scanf("%d", &N);

	for (int x = 0; x < N; x++)
	{
		std::vector<int> temp;
		for (int y = 0; y < N; y++)
		{
			int input = 0;
			(void)scanf("%d", &input);
			temp.push_back(input);
		}
		inputList.push_back(temp);
	}

	calc(-1, 0);

	printf("%d\n", minValue);

	return 0;
}