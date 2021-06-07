# 파스칼 삼각형

n, k=map(int, input().split())
d=[]

for i in range(n+1) :
    d.append([1]*(i+1))

for i in range(2, n+1) :
    for j in range(1, i) :
        d[i][j]=(d[i-1][j-1]+d[i-1][j])%10007

print(d[n][k])