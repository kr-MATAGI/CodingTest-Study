#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define ALPHA_MAX 26

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // like hash
    vector<vector<string>> keyList;
    keyList.resize(ALPHA_MAX + 1);

    // input
    const int partListSize = participant.size();
    for (int idx = 0; idx < partListSize; idx++)
    {
        int key = participant[idx][0] - 97;
        keyList[key].push_back(participant[idx]);
    }

    // find
    const int compListSize = completion.size();
    for (int idx = 0; idx < compListSize; idx++)
    {
        int key = completion[idx][0] - 97;

        vector<string>& valueList = keyList[key];
        vector<string>::iterator valueIter = valueList.begin();

        for (; valueIter != valueList.end();)
        {
            if (0 == strcmp((*valueIter).c_str(), completion[idx].c_str()))
            {
                valueIter = valueList.erase(valueIter);
                break;
            }
            else
                ++valueIter;
        }
    }

    // answer
    for (int idx = 0; idx < ALPHA_MAX + 1; idx++)
    {
        if (1 <= keyList[idx].size())
        {
            answer = keyList[idx].back();
            break;
        }
    }

    return answer;
}


int main()
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };
    solution(participant, completion);

    return 0;
}