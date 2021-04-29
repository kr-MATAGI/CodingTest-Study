#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char*) * (n*3) + 1);   

    bool isSu = true;
    for (int idx = 0; idx < n; idx++)
    {
        if (true == isSu)
        {
            strcpy(answer + (idx * 3), "수");
            isSu = false;
        }
        else 
        {
            strcpy(answer + (idx * 3), "박");
            isSu = true;
        }
    }

    return answer;
}

int main()
{
    char* ans = solution(3);
    printf("%s\n", ans);


    return 0;
}