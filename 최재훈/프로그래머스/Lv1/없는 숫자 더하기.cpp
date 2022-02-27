//
// Created by 최재훈 on 2022/02/27.
//

#include <iostream>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;

    bool is_existed[10] = {false, };
    for(int idx = 0; idx < numbers_len; idx++)
    {
        is_existed[numbers[idx]] = true;
    }

    for(int idx = 0; idx < 10; idx++)
    {
        if(false == is_existed[idx])
        {
            answer += idx;
        }
    }

    return answer;
}

int main()
{
    int numbers[] = {1,2,3,4,6,7,8,0};
    int numbers_len = sizeof(numbers) / sizeof(int);

    int answer = solution(numbers, numbers_len);
    printf("Ans: %d\n", answer);

    return 0;
}