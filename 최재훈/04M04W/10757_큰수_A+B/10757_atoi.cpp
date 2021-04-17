#include <iostream>
#include <cstring>
#include <stdlib.h>

// define
#define MAX_LEN 10002

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	char A[MAX_LEN] = { '\0', };
	char B[MAX_LEN] = { '\0', };
	char result[MAX_LEN + 1] = { '\0', };
	(void)scanf("%s %s", &A, &B);

	const int ALen = std::strlen(A);
	const int BLen = std::strlen(B);
	const int longgerLen = ALen > BLen ? ALen : BLen;
	
	// reverse
	char reA[MAX_LEN] = { '\0', };
	char reB[MAX_LEN] = { '\0', };

	int AMaxIdx = (ALen - 1);
	for (int idx = 0; idx < ALen; idx++ )
	{
		reA[idx] = A[AMaxIdx];
		AMaxIdx--;
	}

	int BMaxIdx = (BLen - 1);
	for (int idx = 0 ; idx < BLen; idx++)
	{
		reB[idx] = B[BMaxIdx];
		BMaxIdx--;
	}

	// calc
	int overflow = 0;
	for (int idx = 0; idx < longgerLen; idx++)
	{
		char aBuf[2] = { "\0", };
		char bBuf[2] = { "\0", };
		aBuf[0] = reA[idx];
		bBuf[0] = reB[idx];

		int aVal = std::atoi(aBuf);
		int bVal = std::atoi(bBuf);
		int plusVal = aVal + bVal;

		if (true == overflow)
		{
			plusVal += overflow;
			overflow = 0;
		}

		if (10 <= plusVal)
		{
			plusVal -= 10;
			overflow = 1;
		}

		char convertBuf[2] = { '\0', };
		sprintf(convertBuf, "%d", plusVal);
		result[idx] = convertBuf[0];

		if (idx == (longgerLen - 1) && 1 == overflow)
		{
			char convertBuf[2] = { '\0', };
			sprintf(convertBuf, "%d", overflow);
			result[idx+1] = convertBuf[0];
		}
	}

	// print
	char reResult[MAX_LEN + 1] = { '\0', };
	const int resultLen = std::strlen(result);
	int resultMaxIdx = (resultLen - 1);
	for (int idx = 0; idx < resultLen; idx++)
	{
		reResult[idx] = result[resultMaxIdx];
		resultMaxIdx--;
	}

	printf("%s\n", reResult);

	return 0;
}