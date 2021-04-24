'''
A+B - 4
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	130249	45432	38879	35.785%

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
각 테스트 케이스마다 A+B를 출력한다.

예제 입력 1 
1 1
2 3
3 4
9 8
5 2
예제 출력 1 
2
5
7
17
7
'''

import sys

while True:
    try:
        a, b = map(int, sys.stdin.readline().split())
        print(a+b)
    except:
        break
        
        
try:
    while True:
        a, b = map(int, sys.stdin.readline().split())
        print(a+b)
except:
    pass
    
# -------------------------------------------------------

import sys

for line in sys.stdin:
    print(sum(map(int,line.split())))

'''
파이썬 입력이 끝날때 까지 받는 방법
1. EOFError 이용
2. sys.readline == ''

+a 파일 읽을때
line = f.readline()
if not line: 
    break

with open('myfile.txt') as file:
    for line in file.readlines():
        print(line.strip().split('\t'))
'''