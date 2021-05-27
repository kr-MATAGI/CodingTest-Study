def calc(answer, n, arr):
    for i, item in enumerate(arr) :
        binList = list(str(bin(item).replace('0b', '')))
        convertedList = [0 for idx in range(n)]
        convertedIdx = n - 1
        for idx in range(int(binList.__len__()) - 1, -1, -1):
            convertedList[convertedIdx] = binList[idx]
            convertedIdx -= 1
        
        for j, element in enumerate(convertedList):
            if('1' == element):
                answer[i][j] = '#'

    return answer

def solution(n, arr1, arr2):
    answer = [ [' ' for idx in range(n)] for jdx in range(n) ]

    answer = calc(answer, n , arr1)
    answer = calc(answer, n , arr2)

    retValue = []
    for item in answer:
        str = ''
        for ch in item : str += ch
        retValue.append(str)
    answer = retValue

    return answer

if __name__ == '__main__':
    '''
        1. 지도는 한 변의 길이가 n, 각 칸은 '' 혹은 '#'으로 이루어져 있다.
        2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다.
           지도 1, 2 중 어느 하나라도 벽인 부분은 전체 지도에서 벽이다.
        3. 지도 1과 2는 각각 정수 배열의 암호로 되어있다.
        4. 암호화된 배열은 지도의 각 가로줄 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 배열
    '''
    n  = 5
    arr1 = [9, 20, 28, 18, 11]
    arr2 = [30, 1, 21, 17, 28]
    answer = solution(n, arr1, arr2)

    print(n)
    print(arr1)
    print(arr2)
    print(answer)
