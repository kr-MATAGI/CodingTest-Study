/*
* Lv2 - 타겟 넘버
*/

#include <string>
#include <vector>

using namespace std;

// Def
enum OPER
{
    PLUS= 1,
    MINUS= 2,
};

// Global
int answer;

// Method
void DFSFunc(vector<int>& numbers, int currIdx, int currSum, const int target, OPER oper)
{
    if (OPER::PLUS == oper)
    {
        currSum += numbers[currIdx];
    }
    else
    {
        currSum -= numbers[currIdx];
    }

    if (currIdx == numbers.size() - 1)
    {
        if (target == currSum)
            answer += 1;

        return;
    }

    DFSFunc(numbers, currIdx + 1, currSum, target, OPER::PLUS);
    
    DFSFunc(numbers, currIdx + 1, currSum, target, OPER::MINUS);
}

int solution(vector<int> numbers, int target) {
    answer = 0;

    int currIdx = 0;
    int currSum = 0;
    DFSFunc(numbers, currIdx, currSum, target, OPER::PLUS);
    DFSFunc(numbers, currIdx, currSum, target, OPER::MINUS);

    return answer;
}


int main()
{
    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;

    int answer = solution(numbers, target);
    printf("answer : %d\n", answer);
}