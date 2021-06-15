"""
문자열 내림차순으로 배치하기
|문제 설명|
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

|제한 사항|
str은 길이 1 이상인 문자열입니다.

|입출력 예|
s	return
"Zbcdefg"	"gfedcbZ"
"""
def solution1(s):
    upper_list = []
    lower_list = []
    for i in range(len(s)):
        if ord(s[i]) <= 90:
            upper_list.append(ord(s[i]))
        else:
            lower_list.append(ord(s[i]))

    lower_list.sort(reverse=True)
    upper_list.sort(reverse=True)

    for i in range(len(lower_list)):
        lower_list[i] = chr(lower_list[i])
    for i in range(len(upper_list)):
        upper_list[i] = chr(upper_list[i])
    
    return ''.join(lower_list+upper_list)

def solution2(s):
    s = list(s)
    return ''.join(sorted(s, reverse=True))