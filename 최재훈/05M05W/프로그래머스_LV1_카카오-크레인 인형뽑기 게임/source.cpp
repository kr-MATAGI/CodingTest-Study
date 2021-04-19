#include <string>
#include <vector>

#define MIN_BOARD 5
#define MAX_BOARD 30

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<int> selectedList;
	const int arrSize = board.size();
	const int movesSize = moves.size();

	for (int mIdx = 0; mIdx < movesSize; mIdx++)
	{
		const int moveValue = moves[mIdx] - 1;
		const int backValue = board[moveValue].back();

		if (true == board[moveValue].empty() || 0 == board[moveValue].back())
			continue;

		if (0 < selectedList.size())
		{
			if (selectedList.back() == backValue)
			{
				answer++;
				selectedList.pop_back();
			}
			else
			{
				selectedList.push_back(backValue);
			}
		}
		else
		{
			selectedList.push_back(backValue);
		}
		
		board[moveValue].pop_back();
	}

	// print
	printf("%d\n", answer);

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