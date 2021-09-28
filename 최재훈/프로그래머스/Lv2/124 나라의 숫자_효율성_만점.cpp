/*
* Lv2 - 124 나라의 숫자
*/

#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(int n) {
    string answer = "";

    vector<char> charVec;
    int currNum = 1;
    int sumNum = 0;
    while (true)
    {
        if (sumNum >= n)
            break;
        else
        {
            charVec.push_back('1');
            currNum *= 3;
            sumNum += currNum;
        }
    }

    // calc
    int lastIdx = charVec.size() - 1;
    int startNum = 0;
    for (int idx = 0; idx <= lastIdx; idx++)
        startNum += pow(3, idx);
    int diffNum = n - startNum;

    while (0 <= lastIdx)
    {
        int leftNum = diffNum % 3;

        if (0 == leftNum)
            charVec[lastIdx] = '1';
        else if (1 == leftNum)
            charVec[lastIdx] = '2';
        else
            charVec[lastIdx] = '4';

        diffNum /= 3;

        lastIdx--;
    }
    
    // make answer
    auto iter = charVec.begin();
    while (iter != charVec.end())
    {
        answer += *iter;
        ++iter;
    }

    return answer;
}