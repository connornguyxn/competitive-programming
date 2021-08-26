n = int(input('Nhap N: '))
a = []
b = []
for i in range(n):
    inp = input('Nhap gia tri thu ' + str(i+1) + ': ')
    try:
        a.append(float(inp))
    except:
        b.append(inp)
if a:
    print('TBC cua A = {:.3f}'.format(sum(a) / len(a)))
print('B =', b)