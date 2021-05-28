#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for (int lhs = 0; lhs < strings.size(); lhs++)
    {
        for (int rhs = lhs + 1; rhs < strings.size(); rhs++)
        {
            if (lhs == rhs)
                continue;

            const int lhsCh = strings[lhs][n];
            const int rhsCh = strings[rhs][n];

            if (lhsCh > rhsCh)
            {
                string temp = strings[lhs];
                strings[lhs] = strings[rhs];
                strings[rhs] = temp;
            }
            else if (lhsCh == rhsCh)
            {
                const int size = strings[lhs].size() > strings[rhs].size()
                    ? strings[lhs].size() : strings[rhs].size();
                for (int idx = 0; idx < size; idx++)
                {
                    if (strings[lhs][idx] > strings[rhs][idx])
                    {
                        string temp = strings[lhs];
                        strings[lhs] = strings[rhs];
                        strings[rhs] = temp;
                        break;
                    }
                    else if (strings[lhs][idx] == strings[rhs][idx])
                        continue;
                    else
                        break;
                }
            }
        }
    }

    answer = strings;

    return answer;
}

int main()
{
    vector<string> strings = { "aen", "bed", "car" };
    int n = 1;
    vector<string> answer = solution(strings, n);

    for (string ans : answer)
    {
        std::cout << ans << std::endl;
    }

    return 0;
}