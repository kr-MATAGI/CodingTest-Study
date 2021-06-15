"""
최대공약수와 최소공배수
|문제 설명|
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

|제한 사항|
두 수는 1이상 1000000이하의 자연수입니다.

|입출력 예|
n	m	return
3	12	[3, 12]
2	5	[1, 10]

입출력 예 설명
입출력 예 #1
위의 설명과 같습니다.

입출력 예 #2
자연수 2와 5의 최대공약수는 1, 최소공배수는 10이므로 [1, 10]을 리턴해야 합니다.
"""

import math

def solution(n, m):
  return [math.gcd(n,m), n*m//math.gcd(n,m)]

# =========================================================================

def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)

def lcm(a, b):
    return int(a * b / gcd(a, b))


def gcdlcm(a, b):
    answer = [gcd(a,b), lcm(a,b)]
    return answer

# =========================================================================

def gcdlcm2(a, b):
    for i in range(a):
        if a%(a-i)+b%(a-i) == 0:
            return [a-i, a*b/(a-i)]

# =========================================================================

# 유클리드 호제법 => 최대공약수 구하는 알고리즘
  # => MOD 연산을 이용한 방법
# MOD연산이란? 두 값을 나눈 나머지를 구하는 연산!
def uclidean_gcdlcm(a, b):
    c, d = max(a, b), min(a, b)
    t = 1
    while t > 0:
        t = c % d
        c, d = d, t
    answer = [c, int(a*b/c)]

    return answer