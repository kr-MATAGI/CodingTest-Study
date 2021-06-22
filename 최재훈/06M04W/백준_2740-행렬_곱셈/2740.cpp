#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	vector<vector<int>> A_Matrix;
	vector<vector<int>> B_Matrix;

	// A
	int N = 0;
	int M = 0;
	(void)scanf("%d %d", &N, &M);

	for (int ndx = 0; ndx < N; ndx++)
	{
		vector<int> rowList;
		for (int mdx = 0; mdx < M; mdx++)
		{
			int input = 0;
			(void)scanf("%d", &input);
			rowList.push_back(input);
		}
		A_Matrix.push_back(rowList);
	}

	// B
	int K = 0;
	(void)scanf("%d %d", &M, &K);
	
	for (int mdx = 0; mdx < M; mdx++)
	{
		vector<int> rowList;
		for (int kdx = 0; kdx < K; kdx++)
		{
			int input = 0;
			(void)scanf("%d", &input);
			rowList.push_back(input);
		}
		B_Matrix.push_back(rowList);
	}

	// calc
	vector<vector<int>> C_Matrix;
	int cMaxRow = N;
	int cMaxCol = K;

	for (int row = 0; row < cMaxRow; row++)
	{		
		vector<int> C_RowList;
		for (int col = 0; col < cMaxCol; col++)
		{
			int C_Value = 0;
			
			auto A_RowList = A_Matrix[row];
			int bRow = 0;
			for (int A_Val : A_RowList)
			{
				C_Value += (A_Val * B_Matrix[bRow][col]);
				bRow++;
				if (M <= bRow)
					bRow = 0;
			}
			C_RowList.push_back(C_Value);
		}
		C_Matrix.push_back(C_RowList);
	}
	
	// print
	for (auto rowList : C_Matrix)
	{
		for (auto value : rowList)
			printf("%d ", value);
		printf("\n");
	}

	return 0;
}