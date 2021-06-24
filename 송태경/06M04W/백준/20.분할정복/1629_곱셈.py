# (a*a*a)%c = ((a%c)*(a%c)*(a%c))%c

a,b,c = map(int, input().split())

def solution(b):
    if b == 1:
        return a%c
    if b%2 == 0:
        ss = solution(b//2)
        return ss*ss%c
    else:
        ss = solution(b//2)
        return ss*ss*a%c
    
print(solution(b))

#----------------------------------------

A, B, C = map(int, input().split()) 
print(pow(A, B, C))