#include <string>
#include <vector>

#define debug_m 1

using namespace std;

string solution(string new_id) 
{
    string answer = "";

    /*
    * // step 1
        a = 97
        z = 122
        A = 65
        Z = 90
    */
    int new_idLen = new_id.length();
    for (int idx = 0; idx < new_idLen; idx++)
    {
        if (65 <= new_id[idx] && 90 >= new_id[idx])
        {
            new_id[idx] += 32;
        }
    }
#if debug_m
    printf("1: %s\n", new_id.c_str());
#endif

    // step 2
    /*
    * 0 = 48
    * 9 = 57
    */
    new_idLen = new_id.length();
    string buff;
    for (int idx = 0; idx < new_idLen; idx++)
    {
        if ((97 <= new_id[idx] && 122 >= new_id[idx]) ||
            (48 <= new_id[idx] && 57 >= new_id[idx]) ||
            ('-' == new_id[idx] || '_' == new_id[idx] || '.' == new_id[idx]))
        {
            buff += new_id[idx];
        }
    }
    new_id = buff;

#if debug_m
    printf("2: %s\n", new_id.c_str());
#endif
        
    // step 3
    while (true)
    {
        bool bBreak = true;
        bool combo = false;
        string::iterator iter = new_id.begin();
        for (; iter != new_id.end(); )
        {
            if(true == combo && '.' == *iter)
            {
                bBreak = false;
                combo = false;
                iter = new_id.erase(iter);
                break;
            }
            else if ('.' == *iter)
            {
                combo = true;
                ++iter;
            }
            else
            {
                combo = false;
                ++iter;
            }
        }

        if (true == bBreak)
            break;
    }
    
#if debug_m
    printf("3: %s\n", new_id.c_str());
#endif

    // step 4
    while (true)
    {
        bool bDel = false;
        new_idLen = new_id.length();
        if (0 < new_idLen)
        {
            if ('.' == new_id[0])
            {
                bDel = true;
                new_id = new_id.substr(1, new_idLen);
            }
            else if ('.' == new_id[new_idLen - 1])
            {
                bDel = true;
                new_id.pop_back();
            }
        }

        if (false == bDel)
            break;
    }

#if debug_m
    printf("4: %s\n", new_id.c_str());
#endif

    // step 5
    if (true == new_id.empty())
        new_id += 'a';

#if debug_m
    printf("5: %s\n", new_id.c_str());
#endif

    // step 6
    if (16 <= new_id.length())
    {
        new_id = new_id.substr(0, 15);
        if ('.' == new_id.back())
            new_id.pop_back();
    }

#if debug_m
    printf("6: %s[%d]\n", new_id.c_str(), new_id.length());
#endif

    // step 7
    if(2 >= new_id.length())
    {
        char lastCh = new_id.back();
        while (true)
        {
            if (3 <= new_id.length())
                break;
            else
                new_id.push_back(lastCh);
        }
    }

#if debug_m
    printf("7: %s\n", new_id.c_str());
#endif
    
    answer = new_id;

#if debug_m
    printf("ans: %s\n", answer.c_str());
#endif

    return answer;
}


int main()
{
    string str = "...!@BaT#*..y.abcdefghijklm";
    solution(str);

    return 0;
}