#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int idx = 0; idx < completion.size(); idx++)
    {
        if (0 != strcmp(participant[idx].c_str(),
            completion[idx].c_str()))
        {
            answer = participant[idx];
            return answer;
        }
    }
    answer = participant.back();

    return answer;
}


int main()
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

    string answer = solution(participant, completion);
    printf("%s\n", answer.c_str());
    

    return 0;
}