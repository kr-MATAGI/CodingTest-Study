from os import sep
import sys

input = sys.stdin.readline
testCase = int(input())

# [ zeroCnt, oneCnt, return ]
dp = [ [0,0,0] for _ in range(41) ]
dp[0] = [1, 0, 0]
dp[1] = [0, 1, 1]

for tc in range(testCase):
    N = int(input())
    
    if(0 == N):
        print(dp[0][0], dp[0][1], sep=' ')
        continue
    if(1 == N):
        print(dp[1][0], dp[1][1], sep=' ')
        continue
    if(0 != dp[N][2]): print(dp[N][0], dp[N][1], sep=' ')
    else:
        for idx in range(2, N+1):
            zeroCnt = dp[idx-1][0] + dp[idx-2][0]
            oneCnt = dp[idx-1][1] + dp[idx-2][1]
            result = dp[idx-1][2] + dp[idx-2][2]
            dp[idx] = [zeroCnt, oneCnt, result]
        print(dp[N][0], dp[N][1], sep=' ')
            
