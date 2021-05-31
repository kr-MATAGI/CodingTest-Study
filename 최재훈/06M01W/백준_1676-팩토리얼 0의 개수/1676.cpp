#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <cmath>

#define MINSIZE 1
#define MAXSIZE 1

using namespace std;



int main()
{
	int N;
	scanf("%d", &N);

	//10의 개수로 결정됨
	//(1,2,5,10)

	int cnt = 0;

	//팩토리얼 계산
	/*long long factorial_num = 1;
	for (int i = 1; i <= N; i++) {
		factorial_num *= i;
	}
	printf("%lld\n", factorial_num);*/

	//각 수의 약수에서 2와 5의 쌍이 나올때 +1
	//10이 나올때 +1
	
	//2와 5의 약수 개수
	int num_2 = 0;
	int num_5 = 0;
	for (int n = 1; n <= N; n++) {
		//결국엔 5의 개수? 2가 모자라진 않음

		int temp = n;

		while (1) {
			if (temp % 5 != 0)
				break;

			else {
				if (temp % 5 == 0) {
					num_5++;
					temp = temp / 5;
				}
			}
		}
		
	}

	cnt += num_5;
	
	printf("%d\n", cnt);
	return 0;

}
