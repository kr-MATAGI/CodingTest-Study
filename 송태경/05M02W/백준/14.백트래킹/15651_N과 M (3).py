n, m = map(int, input().split())

array = []
def back(x):
    if x == m:
        print(' '.join(map(str, array)))            
        return
            
    for i in range(n):
        array.append(i+1)
        back(x + 1)
        array.pop()         
        
back(0)   