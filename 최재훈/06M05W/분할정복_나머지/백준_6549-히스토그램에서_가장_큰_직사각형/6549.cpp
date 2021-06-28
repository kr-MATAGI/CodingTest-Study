#include <iostream>
#include <vector>

using namespace std;

// global
typedef long long LONG;

struct DATA
{
	DATA(LONG _sum = 0, LONG _data = 0, LONG _idx = 0)
		: sum(_sum)
		, data(_data)
		, index(_idx)
	{
	}
	LONG sum;
	LONG data;
	int index;
};

// method
long long MakeTree(vector<LONG>& inputList, vector<DATA>& tree, int node, int start, int end);

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	while (true)
	{
		int N = 0; // 직사각형의 수
		(void)scanf("%d", &N);

		if (0 == N)
			break;

		vector<LONG> hList;
		vector<DATA> segmTree;
		for (int n = 0; n < N; n++)
		{
			LONG hData = 0;
			(void)scanf("%lld", &hData);
			hList.push_back(hData);
		}

		// set tree size
		int segH = (int)ceil(log2(N));
		int treeSize = (1 << (segH + 1));
		segmTree.resize(treeSize);

		// make tree
		MakeTree(hList, segmTree, 0, 0, N-1);
	}

	return 0;
}

long long MakeTree(vector<LONG>& inputList, vector<DATA>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = inputList[start];

	int mid = (start + end) / 2;

	return inputList[node] = MakeTree(inputList, tree, node * 2, start, mid)
		+ MakeTree(inputList, tree, node * 2 + 1, mid + 1, end);
}