def pibo(n):
    if n <= 1:
        return n
    return pibo(n-1)+pibo(n-2)

print(pibo(int(input())))