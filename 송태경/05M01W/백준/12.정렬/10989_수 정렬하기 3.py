# 메모리를 적게 써야 한다

'''
파이썬의 좋은 점은 파이썬의 모든 것이 객체라는 것
이것은 동적 메모리 할당이 파이썬 메모리 관리의 기초라는 것을 의미
객체가 더 이상 필요하지 않으면 Python 메모리 관리자가 자동으로 객체에서 메모리를 회수
'''

# 입력 받는 수의 범위만큼 배열을 미리 만들어 놓고 사용

import sys
n = int(sys.stdin.readline())
cnt_list = [0] * 10001  # 0번째를 카운트 하지 않기 위해, 10001개로

for i in range(n):
    cnt_list[int(sys.stdin.readline())] += 1
    # if 1 3 5 1 => [0, 2, 0, 1, 0, 1]

for i in range(10001):
    if cnt_list[i] != 0:
        for j in range(cnt_list[i]):
            print(i)

# 거의 브루트 포스 
