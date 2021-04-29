t = int(input())
wh_list = []
for _ in range(t):
    a, b = map(int, input().split())
    wh_list.append([a,b])

# cnt_list = []
for i in wh_list:
    count = 1
    for j in wh_list:
        if i[0] < j[0] and i[1] < j[1]:
            count += 1
    # cnt_list.append(count)
    print(count, end = ' ')

for i in cnt_list:
   print(i, end=' ')
   
   
# 리스트 쓰든 안쓰든 실행속도의 차이가 없음?!