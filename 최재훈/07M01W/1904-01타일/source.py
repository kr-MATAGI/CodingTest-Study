N = int(input())
modNum = 15746

dpDict = dict()
dpDict[0] = 0;
dpDict[1] = 1; # 1
dpDict[2] = 2; # 00 11

for n in range(3, N+1): dpDict[n] = (dpDict[n-1] + dpDict[n-2]) % modNum
print(dpDict[N])