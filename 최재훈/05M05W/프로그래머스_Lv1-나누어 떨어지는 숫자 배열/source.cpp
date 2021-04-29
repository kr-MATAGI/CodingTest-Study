#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    vector<int>::const_iterator iter = arr.begin();
    while (iter != arr.end())
    {
        if (0 == *iter % divisor)
            answer.push_back(*iter);
        ++iter;
    }

    if (true == answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}


int main()
{
    vector<int> arr = { 3,2,6 };
    int divisor = 10;
    vector<int> answer = solution(arr, divisor);
    for (auto ans : answer)
    {
        printf("%d ", ans);
    }
    
    return 0;
}