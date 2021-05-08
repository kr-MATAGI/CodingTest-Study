import sys

t = int(sys.stdin.readline())
mem_list = []
for _ in range(t):
    age, name = map(str, input().split())
    mem_list.append([int(age), name])
    
mem_list.sort(key=lambda x: x[0])

for member in mem_list:
    print(member[0], member[1])



import sys
N = int(sys.stdin.readline().strip())

people = []
for _ in range(N):
    people.append(sys.stdin.readline())
people.sort(key=lambda x: int(x[:x.index(" ")]))

for i in people:
    sys.stdout.write(i)