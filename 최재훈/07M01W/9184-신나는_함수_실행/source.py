import sys
input = sys.stdin.readline

dpArray = [ [ [ 0 for k in range(21) ] for j in range(21) ] for i in range(21) ] 

def wFunction(a, b, c):
    if (a <= 0) or (b <= 0) or (c <= 0):
        return 1
    elif (a > 20) or (b > 20) or (c > 20):
        if (0 != dpArray[20][20][20]): return dpArray[20][20][20]
        else: return wFunction(20, 20, 20)
    elif (a < b) and (b < c):
        calc_1 = dpArray[a][b][c-1]
        if (0 == calc_1): 
            calc_1 = wFunction(a, b, c-1)
            dpArray[a][b][c-1] = calc_1

        calc_2 = dpArray[a][b-1][c-1]
        if (0 == calc_2):
            calc_2 = wFunction(a, b-1, c-1)
            dpArray[a][b-1][c-1] = calc_2

        calc_3 = dpArray[a][b-1][c]
        if (0 == calc_3):
            calc_3 = wFunction(a, b-1, c)
            dpArray[a][b-1][c] = calc_3
        
        return calc_1 + calc_2 - calc_3
    else:
        calc_1 = dpArray[a-1][b][c]
        if (0 == calc_1):
            calc_1 = wFunction(a-1, b, c)
            dpArray[a-1][b][c] = calc_1
        
        calc_2 = dpArray[a-1][b-1][c]
        if (0 == calc_2):
            calc_2 = wFunction(a-1, b-1, c)
            dpArray[a-1][b-1][c] = calc_2
        
        calc_3 = dpArray[a-1][b][c-1]
        if (0 == calc_3):
            calc_3 = wFunction(a-1, b, c-1)
            dpArray[a-1][b][c-1] = calc_3        
        
        calc_4 = dpArray[a-1][b-1][c-1]
        if (0 == calc_4):
            calc_4 = wFunction(a-1, b-1, c-1)
            dpArray[a-1][b-1][c-1] = calc_4

        return calc_1 + calc_2 + calc_3 - calc_4

while(True):
    a, b, c = list(map(int, str(input()).split()))
    if(-1 == a) and (-1 == b) and (-1 == c): break
    else: 
        answer = "w(%d, %d, %d) = " % (a,b,c)
        result = wFunction(a,b,c)
        answer += str(result)
        print(answer)
