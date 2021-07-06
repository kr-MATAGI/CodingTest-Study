N = int(input())
modNum = 15746

dp = [ 0 for _ in range(1000001)]
dp[0] = 0;
dp[1] = 1; # 1
dp[2] = 2; # 00 11

for n in range(3, N+1): dp[n] = (dp[n-1] + dp[n-2]) % modNum
print(dp[N])