#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
    vector<int> answer;

    const int commandsSize = commands.size();
    for (int cmdIdx = 0; cmdIdx < commandsSize; cmdIdx++)
    {
        std::vector<int> slice;
        const int startIdx = commands[cmdIdx][0] - 1;
        const int endIdx = commands[cmdIdx][1] - 1;
        const int k = commands[cmdIdx][2];

        const int arrSize = arr.size();
        for (int arrIdx = 0; arrIdx < arrSize; arrIdx++) 
        {
            if (startIdx <= arrIdx && endIdx >= arrIdx)
            {
                slice.push_back(arr[arrIdx]);
            }
        }
        
        sort(slice.begin(), slice.end());
        answer.push_back(slice[k - 1]);
    }

    return answer;
}


int main()
{
    // input
    std::vector<int> arr = { 1,5,2,6,3,7,4 };
    std::vector<int> cmd_1 = { 2,5,3 };
    std::vector<int> cmd_2 = { 4,4,1 };
    std::vector<int> cmd_3 = { 1,7,3 };
    std::vector<std::vector<int>> commands;
    commands.push_back(cmd_1);
    commands.push_back(cmd_2);
    commands.push_back(cmd_3);

    solution(arr, commands);

    return 0;
}