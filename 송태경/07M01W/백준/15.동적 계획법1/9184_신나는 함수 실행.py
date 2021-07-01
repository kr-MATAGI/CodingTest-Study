matrix = [[[0]*21 for _ in range(21)] for _ in range(21)]

def w(a,b,c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)

    if matrix[a][b][c]:
        return matrix[a][b][c]

    if a < b < c:
        matrix[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
  
    matrix[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
    return matrix[a][b][c]

while True:
    a,b,c = map(int, input().split())
    if a == b == c == -1:
        break
    print('w({}, {}, {}) = {}'.format(a,b,c, w(a,b,c)))