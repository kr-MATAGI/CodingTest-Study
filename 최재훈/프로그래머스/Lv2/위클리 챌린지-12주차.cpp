#include <string>
#include <vector>

using namespace std;

vector<bool> checkVec;
int answer;

void LetsGo(int idx, vector<vector<int>>& dungeons, int k, int count)
{
    for (int nextIdx = 0; nextIdx < dungeons.size(); nextIdx++)
    {
        if (idx == nextIdx)
            continue;

        if (k >= dungeons[nextIdx][0] && k >= dungeons[nextIdx][1] &&
            false == checkVec[nextIdx] && 1 <= k - dungeons[nextIdx][1])
        {
            checkVec[nextIdx] = true;
            LetsGo(nextIdx, dungeons, k - dungeons[nextIdx][1], count + 1);
            checkVec[nextIdx] = false;
        }
    }

    if (k < dungeons[idx][0] || k < dungeons[idx][1])
    {
        answer = answer > count ? answer : count;
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;

    int dungeonsCnt = dungeons.size();
    checkVec.resize(dungeonsCnt, false);

    for (int startIdx = 0; startIdx < dungeonsCnt; startIdx++)
    {
        if (k >= dungeons[startIdx][0] && k >= dungeons[startIdx][1] &&
            false == checkVec[startIdx] && 1 <= k - dungeons[startIdx][1])
        {
            checkVec[startIdx] = true;
            LetsGo(startIdx, dungeons, k  - dungeons[startIdx][1], 1);
            checkVec[startIdx] = false;
        }
    }

    return answer;
}

int main()
{
    int k = 80;
    vector<vector<int>> dungeons = { {80, 20},
                                     {50, 40},
                                     {30, 10} };

    int answer = solution(k, dungeons);
    printf("ans: %d\n", answer);

    return 0;
}