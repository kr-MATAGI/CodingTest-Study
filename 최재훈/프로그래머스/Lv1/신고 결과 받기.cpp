#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size(), 0);

    // 각 아이디별 신고당한 횟수 저장
    vector<int> reported_count;
    reported_count.resize(id_list.size(), 0);

    // 각 아이디별 신고한 인덱스 저장
    vector<vector<bool>> id_report_lhs;
    id_report_lhs.resize(id_list.size());
    for(int idx = 0; idx < id_report_lhs.size(); idx++)
    {
        vector<bool> temp;
        temp.resize(id_list.size(), false);
        id_report_lhs[idx] = temp;
    }

    for(string& report_pair : report)
    {
        int space_idx = 0;
        space_idx = report_pair.find(" ");
        string lhs = report_pair.substr(0, space_idx);
        string rhs = report_pair.substr(space_idx+1, report_pair.size());

        int lhs_idx = std::find(id_list.begin(), id_list.end(), lhs) - id_list.begin();
        int rhs_idx = std::find(id_list.begin(), id_list.end(), rhs) - id_list.begin();

        if(false == id_report_lhs[lhs_idx][rhs_idx])
        {
            id_report_lhs[lhs_idx][rhs_idx] = true;
            reported_count[rhs_idx] += 1;
        }
    }

    // result
    vector<int> ban_list;
    for(int idx = 0; idx < reported_count.size(); idx++)
    {
        if(k <= reported_count[idx])
            ban_list.push_back(idx);
    }

    for(auto ban_id : ban_list)
    {
        for(int idx = 0; idx < id_report_lhs.size(); idx++)
        {
            if(true == id_report_lhs[idx][ban_id])
            {
                answer[idx] += 1;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> id_list = {"con", "ryan"};

    vector<string> report = {"ryan con",
                             "ryan con",
                             "ryan con",
                             "ryan con"};
    int k = 3;

    vector<int> answer = solution(id_list, report, k);
    for(auto item : answer)
    {
        printf("%d\n", item);
    }

    return 0;
}