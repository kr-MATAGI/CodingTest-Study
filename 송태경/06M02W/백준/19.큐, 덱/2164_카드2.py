n =  int(input())
qq = []
for i in range(1, n+1):
    qq.append(i)

while len(qq) > 1: 
    if len(qq)%2  == 1: 
        temp_list = [qq[-1]]
        temp_list.extend(qq[1::2])
        qq = temp_list 
    else:
        qq = qq[1::2]
print(qq[0])