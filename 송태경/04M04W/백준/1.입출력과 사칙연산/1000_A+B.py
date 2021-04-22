'''
A+B 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	394049	168269	121664	43.643%

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
첫째 줄에 A+B를 출력한다.

예제 입력 1 
1 2
예제 출력 1 
3
'''

a,b = input().split()
print(int(a)+int(b))

a,b = map(int,input().split())
print(a+b)

print(sum(map(int,input().split())))