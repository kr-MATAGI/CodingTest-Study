n = input()
sol = 0
for i in range(1, int(n)+1):
    sum = 0
    for j in range(len(str(i))):
        sum += int(str(i)[j])
    if i+sum == int(n):
        sol = i
        break
print(sol)