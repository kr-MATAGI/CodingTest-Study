inputData = list(input())

parsedList = []
number = ''
for data in inputData:
    if '-' != data and '+' != data: number += data
    else:
        parsedList.append(number)
        number = ''
        parsedList.append(data)

if 0 < len(number): parsedList.append(int(number))

sumValue = 0
addValue = 0

isMinus = False
for item in parsedList:
    if '-' == item or '+' == item:            
        if False == isMinus and '-' == item:
            isMinus = True
            
    else:
        value = int(item)
        if(False == isMinus): sumValue += value
        else: addValue += value

if(True == isMinus): sumValue = sumValue - addValue
else: sumValue = sumValue + addValue

print(sumValue)