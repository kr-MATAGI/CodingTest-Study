def make_star(ss):
    temp = []
    for i in range(3 * len(ss)):
        if  i // len(ss) == 1:
            temp.append(ss[i%len(ss)]+' '*len(ss)+ss[i%len(ss)])
        else:
            temp.append(ss[i%len(ss)]*3)
    return temp

star = ['***', '* *', '***']
n = int(input())
k = 0

while True:
    if n == 3:
        break
    n = n//3
    k += 1
    
for i in range(k):
    star = make_star(star)

for lin in star:
    print(lin)