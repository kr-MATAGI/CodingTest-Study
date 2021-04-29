n,m = map(int, input().split())
board = []
for _ in range(n):
    board.append(input())
check = []
for i in range(n-7):
    for j in range(m-7):
        cnt_black = 0
        cnt_white = 0
        
        for x in range(i, i+7+1):
            for y in range(j, j+7+1):
                if (x+y)%2 == 0:
                    if board[x][y] == 'B':
                        cnt_white += 1
                    else:
                        cnt_black += 1
                else:
                    if board[x][y] == 'W':
                        cnt_white += 1
                    else:
                        cnt_black += 1
        check.append(cnt_black)
        check.append(cnt_white)
print(min(check))