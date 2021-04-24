x_num = []
y_num = []
for _ in range(3):
    x, y = map(int, input().split())
    x_num.append(x)
    y_num.append(y)

for i in range(3):
    if x_num.count(x_num[i]) == 1:
        x = x_num[i]
    if y_num.count(y_num[i]) == 1:
        y = y_num[i]
print(x, y)

# -------------------------------------------------

x=y=0
exec("a,b=map(int,input().split());x^=a;y^=b;"*3)
print(x,y)

# -------------------------------------------------

x = []
y = []

for i in range(3):
    a,b = map(int,input().split())

    if a in x : x.remove(a)
    else : x.append(a)
    if b in y : y.remove(b)
    else : y.append(b)

print(*x,*y)