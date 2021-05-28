#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

#define ALPHA_MAX 26

typedef pair<string, std::pair<int, int>> KEY_VALUE;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash    
    unordered_map<string, std::pair<int, int>> hash;
    for (int idx = 0; idx < participant.size(); idx++)
    {
        if (hash.end() != hash.find(participant[idx]))
            hash[participant[idx]].first++;
        else
            hash.insert(KEY_VALUE(participant[idx], std::pair<int, int>(1, 0)));
    }

    for (int idx = 0; idx < completion.size(); idx++)
    {
        if (hash.end() != hash.find(completion[idx]))
            hash[completion[idx]].second++;
    }

    for (int idx = 0; idx < participant.size(); idx++)
    {
        if (hash[participant[idx]].first != hash[participant[idx]].second)
        {
            answer = participant[idx];
            break;
        }
    }

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