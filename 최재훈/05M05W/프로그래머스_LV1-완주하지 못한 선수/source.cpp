#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define debug_m 1

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    vector<string>::iterator compIter = completion.begin();
    for (; compIter != completion.end(); ++compIter)
    {
        vector<string>::iterator partiIter = participant.begin();
        for (; partiIter != participant.end(); )
        {
            if (0 == strcmp((*compIter).c_str(), (*partiIter).c_str()))
            {
#if debug_m
                printf("%s %s\n", (*compIter).c_str(), (*partiIter).c_str());
#endif
                partiIter = participant.erase(partiIter);
                break;
            }
            else
            {
                ++partiIter;
            }
        }
    }

    answer = participant.back();

#if debug_m
    printf("%s\n", answer.c_str());
#endif

    return answer;
}


int main()
{
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki"};
    solution(participant, completion);

    return 0;
}