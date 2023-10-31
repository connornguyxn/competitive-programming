from math import sqrt

n = int(input())
c = 0
for i in range(n):
    a = int(input())
    if (sqrt(a) % 1 == 0):
        c += 1
print(c)