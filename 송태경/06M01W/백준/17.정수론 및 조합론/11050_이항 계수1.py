# 자연수 n 및 정수 k가 주어졌을 때, 이항 계수 (n k)는 다음과 같다.
# (n k) = n!/k!(n-k)! (0 <= k <= n)
#         0           (k<0)
#         0           (k>n)

n, k = map(int, input().split())
def facto(n):
    mul = 1
    for i in range(1, n+1):
        mul *= i
    return(mul)
print(int(facto(n)/(facto(k)*facto(n-k))))

# 참고
n,k=map(int, input().split())
a = 1
b = 1
while k:
    a*=n
    b*=k
    n-=1
    k-=1
print(a//b)