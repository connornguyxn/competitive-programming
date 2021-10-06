n = int(input())
c = 0
for i in range(n):
    a = input()
    t = 0
    for char in a:
        t += int(char)
    if (str(t)[-1] == '9'):
        c += 1
print(c)