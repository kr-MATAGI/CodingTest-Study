n = int(input())
paper = []
for _ in range(n):
    tmp = list(map(int, input()))
    paper.append(tmp)
result = []

def division(x,y,n):
    global result
    color = paper[x][y]

    for i in range(x, x+n):
        for j in range(y, y+n):
            if color != paper[i][j]:
                result.append("(")
                division(x,y,n//2)
                division(x, y+n//2, n//2)
                division(x+n//2, y, n//2)
                division(x+n//2, y+n//2, n//2)
                result.append(")")
                return
    result.append(color)

division(0,0,n)
print("".join(map(str,(result))))