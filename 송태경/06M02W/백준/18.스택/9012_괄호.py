n = int(input())
for _ in range(n):
    s = input()
    sum = 0
    for i in s:
        if i =='(':
            sum += 1
        elif i == ')':
            sum -= 1
        if sum < 0:
            print('NO')
            break
    if sum == 0:
        print('YES')
    elif sum > 0:
        print('NO')