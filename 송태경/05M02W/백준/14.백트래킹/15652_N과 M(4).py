n, m = map(int, input().split())

array = []
def back(x, tmp):
    if x == m:
        print(' '.join(map(str, array)))            
        return
            
    for i in range(tmp, n):
        array.append(i+1)
        back(x+1, i)
        array.pop()         
        
back(0, 0)   