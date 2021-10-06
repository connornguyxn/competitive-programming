import re

c = []
a, b = input(), input()
for m in re.finditer(b, a):
    c.append(m.start())
for i in c:
    print(i+1, end=' ')