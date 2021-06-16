#include <string>
#include <vector>

using namespace std;

bool IsNumber(char ch)
{
    bool retValue = false;
    
    switch (ch)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        retValue = true;
        break;

    default:
        break;
    }

    return retValue;
}

int solution(string dartResult) {
    int answer = 0;

    string numStr;
    vector<int> scoreList;
    scoreList.resize(3);
    int curIdx = -1;
    for (int idx = 0; idx < dartResult.size(); idx++)
    {
        const bool isNumber = IsNumber(dartResult[idx]);
        if (true == isNumber)
        {
            numStr += dartResult[idx];

            if ('1' == dartResult[idx] && (idx+1) < dartResult.size())
            {
                if ('0' == dartResult[idx + 1])
                {
                    continue;
                }
            }
            curIdx++;
        }
        else if('S' == dartResult[idx] || 'D' == dartResult[idx] || 'T' == dartResult[idx])
        {            
            int loop = 0;
            int number = 0;
            number = atoi(numStr.c_str());
            
            if ('D' == dartResult[idx])
                loop = 1;
            else if ('T' == dartResult[idx])
                loop = 2;

            int multi = number;
            for (int lp = 0; lp < loop; lp++)
                number *= multi;
            scoreList[curIdx] = number;

            numStr.clear();
        }
        else if ('*' == dartResult[idx] || '#' == dartResult[idx])
        {
            /*
            *   * -> 당첨 시 해당 점수와 바로전에 얻은 점수를 2배로
            *   # -> 점수는 마이너스
            */
            if ('*' == dartResult[idx])
            {
                if (0 == curIdx)
                    scoreList[curIdx] *= 2;
                else
                {
                    scoreList[curIdx] *= 2;
                    scoreList[curIdx - 1] *= 2;
                }
            }
            else
            {
                scoreList[curIdx] *= -1;
            }
        }
    }

    for (int idx = 0; idx < 3; idx++)
    {
        answer += scoreList[idx];
    }

    return answer;
}

int main()
{
    string dartResult = "1D2S#10S";
    const int answer = solution(dartResult);

    printf("dartResult: %s, answer: %d\n", dartResult.c_str(), answer);
}