n, k = map(int, input().split())
coin = [int(input()) for i in range(n)]
coin.sort(reverse=True)
devi = []
for i in range(len(coin)):
    if k//coin[i] != 0:
        devi.append(k//coin[i])
        k = k%coin[i]
print(sum(devi))