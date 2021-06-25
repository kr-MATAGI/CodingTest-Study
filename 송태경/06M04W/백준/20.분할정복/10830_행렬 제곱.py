# (a*a*a)%c = ((a%c)*(a%c)*(a%c))%c

n, b = map(int, input().split())
arr_A = []
for i in range(n):
    arr_A.append(list(map(int, input().split())))
    
def division(b):
    global arr_A
    if b == 1:
        for i in range(n):
            for j in range(n):
                tmp = arr_A[i][j]%1000
                arr_A[i][j] = tmp
        return arr_A
    elif b % 2 == 1:
        tmp = [[0]*n for _ in range(n)]
        c = division(b-1)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    tmp[i][j] += c[i][k] * arr_A[k][j]
                tmp[i][j] %= 1000
        return tmp
    else:
        tmp = [[0] * n for _ in range(n)]
        c = division(b//2)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    tmp[i][j] += c[i][k] * c[k][j]
                tmp[i][j] %= 1000
        return tmp

result = division(b)
for i in range(n):
    for j in range(n):
        print(result[i][j], end=" ")
    print()