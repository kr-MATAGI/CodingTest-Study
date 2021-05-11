n, m = map(int, input().split())

number_list = [1 + i for i in range(n)]
check_number = [False] * n
array = []

def back(x):
    if x == m:
        print(' '.join(map(str, array)))            
        return
            
    for i in range(n):
        if check_number[i]:
            continue
        array.append(number_list[i])
        check_number[i] = True

        back(x + 1)

        array.pop() 
        for j in range(i+1, n):
            check_number[j] = False        
back(0)    