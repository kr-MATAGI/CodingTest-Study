#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(string s)
{
    int answer = 0;

    if(0 != s.size() % 2)
        return  answer;

    vector<char> buff;
    buff.push_back(s[0]);
    s = s.substr(1);
    for(auto ch : s)
    {
        if(false == buff.empty() && buff.back() == ch)
            buff.pop_back();
        else
            buff.push_back(ch);
    }

    if(true == buff.empty())
        answer = 1;

    return answer;
}

int main()
{
    string s = "baabaa";
    int answer = solution(s);
    printf("ans: %d\n", answer);


    return 0;
}