import sys

t = int(sys.stdin.readline())
w_list = []

for _ in range(t):
    w_list.append(input())

w_list = list(set(w_list))
w_list.sort(key=lambda x : (len(x),x))

print("\n".join(w_list))

# -------------------------------------------------

import sys
t = int(sys.stdin.readline())
w_list = []

for _ in range(t):
    word = str(input())
    w_list.append(word)
    
w_list = list(set(w_list))

w_list.sort(key = lambda x: (len(x), x))

for word in w_list:
    print(word)