# 파스칼 삼각형

n, k = map(int, input().split())
pascal_tri = []

for i in range(1, n+2):
    pascal_tri.append([1]*i)
    
for i in range(2, n+1) :
    for j in range(1, i) :
        pascal_tri[i][j]=pascal_tri[i-1][j-1]+pascal_tri[i-1][j]
        
print(pascal_tri[n][k]%10007)