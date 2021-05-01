#include <string>
#include <vector>
#include <algorithm>

#define MAX_NUM 8000000000

using namespace std;

bool compare(const int& lhs, const int& rhs)
{
    return lhs > rhs;
}

long long solution(long long n) {
    long long answer = 0;

    long long div = 10000000000;
    std::vector<int> buff;
    while (0 != div)
    {
        int num = static_cast<int>(n / div);
        buff.push_back(num);
        n -= (n / div) * div;

        div /= 10;
    }

    vector<int>::iterator iter = buff.begin();
    int startIdx = 0;
    while (iter != buff.end())
    {
        if (*iter != 0)
            break;
        startIdx++;
        ++iter;
    }

    iter = buff.begin();
    for (int idx = 0; idx < startIdx; idx++)
    {
        iter = buff.erase(iter);        
    }

    std::sort(buff.begin(), buff.end(), compare);
    long long multi = 1;
    for (int idx = 0; idx < buff.size() - 1; idx++)
    {
        multi *= 10;
    }
    for (int idx = 0; idx < buff.size(); idx++)
    {
        answer += static_cast<long long>(multi * buff[idx]);
        multi /= 10;
    }

    return answer;
}


int main()
{
    long long ans = solution(118372);
    printf("\n%lld", ans);


    return 0;
}