n = int(input())
a = list(map(int, input().split()))

min_pos = 0

for i in range(n):
    if (a[i] == 0):
        loop = 1
    else:
        loop = a[i] // n + min(1, a[i] % n)
    min_loop = a[min_pos] // n + min(1, a[min_pos] % n)
    if ((loop < min_loop) or ((loop == min_loop) and (max(0,a[i] - i) % n < max(0,a[min_pos] - min_pos) % n))):
        min_pos = i
print(min_pos + 1)