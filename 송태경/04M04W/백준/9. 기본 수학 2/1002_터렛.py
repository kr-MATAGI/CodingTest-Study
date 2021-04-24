t = int(input())
for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    r = ((x2-x1)**2 + (y2-y1)**2)** (1/2)
    r_list = [r, r1, r2]
    max_r = max(r_list)
    r_list.remove(max_r)
    if r == 0 and r1 == r2 :  # 두 원이 동심원이고 반지름이 같을 때
        print(-1)
    elif abs(r1-r2) == r or r1+r2 == r:  # 내접, 외접일 때
        print(1)
    elif abs(r1-r2) < r < (r1+r2) :  # 두 원이 서로다른 두 점에서 만날 때
        print(2)
    else:
        print(0)  # 그 외에