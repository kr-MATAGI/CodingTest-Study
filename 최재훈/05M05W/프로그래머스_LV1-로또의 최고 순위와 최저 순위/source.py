def check(correctCnt):
    retValue = 0

    if 6 == correctCnt:
        retValue = 1
    elif 5 == correctCnt:
        retValue = 2
    elif 4 == correctCnt:
        retValue = 3
    elif 3 == correctCnt:
        retValue = 4
    elif 2 == correctCnt:
        retValue = 5
    else:
        retValue = 6
    
    return retValue

def solution(lottos, win_nums):
    answer = []

    zeroCount = 0
    correctCount = 0
    for lottoNum in lottos:
        for winNum in win_nums:
            if lottoNum == winNum:
                correctCount += 1
                break
            elif 0 == lottoNum:
                zeroCount += 1
                break
    
    allCorrect = correctCount + zeroCount
    notAll = correctCount

    maxRank = check(allCorrect)
    minRank = check(notAll)

    answer.append(maxRank)
    answer.append(minRank)

    print(answer)
    return answer


lottos = [44, 1, 0, 0, 31, 25]
win_nums = [31, 10, 45, 1, 6, 19]
solution(lottos, win_nums)