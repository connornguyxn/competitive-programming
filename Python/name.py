n = int(input())
for j in range(n):
    a = input().split()
    for i in range(len(a)):
        a[i] = a[i].capitalize()
    print(' '.join(a))