N = int(input())
Nlist = list(map(int, str(input()).split()))
st = str(Nlist) 

maxValue = max(Nlist)
minValue = min(Nlist)
print(maxValue * minValue)