t = int (input())
for _ in range(t):
    n, m = map(int, input().split())
    jung = list(map(int, input().split()))
    docu = [0 for i in range(n)]
    docu[m] = 'tracking'
    order = 0

    while True:
        if jung[0] == max(jung):
            order += 1
            if docu[0] == 'tracking':
                print(order)
                break
            else:
                jung.pop(0)
                docu.pop(0)

        else:
            jung.append(jung.pop(0))
            docu.append(docu.pop(0))  