import sys
input = sys.stdin.readline

T = int(input())
dpDict = {}
for tdx in range(T):
    N, M = list(map(int, str(input()).split()))
    
    if(N == M): print(1)
    else:
        # r!
        rFact = 1
        if N in dpDict.keys(): rFact = dpDict.get(N)
        else:
            for r in range(1, N+1): rFact *= r

        # (n-r)!
        nrFact = 1
        if (M-N) in dpDict.keys(): nrFact = dpDict.get(M-N)
        else:
            for nr in range(1, M-N+1): nrFact *= nr

        # n!
        nFact = 1
        if M in dpDict.keys(): nrFact = dpDict.get(M)
        else:
            for n in range(1, M+1): nFact *= n
        
        print(int(nFact / (nrFact*rFact)))