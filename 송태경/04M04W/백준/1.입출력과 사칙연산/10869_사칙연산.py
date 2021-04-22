'''
사칙연산
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	157667	80467	71467	52.210%
문제
두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

입력
두 자연수 A와 B가 주어진다. (1 ≤ A, B ≤ 10,000)

출력
첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.

예제 입력 1 
7 3
예제 출력 1 
10
4
21
2
1
'''

a,b = map(int,input().split())
print(a+b)
print(a-b)
print(a*b)
print(a//b)
print(a%b)

a,b=map(int,input().split())
print(a+b,a-b,a*b,a//b,a%b,sep='\n')
