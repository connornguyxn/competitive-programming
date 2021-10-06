a = input().split(',')
o = []
for i in a:
    if (int(i, 2) % 3 == 0):
        o.append(i)
print(','.join(o))