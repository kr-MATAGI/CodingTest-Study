n = int(input())
s = list(map(int, input().split()))
s.sort()
time = []
total = 0
for i in s:
    total+=i
    time.append(total)
print(sum(time))