#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	char* answer;

	int len = 0;
	while (true)
	{
		if ('\0' == s[len])
			break;

		len++;
	}
	
	char buff[3] = { 0, };
	if (0 == len % 2)
	{
		answer = (char*)malloc(sizeof(char) * 3);
		memset(answer, 0, sizeof(char) * 3);
		
		answer[0]= s[len / 2 - 1];
		answer[1] = s[len / 2];
	}
	else
	{
		answer = (char*)malloc(sizeof(char) * 2);
		memset(answer, 0, sizeof(char) * 2);
		answer[0] = s[len / 2];
	}
	
	return answer;
}

int main()
{
	char s[] = "abcde";
	char* ans = solution(s);

	char c[] = "qwer";
	char* ans2 = solution(c);

	return 0;
}