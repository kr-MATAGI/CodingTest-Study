#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define DEBUG_CODE 0

using namespace std;


struct Answer
{
    int stage;
    double rate;
};

bool compare(Answer& lhs, Answer& rhs)
{
    if(lhs.rate == rhs.rate)
    {
        return lhs.stage < rhs.stage;
    }
    else
    {
        return lhs.rate > rhs.rate;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // stage, userCount
    unordered_map<int, int> arrivedUserList;
    unordered_map<int, int> notClearedList;
    
    // stage, fail rate
    unordered_map<int, double> failRateList;
    vector<Answer> answerList;

    for(int idx = 1; idx <= N; idx++)
    {
        arrivedUserList[idx] = 0;
        notClearedList[idx] = 0;
    }

    for(const int stage : stages)
    {
        notClearedList[stage]++;
        
        for(int idx = 1; idx <= stage; idx++)
        {
            arrivedUserList[idx]++;
        }
    }

    // calculated fail rate
    for(int idx = 1; idx <= N; idx++)
    {
        if(0 == notClearedList[idx])
        {
            failRateList[idx] = 0.0;
        }
        else
        {
            failRateList[idx] = (double)notClearedList[idx] / (double)arrivedUserList[idx];
#if DEBUG_CODE
            printf("%s(%d) { stage : %d, notClearedList : %d, arrivedUserList : %d }\n", __FUNCTION__, __LINE__, 
                idx, notClearedList[idx], arrivedUserList[idx]);
#endif
        }
    }

    for(const auto& data : failRateList)
    {
        Answer ans;
        ans.stage = data.first;
        ans.rate = data.second;
#if DEBUG_CODE
        printf("%s(%d) { stage : %d, rate : %f }\n", __FUNCTION__, __LINE__, ans.stage, ans.rate);
#endif
        answerList.push_back(ans);
    }
    sort(answerList.begin(), answerList.end(), compare);

    for(const Answer& ans : answerList)
    {
        answer.push_back(ans.stage);
    }

    return answer;
}