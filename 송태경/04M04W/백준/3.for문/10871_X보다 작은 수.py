'''
X보다 작은 수
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	112736	62183	52676	55.811%

문제
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)

둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. 주어지는 정수는 모두 1보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

출력
X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다. X보다 작은 수는 적어도 하나 존재한다.

예제 입력 1 
10 5
1 10 4 9 2 3 8 5 7 6
예제 출력 1 
1 4 2 3
'''

n, x = map(int, input().split())
list_a = list(map(int, input().split()))
# for i in range(n):
#     a = int(input())
#     list_a.append(a)
for i in list_a:
  if i < x:
    print(i, end = ' ')
    
# -----------------------------------------------------

a,b = map(int,input().split())
score = [x for x in input().split() if int(x)<b]
print(' '.join(score))

# 시스템 입력값 있는 경우------------------------------------
import sys
n, x = map(int, sys.stdin.readline().split())
n_numbers = map(int, sys.stdin.readline().split())

smaller_than_x = []

for number in n_numbers:
    if number < x:
        smaller_than_x.append(number)
print(' '.join(map(str, smaller_than_x)))