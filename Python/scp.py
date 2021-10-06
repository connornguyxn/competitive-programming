import math
a = int(input())
if (math.modf(math.sqrt(a))[0] == 0):
    print('YES')
else:
    print('NO')

# the fked up way

n = int(input())
check = False
 
for i in range(1, n + 1 ):
    if (i**2 == n):
        check = True
        break

if check:
    print('YES')
else:
    print('NO')