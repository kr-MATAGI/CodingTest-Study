#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    memset(answer, '\0', 4);


    const char* list[] = { "SUN", "MON", "TUE",
                            "WED", "THU", "FRI", "SAT" };
    const int listSize = sizeof(list) / sizeof(char*);
    const int dayOfMonthLimit[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int listIdx = 5;

    bool bFind = false;
    for (int aIdx = 1; aIdx <= a; aIdx++)
    {
        const int dom = dayOfMonthLimit[aIdx - 1];
        for (int bIdx = 1; bIdx <= dom; bIdx++)
        {
            if (a == aIdx && b == bIdx)
            {
                bFind = true;
                break;
            }
            listIdx++;
            if (listSize <= listIdx)
                listIdx = 0;
        }

        if (true == bFind)
            break;
    }

    memcpy(answer, list[listIdx], 4);

    return answer;
}

int main()
{
    int a = 12;
    int b = 31;
    char* answer = solution(a, b);

    printf("%s\n", answer);

    return 0;
}