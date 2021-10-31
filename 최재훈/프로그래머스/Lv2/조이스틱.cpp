#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string name) {
    int answer = 0;

    /*
    * A - 65
    * Z - 97
    */

    int nameLen = name.length();    
    
    // Left / Right
    int minVal = nameLen - 1;
    
    int leftRigthMove = 0;
    for (int idx = 0; idx < nameLen; idx++)
    {
        int nextIdx = idx + 1;
        while (nextIdx < nameLen && 'A' == name[nextIdx])
            nextIdx += 1;

        minVal = min(minVal, (idx * 2) + nameLen - nextIdx);
    }
    answer += minVal;

    // Up / Down
    for (int idx = 0; idx < nameLen; idx++)
    {
        char ch = name[idx];

		int diff_A = abs(ch - 'A');
		int diff_Z = abs('Z' - ch) + 1;
		int diff_min = min(diff_A, diff_Z);

        //printf("%c %d %d\n", ch, diff_A, diff_Z);

		answer += diff_min;
    }

    return answer;
}

int main()
{
    //string name = "JEROEN";
    string name = "JAN";
    int answer = solution(name);
    printf("answer: %d\n", answer);

	return 0;
}