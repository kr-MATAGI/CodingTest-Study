s = input().split('-')
final_num = []
for i in s:
    p = 0
    new_i = i.split('+')
    for j in new_i:
        p += int(j)
    final_num.append(p)
result = final_num[0]
for i in final_num[1:]:
    result -= i
print(result)

# 코드 짧고 쪼끔 더 빨라진거
s = input().split('-')
new_sum = []
for i in s:
    tmp = sum(map(int, i.split('+')))
    new_sum.append(tmp)
print(new_sum[0] - sum(new_sum[1:]))