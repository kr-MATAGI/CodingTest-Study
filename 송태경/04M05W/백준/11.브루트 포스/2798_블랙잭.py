n, m = map(int, input().split())
card_list = list(map(int, input().split()))

sum_list = []

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            temp = card_list[i] + card_list[j] + card_list[k]
            sum_list.append(temp)
answer_list = []
for i in sum_list:
    if i <= m:
        answer_list.append(i)
        
print(max(answer_list))