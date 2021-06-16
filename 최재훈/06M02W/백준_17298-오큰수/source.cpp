#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	// input
	int N = 0;
	(void)scanf("%d", &N);

	vector<int> inputList;
	for (int ndx = 0; ndx < N; ndx++)
	{
		int data = 0;
		if (ndx != N - 1)
			(void)scanf("%d ", &data);
		else
			(void)scanf("%d", &data);

		inputList.push_back(data);
	}

	// calc
	vector<int> stack;
	stack.push_back(0);
	vector<int> answerList;
	answerList.resize(N, -1);
	for (int idx = 1; idx < N; idx++)
	{
		while (false == stack.empty() && inputList[stack.back()] < inputList[idx])
		{
			answerList[stack.back()] = inputList[idx];
			stack.pop_back();
		}
		stack.push_back(idx);
	}
	while (false == stack.empty())
	{
		answerList[stack.back()] = -1;
		stack.pop_back();
	}

	// print
	for (int idx = 0; idx < answerList.size(); idx++)
		printf("%d ", answerList[idx]);

	return 0;
}