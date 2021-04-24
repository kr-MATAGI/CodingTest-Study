def is_prime_number(num):
    if num==1:
        return False
    else:
        for i in range(2, int(num**0.5)+1):
            if num%i == 0:
                return False
        return True

m, n = map(int, input().split())

for i in range(m, n+1):
    if is_prime_number(i):
        print(i)

# --------------------------------------------------

m, n = map(int, input().split())
li = [False] + [True] * ((n - 1) // 2)
for x in range(1, int(n**.5/2+1)):
    if li[x]:
        li[2*x*(x+1)::x*2+1] = [False] * ((((n + 1) // 2) - x * x * 2) // (x * 2 + 1))
if m <= 2:
    print(2)
print('\n'.join([f'{x}' for x, val in zip(range(m+(m&1==0), n+1, 2), li[m//2:]) if val]))