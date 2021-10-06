def ucln(a, b):
    if (b == 0):
        return a;
    return ucln(b, a % b);
a ,b = input().split()
print(ucln(int(a), int(b)))