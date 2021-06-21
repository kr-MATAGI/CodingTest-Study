#include <iostream>
#include <vector>

using namespace std;

// global
namespace Global
{
	enum DATA
	{
		e_Minus = 0,
		e_Zero = 1,
		e_One = 2
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
}


vector<vector<Global::DATA>> board;
int answerArr[3]; // -1, 0, 1

// method
Global::DATA ConvertInput(int value);
void CalcPaperCnt(int N, Global::POS pos);
bool AddPaperCnt(int N, Global::POS pos, Global::DATA data);

int main()
{
	// init
	std::ios::sync_with_stdio(false);
	fill(answerArr, answerArr + 3, 0);

	// input
	int N = 0;
	(void)scanf("%d", &N);

	for (int idx = 0; idx < N; idx++)
	{
		vector<Global::DATA> rowList;
		for (int jdx = 0; jdx < N; jdx++)
		{
			int input = 0;
			(void)scanf("%d", &input);
			Global::DATA data = ConvertInput(input);
			rowList.push_back(data);
		}
		board.push_back(rowList);
	}

	// calc
	Global::POS startPos(0, 0);
	CalcPaperCnt(N, startPos);

	// print
	printf("%d\n%d\n%d\n", answerArr[0], answerArr[1], answerArr[2]);

	return 0;
}

Global::DATA ConvertInput(int value)
{
	if (-1 == value)
		return Global::DATA::e_Minus;
	else if (0 == value)
		return Global::DATA::e_Zero;

	return Global::DATA::e_One;
}

void CalcPaperCnt(int N, Global::POS pos)
{
	bool isMinus = false;
	bool isZero = false;
	bool isOne = false;

	isMinus = AddPaperCnt(N, pos, Global::DATA::e_Minus);
	if (false == isMinus)
		isZero = AddPaperCnt(N, pos, Global::DATA::e_Zero);
	if (false == isMinus && false == isZero)
		isOne = AddPaperCnt(N, pos, Global::DATA::e_One);

	if (true == isMinus || true == isZero || true == isOne)
		return;

	// area - 1
	Global::POS areaPos_1 = pos;
	CalcPaperCnt(N / 3, areaPos_1);

	// area - 2
	Global::POS areaPos_2(pos.row, pos.col + (N / 3));
	CalcPaperCnt(N / 3, areaPos_2);

	// area - 3
	Global::POS areaPos_3(pos.row, pos.col + (N / 3) * 2);
	CalcPaperCnt(N / 3, areaPos_3);

	// area - 4
	Global::POS areaPos_4(pos.row + (N / 3), pos.col);
	CalcPaperCnt(N / 3, areaPos_4);

	// area - 5
	Global::POS areaPos_5(pos.row + (N / 3), pos.col + (N / 3));
	CalcPaperCnt(N / 3, areaPos_5);

	// area - 6
	Global::POS areaPos_6(pos.row + (N / 3), pos.col + (N / 3) * 2);
	CalcPaperCnt(N / 3, areaPos_6);

	// area - 7
	Global::POS areaPos_7(pos.row + (N / 3) * 2, pos.col);
	CalcPaperCnt(N / 3, areaPos_7);

	// area - 8
	Global::POS areaPos_8(pos.row + (N / 3) * 2, pos.col + (N / 3));
	CalcPaperCnt(N / 3, areaPos_8);

	// area - 9
	Global::POS areaPos_9(pos.row + (N / 3) * 2, pos.col + (N / 3) * 2);
	CalcPaperCnt(N / 3, areaPos_9);
}

bool AddPaperCnt(int N, Global::POS pos, Global::DATA data)
{
	for (int row = pos.row; row < pos.row + N; row++)
	{
		for (int col = pos.col; col < pos.col + N; col++)
		{
			if (data != board[row][col])
				return false;
		}
	}

	if (Global::DATA::e_Minus == data)
		answerArr[0]++;
	else if (Global::DATA::e_Zero == data)
		answerArr[1]++;
	else
		answerArr[2]++;

	return true;
}