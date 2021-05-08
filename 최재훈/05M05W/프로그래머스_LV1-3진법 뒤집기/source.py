def solution(n):
    answer = 0

    threeDeg = []
    while(True) :
        if 0 == n:
            break
        
        threeDeg.append(int(n % 3))
        n = int(n / 3)

    print(threeDeg)
    threeDeg.reverse()
    multi = 1
    for item in threeDeg:
        answer += (item * multi)
        multi *= 3

    print(answer)

    return answer

n = 45
solution(n)

n = 125
solution(n)

n = 100000000
solution(n)
