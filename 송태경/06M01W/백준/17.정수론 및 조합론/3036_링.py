def GCD(a,b):
  for i in range(a if a>b else b, 0, -1):
    if a%i == 0 and b%i == 0:
        return i
    
n = int(input())
r = list(map(int, input().split()))

l = 2*r[0]
for i in range(1,len(r)):
    round = r[i]*2
    gcd = GCD(l, round)
    print('{}/{}'.format(l//gcd, round//gcd))