# (n k) = n!/(k!(n-k)!)
n, k = map(int, input().split())
p = 1000000007

def power(a, b):
    if b == 0:
        return 1
    if b%2 == 1:
        return (power(a, b // 2) ** 2 * a) % p
    else:
        return (power(a, b // 2) ** 2) % p

fact = [1 for _ in range(n+1)]
for i in range(2, n+1):
    fact[i] = fact[i - 1] * i % p

a = fact[n]
b = (fact[n-k] * fact[k]) % p

# (A % p) * (B^p-2 % p) % p 
print((a%p) * (power(b, p-2)%p)%p)