import sys
input = sys.stdin.readline

K = int(input())
KList = []
for kdx in range(K):
    temp = int(input())
    if 0 != temp: KList.append(temp)
    else: KList.pop()

answer = 0
answer = sum(KList)
print(answer)