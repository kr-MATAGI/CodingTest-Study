def solution(nums):
    answer = 0

    phoneMon = set()
    for num in nums:
        phoneMon.add(num)

    N = int(nums.__len__() / 2)
    phonCnt = phoneMon.__len__()

    if N == phonCnt:
        answer = phonCnt
    elif N < phonCnt:
        answer = N
    elif N > phonCnt:
        answer = phonCnt

    print(N, phoneMon.__len__(), answer)
    return answer

nums = [3, 1, 2, 3]
solution(nums)

nums = [3,3,3,2,2,4]
solution(nums)

nums = [3,3,3,2,2,2]
solution(nums)