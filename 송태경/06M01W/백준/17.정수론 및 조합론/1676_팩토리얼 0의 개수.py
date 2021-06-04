n = int(input())
total = 1
for i in range(1, n+1):
    total *= i
total = str(total)
cnt = 0 
for i in range(len(total)-1,0,-1):
    if total[i] == '0':
        cnt += 1
    else:
        break
print(cnt)