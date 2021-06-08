import sys
n = int(sys.stdin.readline())

queue = []
cnt = 0
for _ in range(n):
    action = sys.stdin.readline().split()
    if action[0] == 'push':
        queue.append(action[1])
    elif action[0] == 'pop':
        if len(queue) > cnt:
            print(queue[cnt])
            cnt += 1
        else: print(-1)
    elif action[0] == 'size':
        print(len(queue)-cnt)
    elif action[0] == 'empty':
        if len(queue) == cnt: 
            print(1)
            cnt = 0
            queue = []
        else:   
            print(0)
    elif action[0] == 'front':
        if len(queue) > cnt: 
            print(queue[cnt])
        else: 
            print(-1)
    elif action[0] == 'back':
        if len(queue) > cnt: 
            print(queue[-1])
        else: 
            print(-1)