import sys

n = int(sys.stdin.readline())
n_list = list(map(int, input().split()))
tmp = list(set(n_list))
tmp.sort()
n_dic = {tmp[i]: i for i in range(len(tmp))}
for i in n_list:
    print(n_dic[i], end = ' ')