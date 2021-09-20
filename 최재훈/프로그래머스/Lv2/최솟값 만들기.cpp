#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// cmp
bool cmp(int lhs, int rhs)
{
	if (lhs > rhs)
		return true;
	else
		return false;
}

// solution
int solution(vector<int> A, vector<int> B)
{
	int retValue = 0;

	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end());

	const int dataSize = A.size();
	for (int idx = 0; idx < dataSize; idx++)
	{
		int data_A = A.back();
		A.pop_back();

		int data_B = B.back();
		B.pop_back();

		retValue += (data_A * data_B);
		//printf("%d * %d = %d\n", data_A, data_B, data_A * data_B);
	}

	return retValue;
}


// main	
int main()
{
	vector<int> A = { 1,4,2 };
	vector<int> B = { 5,4,4 };

	const int answer = solution(A, B);
	printf("answer: %d\n", answer);
}