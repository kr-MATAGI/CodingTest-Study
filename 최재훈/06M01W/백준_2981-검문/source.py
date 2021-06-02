import sys
input = sys.stdin.readline

def GCD(a, b):
    maxVal = max(a,b)
    minVal = min(a,b)
    while 0 != minVal:
        temp = maxVal % minVal
        maxVal = minVal
        minVal = temp
    return maxVal
        
'''
    계산 수식 이해 필요
'''

N = int(input())
NList = []
answerList = []
for ndx in range(N):
    temp = int(input())
    NList.append(temp)
NList.sort(reverse=False)
curIdx = 2
gcdVal = NList[1] - NList[0]
while True:
    if NList.__len__() <= curIdx: break
    gcdVal = abs(GCD(gcdVal, NList[curIdx] - NList[curIdx - 1]))
    curIdx += 1

value = 1
while True:
    if value * value > gcdVal: break
    if 1 == value: pass
    elif 0 == gcdVal % value: 
        if value not in answerList: answerList.append(value)
        if (gcdVal // value) not in answerList: answerList.append(gcdVal // value)
    value +=1
answerList.append(gcdVal)

# print
answerList.sort()
for item in answerList: print(item, end=' ')