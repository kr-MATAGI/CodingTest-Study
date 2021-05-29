n = int(input())
dist = list(map(int, input().split()))
price = list(map(int, input().split()))

mini_p = price[0]
total = 0

for i in range(n-1):
    if mini_p > price[i]:
        mini_p = price[i]
    total += mini_p*dist[i]
print(total)