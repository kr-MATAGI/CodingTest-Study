def factor_or_mutiple(first_num, second_num):
    if first_num > second_num:
        if first_num%second_num == 0:
            print('multiple')
        else:
            print('neither')
    else:
        if second_num%first_num == 0:
            print('factor')
        else:
            print('neither')
            
while(1):
    n_1, n_2 = map(int, input().split())
    if n_1*n_2 == 0:
        break
    else:
        factor_or_mutiple(n_1, n_2)
        

# 참고
while 1:
    a,b=map(int,input().split())
    if a<1 and b<1:break
    if b%a==0:print("factor")
    else:print(["multiple","neither"][a%b>0])
