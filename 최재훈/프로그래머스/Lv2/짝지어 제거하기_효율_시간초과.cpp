#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(string s)
{
    int answer = -1;

    int idx = 0;
    for(;idx < s.size();)
    {
        if(0 != s.size() % 2)
            break;
        if(s[idx] == s[idx + 1])
        {
            s.erase(idx, 2);

            idx = 0;
        }
        else
            idx++;
    }

    if(true == s.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}


int main()
{
    string s = "baabaa";
    int answer = solution(s);
    printf("ans: %d\n", answer);


    return 0;
}