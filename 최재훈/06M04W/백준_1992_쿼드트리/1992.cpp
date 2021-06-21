#include <iostream>
#include <vector>
#include <string>

using namespace std;

// global
string answer;
vector<vector<int>> board;

enum QUAD
{
	e_Zero = 0,
	e_One = 1
};

struct POS
{
	POS(int _r, int _c)
		: row(_r)
		, col(_c)
	{}
	int row;
	int col;
};

// method
void CalcQuadTree(int N, POS pos);
bool IsCompress(int N, POS pos, QUAD quad);

int main()
{
	/*
	* 주어진 영상이 모두 0으로만 되어있으면 압축 결과 = 0
	*				모두 1으로만 되어있으면 압축 결과 = 1
	* 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고
	* 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 4개의 영상으로 압축하게 된다.
	* 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표시한다.
	*/
	
	// init
	std::ios::sync_with_stdio(false);

	// input
	int N = 0;
	(void)scanf("%d", &N);

	for (int idx = 0; idx < N; idx++)
	{
		vector<int> rowList;
		for (int jdx = 0; jdx < N; jdx++)
		{
			int data = 0;
			(void)scanf("%1d", &data);
			rowList.push_back(data);
		}
		board.push_back(rowList);
	}

	// calc
	answer.clear();
	POS startPos(0, 0);
	CalcQuadTree(N, startPos);

	// print
	printf("%s\n", answer.c_str());

	return 0;
}

void CalcQuadTree(int N, POS pos)
{
	bool isZero = false;
	bool isOne = false;

	isZero = IsCompress(N, pos, QUAD::e_Zero);
	if (false == isZero)
		isOne = IsCompress(N, pos, QUAD::e_One);

	if (true == isZero || true == isOne)
		return;

	// area - 1
	answer += '(';

	POS areaPos_1 = pos;
	CalcQuadTree(N / 2, areaPos_1);
	
	// area - 2
	POS areaPos_2(pos.row, pos.col + (N / 2));
	CalcQuadTree(N / 2, areaPos_2);

	// area - 3
	POS areaPos_3(pos.row + (N / 2), pos.col);
	CalcQuadTree(N / 2, areaPos_3);

	// area - 4
	POS areaPos_4(pos.row + (N / 2), pos.col + (N / 2));
	CalcQuadTree(N / 2, areaPos_4);

	answer += ')';
}

bool IsCompress(int N, POS pos, QUAD quad)
{
	for (int row = pos.row; row < pos.row + N; row++)
	{
		for (int col = pos.col; col < pos.col + N; col++)
		{
			if (quad != static_cast<QUAD>(board[row][col]))
				return false;
		}
	}

	if (QUAD::e_Zero == quad)
		answer += '0';
	else
		answer += '1';

	return true;
}