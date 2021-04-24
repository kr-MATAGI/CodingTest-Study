def is_prime_number(num):
    if num==1:
        return False
    else:
        for i in range(2, int(num**0.5)+1):
            if num%i == 0:
                return False
        return True

# Tip: 소수 리스트 미리 만들때 홀수만 하면 속도 더 줄어듬
num_list = list(range(2,246912))
sort_list = []
for i in num_list:
    if is_prime_number(i):
         sort_list.append(i)

while True:
    n = int(input())
    if n == 0:
        break
    cnt = 0
    for i in sort_list:
        if n < i <= n*2:
            cnt += 1
    print(cnt)     