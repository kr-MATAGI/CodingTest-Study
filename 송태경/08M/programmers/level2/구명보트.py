def solution(people, limit):
    cnt, i, j = 0, 0, len(people)-1
    people.sort()
    while i <= j:
        cnt += 1
        if people[i]+people[j] <= limit:
            i += 1
        j -= 1
    return cnt