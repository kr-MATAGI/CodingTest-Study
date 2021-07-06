# 코드 라인은 줄였는데, 실행시간 조금 늘어남
import sys
input = sys.stdin.readline

dpArray = [ [ [ 0 for k in range(21) ] for j in range(21) ] for i in range(21) ] 

def wFunction(a, b, c):
    if (a <= 0) or (b <= 0) or (c <= 0):
        return 1
    elif (a > 20) or (b > 20) or (c > 20):
        if (0 != dpArray[20][20][20]): return dpArray[20][20][20]
        else: return wFunction(20, 20, 20)
    
    elif (0 != dpArray[a][b][c]): return dpArray[a][b][c]

    elif (a < b) and (b < c):
        dpArray[a][b][c] = wFunction(a, b, c-1) + wFunction(a, b-1, c-1) - wFunction(a, b-1, c)
        return dpArray[a][b][c]
    else:
        dpArray[a][b][c] = wFunction(a-1, b, c) + wFunction(a-1, b-1, c) + wFunction(a-1, b, c-1) - wFunction(a-1, b-1, c-1)
        return dpArray[a][b][c]

while(True):
    a, b, c = list(map(int, str(input()).split()))
    if(-1 == a) and (-1 == b) and (-1 == c): break
    else:
        answer = "w(%d, %d, %d) = " % (a,b,c)
        result = wFunction(a,b,c)
        answer += str(result)
        print(answer)
