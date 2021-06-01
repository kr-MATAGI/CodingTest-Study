# import math
import math

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    bridge = math.factorial(m) // (math.factorial(n) * math.factorial(m - n))
    print(bridge)
	
# no import
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    answer = 1
    k = m - n
    while m > k:
        answer *= m
        m -= 1
    while n > 1:
        answer = answer // n
        n -= 1
    
    print(answer)