#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

	int pCnt = 0;
	int yCnt = 0;
	
	const int strLen = s.length();
	for (int idx = 0; idx < strLen; idx++)
	{
		if ('p' == s[idx] || 'P' == s[idx])
		{
			pCnt++;
		}
		else if ('y' == s[idx] || 'Y' == s[idx])
		{
			yCnt++;
		}
	}

	if (0 == pCnt && 0 == yCnt)
		answer = true;
	else
		answer = (pCnt == yCnt);

    return answer;
}

int main()
{
	string input;
	cin >> input;

	solution(input);

	return 0;
}