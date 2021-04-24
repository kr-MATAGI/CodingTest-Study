#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);

    const char* list[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED", };
    const int dayOfMonthLimit[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int dayCount = 0;
    for (int idx = 0; idx < a - 1; idx++)
    {
        dayCount += dayOfMonthLimit[idx];
    }
    dayCount += b;
   
    strcpy(answer, list[dayCount % 7]);

    return answer;
}

int main()
{
    int a = 1;
    int b = 1;
    char* answer = solution(a, b);

    printf("%s\n", answer);

    return 0;
}