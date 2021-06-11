import sys
n, k = map(int, sys.stdin.readline().split())

temp = k-1
result = []
n_list = [i for i in range(1, n+1)]

for i in range(n):
    if len(n_list) > temp:
        result.append(n_list.pop(temp))
        temp += k - 1
    elif len(n_list) <= temp:
        temp = temp % len(n_list)
        result.append(n_list.pop(temp))
        temp += k - 1

print("<", end='')
for i in result:
    if i == result[-1]:
        print(i, end = '')
    else:
        print("%s, " %(i), end='')
print(">")