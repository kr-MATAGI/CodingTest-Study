#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

#define MAX_INPUT 100

int main()
{
	while (true)
	{
		string inputStr = { 0, };
		getline(cin, inputStr);

		if (0 == strcmp(inputStr.c_str(), "."))
			break;
		
		bool isYes = true;
		vector<char> barketList;
		const int inputSize = inputStr.size();
		for (int idx = 0; idx < inputSize; idx++)
		{
			if ('(' == inputStr[idx] || '[' == inputStr[idx])
			{
				barketList.push_back(inputStr[idx]);
			}
			else if (')' == inputStr[idx] || ']' == inputStr[idx])
			{
				if (true == barketList.empty())
				{
					isYes = false;
					break;
				}

				char lastCh = barketList.back();
				barketList.pop_back();
				
				if (')' == inputStr[idx] && '(' != lastCh)
				{
					isYes = false;
					break;
				}
				else if (']' == inputStr[idx] && '[' != lastCh)
				{
					isYes = false;
					break;
				}
			}
		}

		if (0 != barketList.size())
			printf("no\n");
		else
			printf("%s\n", (true == isYes) ? "yes" : "no");
	}

	return 0;
}