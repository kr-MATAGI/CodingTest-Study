import sys
n = int(sys.stdin.readline())
deque = []
for _ in range(n):
    action = sys.stdin.readline().split()
    if action[0] == 'push_front':
        deque.insert(0, action[1])
    elif action[0] == 'push_back':
        deque.append(action[1])
    elif action[0] == 'pop_front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(0))
    elif action[0] == 'pop_back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(-1))
    elif action[0] == 'size':
        print(len(deque))
    elif action[0] == 'empty':
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    elif action[0] == 'front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
    elif action[0] == 'back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[-1])