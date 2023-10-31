def numofdates(m, y):
    if m in (1,3,5,7,8,10,12):
        return 31
    elif m in (4,6,9,11):
        return 30
    elif (y % 400 == 0) or ((y % 4 == 0) and (y % 100 != 0)):
        return 29
    else:
        return 28

m, y = map(int, input().split())
print(numofdates(m, y))