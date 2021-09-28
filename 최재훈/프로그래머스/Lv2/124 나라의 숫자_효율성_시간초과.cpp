/*
* Lv2 - 124 나라의 숫자
*/

#include <string>
#include <vector>

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
    int charVecSize = charVec.size();
    int startNum = sumNum - currNum + 1;
    int diffNum = n - startNum;

    for (int idx = 0; idx < diffNum; idx++)
    {
        if ('1' == charVec[charVecSize - 1])
            charVec[charVecSize - 1] = '2';
        else if('2' == charVec[charVecSize-1])
            charVec[charVecSize - 1] = '4';
        else
        {
            charVec[charVecSize - 1] = '1';
            
            for (int jdx = charVecSize - 2; jdx >= 0; jdx--)
            {
                if ('1' == charVec[jdx])
                {
                    charVec[jdx] = '2';
                    break;
                }
                else if ('2' == charVec[jdx])
                {
                    charVec[jdx] = '4';
                    break;
                }
                else
                {
                    charVec[jdx] = '1';
                }
            }
        }
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

int main()
{
    int n = 10;
    string answer = solution(n);

    printf("answer :%s\n", answer.c_str());
}