n, m = map(int, input().split())

def n_counter(n, k):
    cnt = 0
    while n:
       n //= k
       cnt += n
    return cnt
n_counter(25, 2)

two_counter = n_counter(n,2) - n_counter(m,2) - n_counter(n-m,2)
five_counter = n_counter(n,5) - n_counter(m,5) - n_counter(n-m,5)
print(min(two_counter, five_counter))