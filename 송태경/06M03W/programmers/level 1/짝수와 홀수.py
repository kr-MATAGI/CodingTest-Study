"""
짝수와 홀수
|문제 설명|
정수 num이 짝수일 경우 "Even"을 반환하고 홀수인 경우 "Odd"를 반환하는 함수, solution을 완성해주세요.

|제한 조건|
num은 int 범위의 정수입니다.
0은 짝수입니다.

|입출력 예|
num	return
3	"Odd"
4	"Even"
"""

def solution(num):
    if num == 0:
        return 'Even'
    else:
        if num%2 == 0:
            return 'Even'
        else:
            return 'Odd'
      
def evenOrOdd_1(num):
    return "Even" if num%2 == 0 else "Odd"

def evenOrOdd_2(num):
    if (num%2):
        return "Odd"
    else:
        return "Even"
"""
num % 2가 거짓(0)이라면 num % 2 ==0 (거짓) and Odd 가 되므로, 
둘 다 참이어야하는 조건에 맞지 않기 때문에 
or Even으로 해서 둘 중에 하나라도 참일 때 가능한 Even이 출력되며 , 
num%2가 1(참)이면 and 조건이 성립되어 Odd가 출력됩니다
"""

def evenOrOdd_3(num):
    return ["Even", "Odd"][num & 1]

#  비트 연산자 &
"""
num = 2 (00000010)
      1(00000001)
num&1 =>
  00000010
 &00000001
 -----------
  00000000
  => 0
"""