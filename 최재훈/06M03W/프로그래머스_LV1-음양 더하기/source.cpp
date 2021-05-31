#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 123456789;

    int sum = 0;
    for (int idx = 0; idx < absolutes_len; idx++)
    {
        int num = absolutes[idx];
        const bool bSign = signs[idx];
        if (false == bSign)
            num *= -1;

        sum += num;
    }
    answer = sum;

    return answer;
}