n = int(input())

if n < 0:
    n -= n*2
if n == 0:
    print('INF')
else:
    print(n, end = ' ')
    for i in range(n//2, 1, -1):
        if n % i == 0:
            print(i, end = ' ')
    print(1)