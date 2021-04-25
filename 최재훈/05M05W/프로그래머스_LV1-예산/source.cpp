#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    const int dSize = d.size();
    for (int lhs = 0; lhs < dSize; lhs++)
    {
        for (int rhs = 0; rhs < dSize; rhs++)
        {
            if (lhs == rhs)
                continue;

            int& lhsVal = d[lhs];
            int& rhsVal = d[rhs];

            if (lhsVal < rhsVal)
            {
                int temp = lhsVal;
                lhsVal = rhsVal;
                rhsVal = temp;
            }
        }
    }

    int sum = 0;
    int cnt = 0;
    for (int idx = 0; idx < dSize; idx++)
    {
        int checkVal = sum + d[idx];
        if (checkVal > budget)
        {
            break;
        }
        else
        {
            sum = checkVal;
            cnt++;
        }
    }
    answer = cnt;

    return answer;
}

int main()
{
    vector<int> d = {1,3,2,5,4};
    int budget = 9;
    int ans = solution(d, budget);
    printf("%d\n", ans);

    return 0;
}