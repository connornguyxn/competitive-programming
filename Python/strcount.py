a = input()
upp, low, num, etc = 0, 0, 0, 0
for i in a:
    if i.isupper():
        upp += 1
    elif i.islower():
        low += 1
    elif i.isnumeric():
        num += 1
    else:
        etc += 1

print('''In hoa: {}
In thuong: {}
So: {}
Khac {}'''.format(upp, low, num, etc))