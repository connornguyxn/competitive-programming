a = input().split()
n = input()
if n in a:
    for i, x in enumerate(a):
        if (x == n):
            print(i + 1)
else:
    print(0)
