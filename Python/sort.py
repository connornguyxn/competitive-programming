a = list(map(int, input().split()))
a.sort(reverse = True)
a = list(map(str, a))
print(' '.join(a))