n = int(input())
time = []
for _ in range(n):
    start, end = map(int, input().split())
    time.append([start, end])
time.sort()
time = sorted(time, key=lambda x: x[1])
now = 0
cnt = 0
for i, j in time:
    if now <= i:
      cnt += 1
      now = j
print(cnt)


# 더 빠르게 
import sys
In =sys.stdin.readline

N = int(In())
time =[(*map(int, In().split()),) for i in range(N)]

time.sort()
time = sorted(time, key=lambda x: x[1])

now = 0
cnt = 0

for i, j in time:
    if now <= i:
      cnt += 1
      now = j
print(cnt)