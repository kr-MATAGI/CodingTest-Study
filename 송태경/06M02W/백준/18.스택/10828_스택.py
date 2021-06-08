import sys
n = int(sys.stdin.readline())
stack = []
for _ in range(n):
    action = sys.stdin.readline().split()
    if action[0] == 'push':
        stack.append(action[1])
    elif action[0] == 'pop':
        if len(stack) == 0: 
            print(-1)
        else:   
            print(stack.pop())
    elif action[0] == 'size':
        print(len(stack))
    elif action[0] == 'empty':
        if len(stack) == 0: 
            print(1)
        else:   
            print(0)
    elif action[0] == 'top':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])