nk = list(map(int, str(input()).split()))
N = nk[0]
K = nk[1]

costList = []
for idx in range(N):
    cost = int(input())
    if(cost <= K):
        costList.append(cost)
costList.sort(reverse=True)

answer = 0
costSum = K
costIdx = 0
while(True):
    if(costSum == 0):
        break

    divValue = costSum // costList[costIdx]
    if(0 < divValue):
        answer += divValue
        costSum -= (costList[costIdx] * divValue)
    else:
        costIdx += 1

print(answer)