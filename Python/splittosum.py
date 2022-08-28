a = []

def out():
    for i in range(d):
        print(a[i], sep=' ', end='')

def calc(n, c):
    out()
    print(n)
    if n>=2*c:
        for i in range(c, (n // 2) + 1):
            d += 1
            a[d] = i
            calc
