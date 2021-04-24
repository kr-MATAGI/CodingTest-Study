while True:
    n_list = list(map(int, input().split()))
    max_num = max(n_list)
    if sum(n_list) == 0:
            break
    n_list.remove(max_num)
    if n_list[0] ** 2 + n_list[1] ** 2 == max_num ** 2:
        print('right')
    else:
        print('wrong')