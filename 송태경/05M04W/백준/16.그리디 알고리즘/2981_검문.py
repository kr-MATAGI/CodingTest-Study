def get_gcd(a, b):
    if(b > a):
        num_1 = b
        num_2 = a
    else:
        num_1 = a
        num_2 = b
        
    if(num_1 % num_2 == 0):
        return num_2
        
    while(num_1 % num_2):
        gcd = num_1 % num_2
        num_1 = num_2
        num_2 = gcd
        
    return gcd

N = int(input())
num_list = [int(input()) for _ in range(N)]
num_list = sorted(num_list, reverse = True)

diff_list = [a - b for a, b in zip(num_list, num_list[1:] + [0])][:-1]

init_gcd = diff_list[0]
for i in range(1, len(diff_list)):
    init_gcd = get_gcd(init_gcd, diff_list[i])

results = []

for i in range(2, int(init_gcd ** (1/2)) + 1):
    if(init_gcd % i == 0):
        results.append(i)
        if(init_gcd // i != i):
            results.append(init_gcd // i)
results.append(init_gcd)
results = sorted(set(results))

print(''.join([str(i) + ' ' for i in results])[:-1])