n = int(input())
a = list(map(int, input().split()))
t = 0
n = 0
for i in a:
    if (i % 2 != 0):
        t += i
        n += 1
print('{:.4f}'.format(t/n))