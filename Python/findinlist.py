a = input().split()[1]
b = input().split()
try:
    b.index(a)
    print('YES')
except:
    print('NO')