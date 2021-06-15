def measure(n):
    m_list = []
    h = n//2
    for i in range(1,h+1):
        if n%i == 0:
            m_list.append(i)
    m_list.append(n)
    return len(m_list)

def solution(left, right):
    answer = 0
    for i in range(left, right+1):
        if measure(i)%2 == 0:
            answer += i
        else:
            answer -= i
    return answer
    
# ----------------------------------

def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if int(i**0.5)==i**0.5:
            answer -= i
        else:
            answer += i
    return answer