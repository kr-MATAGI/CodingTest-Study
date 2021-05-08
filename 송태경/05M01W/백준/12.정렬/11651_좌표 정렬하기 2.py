import sys

t = int(sys.stdin.readline())
n_list = []
for _ in range(t):
    x, y = map(int, sys.stdin.readline().split())
    n_list.append([x,y])
    
n_list.sort(key=lambda x: (x[1], x[0]))
for i in n_list:
    print(i[0],i[1])