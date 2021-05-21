#  pypy3로 제출해서 성공

import sys

# 세로랑 대각선만 보자!
def upline(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == x - i:
            return False
    return True
        
        
#한줄씩 재귀하며 DFS를 실행
def dfs(x):
    global result
    
    if x == N:
        result += 1

    else:
        for i in range(N):
            row[x] = i
            if upline(x):
                dfs(x + 1)

N = int(sys.stdin.readline())
row = [0] * N
result = 0
dfs(0)
print(result)