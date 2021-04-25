#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 990000

int buff[MAX_LEN + 1] = { 0, };
int* solution(int numbers[], size_t numbers_len) {
    
    int buffIdx = 0;
    for (int lhsIdx = 0; lhsIdx < numbers_len; lhsIdx++)
    {
        const int lhs = numbers[lhsIdx];
        for (int rhsIdx = 0; rhsIdx < numbers_len; rhsIdx++)
        {
            if (lhsIdx == rhsIdx)
                continue; 

            const int rhs = numbers[rhsIdx];
            const int sum = lhs + rhs;
            
            // check
            bool bIsExisted = false;
            for (int idx = 0; idx < buffIdx; idx++)
            {
                if (sum == buff[idx]) 
                {
                    bIsExisted = true;
                    break;
                }
                    
            }
            if (false == bIsExisted)
            {
                buff[buffIdx] = sum;
                buffIdx++;
            }
        }
    }

    // sort
    for (int lhs = 0; lhs < buffIdx; lhs++)
    {
        for (int rhs = 0; rhs < buffIdx; rhs++)
        {
            if (buff[lhs] < buff[rhs])
            {
                int temp = buff[lhs];
                buff[lhs] = buff[rhs];
                buff[rhs] = temp;
            }
        }
    }

    int* answer = (int*)malloc(sizeof(int) * (buffIdx));
    answer = buff;

    return answer;
}


int main()
{
    int numbers[] = { 5,0,2,7 };
    int numbers_len = sizeof(numbers) / sizeof(int);
    int* ans = solution(numbers, numbers_len);

    return 0;
}