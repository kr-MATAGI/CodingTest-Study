#include <vector>
#include <iostream>

#define MAX_SIZE    1000000

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    vector<int>::const_iterator iter = arr.begin();
    int prevNum = -1;
    for (; iter != arr.end(); ++iter)
    {
        if (prevNum != *iter)
        {
            answer.push_back(*iter);
            prevNum = *iter;
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = { 1,1,3,3,0,1,1 };
    vector<int> ans = solution(arr);

    for (int item : ans)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}