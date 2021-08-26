test = int(input())
for i in range(test):
    n = int(input())
    a = ''
    while (n>0):
        a += str(n%2)
        n = n//2
    a = a[::-1]
    print(a[a.find('1'):])