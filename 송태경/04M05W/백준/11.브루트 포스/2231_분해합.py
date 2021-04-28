n = input()
sol = 0
for i in range(1, int(n)+1):
    sum = 0
    for j in range(len(str(i))):
        sum += int(str(i)[j])
    if i+sum == int(n):
        sol = i
        break
print(sol)


n = int(input())
result = 0

for i in range(1, n+1):        
    a = list(map(int, str(i)))  
    s = i + sum(a)              
    if(s == n):                 
        result = i                   
        break

print(result)

# 탐색 범위를 어떻게 설정하느냐에 따라 실행속도 더 줄이기 가능

n = int(input())
result = 0

for i in range(len(str(n)), n+1):        
    a = list(map(int, str(i)))  
    s = i + sum(a)              
    if(s == n):                 
        result = i                   
        break

print(result)
