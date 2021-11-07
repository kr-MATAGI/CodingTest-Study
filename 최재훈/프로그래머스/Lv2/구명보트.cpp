#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    // calculate
    sort(people.begin(), people.end());

    int minIdx = 0;
    int maxIdx = people.size() - 1;
    while (minIdx <= maxIdx)
    {
        int maxPerson = people[maxIdx];
        
        if (limit >= maxPerson + people[minIdx])
            minIdx++;
        maxIdx--;

        answer += 1;
    }

    return answer;
}

int main()
{
    /*
    * 구명보트는 한 번에 최대 2명
    * 구명보트를 최대한 적게 사용해 모든 사람을 구출
    */
    //vector<int> people = { 40, 50, 150, 160 };
     vector<int> people = {70, 80, 50 };
    int limit = 100;

    int answer = solution(people, limit);
    printf("answer: %d\n", answer);

    return 0;
}