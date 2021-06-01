# 25, 12 -> 5200300
N, M = map(int, str(input()).split())

cnt5 = 0
cnt2 = 0
num = 2
while True: 
    if(num > N): break
    cnt2 += N // num
    num *= 2

num = 5
while True:
    if(num > N): break
    cnt5 += N // num
    num *= 5
##
num = 2
while True: 
    if(num > M): break
    cnt2 -= M // num
    num *= 2

num = 5
while True:
    if(num > M): break
    cnt5 -= M // num
    num *= 5
##

num = 2
while True: 
    if(num > N-M): break
    cnt2 -= (N-M) // num
    num *= 2

num = 5
while True:
    if(num > N-M): break
    cnt5 -= (N-M) // num
    num *= 5

print(cnt5 if cnt5 < cnt2 else cnt2)
