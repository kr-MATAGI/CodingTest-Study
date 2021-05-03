# sys 이용해고 읽고 쓰고 출력하고 시간 줄이기
import sys

n = int(input())
n_list = []

for i in range(n):
    n_list.append(int(sys.stdin.readline()))
for i in sorted(n_list):
    sys.stdout.write(str(i)+'\n')

# ------------------------------------------------

from sys import stdin, stdout

input()
arr = sorted(map(int, stdin.read().split()))
stdout.write('\n'.join(map(str,arr)))