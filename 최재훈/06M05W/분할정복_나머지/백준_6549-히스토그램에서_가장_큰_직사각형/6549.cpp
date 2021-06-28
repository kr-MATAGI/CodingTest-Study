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
DATA MakeTree(vector<LONG>& inputList, vector<DATA>& tree, int node, int start, int end);

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

		hList.push_back(0);
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
		MakeTree(hList, segmTree, 1, 0, N-1);
	}

	return 0;
}

DATA MakeTree(vector<LONG>& inputList, vector<DATA>& tree, int node, int start, int end)
{
	if (start == end)
	{
		/*
		* 노드가 리프 노드인 경우,
		* 배열의 원소를 가짐
		*/
		DATA leaf(0, inputList[node - 1], node-1);
		tree[node] = leaf;

		return leaf;
	}

	int mid = (start + end) / 2;

	DATA leftNode = MakeTree(inputList, tree, node * 2, start, mid);
	DATA rightNode = MakeTree(inputList, tree, node * 2 + 1, mid+1, end);

	DATA subSum;
	if (1 == rightNode.index - leftNode.index)
	{
		LONG leftSum = leftNode.sum + leftNode.data;
		LONG rightSum = rightNode.sum + rightNode.data;

		if (leftSum >= rightSum)
		{
			subSum = leftNode;
			subSum.sum = leftSum;
		}
		else
		{
			subSum = rightNode;
			subSum.sum = rightSum;
		}
	}
	else
	{
		if (leftNode.sum >= rightNode.sum)
			subSum = leftNode;
		else
			subSum = rightNode;
	}
	
	return subSum;
}