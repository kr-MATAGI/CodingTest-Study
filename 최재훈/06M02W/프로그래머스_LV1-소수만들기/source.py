def solution(nums):
    answer = []

    nums.sort(reverse=True)
    maxVal = nums[0] + nums[1] + nums[2]

    che = [True for i in range(maxVal + 1)]
    for i in range(2, maxVal):
        for multi in range(2, maxVal):
            num = i * multi
            if(num > maxVal):
                break
            che[num] = False

    for i, a in enumerate(nums):
        for j, b in enumerate(nums):
            if i == j:
                continue

            for k, c in enumerate(nums):
                if i == k or j == k:
                    continue
                
                sum = a + b + c
                if 1 == sum:
                    continue
                elif True == che[sum]:
                    sumList = [a,b,c]
                    sumList.sort()
                    if sumList not in answer:
                        answer.append(sumList)
                
    # print(answer)
    print(answer.__len__())

    return answer.__len__()

nums = [1,2,7,6,4]
solution(nums)