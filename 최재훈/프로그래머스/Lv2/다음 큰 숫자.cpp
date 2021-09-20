#include <string>
#include <vector>

using namespace std;

/**
* 조건 1. n의 다음 큰 숫자는 n보다 큰 자연수
* 조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같다.
* 조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
*/

int CalculateBinaryOneCount(int srcNum)
{
    int retValue = 0;

    while (0 != (srcNum / 2))
    {
        if (1 == (srcNum % 2))
            retValue += 1;
        if (1 == (srcNum / 2))
            retValue += 1;
        srcNum /= 2;
    }

    return retValue;
}

// solution
int solution(int n) 
{
    int answer = 0;

    const int n_oneCnt = CalculateBinaryOneCount(n);
    for (int nextNum = n + 1; ; nextNum++)
    {
        // Check Condition 2
        const int next_oneCnt = CalculateBinaryOneCount(nextNum);
        if (n_oneCnt != next_oneCnt)
            continue;
        else
        {
            answer = nextNum;
            break;
        }
    }

    return answer;
}

// main
int main()
{
    int n = 78;

    const int answer = solution(n);
    printf("answer : %d\n", answer);
}