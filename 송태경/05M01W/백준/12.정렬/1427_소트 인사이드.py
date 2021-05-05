n = input()
n_list = []
for i in n:
    n_list.append(i)
n_list.sort(reverse=True)
print(''.join(n_list))