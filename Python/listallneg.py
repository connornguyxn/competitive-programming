a = list(map(int, input().split()))
b = []
for i in a[:a.index(0)]:
    if (i < 0):
        b.append(i)

if b:
    print(' '.join(b))
else:
    print('NOT FOUND')