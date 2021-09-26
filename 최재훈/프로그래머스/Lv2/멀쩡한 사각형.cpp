/*
* Programmers - Lv2 멀쩡한 사각형
*/
#include <iostream>

using namespace std;

// Def
typedef long long VLONG; // very long

long long solution(int w, int h) {
    long long answer = 1;

    // nemo
    const VLONG vW = static_cast<VLONG>(w);
    const VLONG vH = static_cast<VLONG>(h);
    const VLONG nemoArea = vW * vH;

    // get gcd
    VLONG bigVal = max(w, h);
    VLONG smallVal = min(w, h);
    VLONG gcd = smallVal;
    while (0 != bigVal % smallVal)
    {
        gcd = bigVal % smallVal;
        bigVal = smallVal;
        smallVal = gcd;
    }

    if (1 == vW || 1 == vH)
        answer = 0;
    else
        answer = nemoArea - (vW + vH - gcd);
   
    return answer;
}


/*
* MAIN
*/
int main()
{
    int w = 11;
    int h = 22;

    const long long answer = solution(w, h);
    printf("answer : %lld\n", answer);
}