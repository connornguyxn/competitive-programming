a = input()
s = 0
while (a[-1] == '-'):
    a = a[:-1]
for i in range(len(a)):
    if a[i].isdecimal():
        if (a[i-1] == '-'):
            s -= int(a[i])
        else:
            s += int(a[i])
print(s)