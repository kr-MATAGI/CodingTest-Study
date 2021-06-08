import sys

def u_gcd(a,b):
    while(a!=b):
        if a>b: a-=b
        else:   b-=a
    return a

t = int(sys.stdin.readline())
num_list = [int(input()) for _ in range(t)]
num_list = sorted(num_list, reverse = True)

gap_list = []
for i in range(len(num_list)-1):
    gap_list.append(num_list[i]-num_list[i+1])
    
tmp = gap_list[0]
for i in range(1, len(gap_list)):
    tmp = u_gcd(tmp, gap_list[i])
    
answer = []
for i in range(2, int(tmp ** (1/2)) + 1):
    if(tmp % i == 0):
        answer.append(i)
        if(tmp // i != i):
            answer.append(tmp // i)
answer.append(tmp)
answer = sorted(set(answer))
print(''.join([str(i) + ' ' for i in answer])[:-1]) 