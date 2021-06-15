"""
소수 찾기
|문제 설명|
1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.

소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
(1은 소수가 아닙니다.)

|제한 조건|
n은 2이상 1000000이하의 자연수입니다.

|입출력 예|
n	result
10	4
5	3
입출력 예 설명
입출력 예 #1
1부터 10 사이의 소수는 [2,3,5,7] 4개가 존재하므로 4를 반환

입출력 예 #2
1부터 5 사이의 소수는 [2,3,5] 3개가 존재하므로 3를 반환
"""

# 다른 사람 풀이 -> 추가 공부 필요
# 에라토스테네스의 체
def solution(n):
    num = set(range(2, n+1))  # 집합 set => { }

    for i in range(2, n+1):
        if i in num:
            num -= set(range(2*i, n+1, i))
    # return len(num)
    return num

# 자료형 set / 순서가 없는 집합?! 리스트나 튜플로 변환한후 인덱싱
test_set = set([1,2,3])
print(type(test_set))
# test_set

string_set = set('hello world')
str_to_list = list(string_set)
print(string_set)
print(type(str_to_list))
print(str_to_list[0])