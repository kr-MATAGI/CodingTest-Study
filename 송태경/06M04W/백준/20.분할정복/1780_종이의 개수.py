n = int(input())
paper = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    paper.append(tmp)
m_one, z_one, p_one = 0, 0, 0

def division(x, y, n):
    global m_one, z_one, p_one
    nn = paper[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if nn != paper[i][j]:
                t = n//3
                division(x,y,t)
                division(x+t,y,t)
                division(x+t*2,y,t)
                division(x,y+t,t)
                division(x+t,y+t,t)
                division(x+t*2,y+t,t)
                division(x,y+t*2,t)
                division(x+t,y+t*2,t)
                division(x+t*2,y+t*2,t)
                return
    if nn == -1:
        m_one += 1
        return
    elif nn == 0:
        z_one += 1
        return
    elif nn == 1:
        p_one += 1
        return
    
division(0, 0, n)
print(m_one)
print(z_one)
print(p_one)