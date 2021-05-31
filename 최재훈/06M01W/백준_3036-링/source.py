def gcd(a, b):
    maxVal = a if a >= b else b
    minVal = a if a < b else b
    while 0 != minVal:
        temp = maxVal % minVal
        maxVal = minVal
        minVal = temp
    return maxVal

N = int(input())
ringList = list(map(int, str(input()).split())) # 링의 반지름

answerList = []
aRadius = ringList[0]
for idx, ring in enumerate(ringList):
    if(0 == idx): continue
    bRadius = ring

    gcdVal = gcd(aRadius, bRadius)
    answer = str(f'{int(aRadius/gcdVal)}/{int(bRadius/gcdVal)}')
    answerList.append(answer)

# print
for ans in answerList: print(ans)