def back(cnt, result, plus, minus, mul, div):
    if cnt == n:
        result_list.append(result)
        return
    if plus:
        back(cnt+1, result+n_list[cnt], plus-1, minus, mul, div)
    if minus:
        back(cnt+1, result-n_list[cnt], plus, minus-1, mul, div)
    if mul:
        back(cnt+1, result*n_list[cnt], plus, minus, mul-1, div)
    if div:
        if result < 0:
            back(cnt+1, -(-result//n_list[cnt]), plus, minus, mul, div-1)
        else:
            back(cnt+1, result//n_list[cnt], plus, minus, mul, div-1)

n = int(input())
n_list = list(map(int, input().split()))
cal = list(map(int, input().split()))
result_list = []
back(1, n_list[0], cal[0], cal[1], cal[2], cal[3])
print(max(result_list), min(result_list))