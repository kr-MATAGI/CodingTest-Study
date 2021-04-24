def is_prime_number(x):
    if x == 1:
        return False
    for i in range(2, x):
        if x % i == 0:
    	    return False
    return True

n = int(input())
numbers = list(map(int, input().split()))
answer = []
for nn in range(n):
    if is_prime_number(numbers[nn]) == True:
        answer.append(numbers[nn])
print(len(answer))

# -----------------------------------------------------

n=int(input())
li=list(map(int,input().split()))
cnt=0
for i in li:
    f=True
    if i<=1:continue
    for j in range(2,i):
        if i%j==0:
            f=False
            break
    if f:
        cnt+=1
print(cnt)
    