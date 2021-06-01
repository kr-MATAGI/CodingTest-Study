# 25, 12 -> 5200300
N, M = map(int, str(input()).split())
dpDict = dict();
dpDict[0] = 1
dpDict[1] = 1

# r!
rFact = 1
if M % 10007 in dpDict.keys(): rFact = dpDict.get(M % 10007)
else : 
    for r in range(1, (M%10007)+1): rFact *= r
    dpDict[M % 10007] = rFact

# n-r!
nrFact = 1
if (N-M) % 10007 in dpDict.keys(): nrFact = dpDict.get((N-M) % 10007)
else:
    for nr in range(1, (N-M) % 10007 + 1): nrFact *= nr
    dpDict[(N-M) % 10007] = nrFact

# n!
nFact = 1
if N % 10007 in dpDict.keys(): nFact = dpDict.get(N % 10007)
else:
    for n in range(1, N % 10007 +1): nFact *= n
    dpDict[n%10007] = nFact

print(int(nFact // (rFact*nrFact)) % 10007)