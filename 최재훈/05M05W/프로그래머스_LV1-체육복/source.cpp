#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int>::iterator lostIter = lost.begin();
    for (; lostIter != lost.end(); )
    {
        const int value = *lostIter;

        vector<int>::iterator sameIter = std::find(reserve.begin(), reserve.end(), value);
        if (reserve.end() != sameIter)
        {
            // 자신꺼 도난당함
            lostIter = lost.erase(lostIter);
            reserve.erase(sameIter);
        }
        else
            ++lostIter;
    }

    lostIter = lost.begin();
    for (; lostIter != lost.end(); )
    {
        const int value = *lostIter;

        vector<int>::iterator plusIter = std::find(reserve.begin(), reserve.end(), value + 1);
        vector<int>::iterator minusIter = std::find(reserve.begin(), reserve.end(), value - 1);

        if (reserve.end() != plusIter)
        {
            lostIter = lost.erase(lostIter);
            reserve.erase(plusIter);
        }
        else if (reserve.end() != minusIter)
        {
            lostIter = lost.erase(lostIter);
            reserve.erase(minusIter);
        }
        else
            ++lostIter;
    }

    answer = n - lost.size();

    return answer;
}

int main()
{
    int n = 3;
    vector<int> lost = { 1,2 };
    vector<int> reserve = { 1,2 };

    int answer = solution(n, lost, reserve);
    printf("ans: %d\n", answer);

    return 0;
}