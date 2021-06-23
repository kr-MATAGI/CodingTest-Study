n, m = map(int, input().split())
arr_A = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr_A.append(tmp)

m, k = map(int, input().split())
arr_B = []
for i in range(m):
    tmp = list(map(int, input().split()))
    arr_B.append(tmp)
result = []
for n_ in range(n):
    tmp_list = []
    for k_ in range(k):
        tmp = 0
        for m_ in range(m):
            tmp += arr_A[n_][m_]*arr_B[m_][k_]
        tmp_list.append(tmp)
    result.append(tmp_list)
    
for i in result:
    for j in i:
        print(j, end=' ')
    print()