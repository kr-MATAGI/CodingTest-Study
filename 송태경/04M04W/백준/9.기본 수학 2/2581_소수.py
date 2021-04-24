def is_prime_number(x):
    if x == 1:
        return False
    for i in range(2, x):
        if x % i == 0:
    	    return False
    return True

nn = int(input())
mm = int(input())
prime_list = []
for i in range(nn, mm+1):
    if is_prime_number(i) == True:
        prime_list.append(i)
if len(prime_list) == 0:
    print(-1)
else:
    print(sum(prime_list))
    print(min(prime_list))

# ------------------------------------------------

arr = [False, False] + [True] * 9999
for i in range(2, 101):
    if arr[i]:
        for j in range(i * 2, len(arr), i):
            arr[j] = False

m = int(input())
n = int(input())
nums = [i for i in range(m, n+1) if arr[i]]
print(sum(nums)if len(nums) else -1)
print(min(nums) if len(nums) else '')