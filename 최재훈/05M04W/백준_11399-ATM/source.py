N = int(input())
PList = list(map(int, str(input()).split()))
PList.sort()

answer = 0
timeSum = 0
for time in PList:
    timeSum += time
    answer += timeSum

print(answer)
    