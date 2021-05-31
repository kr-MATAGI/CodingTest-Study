#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    const int person_1[] = { 1,2,3,4,5 };
    const int person_2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    const int person_3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    const int arrSize_1 = sizeof(person_1) / sizeof(int);
    const int arrSize_2 = sizeof(person_2) / sizeof(int);
    const int arrSize_3 = sizeof(person_3) / sizeof(int);

    int index_1 = 0;
    int index_2 = 0;
    int index_3 = 0;

    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;

    for (int idx = 0; idx < answers.size(); idx++)
    {
        const int ans = answers[idx];

        if (person_1[index_1] == ans)
        {
            count_1++;
        }

        if (person_2[index_2] == ans)
        {
            count_2++;
        }

        if (person_3[index_3] == ans)
        {
            count_3++;
        }

        index_1++;
        if (arrSize_1 <= index_1)
            index_1 = 0;

        index_2++;
        if (arrSize_2 <= index_2)
            index_2 = 0;

        index_3++;
        if (arrSize_3 <= index_3)
            index_3 = 0;
    }

    const int maxCnt = count_1 > count_2 ? (count_1 > count_3 ? count_1 : count_3)
                                    : (count_2 > count_3 ? count_2 : count_3);

    if (maxCnt == count_1)
        answer.push_back(1);
    if (maxCnt == count_2)
        answer.push_back(2);
    if (maxCnt == count_3)
        answer.push_back(3);

#if 0
    printf("%d, %d %d %d\n", maxCnt, count_1, count_2, count_3);
#endif

    return answer;
}

int main()
{
    vector<int> answers = { 1,3,2,4,2 };

    vector<int> answer = solution(answers);   

    return 0;
}