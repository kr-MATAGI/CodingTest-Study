def get_prize(n):
    if n == 6:
        return 1
    elif n == 5:
        return 2
    elif n == 4:
        return 3
    elif n == 3:
        return 4
    elif n == 2:
        return 5
    else:
        return 6
    
def solution(lottos, win_nums):
    s_cnt, z_cnt = 0, 0
    for i in lottos:
        if i == 0:
            z_cnt += 1
        if i in win_nums:
            s_cnt += 1
    return [get_prize(s_cnt+z_cnt), get_prize(s_cnt)]
    
# ----------------------------------------------------

def solution(lottos, win_nums):

    rank=[6,6,5,4,3,2,1]

    cnt_0 = lottos.count(0)
    ans = 0
    for x in win_nums:
        if x in lottos:
            ans += 1
    return rank[cnt_0 + ans],rank[ans]