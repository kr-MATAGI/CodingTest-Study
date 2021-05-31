testCase = int(input())

for tc in range(testCase):
    N = int(input())

    clothesDict = dict()
    clothSet = set()
    for n in range(N):
        name, cloth = str(input()).split()

        if cloth in clothesDict.keys():
            temp = clothesDict.get(cloth)
            if( type(temp) == type(list()) ): temp.append(name)
            clothesDict[cloth] = temp
        else:
            temp = []
            temp.append(name)
            clothesDict[cloth] = temp
            clothSet.add(cloth)
    
    result = 0
    combiList = []
    for cloth in clothSet:
        nFact = 1
        nrFact = 1
        value = clothesDict.get(cloth).__len__()
        for v in range(1, value + 2): nFact *= v
        for v in range(1, value + 1): nrFact *= v
        combiList.append(nFact // nrFact)
        
    answer = 1
    for value in combiList: answer *= value
    print(answer - 1)