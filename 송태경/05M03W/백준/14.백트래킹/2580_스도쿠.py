 sudoku = [[0, 3, 5, 4, 6, 9, 2, 7, 8],
          [7, 8, 2, 1, 0, 5, 6, 0, 9],
          [0, 6, 0, 2, 7, 8, 1, 3, 5],
          [3, 2, 1, 0, 4, 6, 8, 9, 7],
          [8, 0, 4, 9, 1, 3, 5, 0, 6],
          [5, 9, 6, 8, 2, 0, 4, 1, 3],
          [9, 1, 7, 6, 5, 2, 0, 8, 0],
          [6, 0, 3, 7, 0, 1, 9, 5, 2],
          [2, 5, 8, 3, 9, 4, 7, 6, 0]]
          
import sys
r = sys.stdin.readline

def tt(x, y, index):
    r_x = x//3*3
    r_y = y//3*3
    for i in range(3):
        for j in range(3):
            if index == sudoku[i+r_x][j+r_y]:
                return False
    return True

def hori(x, index):
    if index in sudoku[x]:
        return False
    return True

def verti(y, index):
    for i in range(9):
        if index == sudoku[i][y]:
            return False
    return True


def dfs(index):
    if index == len(zeros):
        for row in sudoku:
            for n in row:
                print(n, end=" ")
            print()
        sys.exit(0)
    else:
        for i in range(1, 10):
            x = zeros[index][0]
            y = zeros[index][1]

            if hori(x, i) and verti(y, i) and tt(x, y, i):
                sudoku[x][y] = i
                dfs(index+1)
                sudoku[x][y] = 0


sudoku = [list(map(int, r().split())) for _ in range(9)]
zeros = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]

dfs(0)