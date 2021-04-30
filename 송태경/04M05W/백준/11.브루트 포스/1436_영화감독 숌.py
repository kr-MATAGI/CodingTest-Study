n = int(input())
death_num = 666
cnt = 0

while True:
    if '666' in str(death_num):
        cnt += 1
    if cnt == n:
        break
    death_num += 1
print(death_num)

# --------------------------------------------

sss=[666]
i=1

while len(sss)<10000:
    num=i*1000+666
    if i%1000==666:
        for j in range(1000):
            sss.append(i*1000+j)
    elif i%100==66:
        for j in range(100):
            sss.append(i*1000+600+j)
    elif i%10==6:
        for j in range(10):
            sss.append(i*1000+660+j)
    else:
        sss.append(num)
    i+=1
print(sss[int(input())-1])