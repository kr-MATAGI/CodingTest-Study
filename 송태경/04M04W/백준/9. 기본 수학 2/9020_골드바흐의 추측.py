def is_prime_number(num):
    if num==1:
        return False
    else:
        for i in range(2, int(num**0.5)+1):
            if num%i == 0:
                return False
        return True

# Tip: 소수 리스트 미리 만들때 홀수만 하면 속도 더 줄어듬
num_list = list(range(2,10001))
sort_list = []
for i in num_list:
    if is_prime_number(i):
         sort_list.append(i)

t =  int(input())
for _ in range(t):
    n = int(input())
    m = n//2
    for i in range(m,1,-1):
        if (n-i in sort_list) and (i in sort_list):
            print(i,n-i)
            break

# --------------------------------------------------------------------

import sys
read = sys.stdin.readline

def goldBache(k, prime, MAX):
    cnt = 0
    half = k // 2 
    for val in range(half, MAX):
        if prime[val] and prime[k - val]:
            return val
    return -1


MAX = 10001
prime = [1] * MAX 
prime[0] = 0
prime[1] = 0
for i in range(MAX):
    if prime[i] == 1:
        for not_prime in range(2 * i, MAX, i):
            prime[not_prime] = 0

n = int(input())
while(n > 0):
    k = int(read())
    pair_1 = goldBache(k, prime, MAX)
    pair_2 = k - pair_1
    print("{} {}".format(pair_2, pair_1))
    n -= 1