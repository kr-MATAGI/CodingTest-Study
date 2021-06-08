import sys
n = int(sys.stdin.readline())
stack = []
for _ in range(n):
    inum = int(sys.stdin.readline())
    if inum == 0:
        stack.pop()
    else:
        stack.append(inum)
print(sum(stack))