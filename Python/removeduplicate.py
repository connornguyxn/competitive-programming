n = int(input())
a = []
for i in range(n):
    a.append(input())
print(len(list(dict.fromkeys(a))))