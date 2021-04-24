div = 2
insu = []
n = int(input())
while n != 1:
    if n%div == 0:
        n = n//div
        # insu.append(div)
        print(div)
    else:
        div += 1
for i in insu:
    print(i)

# -----------------------------------

n = int(input())
i = 2
r = int(n ** 0.5)

while i <= r:
    while not n % i:
        print(i)
        n //= i
    i += 1
if n > 1:
    print(n)
