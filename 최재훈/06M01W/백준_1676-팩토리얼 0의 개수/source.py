N = int(input())

nFact = 1
for val in range(1, N+1):
    nFact *= val
result = list(str(nFact))[::-1]

cnt = 0
for ch in result:
    if '0' != ch: break
    else: cnt += 1
print(cnt)
