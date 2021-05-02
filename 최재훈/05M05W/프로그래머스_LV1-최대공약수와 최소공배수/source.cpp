#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    long long nLong = static_cast<long long>(n);
    long long mLong = static_cast<long long>(m);
    long long multi = nLong * mLong;
    
    long long bigger = nLong > mLong ? nLong : mLong;
    long long smaller = nLong < mLong ? nLong : mLong;
    long long gcd = smaller;
    while (0 != bigger % smaller)
	{
        gcd = bigger % smaller;
        bigger = smaller;
        smaller = gcd;
	}
    answer.push_back((int)(gcd));
    
    long long lcm = multi / gcd;
    answer.push_back((int)(lcm));
    
    printf("%d %d -> %d %d\n", n, m, answer[0], answer[1]);

    return answer;
}

int main()
{
    solution(3, 12);
    solution(2, 5);
    solution(6, 18);
    solution(1, 12);
    solution(1, 1);
    solution(5, 6);
    solution(10, 50);
    solution(1, 50);
    solution(3, 71);
    solution(2, 18);
    solution(1, 2);
    solution(1, 1);
    solution(2, 6);
    solution(11, 15);
    solution(1000000, 999999);

    return 0;
}