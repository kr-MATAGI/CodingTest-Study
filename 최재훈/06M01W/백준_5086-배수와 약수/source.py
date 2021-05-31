import sys
input = sys.stdin.readline

'''
    첫 번째 숫자가 두 번째 숫자의 약수라면 factor
    배수라면 multiple
    둘 다 아니라면 neither
'''
answerList = [ 'factor', 'multiple', 'neither']

while(True):
    testCase = list(map(int, str(input()).split()))
    if 0 == testCase[0] and 0 == testCase[1]: break

    if 0 == testCase[1] % testCase[0]: print(answerList[0])
    elif 0 == testCase[0] % testCase[1]: print(answerList[1])
    else: print(answerList[2])