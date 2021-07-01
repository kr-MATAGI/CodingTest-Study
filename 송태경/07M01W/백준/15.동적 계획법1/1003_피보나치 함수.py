n = int(input())
 
z_list = [1, 0, 1]
o_list = [0, 1, 1]
 
def cal(num):
    length = len(z_list)
    if length <= num:
        for i in range(length, num+1):
            z_list.append(z_list[i-1] + z_list[i-2])
            o_list.append(o_list[i-1] + o_list[i-2])
    print(z_list[num], o_list[num])

for i in range(n):
    k = int(input())
    cal(k)