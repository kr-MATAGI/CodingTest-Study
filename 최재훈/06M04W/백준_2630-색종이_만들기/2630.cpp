#include <iostream>
#include <vector>

using namespace std;

// global
int whiteCnt; // 0
int blueCnt; // 1;
vector<vector<int>> board;

enum COLOR
{
	e_White = 0,
	e_Blue = 1
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
void CalcPaperCnt(int N, POS pos);
bool AddPaperCnt(int N, POS pos, COLOR color);

int main()
{
	// init
	std::ios::sync_with_stdio(false);
	whiteCnt = 0;
	blueCnt = 0;

	// input
	int N = 0;
	(void)scanf("%d", &N);

	for (int idx = 0; idx < N; idx++)
	{
		vector<int> rowList;
		for (int jdx = 0; jdx < N; jdx++)
		{
			int data = -1;
			(void)scanf("%d", &data);
			rowList.push_back(data);
		}
		board.push_back(rowList);
	}

	// calc
	POS startPos(0, 0);
	CalcPaperCnt(N, startPos);

	// print
	printf("%d\n%d\n", whiteCnt, blueCnt);

	return 0;
}

void CalcPaperCnt(int N, POS pos)
{
	bool isWhite = false;
	bool isBlue = false;

	isWhite = AddPaperCnt(N, pos, COLOR::e_White);
	if (false == isWhite)
		isBlue = AddPaperCnt(N, pos, COLOR::e_Blue);

	if (true == isWhite || true == isBlue)
		return;

	// area - 1
	POS areaPos_1 = pos;
	CalcPaperCnt(N / 2, areaPos_1);

	// area - 2
	POS areaPos_2(pos.row, pos.col + (N / 2));
	CalcPaperCnt(N / 2, areaPos_2);

	// area - 3
	POS areaPos_3(pos.row + (N / 2), pos.col);
	CalcPaperCnt(N / 2, areaPos_3);

	// area - 4
	POS areaPos_4(pos.row + (N / 2), pos.col + (N / 2));
	CalcPaperCnt(N / 2, areaPos_4);
}

bool AddPaperCnt(int N, POS pos, COLOR color)
{
	for (int row = pos.row; row < pos.row + N; row++)
	{
		for (int col = pos.col; col < pos.col + N; col++)
		{
			if (color != static_cast<int>(board[row][col]))
				return false;
		}
	}

	if (COLOR::e_White == color)
		whiteCnt++;
	else
		blueCnt++;

	return true;
}