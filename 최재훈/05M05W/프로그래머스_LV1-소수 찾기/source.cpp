#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE    1000000

int solution(int n) {
    int answer = 0;

    /**
    * @note 에라토스테네스의 체
    *       1. 배열을 생성하여 초기화한다.
    *       2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
    *        (자기 자신은 지우지 않는다.)
    *       3. 2부터 시작하여 남은 수를 모두 출력
    */

    vector<bool> che;
    che.resize(n + 1, true);

    for (int idx = 2; idx <= n / 2; idx++)
    {
        for (int cheIdx = 2; cheIdx <= n / 2; cheIdx++)
        {
            int number = idx * cheIdx;
            if (idx == number)
                continue;
            else if (number > n)
                break;
            
            che[number] = false;
        }
    }

    // answer
    for (int idx = 2; idx <= n; idx++)
    {
        if (true == che[idx])
            answer++;
    }

    return answer;
}


int main()
{
    int n = 10;
    int answer = solution(n);
    printf("\n%d\n", answer);

    return 0;
}