#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    const int min = a > b ? b : a;
    const int max = a > b ? a : b;
    for(int idx = min; idx <= max; idx++)
    {
        answer += idx;
    }
    

    return answer;
}