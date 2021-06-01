times = int(input())
for _ in range(times):
    n, m = map(int, input().split())
    if n > m:    biggy = n
    else:    biggy = m
    for i in range(biggy, 0, -1):
        if n%i == 0 and m%i == 0:
            GCD = i
            break
    LCM = int(n*m/GCD)
    print(LCM)

# 느려서 개선
import sys

def gcd(a,b):
    if b == 0: return a
    return gcd(b,a%b)
times = int(sys.stdin.readline())
while times:
    n,m = map(int, sys.stdin.readline().split())
    print(n*m//gcd(n,m))
    times-=1