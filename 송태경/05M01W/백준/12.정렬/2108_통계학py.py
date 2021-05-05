import sys
t = int(sys.stdin.readline())
n_list= []
for _ in range(t):
    n_list.append(int(sys.stdin.readline()))
    
print(round(sum(n_list)/len(n_list)))

n_list.sort()
print(n_list[t//2])

from collections import Counter
k=Counter(n_list).most_common()
if len(n_list) > 1:
    if k[0][1] == k[1][1]:
        print(k[1][0]) 
    else : 
        print(k[0][0]) 
else : 
    print(n_list[0]) 
    
print(n_list[-1] -  n_list[0])