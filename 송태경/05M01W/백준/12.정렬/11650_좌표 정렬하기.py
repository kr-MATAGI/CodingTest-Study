import sys

t = int(sys.stdin.readline())
n_list = []
for _ in range(t):
    x, y = map(int, sys.stdin.readline().split())
    n_list.append([x,y])
    
n_list.sort()
for i in n_list:
    print(i[0],i[1])