t = int(input())
stack = []
cnt = 0
result = []
torf = True

for _ in range(t):
    n = int(input())
    while cnt < n:
        cnt += 1
        stack.append(cnt)
        result.append('+')
    if stack[-1] == n:
        stack.pop()
        result.append('-')
    else:
        torf = False
        
if torf == False:
    print('NO')
else:
    for i in result:
        print(i)