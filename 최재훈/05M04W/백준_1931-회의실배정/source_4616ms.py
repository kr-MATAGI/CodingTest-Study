# input
N = int(input())

startEndList = []
for ndx in range(N):
    startEnd = list(map(int, str(input()).split()))
    startEndList.append(startEnd)

'''
    빨리 끝나는 회의 순서대로 정렬을 해야한다.
    빨리 끝날수록 뒤에서 고려해볼 기회가 많다.
'''
startEndList.sort(key= lambda x: (x[1], x[0]))

# calc
answer = 1
lastEndTime = startEndList[0][1]
for idx, startEndTime in enumerate(startEndList):
    if 0 == idx: continue
    if startEndTime[0] >= lastEndTime:
        answer += 1
        lastEndTime = startEndTime[1]
    
# print
print(answer)