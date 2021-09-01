cout = 0
inp = 1
s = 0
while (inp != 0):
    inp = int(input())
    if (inp % 2 == 0) and (inp > 0):
        s += inp
        cout += 1
if (cout == 0):
    print('khong hop le')
else:
    print(s/cout)