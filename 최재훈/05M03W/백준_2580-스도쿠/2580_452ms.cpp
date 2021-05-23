#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> inputList;

typedef pair<int, int> ZERO_POS;
deque<ZERO_POS> zeroPosList;

// debug
#define debug_m 0

// method
void Print();
void Sudoku(int x, int y);
bool CheckV(int x, int y, int value);
bool CheckH(int x, int y, int value);
bool CheckNemo(int x, int y, int value);

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	for (int x = 0; x < 9; x++)
	{
		vector<int> tempList;
		for (int y = 0; y < 9; y++)
		{
			int input = 0;
			(void)scanf("%d", &input);

			if (0 == input)
			{
				ZERO_POS zeroPos(x, y);
				zeroPosList.push_back(zeroPos);
			}

			tempList.push_back(input);
		}
		inputList.push_back(tempList);
	}

	// Calc
	ZERO_POS startPos = zeroPosList.front();
	zeroPosList.pop_front();
	Sudoku(startPos.first, startPos.second);

	// print
	Print();

	return 0;
}

void Print()
{
#if debug_m
	printf("\n");
#endif

	// Print
	for (auto x : inputList)
	{
		for (auto y : x)
			printf("%d ", y);
		printf("\n");
	}

}

void Sudoku(int x, int y)
{
	for (int value = 1; value <= 9; value++)
	{
		const bool isOkH = CheckH(x, y, value);
		if (false == isOkH)
			continue;

		const bool isOkV = CheckV(x, y, value);
		if (false == isOkV)
			continue;

		const bool isOkNemo = CheckNemo(x, y, value);
		if (false == isOkNemo)
			continue;
		else
		{
			inputList[x][y] = value;

#if debug_m
			Print();
#endif

			// stop
			if (true == zeroPosList.empty())
				return;

			// next
			ZERO_POS nextZeroPos = zeroPosList.front();
			zeroPosList.pop_front();

			Sudoku(nextZeroPos.first, nextZeroPos.second);

			// stop
			if (true == zeroPosList.empty())
				return;

			zeroPosList.push_front(nextZeroPos);
			inputList[x][y] = 0;
		}
	}
}

bool CheckV(int x, int y, int value)
{
	bool numCheck[10] = { false, };

	for (int idx = 0; idx < 9; idx++)
	{
		if (x == idx)
			continue;

		const int arrVal = inputList[idx][y];
		if (false == numCheck[arrVal])
		{
			numCheck[arrVal] = true;
		}
	}

	if (true == numCheck[value])
		return false;

	return true;
}

bool CheckH(int x, int y, int value)
{
	bool numCheck[10] = { false, };

	for (int idx = 0; idx < 9; idx++)
	{
		if (y == idx)
			continue;

		const int arrVal = inputList[x][idx];
		if (false == numCheck[arrVal])
		{
			numCheck[arrVal] = true;
		}
	}

	if (true == numCheck[value])
		return false;

	return true;
}

bool CheckNemo(int x, int y, int value)
{
	bool numCheck[10] = { false , };

	int nemoX = 0;
	int nemoY = 0;

	if (0 <= x && 2 >= x)
		nemoX = 0;
	else if (3 <= x && 5 >= x)
		nemoX = 3;
	else
		nemoX = 6;

	if (0 <= y && 2 >= y)
		nemoY = 0;
	else if (3 <= y && 5 >= y)
		nemoY = 3;
	else
		nemoY = 6;

	for (int startX = nemoX; startX < nemoX + 3; startX++)
	{
		for (int startY = nemoY; startY < nemoY + 3; startY++)
		{
			if (x == startX && y == startY)
				continue;

			const int arrVal = inputList[startX][startY];
			if (false == numCheck[arrVal])
				numCheck[arrVal] = true;
		}
	}

	if (true == numCheck[value])
		return false;

	return true;
}