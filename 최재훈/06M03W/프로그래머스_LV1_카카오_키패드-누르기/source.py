def solution(numbers, hand):
    answer = ''

    '''
        10 == '*'
        11 == '#'
    '''
    phoneDict = {1: [1,1], 2: [1,2], 3: [1,3],
                 4: [2,1], 5: [2,2], 6: [2,3],
                 7: [3,1], 8: [3,2], 9: [3,3],
                 10: [4,1], 0: [4,2], 11: [4,3]}


    leftNum = 10
    rightNum = 11
    for number in numbers:
        if 1 == number or 4 == number or 7 == number:
            leftNum = number
            answer += 'L'
        
        elif 3 == number or 6 == number or 9 == number:
            rightNum = number
            answer += 'R'
        
        else:
            midValue = phoneDict[number]
            leftValue = phoneDict[leftNum]
            rightValue = phoneDict[rightNum]

            leftScore = abs(midValue[0] - leftValue[0]) + abs(midValue[1] - leftValue[1])
            rightScore = abs(midValue[0] - rightValue[0]) + abs(midValue[1] - rightValue[1])

            if(leftScore == rightScore):
                if('right' == hand):
                    rightNum = number
                    answer += 'R'
                else:
                    leftNum = number
                    answer += 'L'
            elif(leftScore < rightScore):
                leftNum = number
                answer += 'L'
            else:
                rightNum = number
                answer += 'R'

    return answer

if __name__ == '__main__':
    '''
        엄지손가락은 상화좌우 4가지 방향으로만 이동할 수 있다.
        키패드 이동 한 칸은 거리 1에 해당
        왼쪽 열 3개의 숫자 1,4,7은 왼손 엄지
        오른쪽 열 3개 숫자 3,6,9는 오른손 엄지
        가운데 열 4개의 숫자 2, 5, 8, 0을 입력시 두 엄지손가락의 현재 위치에서 더 가까운 엄지
        (만약 두 엄지 손가락이 같다면, 오른손잡이는 오른손, 왼손잡이는 왼손)
    '''
    numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
    hand = 'right'
    answer = solution(numbers, hand)

    rightAns = 'LRLLLRLLRRL'
    print(numbers)
    print(rightAns)
    print(answer)
    