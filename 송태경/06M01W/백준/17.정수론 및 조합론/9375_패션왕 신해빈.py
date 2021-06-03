t =  int(input())
for _ in range(t):
    item = int(input())
    item_dict = {}
    for _ in range(item):
        cloth, parts = input().split()
        if parts in item_dict.keys():
            item_dict[parts] += 1
        else:
            item_dict[parts] = 1
    total = 1
    for w in item_dict.keys():
        total *= (item_dict[w]+1)
    print(total-1)