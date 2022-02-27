#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> en_dict = {
        "zero", "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
};

int solution(string s) {
    int answer = 0;

    // 0: 48, 9: 57
    string total_number = "";
    string cur_word = "";
    for(auto ch : s)
    {
        if(48 <= ch && 57 >= ch)
        {
            total_number += ch;
            continue;
        }

        cur_word += ch;
        if (en_dict.end() != std::find(en_dict.begin(), en_dict.end(), cur_word))
        {
            if(0 < cur_word.size())
            {
                int conv_num  = std::find(en_dict.begin(), en_dict.end(), cur_word) - en_dict.begin();

                char buff[2] = {0,};
                sprintf(buff, "%d", conv_num);
                total_number += buff;

                cur_word = "";
            }
        }
    }

    answer = std::atoi(total_number.c_str());
    return answer;
}

int main()
{
    string s = "one4seveneight";
    int ansewr = solution(s);
    printf("ans: %d\n", ansewr);

    return 0;
}