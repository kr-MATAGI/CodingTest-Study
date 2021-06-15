"""
약수의 합
|문제 설명|
정수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수, solution을 완성해주세요.

|제한 사항|
n은 0 이상 3000이하인 정수입니다.

|입출력 예|
n	return
12	28
5	6
입출력 예 설명
입출력 예 #1
12의 약수는 1, 2, 3, 4, 6, 12입니다. 이를 모두 더하면 28입니다.

입출력 예 #2
5의 약수는 1, 5입니다. 이를 모두 더하면 6입니다.
"""

def solution(n):
    divisor_list = []
    for i in range(1, n):
      if n%i == 0:
        divisor_list.append(i)
    divisor_list.append(n)
    return sum(divisor_list)

def sumDivisor(num):
    # num / 2 의 수들만 검사하면 성능 약 2배 향상잼
    return num + sum([i for i in range(1, (num // 2) + 1) if num % i == 0])