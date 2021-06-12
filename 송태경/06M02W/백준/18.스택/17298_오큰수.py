n = int(input())
n_list= list(map(int, input().split()))
stack = []
result = [-1]*n

for i in range(len(n_list)):
    while len(stack) != 0 and n_list[stack[-1]] < n_list[i]:
        result[stack.pop()] = n_list[i]
    stack.append(i)
for i in result:
    print(i, end =' ')