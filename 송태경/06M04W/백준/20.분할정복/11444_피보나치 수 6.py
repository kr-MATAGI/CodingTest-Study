# https://www.acmicpc.net/blog/view/28
# 아주 큰 수의 피보나치를 빠르게 구하는 방법 => 행렬의 거듭제곱 사용

"""
(a*a*a)%c = ((a%c)*(a%c)*(a%c))%c
n%2 == 0 => n//2
pow(a,y), 즉 a^y 를 구할때 만약 y가 홀수면 a * a^y/2*a^y/2로 분해하여 
짝수 거듭 제곱의 반을 구해가면서 O(lgY)의 복잡도로 구할 수 있다.
"""

n = int(input())
divi = 1000000007
first_arr = [[1, 1],[1, 0]]

def multi(first_arr, b):
    fibo_arr = [] 
    for i in range(2):
        fibo_arr.append([])
        for j in range(len(b[0])):
            sum = 0
            for k in range(2):
                sum += first_arr[i][k]*b[k][j]
            fibo_arr[i].append(sum%divi)
    return fibo_arr

def power(first_arr, n):
    if n == 1:
        return first_arr
    else: 
        temp = power(first_arr, n//2) 
        if n%2 == 0: 
            return multi(temp, temp) 
        else: 
            return multi(multi(temp, temp), first_arr)
        
print(power(first_arr, n)[0][1])