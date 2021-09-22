#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

// Def
#define ROW_MAX 1000
#define COL_MAX 1000

// Global
int dpArr[ROW_MAX + 1][COL_MAX + 1];
int rowSize = 0;
int colSize = 0;

int solution(vector<vector<int>> board)
{
    int answer = 0;
        
    rowSize = board.size();
    colSize = board[0].size();
    
    for (int rIdx = 0; rIdx < ROW_MAX + 1; rIdx++)
    {
        memset(dpArr[rIdx], 0, COL_MAX + 1);
    }

    for (int rIdx = 0; rIdx < rowSize; rIdx++)
    {
        for (int cIdx = 0; cIdx < colSize; cIdx++)
        {
            if (0 == rIdx || 0 == cIdx)
                dpArr[rIdx][cIdx] = board[rIdx][cIdx];
            else if(1 == board[rIdx][cIdx])
            {
                const int slopeVal = dpArr[rIdx - 1][cIdx - 1];
                const int leftVal = dpArr[rIdx][cIdx - 1];
                const int upperVal = dpArr[rIdx - 1][cIdx];

                dpArr[rIdx][cIdx] = min(slopeVal, leftVal);
                dpArr[rIdx][cIdx] = min(dpArr[rIdx][cIdx], upperVal) + 1;
            }
            else
            {
                dpArr[rIdx][cIdx] = board[rIdx][cIdx];
            }
            answer = max(answer, dpArr[rIdx][cIdx]);
        }
    }

    // Return
    return answer * answer;
}

int main()
{
	vector<vector<int>> board = {   {0,0,0,0}, 
                                    {1,0,0,0},
	                            	{0,0,0,0},
                                    {1,0,0,0} 
                                };
    int answer = solution(board);
    printf("answer : %d\n", answer);
}