/*
* Lv2 - 카카오 프렌즈 컬러링북
* 0은 색칠하지 않음
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

// Def
#define PIC_MAX 2147483647
#define AREA_MIN   1
#define AREA_MAX   100

typedef std::pair<int, int> POS;

// Global
int number_of_area;
int max_size_of_one_area;
bool visitedArr[AREA_MAX + 1][AREA_MAX + 1];
int currM;
int currN;

// Method
void BFS(vector<vector<int>>& picture, int row, int col, int &currSize)
{
    currSize += 1;

    queue<POS> bfsQue;
    vector<vector<int>> directArr = { // (row, col)
        {0, -1}, // left
        {-1, 0}, // up
        {0, 1}, // right
        {1, 0} // bottom
    };

    for (int idx = 0; idx < 4; idx++)
    {
        int nextRow = row + directArr[idx][0];
        int nextCol = col + directArr[idx][1];

        if (0 > nextRow || currM <= nextRow)
            continue;
        if (0 > nextCol || currN <= nextCol)
            continue;

        if (false == visitedArr[nextRow][nextCol] &&
            picture[row][col] == picture[nextRow][nextCol])
        {
            visitedArr[nextRow][nextCol] = true;
            bfsQue.push(POS(nextRow, nextCol));
        }
    }

    while (false == bfsQue.empty())
    {
        POS pos = bfsQue.front();
        bfsQue.pop();

        BFS(picture, pos.first, pos.second, currSize);
    }

    max_size_of_one_area = max(max_size_of_one_area, currSize);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // init
    vector<int> answer(2);
    
    number_of_area = 0;
    max_size_of_one_area = 0;

    currM = m;
    currN = n;

    for (int rIdx = 0; rIdx < AREA_MAX + 1; rIdx++)
    {
        memset(visitedArr[rIdx], false, AREA_MAX + 1);
    }

    for (int rIdx = 0; rIdx < m; rIdx++)
    {
        for (int cIdx = 0; cIdx < n; cIdx++)
        {
            if (0 == picture[rIdx][cIdx] || true == visitedArr[rIdx][cIdx])
                continue;

            int currSize = 0;
            visitedArr[rIdx][cIdx] = true;
            BFS(picture, rIdx, cIdx, currSize);
            number_of_area += 1;
        }
    }

    // return
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = { 
        {1, 1, 1, 0}, 
        {1, 2, 2, 0}, 
        {1, 0, 0, 1}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 3}, 
        {0, 0, 0, 3} 
    };

    vector<vector<int>> picture2 = { 
        {1, 1, 1, 0}, 
        {1, 1, 1, 0}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 1} 
    };

    vector<int> answer = solution(m, n, picture);
    printf("answer: %d %d\n", answer[0], answer[1]);
}