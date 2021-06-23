n = int(input())
paper = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    paper.append(tmp)
white, blue = 0, 0

def division(x, y, n):
    global blue, white
    color = paper[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if color != paper[i][j]:
                division(x,y,n//2)
                division(x,y+n//2,n//2)
                division(x+n//2,y,n//2)
                division(x+n//2,y+n//2,n//2)
                return
    if color == 0:
        white += 1
        return
    elif color == 1:
        blue += 1
        return
    
division(0, 0, n)
print(white)
print(blue)