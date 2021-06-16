#include <string>
#include <vector>

using namespace std;

bool calc(const int number)
{
    if (1 == number)
        return false;

    bool isEven = false;

    int numCnt = 2; // 1, number

    for (int idx = 2; idx <= number / 2; idx++)
    {
        if (0 == number % idx)
        {
            numCnt++;
        }
    }

    isEven = (0 == numCnt % 2) ? true : false;

    return isEven;
}

int solution(int left, int right) {
    int answer = 0;

    /*
    * 약수의 개수가 짝수인 수는 더하고
    * 약수의 개수가 홀수인 수는 뺌
    */

    for (int num = left; num <= right; num++) 
    {
        const bool isEven = calc(num);
        if (true == isEven)
            answer += num;
        else
            answer -= num;
    }

    return answer;
}

int main()
{
    int left = 1;
    int right = 2;
    int answer = solution(left, right);
    printf("left : %d, right : %d, answer : %d", left, right, answer);

	return 0;
}