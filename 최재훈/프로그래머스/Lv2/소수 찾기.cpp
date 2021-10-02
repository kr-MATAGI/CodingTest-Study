#include <string>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

// Def
#define NUM_MAX 7

// global
bool visitedCheck[NUM_MAX + 1];
set<string> resultSet;

// Method
bool IsSosu(int number)
{
    bool retValue = true;

    for (int idx = 2; idx <= number / 2; idx++)
    {
        if (0 == number % idx)
        {
            retValue = false;
            break;
        }
    }
    
    return retValue;
}

void DFS(string& numbers, int currIdx, string currNum)
{
    currNum += numbers[currIdx];
    if ('0' == currNum[0])
        return;
    else
    {
        resultSet.insert(currNum);
    }

    if (currNum.size() == numbers.size())
        return;

    for (int idx = 0; idx < numbers.size(); idx++)
    {
        if(false == visitedCheck[idx])
        {
			visitedCheck[idx] = true;
			DFS(numbers, idx, currNum);
			visitedCheck[idx] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    // init
    memset(visitedCheck, false, NUM_MAX + 1);
    
    for (int idx = 0; idx < numbers.size(); idx++)
    {
        visitedCheck[idx] = true;
        DFS(numbers, idx, "");
        visitedCheck[idx] = false;
    }

    vector<int> sosuAns;
    auto iter = resultSet.begin();
    while(iter != resultSet.end())
    {
        const int number = std::atoi((*iter).c_str());
        const bool isSosu = IsSosu(number);
        if (true == isSosu && 1 != number && 0 != number)
            sosuAns.push_back(number);

        ++iter;
    }

    answer = sosuAns.size();
    return answer;
}