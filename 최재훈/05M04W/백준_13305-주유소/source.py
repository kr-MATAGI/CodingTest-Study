N = int(input())
distList = list(map(int, str(input()).split()))
costList = list(map(int, str(input()).split()))


distIdx = 0
cityIdx = 0
nextCityIdx = 1
costSum = 0
while(True):
    if(distIdx >= len(distList)): break

    if(0 == distIdx):
        costSum += (costList[cityIdx] * distList[distIdx])
        distIdx += 1
        continue
    
    if(costList[cityIdx] <= costList[nextCityIdx]):
        costSum += (costList[cityIdx] * distList[distIdx])
        nextCityIdx += 1
    else:
        costSum += (costList[nextCityIdx] * distList[distIdx])
        cityIdx = nextCityIdx
        nextCityIdx += 1
    distIdx += 1

print(costSum)

