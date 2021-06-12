from collections import deque
import sys

t = int(sys.stdin.readline())

for _ in range(t):
    exe = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    dq = sys.stdin.readline()[1:-2].split(',')
    dq = deque(dq)
    error = 0
    reverse = 0
    
    for e in exe:
        if e == 'R':
            if reverse == 0:
                reverse = 1
            else:
                reverse = 0
        elif e == 'D':
            if dq and dq[0] != '':
                if reverse == 0:
                    dq.popleft()
                else:
                    dq.pop()
            else:    
                error = 1
                break
    if error == 1:
        print('error')
    else:
        if reverse == 1:
            dq.reverse()
        print('[', end = '')
        for i in range(len(dq)):
            print(dq[i],end="")
            if i != len(dq)-1:
                print(",",end="")
        print("]")