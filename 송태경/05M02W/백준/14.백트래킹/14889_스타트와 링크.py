from itertools import combinations
import sys

n = int(sys.stdin.readline())
s = []
for _ in range(n):
    s.append(list(map(int, sys.stdin.readline().split())))
mem_list = [i for i in range(1, n+1)]
team_list = list(combinations(mem_list, int(n//2)))

gap_list = [] 
for i in range(len(team_list)//2):
    power_S = 0
    for j in range(n//2):
        for k in team_list[i]:
            power_S += s[team_list[i][j]-1][k-1]
    power_L = 0
    for j in range(n//2):
        for k in team_list[-i-1]:
            power_L += s[team_list[-i-1][j]-1][k-1]
    gap_list.append(abs(power_S - power_L))
    
print(min(gap_list))