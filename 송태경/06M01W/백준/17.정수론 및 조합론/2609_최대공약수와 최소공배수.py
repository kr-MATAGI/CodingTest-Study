n, m = map(int, input().split())
if n > m:
    biggy = n
else:
    biggy = m
for i in range(biggy, 0, -1):
    if n%i == 0 and m%i == 0:
        GCD = i
        break
LCM = int(n*m/GCD)
print(GCD, LCM)