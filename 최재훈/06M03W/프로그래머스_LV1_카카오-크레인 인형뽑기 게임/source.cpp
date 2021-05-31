#include <string>
#include <vector>

#define MIN_BOARD 5
#define MAX_BOARD 30

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	
	const int boardSize = board.size();
	int boardCnt[MAX_BOARD] = { 0, };


	vector<int> selectedList;
	const int movesSize = moves.size();
	for (int mIdx = 0; mIdx < movesSize; mIdx++)
	{
		const int moveVal = moves[mIdx] - 1;
		while (true)
		{
			if (boardSize - 1 < boardCnt[moveVal])
				break;
			else if (0 == board[boardCnt[moveVal]][moveVal])
				boardCnt[moveVal]++;
			else
			{
				int value = board[boardCnt[moveVal]][moveVal];
				selectedList.push_back(value);
				board[boardCnt[moveVal]][moveVal] = 0;
				break;
			}
		}
	}

	// check
	while (true)
	{
		bool boom = false;
		
		const int listSize = selectedList.size();		
		for (int idx = 0; idx < listSize; idx++)
		{
			if (idx + 1 < listSize)
			{
				if (selectedList[idx] == selectedList[idx + 1]) 
				{
					//printf("%d %d \n", selectedList[idx], selectedList[idx + 1]);
					boom = true;
					selectedList.erase(selectedList.begin() + idx);
					selectedList.erase(selectedList.begin() + idx);
					answer += 2;
					break;
				}
			}
		}

		if (false == boom)
			break;
	}
	
	//printf("%d \n", answer);

	return answer;
}


int main()
{
	vector<vector<int>> board;
	vector<int> boardInput_1 = { 0,0,0,0,0 };
	vector<int> boardInput_2 = { 0,0,1,0,3 };
	vector<int> boardInput_3 = { 0,2,5,0,1 };
	vector<int> boardInput_4 = { 4,2,4,4,2 };
	vector<int> boardInput_5 = { 3,5,1,3,1 };
	board.push_back(boardInput_1);
	board.push_back(boardInput_2);
	board.push_back(boardInput_3);
	board.push_back(boardInput_4);
	board.push_back(boardInput_5);

	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	solution(board, moves);

	return 0;
}